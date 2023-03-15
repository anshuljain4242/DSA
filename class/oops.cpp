#include<iostream>
using namespace std;

class Human{
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return this->age;
    }
    void setWeight(int w){
        this->weight = w; 
    }
};
class Male : protected Human{
    public:
    string color;

    void sleep(){
        cout<<"Male Sleeping"<<endl;
    }
    int getHeight(){
        return this->height;
    }
};
int main(){

    Male obj1;
    //obj1.height  protected in Male class and therefore cannot access outside the class
    cout << obj1.getHeight() << endl;
   /*
   cout << obj1.height << endl;
    cout << obj1.weight  << endl;
    cout << obj1.color << endl;
    obj1.sleep();
   */ 
    cout<< endl;
    return 0;
}