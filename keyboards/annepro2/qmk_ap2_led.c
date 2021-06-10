#include <string.h>
#include <stdio.h>
#include "hal.h"
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "protocol.h"

annepro2LedStatus_t annepro2LedStatus;

void ledCommandCallback(message_t *msg) {
    switch (msg->command) {
        case CMD_LED_STATUS:
            annepro2LedStatus.amountOfProfiles = msg->payload[0];
            annepro2LedStatus.currentProfile   = msg->payload[1];
            annepro2LedStatus.matrixEnabled    = msg->payload[2];
            annepro2LedStatus.isReactive       = msg->payload[3];
            annepro2LedStatus.ledIntensity     = msg->payload[4];
            annepro2LedStatus.errors           = msg->payload[5];
            break;

#ifdef CONSOLE_ENABLE
        case CMD_LED_DEBUG:
            /* TODO: Don't use printf. */
            printf("LED:");
            for (int i = 0; i < msg->payloadSize; i++) {
                printf("%c", msg->payload[i]);
            }
            printf("\n");
            break;
#endif
    }
}

void annepro2SetIAP(void) { protoTx(CMD_LED_IAP, NULL, 0, 3); }

void annepro2LedDisable(void) { protoTx(CMD_LED_OFF, NULL, 0, 3); }

void annepro2LedEnable(void) { protoTx(CMD_LED_ON, NULL, 0, 3); }

void annepro2LedSetProfile(uint8_t prof) { protoTx(CMD_LED_SET_PROFILE, &prof, sizeof(prof), 3); }

void annepro2LedGetStatus() { protoTx(CMD_LED_GET_STATUS, NULL, 0, 3); }

void annepro2LedNextProfile() { protoTx(CMD_LED_NEXT_PROFILE, NULL, 0, 3); }

void annepro2LedNextIntensity() { protoTx(CMD_LED_NEXT_INTENSITY, NULL, 0, 3); }

void annepro2LedNextAnimationSpeed() { protoTx(CMD_LED_NEXT_ANIMATION_SPEED, NULL, 0, 3); }

void annepro2LedPrevProfile() { protoTx(CMD_LED_PREV_PROFILE, NULL, 0, 3); }

void annepro2LedSetForegroundColor(uint8_t red, uint8_t green, uint8_t blue) {
    // TODO
    // uint8_t colors[3] = {red, green, blue};
    // protoTx(CMD_LED_SET_FOREGROUND_COLOR, colors, sizeof(colors), 1);
}

void annepro2LedResetForegroundColor() {
    // TODO
    // protoTx(CMD_LED_CLEAR_FOREGROUND_COLOR, NULL, 0, 1);
}

/*
 * Currently keypresses are unified with other messages, still with single 1
 * byte payload. Transfer is normally fast enough for that to not be a problem -
 * especially with asynchronous message reading.
 *
 *
 * Previous description:
 * If enabled, this data is sent to LED MCU on every keypress.
 * In order to improve performance, both row and column values
 * are packed into a single byte.
 * Row range is [0, 4] and requires only 3 bits.
 * Column range is [0, 13] and requires 4 bits.
 *
 * In order to differentiate this command from regular commands,
 * the leftmost bit is set to 1 (0b10000000).
 * Following it are 3 bits of row and 4 bits of col.
 * 1 + 3 + 4 = 8 bits - only a single byte is sent for every keypress.
 */
void annepro2LedForwardKeypress(uint8_t row, uint8_t col) {
    const uint8_t payload = row << 4 | col;
    protoTx(CMD_LED_KEY_DOWN, &payload, 1, 1);
}
