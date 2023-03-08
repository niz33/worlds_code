#include "main.h"

void Drive::update_drive(){
    float yDia=sinf(directionLocal-45);
    float xDia=cosf(directionLocal-45);

    float ratio = 200/max(abs(yDia),abs(xDia));

    frWheel.move_velocity(moveVelocity*ratio*yDia+spinVelocity*200);
    flWheel.move_velocity(moveVelocity*ratio*xDia+spinVelocity*200);
    brWheel.move_velocity(moveVelocity*ratio*xDia+spinVelocity*200);
    blWheel.move_velocity(moveVelocity*ratio*yDia+spinVelocity*200);
}

void Drive::set_direction(float dir, bool useLocal){
    if (useLocal){
        dir+=odometry.rot;
    }
    direction=dir;
    directionLocal=dir-odometry.rot;
}

void Drive::set_move_velocity(float velocity){
    moveVelocity=velocity;
}

void Drive::set_spin_velocity(float velocity){
    spinVelocity=velocity;
}