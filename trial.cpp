using namespace std;
#include <bits/stdc++.h>
class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z); // Constructor declaration
};
Car::Car(string x, string y, int z) {
  brand = x;
  model = y;
  year = z;
}
class Trial{
    private:
        int a;
    public:
        Trial(int A);
        void change(int A);
        int get();
};
Trial::Trial(int A){
    a = A;
}
void Trial :: change(int A){
    a = A;
}
int Trial :: get(){
    return a;
}

class meta{
    private:
        Trial* obj;
    public:
        meta(Trial t);
        Trial get();
};
meta :: meta(Trial t){
    obj = &t;
}
Trial meta :: get(){
    return *obj;
}
int main(){
    Trial t = Trial(5);
    meta m = meta(t);
    t.change(7);
    int[][] ticketInfo;

    cout << (m.get()).get() << endl;
}