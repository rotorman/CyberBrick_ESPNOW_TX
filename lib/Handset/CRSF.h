#ifndef H_CRSF
#define H_CRSF

#include "crsf_protocol.h"

class CRSF
{
public:
    static crsfLinkStatistics_t LinkStatistics; // Link Statistics Stored as Struct

    static void SetHeaderAndCrc(uint8_t *frame, crsf_frame_type_e frameType, uint8_t frameSize, crsf_addr_e destAddr);
    static void SetExtendedHeaderAndCrc(uint8_t *frame, crsf_frame_type_e frameType, uint8_t frameSize, crsf_addr_e senderAddr, crsf_addr_e destAddr);
    static uint32_t VersionStrToU32(const char *verStr);
};

extern GENERIC_CRC8 crsf_crc;

#endif