#ifndef KINEMATIKA_BALIK_H
#define KINEMATIKA_BALIK_H

#include <Eigen/Dense>
#include <math.h>

class KinematikaBalik {
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
        KinematikaBalik(int jumlahRoda, double jariJariRoda, double jarakRodaKePusat);
        Eigen::Vector3d hitungKecepatanMotor(double xdot, double ydot, double tdot, double theta);
};

#endif