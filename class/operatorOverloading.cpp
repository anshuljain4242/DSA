#include<iostream>
using namespace std;

class A{
    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;
    }

    void operator+ (A& obj){
        int value1 = this -> a;
        int value2 = obj.a;
        cout<<"Output: " << value2 - value1 << endl;
    }

    void operator() (){
        cout << "I'm  bracket! " << this->a << endl;
    }
};

int main(){

    A ob1, ob2;
    ob1.a = 8;
    ob2.a = 10;
    ob1 + ob2;

    ob1();
    return 0;
}