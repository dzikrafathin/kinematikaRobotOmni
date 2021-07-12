#include <KinematikaRobot/KinematikaBalik.h>

KinematikaBalik::KinematikaBalik(
    int jumlahRoda, 
    double jariJariRoda, 
    double jarakRodaKePusat) {

        this->jumlahRoda = jumlahRoda;
        this->jariJariRoda = (1.0/jariJariRoda);
        this->jarakRodaKePusat = jarakRodaKePusat;

        double sudut = (2 * M_PI) / this->jumlahRoda;

        alphaRoda = Eigen::VectorXd(this->jumlahRoda);

        for (int i=0;i<this->jumlahRoda;i++) {
            if (i==0) {
                this->alphaRoda(i) = 0.0;
            } else {
                this->alphaRoda(i) = sudut;
                sudut = sudut + sudut;
            }
        }

}

Eigen::Vector3d KinematikaBalik::hitungKecepatanMotor(
    double xdot, double ydot, double tdot, double theta) {

    if (jumlahRoda == 3) {

        mat1 <<
            (-1.0 * sin(theta+alphaRoda(0))), cos(theta+alphaRoda(0)), jarakRodaKePusat,
            (-1.0 * sin(theta+alphaRoda(1))), cos(theta+alphaRoda(1)), jarakRodaKePusat,
            (-1.0 * sin(theta+alphaRoda(2))), cos(theta+alphaRoda(2)), jarakRodaKePusat;

        mat2 <<
            cos(theta), 0.0, 0.0,
            0.0, cos(theta), 0.0,
            0.0, 0.0, 1.0;

        mat1x2 = jariJariRoda*mat1*mat2;

        input_dot << xdot, ydot, tdot;

        hasil_dot = mat1x2 * input_dot;

    } else if (jumlahRoda == 4) {
        
    }

    return hasil_dot;

}