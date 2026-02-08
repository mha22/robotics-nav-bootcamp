#pragma once

namespace nav{
struct Pose2D { 
    double x, y, yaw_rad; 
};

double deg2rad(double deg);
double rad2deg(double rad);
double normalize_angle_rad(double a);
Pose2D integrate_body_twist(const Pose2D& p, double v, double w_rad, double dt);

}