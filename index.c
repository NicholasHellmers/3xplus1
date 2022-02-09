#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp_o;
    FILE *fp_ll;

    fp_o = fopen("./data/output.csv", "a");
    fp_ll = fopen("./data/largestLoops.csv", "a");
    fprintf(fp_ll,"n,loops\n");
    fprintf(fp_o,"n,loops\n");

    unsigned int y = 0; // cycle tracker
    unsigned int y_max = 0; // current max cycles
    unsigned int z; // current sum tracker
    for (unsigned int i = 2; i < 100000000; i++) {
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
            printf("New max: %d\n", i);
        }
        fprintf(fp_o,"%d,%d\n", i, y);
    }
    
    fclose(fp_o);
    fclose(fp_ll);

    return 0;

}