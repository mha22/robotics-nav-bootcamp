#include<iostream>
#include "nav/pose2d.hpp"



int main(){
    double x, y, yaw_deg;
    std::cout << "PLease enter x, y,  yaw_deg(deg):" << std::endl;
    std::cin >> x >> y >> yaw_deg;

    double v, w_deg, dt;
    std::cout << "Please enter v(m/s), w_deg(deg/s), dt(s)" << std::endl;
    std::cin >> v >> w_deg >> dt;

    if (dt <= 0){
        std::cout << "Error: dt must be positive. \n";
        return EXIT_FAILURE;
    }

    double yaw_rad = nav::deg2rad(yaw_deg);
    double w_rad = nav::deg2rad(w_deg);
    nav::Pose2D p = nav::Pose2D {x, y, yaw_rad};


    nav::Pose2D q = nav::integrate_body_twist(p, v, w_rad, dt);
    double x2 = q.x;
    double y2 = q.y;
    double yaw2_rad = q.yaw_rad;
    double yaw2_deg = nav::rad2deg(yaw2_rad);

    std::cout << "Result after " << dt << "s dead-reckoning step:\n";
    std::cout << "x2 = " << x2 << std::endl;
    std::cout << "y2 = " << y2 << std::endl;
    std::cout << "yaw2_deg = " << yaw2_deg << std::endl;

    return 0;
}