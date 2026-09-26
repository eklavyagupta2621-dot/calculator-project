#include <stdio.h>
#include <math.h>
#include "trig.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float trigonometry(int degrees) {
    float radians = degrees * (M_PI / 180.0);
    int choice;

    printf("1. Sine\n2. Cosine\n3. Tangent\nEnter your operation to perform: ");
    scanf("%d", &choice);

    if (choice == 1) {
        return sinf(radians);
    }
    else if (choice == 2) {
        return cosf(radians);
    }
    else if (choice == 3) {
        return tanf(radians);
    }
    else {
        printf("Invalid input\n");
        return 0.0f;
    }
}