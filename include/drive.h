#include "api.h"

using namespace std;
using namespace pros;

class Drive{
public:

    int moveVelocity;
    int spinVelocity;

    void update_drive(int velocity);

};