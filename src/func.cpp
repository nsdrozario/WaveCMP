#include <wavecmp.hpp>

void wavecmp::func::set_resolution(int res) {

    x_step = 1.0d / (double) res;

}

double wavecmp::func::calculate(double x, double val) {

    double calculation = amplitude * sin((TAU/period)*(x - phase)) + mean;
    return (calculation > val) ? calculation : val; // didn't want to use max() because i would have to import another header for it

}

double wavecmp::func::integrate(double start, double end, double val) {

    double integral = 0.0d;

    for (double a = 0, b = x_step; b < end; a+=x_step, b+=x_step) {
        double point1 = calculate(a, val);
        double point2 = calculate(b, val);
        integral += ((point1 + point2)/2.0d) * x_step;
    }

    return integral;

}

double wavecmp::func::compare_wave(double start, double end, bool greater, double val) { 

    /* 
        bool greater determines if we are measuring 
        if the wave goes above the value we want to compare if true and vice versa
    */

    double int_osc = integrate(phase, phase+(period/2.0d), val); // integral of one oscillation
    double int_func = integrate(start, end, val); // integral of the function across the given interval

    return (greater) ? (int_func/int_osc)*(period/2) : ((end-start)-(int_func/int_osc)*(period/2)); 

}

wavecmp::func::func(double a, double b, double c, double d) : amplitude(a), period(b), phase(c), mean(d) {}

wavecmp::func::func(double a, double b, double c, double d, double r) : amplitude(a), period(b), phase(c), mean(d) {

    set_resolution(r);

}