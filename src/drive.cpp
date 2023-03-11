#include "main.h"

void Drive::update_drive(){
    double yDia=sinf(directionLocal-45);
    double xDia=cosf(directionLocal-45);

    double ratio = 200/max(abs(yDia),abs(xDia));

    frWheel.move_velocity(moveVelocity*ratio*yDia+spinVelocity*200);
    flWheel.move_velocity(moveVelocity*ratio*xDia+spinVelocity*200);
    brWheel.move_velocity(moveVelocity*ratio*xDia+spinVelocity*200);
    blWheel.move_velocity(moveVelocity*ratio*yDia+spinVelocity*200);

    frWheel.move(127);
}

void Drive::set_direction(double dir, bool useLocal){
    if (useLocal){
        dir+=odometry.rot;
    }
    direction=dir;
    directionLocal=dir-odometry.rot;
}

void Drive::set_move_velocity(double velocity){
    moveVelocity=velocity;
}

void Drive::set_spin_velocity(double velocity){
    spinVelocity=velocity;
}