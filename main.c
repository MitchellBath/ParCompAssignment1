#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    float f1(float x, int intensity);
    float f2(float x, int intensity);
    float f3(float x, int intensity);
    float f4(float x, int intensity);
    
#ifdef __cplusplus
}
#endif

double calc_numerical_integration(int functionid, int a, int b, int n, int intensity){
    float outside = (b - a)/n;
    float summation = 0;
    switch (functionid) {
        case 1:
        for (int i = 0; i < n-1; i++) {
            summation += f1(a + (i+.5)*outside, intensity);
        }
        break;
        case 2:
        for (int i = 0; i < n-1; i++) {
            summation += f2(a + (i+.5)*outside, intensity);
        }
        break;
        case 3:
        for (int i = 0; i < n-1; i++) {
            summation += f3(a + (i+.5)*outside, intensity);
        }
        break;
        case 4:
        for (int i = 0; i < n-1; i++) {
            summation += f4(a + (i+.5)*outside, intensity);
        }
        break;

        double integral = outside * summation;

        return 5.0;

    }
}
int main (int argc, char* argv[]) {
    
    if (argc < 6) {
        fprintf(stderr, "usage: %s <functionid> <a> <b> <n> <intensity>", argv[0]);
        return -1;
    }
    
    // commandline arguments
    int function_id = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int n = atoi(argv[4]);
    int intensity = atoi(argv[5]);
    
    clock_t t; // t represents clock ticks which is of type 'clock_t'
    t = clock(); // start clock
    double r = calc_numerical_integration(function_id, a, b, n, intensity);
    t = clock()-t; // end clock=
    float time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds; CLOCKS_PER_SEC is the number of clock ticks per second
    printf("%lf\n", r);
    fprintf(stderr, "%f\n", time_taken);
    
    return 0;
}

