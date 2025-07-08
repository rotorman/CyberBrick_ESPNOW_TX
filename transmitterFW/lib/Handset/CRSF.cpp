#include "CRSF.h"
#include "common.h"

GENERIC_CRC8 crsf_crc(CRSF_CRC_POLY);

/***
 * @brief: Convert `version` (string) to a integer version representation
 * e.g. "2.2.15 ISM24G" => 0x0002020f
 * Assumes all version fields are < 256, the number portion
 * MUST be followed by a space to correctly be parsed
 ***/
uint32_t CRSF::VersionStrToU32(const char *verStr)
{
    uint32_t retVal = 0;
    uint8_t accumulator = 0;
    char c;
    bool trailing_data = false;
    while ((c = *verStr))
    {
        ++verStr;
        // A decimal indicates moving to a new version field
        if (c == '.')
        {
            retVal = (retVal << 8) | accumulator;
            accumulator = 0;
            trailing_data = false;
        }
        // Else if this is a number add it up
        else if (c >= '0' && c <= '9')
        {
            accumulator = (accumulator * 10) + (c - '0');
            trailing_data = true;
        }
        // Anything except [0-9.] ends the parsing
        else
        {
            break;
        }
    }
    if (trailing_data)
    {
        retVal = (retVal << 8) | accumulator;
    }
    // If the version ID is < 1.0.0, we could not parse it,
    if (retVal < 0x010000)
    {
        retVal = 0x010000;
    }
    return retVal;
}

void CRSF::GetDeviceInformation(uint8_t *frame, uint8_t fieldCount)
{
    const uint8_t size = strlen(device_name)+1;
    auto *device = (deviceInformationPacket_t *)(frame + sizeof(crsf_ext_header_t) + size);
    // Packet starts with device name
    memcpy(frame + sizeof(crsf_ext_header_t), device_name, size);
    // Followed by the device
    device->serialNo = htobe32(0x43425458); // ['C', 'B', 'T', 'X']
    device->hardwareVer = 0; // currently unused
    device->softwareVer = htobe32(VersionStrToU32(versionID)); // Example "Firmware: V 1.15" results to [ 0x00, 0x00, 0x01, 0x0f ]
    device->parametersCnt = fieldCount;
    device->parameterVersion = 0;
}

void CRSF::SetHeaderAndCrc(uint8_t *frame, crsf_frame_type_e frameType, uint8_t frameSize, crsf_addr_e destAddr)
{
    auto *header = (crsf_header_t *)frame;
    header->device_addr = destAddr;
    header->frame_size = frameSize;
    header->type = frameType;

    uint8_t crc = crsf_crc.calc(&frame[CRSF_FRAME_NOT_COUNTED_BYTES], frameSize - 1, 0);
    frame[frameSize + CRSF_FRAME_NOT_COUNTED_BYTES - 1] = crc;
}

void CRSF::SetExtendedHeaderAndCrc(uint8_t *frame, crsf_frame_type_e frameType, uint8_t frameSize, crsf_addr_e senderAddr, crsf_addr_e destAddr)
{
    auto *header = (crsf_ext_header_t *)frame;
    header->dest_addr = destAddr;
    header->orig_addr = senderAddr;
    SetHeaderAndCrc(frame, frameType, frameSize, destAddr);
}

