"""
CyberBrick ESP-NOW receiver script in CyberBrick MicroPython flavor.
To be copied to CyberBrick Core on the model side.
Debug script, that prints incoming data onto MicroPython REPL.

The handset, running EdgeTX firmware, sends, via custom ESP-NOW flashed
ExpressLRS transmitter module channel data according to CRSF specifications:
16 proportional channels in slightly lower than 11-bit resolution.
The channel order, range, mixing and further parameters can be adjusted
in the EdgeTX radio.

The incoming value range of the channel data is from 173 to 1811,
with 992 being middle.

The most widely used mapping of the first 4 control channels are (Mode 2, AETR):
1) ch1 - right horizontal (RH) stick (left 173, right 1811)
2) ch2 - right vertical (RV) stick (up 173, down 1811)
3) ch3 - left vertical (LV) stick (down 173, up 1811)
4) ch4 - left horizontal (LH) stick (left 173, right 1811)
"""

from machine import Pin, PWM
import network
import espnow
from neopixel import NeoPixel
import utime
import struct

# If you wish to change the WiFi channel, change this value (valid range is between 1 and 11):
wifi_channel = 1
# Remember to change it ALSO in the transmitter firmware!

# Initialize Wi-Fi in station mode
sta = network.WLAN(network.STA_IF)
sta.active(True)
mac = sta.config('mac')
mac_address = ':'.join('%02x' % b for b in mac)
print("MAC address of the receiver:", mac_address)

def wifi_reset():
  # Reset Wi-Fi to AP_IF off, STA_IF on and disconnected
  sta = network.WLAN(network.WLAN.IF_STA); sta.active(False)
  ap = network.WLAN(network.WLAN.IF_AP); ap.active(False)
  sta.active(True)
  while not sta.active():
      time.sleep(0.1)
  while sta.isconnected():
      time.sleep(0.1)
  sta = network.WLAN(network.STA_IF)
  sta.active(True)
  sta.config(channel=wifi_channel,pm=sta.PM_NONE,reconnects=0)
  sta.disconnect()

wifi_reset()

# Initialize ESP-NOW
e = espnow.ESPNow()

def enow_reset():
  try:
      e.active(True)
  except OSError as err:
      print("Failed to initialize ESP-NOW:", err)
      raise

enow_reset()

# Drive NeoPixel on CyberBrick Core
npcore = Pin(8, Pin.OUT)
np = NeoPixel(npcore, 1)
np[0] = (0, 10, 0) # dim green
np.write()

blinkertime_ms    = 750  # 1.5 Hz

while True:
  try:
    # Receive message (host MAC, message, 500ms failsafe timeout)
    host, msg = e.recv(500)
    if msg == None:
      # No signal from remote, blink red
      if ((utime.ticks_ms() % blinkertime_ms) > (blinkertime_ms / 2)):
        np[0] = (0, 0, 0) # Dark phase
      else:
        np[0] = (10, 0, 0) # Dim red phase
      np.write()
      wifi_reset()
      enow_reset()

    else:
      if len(msg) > 31:
        ch = struct.unpack('<HHHHHHHHHHHHHHHH', msg)
        if len(ch) == 16:
          # Received expected CRSF telegram channel count from the handset
          print('%-5i%-5i%-5i%-5i| %-5i%-5i%-5i%-5i|%-5i%-5i%-5i%-5i| %-5i%-5i%-5i%-5i' % (ch[0:16]))
          # Blink green
          if ((utime.ticks_ms() % blinkertime_ms) > (blinkertime_ms / 2)):
            np[0] = (0, 0, 0) # Dark phase
          else:
            np[0] = (0, 10, 0) # Dim green phase
          np.write()
      else:
        # Unexpected message length
        print(f"Unexpected ESP-NOW message length: {len(msg)}")
        # Blink yellow
        if ((utime.ticks_ms() % blinkertime_ms) > (blinkertime_ms / 2)):
          np[0] = (0, 0, 0) # Dark phase
        else:
          np[0] = (8, 8, 0) # Dim yellow phase
        np.write()
         
  except OSError as err:
    print("Error:", err)
    time.sleep(0.5)
    e.active(False)
    wifi_reset()
    enow_reset()

  except KeyboardInterrupt:
    print("Stopping receiver...")
    e.active(False)
    sta.active(False)
    break
