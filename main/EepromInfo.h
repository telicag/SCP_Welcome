//
// Created by telic on 1/9/24.
//

#ifndef SCP_WELCOME_PRINTHARDWAREINFO_H
#define SCP_WELCOME_PRINTHARDWAREINFO_H

#include <stdint.h>

#define EEPROM_I2C_ADDR                 0x50
#define EEPROM_MAX_READ_INDEX           0x30

/* EEPROM constants */
typedef struct
{
    uint8_t     eepromVersion;
    uint32_t    productCodeMajor;
    uint16_t    productCodeMinor;
    uint32_t    timestamp;
    uint32_t    assemblyCodeMajor;
    uint16_t    assemblyCodeMinor;
    char        imei[17];
} EEPROMInfo;


int getEepromInfo( const uint8_t  *buffer,const uint16_t buflen, EEPROMInfo *info);
void printEepromInfo( EEPROMInfo info);

#endif //SCP_WELCOME_PRINTHARDWAREINFO_H
