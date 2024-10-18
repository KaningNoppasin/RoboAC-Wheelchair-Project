#ifndef INIT_IO
#define INIT_IO

// #define INA_MOTOR_LEFT 4
// #define INB_MOTOR_LEFT 3
// #define PWM_MOTOR_LEFT 2
#define INA_MOTOR_LEFT 3
#define INB_MOTOR_LEFT 4
#define PWM_MOTOR_LEFT 2

#define INA_MOTOR_RIGHT 7
#define INB_MOTOR_RIGHT 6
#define PWM_MOTOR_RIGHT 5

byte PINOUT[6] = {
    INA_MOTOR_LEFT, INB_MOTOR_LEFT, PWM_MOTOR_LEFT,
    INA_MOTOR_RIGHT, INB_MOTOR_RIGHT, PWM_MOTOR_RIGHT,
};

#define JOY_VRX A9
#define JOY_VRY A8
#define JOY_SW  23
#define SIDE_SWITCH  25

byte PININ[4] = {
    JOY_VRX, JOY_VRY, JOY_SW,
    SIDE_SWITCH
};

void initIO(){
    for (byte i = 0;i < sizeof(PINOUT) / sizeof(byte);i++) pinMode(PINOUT[i], OUTPUT);
    for (byte i = 0;i < sizeof(PININ) / sizeof(byte);i++) pinMode(PININ[i], INPUT_PULLUP);
}

#endif