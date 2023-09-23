#include <stdio.h>
#include <math.h>

sineOfX(float x, float e, float dx, float x1, float x2);

main()
{
    float x1, x2, dx, e;

    char x1_[10];
    char x2_[10];
    char dx_[10];
    char e_[20];

    float x = 0.0;

    int n;

    printf("x1: ");
    fgets(x1_, sizeof(x1_), stdin);
    x1 = atof(x1_);

    printf("x2: ");
    fgets(x2_, sizeof(x2_), stdin);
    x2 = atof(x2_);


    printf("dx: ");
    fgets(dx_, sizeof(dx_), stdin);
    dx= atof(dx_);

    printf("Epsilon: ");
    fgets(e_, sizeof(e_), stdin);
    e= atof(e_);

    x2 = (x2> x1) ? (x2 + dx): (x2 -dx); // CORRECTOR. USED TO PRINT OUT ALL OF THE VALUES


    if (dx <= 0){
        printf("Dx must be greater than zero. Restart the program and try again. \n");
        getchar();
        exit(-1);
    }
    else if(e<=0){
        printf("Epsilon must be greater than zero. Restart the program and try again. \n");
        getchar();
        exit(-1);
    }



    printf("\n  ---x---    ---sin(x)---     ---sin(Taylor)---    ---sin(x) - sin(Taylor)---\n");
    sineOfX(x,  e,  dx,  x1,  x2);



    getchar();
    return 0;


}
sineOfX(float x, float e, float dx, float x1, float x2){
    float beta, sinx; //sinx is a result variable, which will be later. Hence it must be set to zero.
    int n;
    if (x1 < x2){
        while ((x1+ dx/2) <= x2){ //Case where x2 is greater than x1. dx/2 IS ALSO A CORRECTOR
        beta = 1.0;
        n = 1;
        x = x1;

        x = x*M_PI/180.0;
        sinx = x;

        while (fabs(beta) >= e){

            beta = beta*(-x*x)/((n+1)*(n+2));
            sinx += beta;
            n += 2;
        }

        printf(" %.6f      %.6f          %.6f                %.6f   \n", x1, sin(x), sinx, sin(x) - sinx);

        x1 += dx; //Increasing x1 to eventually leave the loop

        }
    }
    else{
        while ((x1-dx/2) >= x2){ ////Case where x1 is greater than x2. dx/2 IS ALSO A CORRECTOR
        beta = 1.0;
        n = 1;
        x = x1;

        x = x*M_PI/180.0;
        sinx = x;

        while (fabs(beta) >= e){

            beta = beta*(-x*x)/((n+1)*(n+2));
            sinx += beta;
            n += 2;
        }

        printf(" %.6f      %.6f          %.6f                %.6f   \n", x1, sin(x), sinx, sin(x) - sinx);

        x1 -= dx; //Decreasing x1 to eventually leave th loop

        }
    }

}
