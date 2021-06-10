#pragma once

#include "protocol.h"

extern void ledCommandCallback(message_t *msg);

void annepro2SetIAP(void);
void annepro2LedDisable(void);
void annepro2LedEnable(void);
void annepro2LedSetProfile(uint8_t prof);
void annepro2LedGetStatus(void);
void annepro2LedNextProfile(void);
void annepro2LedPrevProfile(void);
void annepro2LedSetMask(uint8_t key);
void annepro2LedClearMask(uint8_t key);
void annepro2LedNextIntensity(void);
void annepro2LedNextAnimationSpeed(void);
void annepro2LedSetForegroundColor(uint8_t red, uint8_t green, uint8_t blue);
void annepro2LedResetForegroundColor(void);
void annepro2LedForwardKeypress(uint8_t row, uint8_t col);

typedef struct {
    uint8_t amountOfProfiles;
    uint8_t currentProfile;
    uint8_t matrixEnabled;
    uint8_t isReactive;
    uint8_t ledIntensity;
    uint8_t errors;
} annepro2LedStatus_t;

extern annepro2LedStatus_t annepro2LedStatus;
