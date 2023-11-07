#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "Drawing_tools.cpp"
#include "Test_Shapes.cpp"
using namespace std;
vector<Line> LineMaker(Cartesian &POV){
    int choice = 1;
    vector<Line> ans;
    while(choice == 1){
        cout << "Enter point 1 in the form x y z" << endl;
        double x1,y1,z1;
        cin >> x1 >> y1 >> z1;
        
        cout << "Enter point 2 in the form x y z" << endl;
        double x2,y2,z2;
        cin >> x2 >> y2 >> z2;

        Line l = Line(POV, x1, y1, z1, x2, y2, z2);
        ans.push_back(l);
        cout << "Enter 1 to continue else enter any other integer" << endl;
        cin >> choice;
    }
    return ans;
}

int main(){
    Cartesian POV = Cartesian();
    //vector<Line> LineVec = LineMaker(POV);
    vector<Line> LineVec = Cube(POV,20,100);
    vector<Line> LineVec2 = Cube(POV,45,300);
    for(auto it: LineVec2){
        LineVec.push_back(it);
    }
    const int WIDTH = 80;
    const int HEIGHT = 60;
    const double SCREENDIST = 50.0;
    const double VELOCITY = 1;
    const double ANG_VELOCITY = 0.01; 
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
    window.setSize(sf::Vector2u(WIDTH,HEIGHT));
    //Coordinate topleft is 0,0 however I want coordinate at centre to be 0,0
    const int FRAME_RATE = 60;
    window.setFramerateLimit(FRAME_RATE);
    Draw brush = Draw(WIDTH,HEIGHT,SCREENDIST,window);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                POV.moveFront(VELOCITY);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                POV.moveFront(-VELOCITY);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                POV.turnX(-ANG_VELOCITY);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                POV.turnX(ANG_VELOCITY);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){//E to look up
                POV.turnY(ANG_VELOCITY);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){//Q to look down
                POV.turnY(-ANG_VELOCITY);
            }
        }
        window.clear(sf::Color::Black);
        brush.drawLines(LineVec);
        window.display();
    }
}