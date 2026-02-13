#include <cassert>
#include <cmath>
#include <iostream>

#include "nav/transform2d.hpp"

namespace {
bool near(double a, double b, double eps = 1e-9) { return std::fabs(a - b) < eps; }
}  // namespace

int main() {
    using nav::apply;
    using nav::Transform2D;
    using nav::Vec2;

    Vec2 p = {1.0, 1.0};
    Transform2D T = {0.0, 0.0, 0.0};
    Vec2 q = apply(T, p);
    assert(near(p.x, q.x));
    assert(near(p.y, q.y));

    // Pure translation
    p = {3.0, 4.0};
    T = {1.0, 2.0, 0.0};
    q = apply(T, p);
    assert(near(q.x, 4.0));
    assert(near(q.y, 6.0));

    // Pure rotation
    p = {1.0, 0.0};
    T = {0.0, 0.0, nav::deg2rad(90.0)};
    q = apply(T, p);
    assert(near(q.x, 0.0));
    assert(near(q.y, 1.0));

    // Inverse correctness
    p = {1.0, 0.0};
    T = {1.0, 2.0, nav::deg2rad(90.0)};
    Transform2D T_inv = nav::inverse(T);
    Transform2D I = nav::compose(T, T_inv);
    assert(near(I.x, 0.0));
    assert(near(I.y, 0.0));
    assert(near(I.yaw_rad, 0.0));

    Vec2 p0 = {2.3, -4.7};
    Vec2 p1 = apply(T, p0);
    Vec2 p2 = apply(T_inv, p1);
    assert(near(p2.x, p0.x));
    assert(near(p2.y, p0.y));

    // Composition correctness
    Transform2D T_A = {2.0, 1.0, nav::deg2rad(90.0)};
    Transform2D T_B = {0.2, 0.0, 0};
    Vec2 q1 = apply(T_A, apply(T_B, p));
    Vec2 q2 = apply(nav::compose(T_A, T_B), p);
    assert(near(q1.x, q2.x));
    assert(near(q1.y, q2.y));

    std::cout << "All tests passed" << std::endl;
    return 0;
}