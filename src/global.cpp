#include "main.h";
using namespace pros;

Motor flWheel(1,E_MOTOR_GEARSET_06,false);
Motor frWheel(2,E_MOTOR_GEARSET_06,false);
Motor blWheel(3,E_MOTOR_GEARSET_06,false);
Motor brWheel(4,E_MOTOR_GEARSET_06,false);

Rotation lEncoder(5);
Rotation rEncoder(6);
Rotation bEncoder(7);

Controller controller(CONTROLLER_MASTER);