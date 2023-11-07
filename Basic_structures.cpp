#include <bits/stdc++.h>
using namespace std;

class Point{
    private:
        double x;
        double y;
        double z;
    public:
        Point();
        Point(double X, double Y, double Z);

        double getX();
        double getY();
        double getZ();

        void changeX(double Xnew);
        void changeZ(double Znew);
};
Point :: Point(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
}
Point :: Point(double X, double Y, double Z){
    x = X;
    y = Y;
    z = Z;
}
double Point :: getX(){
    return x;
}
double Point :: getY(){
    return y;
}
double Point :: getZ(){
    return z;
}
void Point :: changeX(double Xnew){
    x = Xnew;
}
void Point :: changeZ(double Znew){
    z = Znew;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////


class Cartesian{
    private:
        Point origin;
        double alpha;
        double beta;
        double transformation[3][3];
        void updateTransformation();
        void moveX(double step);
        void moveZ(double step);
    public:
        Cartesian();
        Point applyTransformation(Point &p);
        void turnX(double dalpha);
        void turnY(double dbeta);
        void moveFront(double dist);
};
Cartesian :: Cartesian(){
    origin = Point(0.0,0.0,0.0);
    alpha = 0.0;//angle between x and x'
    beta = 0.0;//angle between y and y'
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j){
                transformation[i][j] = 1.0;
            }
            else{
                transformation[i][j] = 0.0;
            }
        }
    }
}
void Cartesian :: updateTransformation(){
    transformation[0][0] = cos(alpha);
    transformation[0][1] = 0;
    transformation[0][2] = sin(alpha);
    
    transformation[1][0] = -sin(alpha)*sin(beta);
    transformation[1][1] = cos(beta);
    transformation[1][2] = sin(beta)*cos(alpha);

    transformation[2][0] = -sin(alpha)*cos(beta);
    transformation[2][1] = -sin(beta);
    transformation[2][2] = cos(alpha)*cos(beta);
}
void Cartesian :: moveX(double step){
    origin.changeX(origin.getX() + step);
}
void Cartesian :: moveZ(double step){
    origin.changeZ(origin.getZ() + step);
}
void Cartesian :: moveFront(double dist){
    double xstep = -sin(alpha) * dist;
    double zstep = cos(alpha) * dist;
    cout << "Moving here" << endl;
    moveX(xstep);
    moveZ(zstep);
}
void Cartesian :: turnX(double dalpha){
    alpha += dalpha;
    updateTransformation();
}
void Cartesian :: turnY(double dbeta){
    beta += dbeta;
    if(beta > M_PI_2 || beta < -M_PI_2){//M_PI_2 = pi/2
        beta -= dbeta;
    }
    updateTransformation();
}
Point Cartesian :: applyTransformation(Point &p){
    //linear translation
    double xcoord = p.getX() - origin.getX();
    double ycoord = p.getY() - origin.getY();
    double zcoord = p.getZ() - origin.getZ();
    
    //the transformation
    double xfinal = transformation[0][0]*xcoord + transformation[0][1]*ycoord + transformation[0][2]*zcoord;
    double yfinal = transformation[1][0]*xcoord + transformation[1][1]*ycoord + transformation[1][2]*zcoord;
    double zfinal = transformation[2][0]*xcoord + transformation[2][1]*ycoord + transformation[2][2]*zcoord;

    return Point(xfinal, yfinal, zfinal);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////


class Line{
    private:
        const double SCREENDIST = 10.0;
        Cartesian* POV;
        Point p1,p2;
    public:
        Line(Cartesian &pov, double x1, double y1, double z1, double x2, double y2, double z2);
        Point get_Rel_P1();
        Point get_Rel_P2();
        Point getP1();
        Point getP2();
};
Point Line :: getP1(){
    return p1;
}
Point Line :: getP2(){
    return p2;
}
Point Line :: get_Rel_P1(){
    return (*POV).applyTransformation(p1);
}
Point Line :: get_Rel_P2(){
    return (*POV).applyTransformation(p2);
}
Line :: Line(Cartesian &pov, double x1, double y1, double z1, double x2, double y2, double z2){
    POV = &pov;
    p1 = Point(x1,y1,z1);
    p2 = Point(x2,y2,z2);
}
/*void Line :: update(){
    p1 = (*POV).applyTransformation(p1);
    p2 = (*POV).applyTransformation(p2);
}*/


//I think the uncanniness lies in using a plane. We need to use a sphere