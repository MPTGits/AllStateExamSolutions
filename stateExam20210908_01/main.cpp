#include <iostream>
#include <math.h>

using namespace std;

enum RelativePosition {
    NO_COMMON_POINTS,
    TOUCHING,
    INTERSECTING,
    SAME
};

char *RelativeCirclesTypes[] =
{
    "NO_COMMON_POINTS",
    "TOUCHING",
    "INTERSECTING",
    "SAME"
};



struct Point{
    float x;
    float y;
    Point(int a, int b): x(a), y(b) {};
};

struct Circle{
    Point center;
    float r;

    Circle(Point c, float rad): center(c), r(rad){};
};

float e = 0.0001;

RelativePosition findrelativePosition(Circle c1, Circle c2){
    bool isSamePoint = fabs(c1.center.x-c2.center.x)<e && fabs(c1.center.y-c2.center.y)<e;
    if(isSamePoint && fabs(c1.r - c2.r) < e){
        return SAME;
    }
    float pointDistance = sqrt((c1.center.x-c2.center.x)*(c1.center.x-c2.center.x) + (c1.center.y-c2.center.y)*(c1.center.y-c2.center.y));

    if(pointDistance > c1.r + c2.r || (isSamePoint && fabs(c1.r - c2.r) > e)){
        return NO_COMMON_POINTS;
    }
    if(fabs((c1.r + c2.r) - pointDistance) < e || fabs(c1.r - (pointDistance+c2.r))< e || abs(c2.r - (pointDistance+c1.r))< e){
        return TOUCHING;
    }
    else {
        return INTERSECTING;
    }

}



int main()
{
    Circle c1(Point(2,2), 2.0);
    Circle c2(Point(2,2), 4.0);


    cout <<RelativeCirclesTypes[findrelativePosition(c1, c2)]<< endl;
    return 0;
}
