#include "./initIO.h"
#include "./MotorController.ino"

void setup()
{
    Serial.begin(115200);
    for (byte i = 0;i < sizeof(PINOUT) / sizeof(byte);i++) pinMode(PINOUT[i], OUTPUT);
    for (byte i = 0;i < sizeof(PININ) / sizeof(byte);i++) pinMode(PININ[i], INPUT_PULLUP);
    // for (byte i = 0;i < sizeof(TEST_ANALOG) / sizeof(byte);i++) pinMode(TEST_ANALOG[i], INPUT_PULLUP);
}

void loop()
{
    // Serial.print("JOY_VRX: "); Serial.print(analogRead(JOY_VRX));
    // Serial.print(" JOY_VRY: "); Serial.print(analogRead(JOY_VRY));
    // Serial.print(" JOY_SW: "); Serial.print(digitalRead(JOY_SW));
    // Serial.print(" SIDE_SWITCH: "); Serial.println(digitalRead(SIDE_SWITCH));

    // delay(20);
    // for (byte i = 0;i < sizeof(TEST_ANALOG) / sizeof(byte);i++){
    //     Serial.print(" ");
    //     Serial.print(analogRead(TEST_ANALOG[i]));
    // }
    // Serial.println();
}