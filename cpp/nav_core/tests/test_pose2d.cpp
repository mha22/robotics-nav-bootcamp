#include<iostream>
#include <cmath>
#include <cassert>
#include<nav/pose2d.hpp>
using namespace std;



int main(){
    assert(deg2rad(180) == M_PI);
    assert(normalize_angle_rad(M_PI + 0.1) == - M_PI + 0.1);

    Pose2D p = {2.0, 0.0, 0.0};
    Pose2D q = integrate_body_twist(p, 1.0, 0.0, 2.0);
    assert(q.x == 4 && q.y == 0 && q.yaw_rad == 0);

    Pose2D q2 = integrate_body_twist(p, 0, deg2rad(90), 2);
    assert(q2.x == 2.0 && q2.y == 0 && q2.yaw_rad == M_PI);
    cout << "All tests passed" << endl;
    return 0;
}