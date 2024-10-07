#ifndef JOY_CONTROLLER
#define JOY_CONTROLLER
#include <Arduino.h>
#include "./initIO.h"

const uint16_t MAX_JOY_VRX = 1023;   // LEFT
const uint16_t MAX_JOY_VRY = 1022;   // DOWN
const uint16_t MAX_OFFSET = 200;

const uint16_t NORMAL_JOY_VRX = 608;
const uint16_t NORMAL_JOY_VRY = 597;
const uint16_t NORMAL_OFFSET = 200;

const uint16_t MIN_JOY_VRX = 15;     // RIGHT
const uint16_t MIN_JOY_VRY = 87;     // UP
const uint16_t MIN_OFFSET = 300;

uint16_t JOY_VRX_VALUE;
uint16_t JOY_VRY_VALUE;

void joyController(
    void (*callbackUp)(),
    void (*callbackDown)(),
    void (*callbackLeft)(),
    void (*callbackRight)(),
    void (*callbackStop)(),
    void (*callbackUpLeft)(),
    void (*callbackUpRight)(),
    void (*callbackDownLeft)(),
    void (*callbackDownRight)()
){
    JOY_VRX_VALUE = analogRead(JOY_VRX);
    JOY_VRY_VALUE = analogRead(JOY_VRY);

    // JOY_VRX
    if (
        JOY_VRX_VALUE > MAX_JOY_VRX - MAX_OFFSET &&
        (NORMAL_JOY_VRY + NORMAL_OFFSET > JOY_VRY_VALUE && JOY_VRY_VALUE > NORMAL_JOY_VRY - NORMAL_OFFSET))
    {
        if (callbackLeft != nullptr) callbackLeft();
    }
    else if (
        MIN_JOY_VRX + MIN_OFFSET > JOY_VRX_VALUE &&
        (NORMAL_JOY_VRY + NORMAL_OFFSET > JOY_VRY_VALUE && JOY_VRY_VALUE > NORMAL_JOY_VRY - NORMAL_OFFSET))
    {
        if (callbackRight != nullptr) callbackRight();
    }
    // JOY_VRY
    else if (
        JOY_VRY_VALUE > MAX_JOY_VRY - MAX_OFFSET &&
        (NORMAL_JOY_VRX + NORMAL_OFFSET > JOY_VRX_VALUE && JOY_VRX_VALUE > NORMAL_JOY_VRX - NORMAL_OFFSET))
    {
        if (callbackDown != nullptr) callbackDown();
    }
    else if (
        MIN_JOY_VRY + MIN_OFFSET > JOY_VRY_VALUE &&
        (NORMAL_JOY_VRX + NORMAL_OFFSET > JOY_VRX_VALUE && JOY_VRX_VALUE > NORMAL_JOY_VRX - NORMAL_OFFSET))
    {
        if (callbackUp != nullptr) callbackUp();
    }
    else if(
        (NORMAL_JOY_VRY + NORMAL_OFFSET > JOY_VRY_VALUE && JOY_VRY_VALUE > NORMAL_JOY_VRY - NORMAL_OFFSET) &&
        (NORMAL_JOY_VRX + NORMAL_OFFSET > JOY_VRX_VALUE && JOY_VRX_VALUE > NORMAL_JOY_VRX - NORMAL_OFFSET)
    )
    {
        if (callbackStop != nullptr) callbackStop();
    }
    // ↖
    //  ↘
    else{
        // UP-LEFT
        if (
            JOY_VRY_VALUE < NORMAL_JOY_VRY - NORMAL_OFFSET &&
            JOY_VRX_VALUE > NORMAL_JOY_VRX + NORMAL_OFFSET
        ){
            // Serial.println("UP-LEFT");
            if (callbackUpLeft != nullptr) callbackUpLeft();
        }
        // UP-RIGHT
        else if (
            JOY_VRY_VALUE < NORMAL_JOY_VRY - NORMAL_OFFSET &&
            JOY_VRX_VALUE < NORMAL_JOY_VRX - NORMAL_OFFSET
        ){
            // Serial.println("UP-RIGHT");
            if (callbackUpRight != nullptr) callbackUpRight();
        }
        // DOWN-LEFT
        else if (
            JOY_VRY_VALUE > NORMAL_JOY_VRY + NORMAL_OFFSET &&
            JOY_VRX_VALUE > NORMAL_JOY_VRX + NORMAL_OFFSET
        ){
            // Serial.println("DOWN-LEFT");
            if (callbackDownLeft != nullptr) callbackDownLeft();
        }
        // DOWN-RIGHT
        else if (
            JOY_VRY_VALUE > NORMAL_JOY_VRY + NORMAL_OFFSET &&
            JOY_VRX_VALUE < NORMAL_JOY_VRX - NORMAL_OFFSET
        ){
            // Serial.println("DOWN-RIGHT");
            if (callbackDownRight != nullptr) callbackDownRight();
        }else{
            if (callbackStop != nullptr) callbackStop();
        }
    }
}

#endif
