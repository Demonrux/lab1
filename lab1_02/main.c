#include <stdio.h>
#include <math.h>
#define EPS 0.000001
#define CORRECT_INPUT_COORDINATES 2

typedef enum{
    CORRECT_INPUT,
    INCORRECT_INPUT,
}StatusInput;

typedef enum{
    LINE_1,
    LINE_2,
    LINE_3,
    LINE_1_AND_2,
    LINE_1_AND_3,
    LINE_2_AND_3,
    REGION_1,
    REGION_2,
    REGION_3,
    REGION_4,
    REGION_5,
    REGION_6,
    REGION_7,
}PointLocation;


double functionOne(double x);
double functionTwo(double x);
double functionThree(double x);
StatusInput inputCoordinates(double* x, double* y);
PointLocation getPointLocation(double x, double y);
void locationOutput(PointLocation logic);

int main(){
    double x = 0;
    double y = 0;
    StatusInput statusInput = inputCoordinates(&x, &y);
    if (statusInput == INCORRECT_INPUT){
    }
    else {
        PointLocation logic = getPointLocation(x, y);
        locationOutput(logic);
    }
    return statusInput;
}

double functionOne(double x) {
    return 2 * x + 2 ;
}
double functionTwo(double x){
    return 0.5 * x - 1;
}
double functionThree(double x){
    return - x + 2;
}
StatusInput inputCoordinates(double* x, double* y){
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

PointLocation getPointLocation(double x, double y) {
    PointLocation logic = REGION_7;
    double lineOne = functionOne(x);
    double lineTwo = functionTwo(x);
    double lineThree = functionThree(x);
    double deltaLineOne = fabs(y - lineOne);
    double deltaLineTwo = fabs(y - functionTwo(x));
    double deltaLineThree = fabs(y - functionThree(x));

    if ((deltaLineOne <= EPS) && (deltaLineTwo <= EPS)) {
        logic = LINE_1_AND_2;
    }
    else if ((deltaLineOne <= EPS) && (deltaLineThree <= EPS)) {
        logic = LINE_1_AND_3;
    }
    else if ((deltaLineTwo <= EPS) && (deltaLineThree <= EPS)) {
        logic = LINE_2_AND_3;
    }
    else if (((deltaLineOne <= EPS) && !(deltaLineTwo <= EPS)) && !(deltaLineThree <= EPS)) {
        logic = LINE_1;
    }
    else if (((deltaLineTwo <= EPS) && !(deltaLineOne <= EPS)) && !(deltaLineThree <= EPS)) {
        logic = LINE_2;
    }
    else if (((deltaLineThree <= EPS) && !(deltaLineTwo <= EPS)) && !(deltaLineOne <= EPS)) {
        logic = LINE_3;
    }
    else if ((y < lineOne) && (y > lineTwo) && (y > lineThree)) {
        logic = REGION_1;
    }
    else if ((y > lineThree) && (y < lineTwo) && (y < lineOne)) {
        logic = REGION_2;
    }
    else if ((y < lineThree) && (y < lineTwo) && (y < lineOne)) {
        logic = REGION_3;
    }
    else if ((y > lineOne) && (y < lineTwo) && (y < lineThree)) {
        logic = REGION_4;
    }
    else if ((y < lineThree) && (y > lineTwo) && (y > lineOne)) {
        logic = REGION_5;
    }

    else if ((y > lineThree) && (y > lineTwo) && (y > lineOne)) {
        logic = REGION_6;
    }
    else if ((y < lineThree) && (y < lineTwo) && (y > lineOne)) {
        logic = REGION_7;
    }
    return logic;
}

void locationOutput(PointLocation logic) {
    switch(logic){
    case LINE_1: {
        printf("Point placed on line 1");
        break; }
    case LINE_2: {
        printf("Point placed on line 2");
        break;}
    case LINE_3: {
        printf("Point placed on line 3");
        break; }
    case LINE_1_AND_2: {
        printf("Point placed on lines 1 and 2");
        break; }
    case LINE_1_AND_3: {
        printf("Point placed on lines 1 and 3");
        break; }
    case LINE_2_AND_3: {
        printf("Point placed on lines 2 and 3");
        break; }
    case REGION_1: {
        printf("Point placed in region 1");
        break; }
    case REGION_2: {
        printf("Point placed in region 2");
        break; }
    case REGION_3: {
        printf("Point placed in region 3");
        break; }
    case REGION_4: {
        printf("Point placed in region 4");
        break; }
    case REGION_5: {
        printf("Point placed in region 5");
        break; }
    case REGION_6: {
        printf("Point placed in region 6");
        break; }
    case REGION_7: {
        printf("Point placed in region 7");
        break; }
    }
}
