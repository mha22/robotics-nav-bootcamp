#include <cmath>
#include "nav/pose2d.hpp"

namespace nav {

double deg2rad(double deg){
    return deg * M_PI / 180;
}


double rad2deg(double rad){
    return rad * 180 / M_PI;
}


double normalize_angle_rad(double yaw_raw){
    while (yaw_raw > M_PI)
        yaw_raw -= 2 * M_PI;
    while (yaw_raw <= -M_PI)
        yaw_raw += 2 * M_PI;
    return yaw_raw;
}


Pose2D integrate_body_twist(const Pose2D& p, double v, double w_rad, double dt){
    

    double yaw2_rad = p.yaw_rad + w_rad * dt;
    double x2 = p.x + v * dt * cos(p.yaw_rad);
    double y2 = p.y + v * dt * sin(p.yaw_rad);
    yaw2_rad = normalize_angle_rad(yaw2_rad);
    return Pose2D {x2, y2, yaw2_rad};
}


}