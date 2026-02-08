#include<iostream>
#include <cmath>
#include <cassert>
#include<nav/pose2d.hpp>
using namespace std;

bool near(double a, double b, double eps=1e-9){return fabs(a - b) < eps;}


int main(){
    assert(near(deg2rad(180), M_PI));
    assert(near(normalize_angle_rad(M_PI + 0.1), - M_PI + 0.1)
);

    Pose2D p = {2.0, 0.0, 0.0};
    Pose2D q = integrate_body_twist(p, 1.0, 0.0, 2.0);
    assert(near(q.x, 4.0) && near(q.y, 0.0) && near(q.yaw_rad, 0.0));

    Pose2D q2 = integrate_body_twist(p, 0, deg2rad(90), 2);
    assert(near(q2.x, 2.0) && near(q2.y, 0.0) && near(q2.yaw_rad, M_PI));
    cout << "All tests passed" << endl;
    return 0;
}


