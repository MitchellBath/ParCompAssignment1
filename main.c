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
    double outside;
    double summation;
    outside = (b - a)/n;
    //printf("outside: %lf\n", outside);// prints 0.0
    summation = 0;
    /*
    switch (functionid) {
        case 1:
            for (int i = 0; i < n; i++) {
                summation += f1(a + (i+.5)*outside, intensity);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                summation += f2(a + (i+.5)*outside, intensity);
            }
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                summation += f3(a + (i+.5)*outside, intensity);
            }
            break;
        case 4:
            for (int i = 0; i < n; i++) {
                summation += f4(a + (i+.5)*outside, intensity);
            }
            break;
    }
    */

    if (functionid == 1) {
        for (int i = 0; i < n; i++) {
                summation += f1(a + (i+.5)*((b-a)/n), intensity);
        }
    }
    if (functionid == 2) {
        for (int i = 0; i < n; i++) {
                summation += f2(a + (i+.5)*((b-a)/n), intensity);
        }
    }
    if (functionid == 3) {
        for (int i = 0; i < n; i++) {
                summation += f3(a + (i+.5)*((b-a)/n), intensity);
        }
    }
    if (functionid == 4) {
        for (int i = 0; i < n; i++) {
                summation += f4(a + (i+.5)*((b-a)/n), intensity);
        }
    }
        double integral;
        //printf("outside: %lf\n", outside); prints 0.0
        integral = outside * summation;
        //printf("calc: %lf\n", integral); prints 0.0
        return integral;

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
    printf("funcid:%i, a:%i, b:%i, n:%i, int:%i", function_id, a, b, n, intensity);
    //
    
    clock_t t; // t represents clock ticks which is of type 'clock_t'
    t = clock(); // start clock
    double r = calc_numerical_integration(function_id, a, b, n, intensity);
    t = clock()-t; // end clock=
    float time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds; CLOCKS_PER_SEC is the number of clock ticks per second
    printf("%lf\n", r);
    fprintf(stderr, "%f\n", time_taken);
    
    return 0;
}

