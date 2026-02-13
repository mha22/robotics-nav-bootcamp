#include <cmath>
#include <iomanip>
#include <iostream>

#include "nav/transform2d.hpp"

int main() {
    using nav::apply;
    using nav::Transform2D;
    using nav::Vec2;

    double tx, ty, yaw_deg;
    std::cout << "Please enter Transform T_ab(tx, ty, yaw_deg):\n";
    if (!(std::cin >> tx >> ty >> yaw_deg)) {
        std::cerr << "Invalid input for transform.\n";
        return 1;
    }

    Transform2D T_ab = {tx, ty, nav::deg2rad(yaw_deg)};

    double px, py;
    std::cout << "Please enter p_b(px, py):\n";
    if (!(std::cin >> px >> py)) {
        std::cerr << "Invalid input for p_b.\n";
        return 1;
    }
    Vec2 p_b = {px, py};

    Vec2 p_a = apply(T_ab, p_b);
    Transform2D T_ba = nav::inverse(T_ab);
    Vec2 p_b_recovered = apply(T_ba, p_a);

    const double dx = p_b_recovered.x - p_b.x;
    const double dy = p_b_recovered.y - p_b.y;
    const double err_norm = std::sqrt(dx * dx + dy * dy);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "p_a: " << p_a.x << " " << p_a.y << "\n";
    std::cout << "p_b_recovered: " << p_b_recovered.x << " " << p_b_recovered.y << "\n";
    std::cout << "error_norm: " << err_norm << "\n";
    return 0;
}
