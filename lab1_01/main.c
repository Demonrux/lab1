#include <stdio.h>
#include <math.h>

#define EPS 0.000001
#define CORRECT_INPUT_COORDINATES 2

typedef enum{
    CORRECT_INPUT,
    INCORRECT_INPUT,
}StatusInput;

typedef enum{
    IN_LINE,
    ABOVE_LINE,
    UNDER_LINE,
}PointLocation;


double function(double x);
StatusInput inputCoordinates(double* x, double* y);
PointLocation location(double x, double y);
void locationOutput(PointLocation logic);

int main(){
    double x = 0;
    double y = 0;
    StatusInput statusInput = inputCoordinates(&x, &y);
    if (statusInput == INCORRECT_INPUT) {
    }
    else {
        PointLocation logic = location(x, y);
        locationOutput(logic);
    }
    return statusInput;
}

double function(double x) {
    return 0.5 * x + 1 ;
}
StatusInput inputCoordinates(double* x, double* y) {
    StatusInput statusInput;
    if (scanf("%lf %lf", x, y) == CORRECT_INPUT_COORDINATES) {
        statusInput = CORRECT_INPUT;
    }
    else {
        statusInput = INCORRECT_INPUT;
        printf("Incorrect input");
    }
    return statusInput;
}

PointLocation location(double x, double y) {
    PointLocation logic;
    if (fabs(y - function(x)) < EPS) {
        logic = IN_LINE;
    }
    else if (y > function(x)) {
        logic = ABOVE_LINE;
    }
    else {
        logic = UNDER_LINE;
    }
    return logic;
}

void locationOutput(PointLocation logic) {
    switch(logic){
    case IN_LINE: {
        printf("Point is on the line");
        break;}
    case ABOVE_LINE: {
        printf("Point is above the line");
        break;}
    case UNDER_LINE: {
        printf("Point is under the line");
        break;}
    }
}

