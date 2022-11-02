#include "cmplx.h"
#include <math.h>

//((ac + bd) / (c2 + d2)) + ((bc - ad) / (c2 + d2))i
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = (a[0] * b[0] + a[1] * b[1]) / (pow(b[0], 2) + pow(b[1], 2));
    c[1] = (a[1] * b[0] - a[0] * b[1]) / (pow(b[0], 2) + pow(b[1], 2)); 
}
// cnum1.real * cnum2.real - cnum1.imaginary * cnum2.imaginary;
//     mul.imaginary = cnum1.real * cnum2.imaginary + cnum2.real * cnum1.imaginary;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = a[0] * b[0] - a[1] * b[1];
    c[1] = a[0] * b[1] - a[1] * b[0];
}

double cmplx_mag(cmplx_t a) {
    return sqrt(pow(a[0], 2) + pow(a[1], 2));
}

double cmplx_phs(cmplx_t a) {
    return atan(a[1] / a[0]);
}
// returns real part of mag/_phs
double cmplx_real(double mag, double phs) {
    return sqrt(pow(mag, 2) / (pow(tan(phs), 2) + 1));
}

// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs){
    return 0;
}
// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N){
    double sumReal;
    double sumImag;
    double angle;
    float real;
    float imag;




    for (int k = 0; k < N; k++) {
        sumReal = 0;
        sumImag = 0;
        for (int n = 0; n < N; n++) {
            real = *input[2*n];
            imag = *input[2*n + 1];
            angle = 2 * 3.1415 * n * k / N;

            sumReal +=  real * cos(angle) + imag * sin(angle);
            sumImag += -real * sin(angle) + imag * cos(angle);
        }

        *output[2*k] = sumReal;
        *output[2*k + 1] = sumImag;
    }
}

// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N){
    cmplx_dft(input, output, N);

    for (int n = 0; n < N; n++) {
        *output[2*n + 1] = *output[2*n + 1] * (1 / (float) N);
        *output[2*n + 1] = -*output[2*n + 1] * (1 / (float) N);
    }
}