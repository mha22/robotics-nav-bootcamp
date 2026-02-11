#include <cmath>
#include "nav/transform2d.hpp"

namespace nav {

Vec2 apply(const Transform2D& T, const Vec2& p){
    const double theta = normalize_angle_rad(T.yaw_rad);
    const double c = std::cos(theta);
    const double s = std::sin(theta);

    Vec2 q{};
    q.x = c * p.x - s * p.y + T.x;
    q.y = s * p.x + c * p.y + T.y;
    return q;
}


Transform2D compose(const Transform2D& A, const Transform2D& B){
    const double theta = normalize_angle_rad(A.yaw_rad);
    const double c = std::cos(theta);
    const double s = std::sin(theta);

    Transform2D C{};
    C.x = A.x + c * B.x - s * B.y;
    C.y = A.y + s * B.x + c * B.y;
    C.yaw_rad = normalize_angle_rad(theta + B.yaw_rad);
    return C;
}


Transform2D inverse(const Transform2D& T){
    const double theta = normalize_angle_rad(T.yaw_rad);
    const double c = std::cos(theta);
    const double s = std::sin(theta);

    Transform2D T_inv{};
    T_inv.x = -(c * T.x + s * T.y);
    T_inv.y = s * T.x - c * T.y;
    T_inv.yaw_rad = normalize_angle_rad(-theta);
    return T_inv;
}

}  // namespace nav