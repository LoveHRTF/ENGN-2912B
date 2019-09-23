#include "translation.h"

// TODO: Implement your "translation" function 

bool translation(double const& p1_x, double const& p1_y, double const& p2_x, double const& p2_y, double& res_x, double& res_y){


    // Check if overlaps
    if ((res_x == p1_x) && (res_y == p1_y)){
        return 0;
    }

    // Calculate Vector
    res_x = p2_x - p1_x;
    res_y = p2_y - p1_y;

return 0;

}