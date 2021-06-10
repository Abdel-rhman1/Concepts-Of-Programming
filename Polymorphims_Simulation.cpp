#include <iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;
struct vtable;  // taht struct contains all operations
struct Shape{
    vtable *vtab; // the base struct

};
struct vtable{
    double (*Get)(Shape *s); // implement Shape Opertaions
};
double GetArea(Shape *s){
   return  s->vtab->Get(s); // implement Operations
}


struct Circle { // Circle Struct
    Shape shape;
    double raduis; // Circle Raduis
};

double Getarea(Circle *cir){        // Implemt Circle GetArea
    double x = cir->raduis;
    return M_PI*(x*x); //pi*(raduis)^2
}
vtable circle_vtable =
{
    (double (*)(Shape*)) Getarea,
};
void CircleInitialize(Circle *cir  , double R){ // circle Constructor
    cir->raduis = R;
    cir->shape.vtab = &circle_vtable;
}
struct Rectangle{ // rectangle Struct
    Shape shape;
    double width , height;
};

double GetArea2(Rectangle *rec){ // Rectangle Area
    double w = rec->width;
    double h = rec->height;
    return w*h; // Width * height
}
vtable rect_vtable=
{
    (double(*)(Shape*)) GetArea2,
};
void RectangleInitialize(Rectangle *rec  , double W , double H ){ // Rectangle struct
    rec->width = W;
    rec->height = H;
    //cir->shape->vtab = &circle_vtable;
    rec->shape.vtab = &rect_vtable;
}
struct Triangle{ // Traingle struct
    Shape shape;
    double width , height , base;
};

double GetArea3(Triangle *trian){
    double w = trian->width;
    double h = trian->height;
    double b = trian->base;
    double s =  (b + w + h)/2; //s
    return sqrt (s*fabs((double)s-w)*fabs((double)s-h)*fabs((double)s-b)); // triangle Area equation
}
vtable trian_vtable=
{
    (double(*)(Shape*)) GetArea3,
};
void TriangleInitialize(Triangle * trian  , double W , double H , double B){ // Triangle Constructor
    trian->width = W;
    trian->height = H;
    trian->base = B;
    trian->shape.vtab = &trian_vtable;
}
int main()
{
    Circle circle;
    CircleInitialize(&circle, 10); // circle with radius 10
    Rectangle rect;
    RectangleInitialize(&rect, 3, 5); //
    Triangle triang;
    TriangleInitialize(&triang, 7, 4, 12);
    Shape* shapes[3];
    shapes[0]=(Shape*)&circle;
    shapes[1]=(Shape*)&rect;
    shapes[2]=(Shape*)&triang;
    double total_area=0;
    int i;
    for(i=0;i<3;i++)
    {
        double d=GetArea(shapes[i]);  // shape[i].GreateArea();
        total_area+=d;
        cout<<d<<endl;
    }
    cout<<total_area<<endl;
    return 0;
}
