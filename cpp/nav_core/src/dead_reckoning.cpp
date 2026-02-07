#include<iostream>
#include<nav/pose2d.hpp>
using namespace std;


int main(){
    double x, y, yaw_deg;
    cout << "PLease enter x, y,  yaw_deg(deg):" << endl;
    cin >> x >> y >> yaw_deg;

    double v, w_deg, dt;
    cout << "Please enter v(m/s), w_deg(deg/s), dt(s)" << endl;
    cin >> v >> w_deg >> dt;

    if (dt <= 0){
        cout << "Error: dt must be positive. \n";
        return EXIT_FAILURE;
    }

    double yaw_rad = deg2rad(yaw_deg);
    double w_rad = deg2rad(w_deg);
    Pose2D p = Pose2D {x, y, yaw_rad};


    Pose2D q = integrate_body_twist(p, v, w_rad, dt);
    double x2 = q.x;
    double y2 = q.y;
    double yaw2_rad = q.yaw_rad;
    double yaw2_deg = rad2deg(yaw2_rad);

    cout << "Result after " << dt << "s dead-reckoning step:\n";
    cout << "x2 = " << x2 << endl;
    cout << "y2 = " << y2 << endl;
    cout << "yaw2_deg = " << yaw2_deg << endl;

    return 0;
}