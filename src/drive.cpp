#include "main.h"

void Drive::update_drive(int voltage){
    flWheel.move_velocity(moveVelocity+spinVelocity);
    frWheel.move_velocity(0-moveVelocity+spinVelocity);
    blWheel.move_velocity(moveVelocity+spinVelocity);
    brWheel.move_velocity(0-moveVelocity+spinVelocity);
}