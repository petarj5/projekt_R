#include "cmplx.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    cmplx_t a;
    a[0] = 3;
    a[1] = 4;

    cmplx_t b;
    b[0] = 1;
    b[1] = 2;

    cmplx_t c;

    cmplx_div(a, b, c);
    printf("%f %f\n", c[0], c[1]);
    
    printf("%f\n", cmplx_mag(a));
    
    return 0;
}
