#pragma once

using namespace std;

class Odometry{

public:
    //constants
    float lrRad;
    float bRad;
    float encoderWheelRatio;

    float xStart;
    float yStart;
    float rotStart;

    //variables
    float x;
    float y;
    float rot;

    float l,r,b;

    float dl;
    float dr;
    float db;
    float drot;
    float cRad;
    float dxLoc;
    float dyLoc;
    float dx;
    float dy;

    void init();
    void update();
};

