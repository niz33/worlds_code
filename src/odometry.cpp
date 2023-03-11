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

    lEncoder.reset();
    rEncoder.reset();
    bEncoder.reset();

    //constants;
    encoderWheelRatio=8.63937979737;

    lrRad=7.14;
}

double sinx_over_x(double x) {
return 1 - x * x / 6.0 + x * x * x * x / 120.0 -
        x * x * x * x * x * x / 5040.0;
}

void Odometry::update(){

    dl=(double)lEncoder.get_position()/36000*encoderWheelRatio-l;
    dr=(double)rEncoder.get_position()/36000*encoderWheelRatio-r;
    db=(double)bEncoder.get_position()/36000*encoderWheelRatio-b;

    l=(double)lEncoder.get_position()/36000*encoderWheelRatio;
    r=(double)rEncoder.get_position()/36000*encoderWheelRatio;
    b=(double)bEncoder.get_position()/36000*encoderWheelRatio;

    drot = (dr - dl) / (2.0 * lrRad);
    double temp = sinx_over_x(drot / 2.0);
    dyLoc = temp * (dl + dr) / 2.0;
    dxLoc = temp * (db + drot * bRad);

    double averot=rot+drot/2.0;

    dx=dxLoc*cos(averot)-dyLoc*sin(averot);
    dx=dxLoc*sin(averot)+dyLoc*cos(averot);

    x+=dx;
    y+=dy;
    rot+=drot;

}