#include "./initIO.h"
#include "./MotorController.ino"
#include "./JoyController.ino"

uint8_t setSpeed[2] = {100, 200};
bool index = 1;

void setup()
{
    Serial.begin(115200);
    Serial.println("> Hello Robot");
    initIO();
}

void loop()
{
    // joyController(
    //     []() { Serial.println("UP"); },    // Callback for Up
    //     []() { Serial.println("DOWN"); },  // Callback for Down
    //     []() { Serial.println("LEFT"); },  // Callback for Left
    //     []() { Serial.println("RIGHT"); }, // Callback for Right
    //     []() { Serial.println("STOP"); },   // Callback for Stop
    //     []() { Serial.println("UP-LEFT"); },   // Callback for UP-LEFT
    //     []() { Serial.println("UP-RIGHT"); },   // Callback for UP-RIGHT
    //     []() { Serial.println("DOWN-LEFT"); },   // Callback for DOWN-LEFT
    //     []() { Serial.println("DOWN-RIGHT"); }   // Callback for DOWN-RIGHT
    // );
    Serial.println(speed);
    if (!digitalRead(JOY_SW)){
        index = !index;
        speed = setSpeed[index];
        while (!digitalRead(JOY_SW));
        delay(20);
    }
    joyController(
        []() { FORWARD(speed); },    // Callback for Up
        []() { BACKOFF(speed); },  // Callback for Down
        []() { LEFT_1(speed); },  // Callback for Left
        []() { RIGHT_1(speed); }, // Callback for Right
        []() { STOP(speed); },   // Callback for Stop
        []() { upLeftWithDifferentSpeed(speed); },   // Callback for UP-LEFT
        []() { upRightWithDifferentSpeed(speed); },   // Callback for UP-RIGHT
        []() { downLeftWithDifferentSpeed(speed); },   // Callback for DOWN-LEFT
        []() { downRightWithDifferentSpeed(speed); }   // Callback for DOWN-RIGHT
    );


    // Serial.print("JOY_VRX: "); Serial.print(analogRead(JOY_VRX));
    // Serial.print(" JOY_VRY: "); Serial.print(analogRead(JOY_VRY));
    // Serial.print(" JOY_SW: "); Serial.print(digitalRead(JOY_SW));
    // Serial.print(" SIDE_SWITCH: "); Serial.println(digitalRead(SIDE_SWITCH));

}