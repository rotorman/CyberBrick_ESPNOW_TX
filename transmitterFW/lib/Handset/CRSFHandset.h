#pragma once

#include "crsf_protocol.h"
#include "HardwareSerial.h"
#include "common.h"
#include "driver/uart.h"

class CRSFHandset final
{
public:
    /**
     * @brief Start the CRSF handset protocol
     */
    void Begin();

    /**
     * @brief register a function to be called when the protocol has read an RC data packet from the handset
     * @param callback
     */
    void setRCDataCallback(void (*callback)()) { RCdataCallback = callback; }

    /**
     * Register callback functions for state information about the connection or handset
     * @param connectedCallback called when the protocol detects a stable connection to the handset
     * @param disconnectedCallback called when the protocol loses its connection to the handset
     */
    void registerCallbacks(void (*connectedCallback)(), void (*disconnectedCallback)())
    {
        connected = connectedCallback;
        disconnected = disconnectedCallback;
    }

    /**
     * @brief Process any pending input data from the CRSF handset
     */
    void handleInput();

	void handleOutput(int receivedBytes);

	static HardwareSerial Port;
	
	static uint8_t modelId;         // The model ID as received from the handset
	
    static void makeLinkStatisticsPacket(uint8_t *buffer);

    static void packetQueueExtended(uint8_t type, void *data, uint8_t len);

    /**
     * @brief Called to indicate to the protocol that a packet has just been sent over-the-air
     * This is used to synchronise the packets from the handset to the OTA protocol to minimise latency
     */
    void JustSentRFpacket();

    /**
     * Send a telemetry packet back to the handset
     * @param data
     */
	void sendTelemetryToTX(uint8_t *data);

    /**
     * @return the time in microseconds when the last RC packet was received from the handset
     */
    uint32_t GetRCdataLastRecv() const { return RCdataLastRecv; }
	
	/**
     * @return the maximum number of bytes that the protocol can send to the handset in a single message
     */
    uint8_t GetMaxPacketBytes() const { return maxPacketBytes; }

protected:
    bool controllerConnected = false;
    void (*RCdataCallback)() = nullptr;  // called when there is new RC data
    void (*disconnected)() = nullptr;    // called when RC packet stream is lost
    void (*connected)() = nullptr;       // called when RC packet stream is regained

    volatile uint32_t RCdataLastRecv = 0;
    int32_t RequestedRCpacketIntervalUS = RF_FRAME_RATE_US;

private:
    inBuffer_U inBuffer = {};

    /// EdgeTX mixer sync ///
    volatile uint32_t dataLastRecv = 0;
    volatile int32_t EdgeTXsyncOffset = 0;
    volatile int32_t EdgeTXsyncWindow = 0;
    volatile int32_t EdgeTXsyncWindowSize = 1;
    uint32_t EdgeTXsyncLastSent = 0;

    /// UART Handling ///
    uint8_t SerialInPacketPtr = 0; // index where we are reading/writing
    uint32_t GoodPktsCount = 0;
    uint32_t BadPktsCount = 0;
    uint8_t maxPacketBytes = CRSF_MAX_PACKET_LEN;
    uint8_t maxPeriodBytes = CRSF_MAX_PACKET_LEN;
    static uint32_t UARTbaud;
    void sendSyncPacketToTX();
    void RcPacketToChannelsData();
    bool processInternalCrsfPackage(uint8_t *package);
    void alignBufferToSync(uint8_t startIdx);
    bool ProcessPacket();
    void flush_port_input();
};

