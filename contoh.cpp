#include <iostream>
#include <KinematikaRobot/KinematikaBalik.h>
#include <KinematikaRobot/KinematikaMaju.h>

int main() {

    KinematikaBalik kinematikaBalik(3, 0.05, 0.2);
    KinematikaMaju kinematikaMaju(3, 0.05, 0.2);

    // 30 derajat = 0.523599 radian
    std::cout << kinematikaBalik.hitungKecepatanMotor(0.0, 0.8, 0.0, 0.523599) << std::endl;
    std::cout << kinematikaMaju.hitungOdometryRobot(10.0, -10.0, 0.0, 0.523599) << std::endl;

}