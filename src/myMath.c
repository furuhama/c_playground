#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14

int main() {
    int a, b;
    // initialize random number
    srand((unsigned) time(NULL));
    // generate random number from 1 to 10
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    // print results
    printf("%d + %d = %d\n", a, b, a + b);

    int angle;
    double rad;
    printf("please input the angle(0~360): ");
    scanf("%d", &angle);
    // convert angle to radian
    rad = PI * (double)angle / 180.0;
    // Trigonometric function
    printf("sin(%d)=%f\n", angle, sin(rad));
    printf("cos(%d)=%f\n", angle, cos(rad));
    printf("tan(%d)=%f\n", angle, tan(rad));
}
