#include "main.h"
#include<iostream>
#include<cmath>

void Odometry::init(){
    x=xStart;
    y=yStart;
    rot=rotStart;

    l=0;
    r=0;
    b=0;

    //constants;
    encoderWheelRatio=8.63937979737;
}

void Odometry::update(){

    dl=(float)lEncoder.get_position()/36000*encoderWheelRatio-l;
    dr=(float)rEncoder.get_position()/36000*encoderWheelRatio-r;
    db=(float)bEncoder.get_position()/36000*encoderWheelRatio-b;

    l=(float)lEncoder.get_position()/36000*encoderWheelRatio-l;
    r=(float)rEncoder.get_position()/36000*encoderWheelRatio-l;
    b=(float)bEncoder.get_position()/36000*encoderWheelRatio-l;

    drot=(dr-dl)/(2.0*lrRad);

    dyLoc=2.0*sinf(drot/2.0)*(dl/drot+lrRad);
    dxLoc=2.0*sinf(drot/2.0)*(db/drot+bRad);

    float averot=rot+drot/2.0;

    dx=dxLoc*cos(averot)-dyLoc*sin(averot);
    dx=dxLoc*sin(averot)+dyLoc*cos(averot);

    x+=dx;
    y+=dy;
    rot+=drot;

}