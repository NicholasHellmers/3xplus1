#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp_o;
    FILE *fp_ll;
    // FILE *fp_r;

    fp_o = fopen("./data/output.csv", "w");
    fp_ll = fopen("./data/largestLoops.csv", "a");
    // fp_r = fopen("./data/lastComputuation.csv", "r+");
    // char LC[150];


    unsigned int y = 0; // cycle tracker
    unsigned int y_max = 0; // current max cycles
    unsigned int z; // current sum tracker
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    for (unsigned int i = 2; i < 300000000; i++) {
        y = 0;
        z = i;
        while(z != 1) {
            y++;
            if (!(z%2)) {
                z = z/2;
            } else {
                z = (3*z) + 1;
            }
        }
        if (y > y_max) {
            y_max = y;
            fprintf(fp_ll,"%d,%d\n", i, y);
            printf("New max: %d,%d\n", i, y);
        }
        //fprintf(fp_o,"%d,%d\n", i, y); // This is in case it is desired to record all output data
    }
    float endTime = (float)clock()/CLOCKS_PER_SEC;
    float timeElapsed = endTime - startTime;
    printf("%f\n",timeElapsed);
    fclose(fp_o);
    fclose(fp_ll);
    // fclose(fp_r);

    return 0;

}