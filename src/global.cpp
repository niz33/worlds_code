#include "main.h";
using namespace pros;

Motor flWheel(1,E_MOTOR_GEARSET_06,false,E_MOTOR_ENCODER_ROTATIONS);
Motor frWheel(2,E_MOTOR_GEARSET_06,false,E_MOTOR_ENCODER_ROTATIONS);
Motor blWheel(3,E_MOTOR_GEARSET_06,false,E_MOTOR_ENCODER_ROTATIONS);
Motor brWheel(4,E_MOTOR_GEARSET_06,false,E_MOTOR_ENCODER_ROTATIONS);

Rotation lEncoder(5);
Rotation rEncoder(6);
Rotation bEncoder(7);

Controller controller(CONTROLLER_MASTER);