#ifndef WAVECMP_HPP
#define WAVECMP_HPP
#define _USE_MATH_DEFINES

#include <cmath>

#define TAU 2.0d * M_PI

namespace wavecmp {

    /*
    double period_to_frequency(double p, double f); // will implement later

    double frequency_to_period(double f, double p);
    */

    class func {

        public:
            double phase = 0.0d;
            double amplitude = 1.0d;
            double mean = 0.0d;
            double period = TAU;
        
            void set_resolution(int res); // set amount of points per unit
            double compare_wave(double start, double end, bool greater, double val); // 

            func(double a, double b, double c, double d); // constructor
            func(double a, double b, double c, double d, double r);
        private:
            double x_step = 0.1d; // increment value
            double calculate(double x, double val); // x value and comparison value
            double integrate(double start, double end, double val); // trapezoidal rule

    };


}

#endif