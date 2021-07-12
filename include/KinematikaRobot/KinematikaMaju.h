#ifndef KINEMATIKA_MAJU_H
#define KINEMATIKA_MAJU_H

#include <Eigen/Dense>
#include <math.h>

class KinematikaMaju {
    private:
        int jumlahRoda;
        double jariJariRoda;
        double jarakRodaKePusat;

        Eigen::VectorXd alphaRoda;
        Eigen::Matrix3d mat1;
        Eigen::Matrix3d mat2;
        Eigen::Matrix3d mat1x2;

        Eigen::Vector3d input_dot;
        Eigen::Vector3d hasil_dot;

    public:
        KinematikaMaju(int jumlahRoda, double jariJariRoda, double jarakRodaKePusat);
        Eigen::Vector3d hitungOdometryRobot(double radM1, double radM2, double radM3, double theta);
};

#endif