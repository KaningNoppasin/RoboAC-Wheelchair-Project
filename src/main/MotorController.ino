#ifndef MOTOR_FILE
#define MOTOR_FILE

#include "./initIO.h"

#define MOTOR_LEFT_FORWARD (pwm)    do{ digitalWrite(INA_MOTOR_LEFT, HIGH); digitalWrite(INB_MOTOR_LEFT, LOW);  analogWrite(INA_MOTOR_LEFT, pwm); } while(0)
#define MOTOR_LEFT_STOP (x)         do{ digitalWrite(INA_MOTOR_LEFT, LOW);  digitalWrite(INB_MOTOR_LEFT, LOW);  analogWrite(INA_MOTOR_LEFT, 0); }   while(0)
#define MOTOR_LEFT_BACKOFF (pwm)    do{ digitalWrite(INA_MOTOR_LEFT, LOW);  digitalWrite(INB_MOTOR_LEFT, HIGH); analogWrite(INA_MOTOR_LEFT, pwm); } while(0)

#define MOTOR_RIGHT_FORWARD (pwm)   do{ digitalWrite(INA_MOTOR_RIGHT, HIGH); digitalWrite(INB_MOTOR_RIGHT, LOW);  analogWrite(INA_MOTOR_RIGHT, pwm); } while(0)
#define MOTOR_RIGHT_STOP (x)        do{ digitalWrite(INA_MOTOR_RIGHT, LOW);  digitalWrite(INB_MOTOR_RIGHT, LOW);  analogWrite(INA_MOTOR_RIGHT, 0); }   while(0)
#define MOTOR_RIGHT_BACKOFF (pwm)   do{ digitalWrite(INA_MOTOR_RIGHT, LOW);  digitalWrite(INB_MOTOR_RIGHT, HIGH); analogWrite(INA_MOTOR_RIGHT, pwm); } while(0)

//     -------
//     |  =  |
//   ↑L   =   R↑
//     |  =  |
//     -------
#define FORWARD (pwm)   do{ MOTOR_LEFT_FORWARD(pwm); MOTOR_RIGHT_FORWARD(pwm); } while(0)

//     -------
//     |  =  |
//   =L   =   R=
//     |  =  |
//     -------
#define STOP (x)        do{ MOTOR_LEFT_STOP(0);      MOTOR_RIGHT_STOP(0); } while(0)

//     -------
//     |  =  |
//   ↓L   =   R↓
//     |  =  |
//     -------
#define BACKOFF (pwm)   do{ MOTOR_LEFT_BACKOFF(pwm); MOTOR_RIGHT_BACKOFF(pwm); } while(0)

//     -------
//     |   ↖ |
//   ↓L   =   R↑
//     | ↘   |
//     -------
#define LEFT_1 (pwm)   do{ MOTOR_LEFT_BACKOFF(pwm); MOTOR_RIGHT_FORWARD(pwm); } while(0)

//     -------
//     |  ←  |
//   =L   =   R↑
//     |  =  |
//     -------
#define LEFT_2 (pwm)   do{ MOTOR_LEFT_STOP(pwm); MOTOR_RIGHT_FORWARD(pwm); } while(0)


//     -------
//     |   ↘ |
//   ↑L   =   R↓
//     | ↖   |
//     -------
#define RIGHT_1 (pwm)   do{ MOTOR_LEFT_FORWARD(pwm); MOTOR_RIGHT_BACKOFF(pwm); } while(0)

//     -------
//     |  →  |
//   ↑L   =   R=
//     |  =  |
//     -------
#define RIGHT_2 (pwm)   do{ MOTOR_LEFT_FORWARD(pwm); MOTOR_RIGHT_STOP(pwm); } while(0)



#endif