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
    double outside, summation;
    outside = ((float)b - (float)a)/(float)n;
    summation = 0;
    float (*f)(float, int);

    if (functionid == 1) {
        f = f1;
    }
    else if (functionid == 2) {
        f = f2;
    }
    else if (functionid == 3) {
        f = f3;
    }
    else if (functionid == 4) {
        f = f4;
    } else {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        summation += f(a + (i+.5)*(((float)b-(float)a)/(float)n), intensity);
    }

    return outside * summation;

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
    //printf("funcid:%i, a:%i, b:%i, n:%i, int:%i", function_id, a, b, n, intensity); 10 intensity?
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

