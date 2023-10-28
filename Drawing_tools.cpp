#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "Basic_structures.cpp"
using namespace std;

class Draw{
    private:
        int WIDTH;
        int HEIGHT;
        double SCREENDIST;
        sf::RenderWindow *window;
        void draw2D(double x1, double y1, double x2, double y2);
        void drawLine3D(Line l);
    public:
        Draw(int width, int height, double screendist, sf::RenderWindow &win);
        void drawLines(vector<Line> &LineMaker);
};
Draw :: Draw(int width, int height, double screendist, sf::RenderWindow &win){
    WIDTH = width;
    HEIGHT = height;
    SCREENDIST = screendist;
    window = &win;
}
void Draw :: drawLines(vector<Line> &LineVec){
    for(int i = 0; i < LineVec.size(); i++){
        LineVec[i].update();//Updated here
        cout << LineVec[i].getP1().getZ() << endl;//Here is the problem. For some reason, the line is not updated here.
        drawLine3D(LineVec[i]);
    }
}
void Draw :: drawLine3D(Line l){
    Point p1 = l.getP1();
    Point p2 = l.getP2();
    if(p1.getZ() < SCREENDIST || p2.getZ() < SCREENDIST){
        return;
        //TODO: draw partial line if one is infront of screen and the other is behind the screen
    }
    else{
        draw2D(p1.getX() * SCREENDIST / p1.getZ(), 
             p1.getY() * SCREENDIST / p1.getZ(),
             p2.getX() * SCREENDIST / p2.getZ(),
             p2.getY() * SCREENDIST / p2.getZ());
    }
}
void Draw :: draw2D(double x1, double y1, double x2, double y2){
    //Notice that the coordinate system in sfml has 0,0 at the top left corner.
    //However I want 0,0 to be at the centre of the screen
    //Therefore I will apply one final trivial transformation on the Points so that they match sfmls coordinate system
    //The transformation is (coordX + WIDTH / 2, coordY + HEIGHT / 2)
    x1 += WIDTH / 2;
    x2 += WIDTH / 2;
    y1 += HEIGHT / 2;
    y2 += HEIGHT / 2;
    //cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
    //Now finally, this function does the actual drawing
    sf :: Vertex line[] =
    {
        sf :: Vertex(sf :: Vector2f(x1,y1)),
        sf :: Vertex(sf :: Vector2f(x2,y2))
    
    };
    (*window).draw(line,2,sf :: Lines);
    //cout << "Drawn here" << endl;
}
