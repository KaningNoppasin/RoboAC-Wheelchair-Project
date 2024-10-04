#ifndef INIT_IO
#define INIT_IO

#define INA_MOTOR_LEFT 4
#define INB_MOTOR_LEFT 3
#define PWM_MOTOR_LEFT 2

#define INA_MOTOR_RIGHT 7
#define INB_MOTOR_RIGHT 6
#define PWM_MOTOR_RIGHT 5

byte PINOUT[6] = {
    INA_MOTOR_LEFT, INB_MOTOR_LEFT, PWM_MOTOR_LEFT,
    INA_MOTOR_RIGHT, INB_MOTOR_RIGHT, PWM_MOTOR_RIGHT,
};

#define JOY_VRX A15
#define JOY_VRY A14
#define JOY_SW  23
#define SIDE_SWITCH  25

byte PININ[4] = {
    JOY_VRX, JOY_VRY, JOY_SW,
    SIDE_SWITCH
};

// byte TEST_ANALOG[16] = {
//     A0,
//     A1,
//     A2,
//     A3,
//     A4,
//     A5,
//     A6,
//     A7,
//     A8,
//     A9,
//     A10,
//     A11,
//     A12,
//     A13,
//     A14,
//     A15
// };


#endif