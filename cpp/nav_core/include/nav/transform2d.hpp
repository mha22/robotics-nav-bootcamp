#pragma once
#include "nav/pose2d.hpp"

namespace nav {

struct Vec2 {
    double x, y;
};

struct Transform2D {
    double x, y, yaw_rad;
};

Vec2 apply(const Transform2D& T, const Vec2& p);  // p' = T_map_base * p
Transform2D compose(const Transform2D& A,
                    const Transform2D& B);  // T_map_base,T_base_laser  --->  T_map_laser
Transform2D inverse(const Transform2D& T);
Transform2D from_pose(const Pose2D& P);  // Convert pose representation to transform representation
                                         // (same SE(2) element)
Pose2D to_pose(
    const Transform2D& T);  // Convert transform representation back to pose representation

}  // namespace nav
