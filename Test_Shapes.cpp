#include <bits/stdc++.h>
//#include "Basic_structures.cpp"
using namespace std;

vector<Line> Cube(Cartesian &POV,double a,double dist){
    int choice = 1;
    vector<Line> ans;
    Line e1 = Line(POV,-a,-a,dist,a,-a,dist);
    ans.push_back(e1);
    Line e2 = Line(POV,a,-a,dist,a,a,dist);
    ans.push_back(e2);
    Line e3 = Line(POV,a,a,dist,-a,a,dist);
    ans.push_back(e3);
    Line e4 = Line(POV,-a,a,dist,-a,-a,dist);
    ans.push_back(e4);
    Line e5 = Line(POV,-a,-a,dist + 2*a,a,-a,dist + 2*a);
    ans.push_back(e5);
    Line e6 = Line(POV,a,-a,dist + 2*a,a,a,dist + 2*a);
    ans.push_back(e6);
    Line e7 = Line(POV,a,a,dist + 2*a,-a,a,dist + 2*a);
    ans.push_back(e7);
    Line e8 = Line(POV,-a,a,dist + 2*a,-a,-a,dist + 2*a);
    ans.push_back(e8);
    Line e9 = Line(POV,-a,-a,dist,-a,-a,dist + 2*a);
    ans.push_back(e9);
    Line e10 = Line(POV,a,-a,dist,a,-a,dist + 2*a);
    ans.push_back(e10);
    Line e11 = Line(POV,a,a,dist,a,a,dist + 2*a);
    ans.push_back(e11);
    Line e12 = Line(POV,-a,a,dist,-a,a,dist + 2*a);
    ans.push_back(e12);
    return ans;
}