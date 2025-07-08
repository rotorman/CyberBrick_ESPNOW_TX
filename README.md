# CyberBrick_ESPNOW_TX
<img alt="EdgeTXplusCyberBrickAreGreatFun" src="https://github.com/user-attachments/assets/dae157e8-c7b3-4e4b-a221-7fbd8e9f20e9" width="800px" />

Here you can find a custom open-source firmware development for the [internal ExpressLRS](https://github.com/ExpressLRS/ExpressLRS/) RF module(s) to communicate with [BambuLabs/MakerWorls CyberBrick Core](https://eu.store.bambulab.com/de/products/multi-function-controller-core-1pcs) receiver modules, flashed with [custom MicroPython ESP-NOW protocol](https://github.com/CyberBrick-Official/CyberBrick_Controller_Core/pull/4) (code at: [https://github.com/rotorman/CyberBrick_Controller_Core/tree/espnowdemo/src/community/app_espnow](https://github.com/rotorman/CyberBrick_Controller_Core/tree/espnowdemo/src/community/app_espnow)).

To be built, [similar to ExpressLRS firmware](https://www.expresslrs.org/software/toolchain-install/), with [Visual Studio Code](https://code.visualstudio.com/) and [PlatformIO](https://platformio.org/) extension using [Arduino framework](https://docs.platformio.org/en/latest/frameworks/arduino.html) for [Espressif ESP32](https://docs.platformio.org/en/latest/platforms/espressif32.html#platform-espressif32) platform.

The code supports following handsets running [EdgeTX](https://edgetx.org/) open-source firmware (supported radios listed alphabetically):

* [HelloRadioSky V14](https://www.helloradiosky.com/)
* [HelloRadioSky V16](https://www.helloradiosky.com/)
* [Jumper T-14 with 900 MHz and 2.4 GHz internal ELRS modules](https://www.jumper-rc.com/transmitters/t14-3/)
* [Jumper T-15 with 900 MHz and 2.4 GHz internal ELRS modules](https://www.jumper-rc.com/transmitters/t15/)
* [Jumper T20 and T20v2, both with 900MHz and 2.4 GHz internal ELRS modules and T20 Gemini](https://www.jumper-rc.com/transmitters/t20-2/)
* [Jumper T-Lite](https://www.jumper-rc.com/transmitters/t-lite-v2/)
* [Jumper T-Pro with 900 MHz and 2.4 GHz internal ELRS modules](https://www.jumper-rc.com/transmitters/)
* [Jumper T-Pro S with 900 MHz and 2.4 GHz internal ELRS modules](https://www.jumper-rc.com/transmitters/t-pro-s-2/)
* [RadioMaster Boxer with internal ELRS module](https://radiomasterrc.com/products/boxer-radio-controller-m2)
* [RadioMaster MT12 with internal ELRS module](https://radiomasterrc.com/products/mt12-surface-radio-controller)
* [RadioMaster Pocket with internal ELRS module](https://radiomasterrc.com/products/pocket-radio-controller-m2)
* [RadioMaster TX12 mkII with internal ELRS module](https://radiomasterrc.com/products/tx12-mark-ii-radio-controller)
* [RadioMaster TX16s mkII with internal ELRS module](https://radiomasterrc.com/products/tx16s-mark-ii-radio-controller)
* [RadioMaster Zorro with internal ELRS module](https://radiomasterrc.com/products/zorro-radio-controller?variant=46486367371456)

Flashing the internal ExpressLRS module(s) is possible via EdgeTX passthrough (triggered in the background while uploading firmware from VSCode and PlatformIO by [Python script](https://github.com/rotorman/CyberBrick_ESPNOW_TX/python/EdgeTXpassthrough.py)).

Numerous parts of the code used in this repository stem from the wonderful [ExpressLRS project](https://github.com/ExpressLRS/ExpressLRS/).

The development and testing was carried out using an [ESP32DevKitCv4](https://www.az-delivery.de/en/products/esp-32-dev-kit-c-v4), paired with radio running [EdgeTX](https://edgetx.org/) firmware. The code is setup for in-circuit-debugging with [ESP-Prog](https://docs.espressif.com/projects/esp-iot-solution/en/latest/hw-reference/ESP-Prog_guide.html) on ESP32DevKitCv4 target. You can find more info about this in the [Wiki section](https://github.com/rotorman/CyberBrick_ESPNOW_TX/wiki/In%E2%80%90Circuit%E2%80%90Debugging), incl. a detailed hookup scheme.

<img src="https://www.expresslrs.org/assets/external/raw.githubusercontent.com/ExpressLRS/ExpressLRS-hardware/master/img/hardware.png" height="50px"> <img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2020/01/esp-now-logo.png" height="50px"> <img src="https://avatars.githubusercontent.com/u/64278475" height="50px"> <img src="https://blog.bambulab.com/content/images/size/w320/2025/03/Frame-62.png" height="50px"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Visual_Studio_Code_1.35_icon.svg/250px-Visual_Studio_Code_1.35_icon.svg.png" height="50px"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/cd/PlatformIO_logo.svg/500px-PlatformIO_logo.svg.png" height="50px"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Arduino_Logo.svg/330px-Arduino_Logo.svg.png" height="50px"> <img src="https://raw.githubusercontent.com/EdgeTX/edgetx/refs/heads/main/companion/src/images/icon.png" height="50px">
