#include <iostream>
#include <cmath>
using namespace std;

double deg2rad(double deg){
    return deg * M_PI / 180;
}

double normalizeYaw(double yaw_deg){
    while (yaw_deg > 180.0)
        yaw_deg -= 360.0;
    while (yaw_deg <= -180.0)
        yaw_deg += 360.0;
    return yaw_deg;
}



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


    double x2, y2, yaw2_deg;
    yaw2_deg = yaw_deg + w_deg * dt;
    x2 = x + v * dt * cos(yaw_rad);
    y2 = y + v * dt * sin(yaw_rad);

    yaw2_deg = normalizeYaw(yaw2_deg);


    cout << "Result after one dead-reckoning step:\n";
    cout << "x2 = " << x2 << endl;
    cout << "y2 = " << y2 << endl;
    cout << "yaw2_deg = " << yaw2_deg << endl;

    return 0;
}

