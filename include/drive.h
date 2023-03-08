#include "api.h"

using namespace std;
using namespace pros;

class Drive{


    int moveVelocity;
    int spinVelocity;
    float direction;
    float directionLocal;

public:

    void update_drive();

    void set_direction(float direction, bool useLocal);
    void set_move_velocity(float velocity);
    void set_spin_velocity(float velocity);

};