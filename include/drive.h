#include "api.h"

using namespace std;
using namespace pros;

class Drive{


    int moveVelocity;
    int spinVelocity;
    double direction;
    double directionLocal;

public:

    Odometry odometry;

    void update_drive();

    void set_direction(double direction, bool useLocal);
    void set_move_velocity(double velocity);
    void set_spin_velocity(double velocity);

};