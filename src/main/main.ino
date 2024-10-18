#include "./initIO.h"
#include "./MotorController.ino"
#include "./JoyController.ino"

uint8_t setSpeed[2] = {30, 50};
bool index = 1;

const long interval = 1000;
unsigned long previousMillis = 0;

uint8_t maxSpeed = 100;
uint8_t speedIncest = 1;
unsigned long countMoveTime = 0;


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
    if (millis() - previousMillis >= interval && !isStop) {
        countMoveTime++;
        previousMillis = millis();
        speed += speedIncest;
        if (countMoveTime < 5) {
            speedIncest = 5;
        }
        else if (countMoveTime < 10){
            speedIncest = 3;
        }
        else if (countMoveTime < 15){
            speedIncest = 2;
        }
        else{
            speedIncest = 1;
        }

        if (speed > maxSpeed){
            speed = maxSpeed;
        }
    }

    if (isStop) {
        countMoveTime = 0;
        speed = defaultSpeed;
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
}