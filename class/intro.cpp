#include<iostream>
using namespace std;
//#include "Hero.cpp"(if class is in another file)

class Hero{
    //properties
    private:  
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;
    
    //Simple Constructor
    Hero(){
        cout << "Constructor called!" << endl;
        name = new char[100];
    }

    //Parameterised constructor
    Hero(int health, char level){

        //this stores the address of the current object
        //cout<<"this is: " << this << endl;
        this -> health = health;
        this -> level = level;
    }

    //Copy Constructor
    Hero(Hero& temp){
        cout<<"Copy constructor called" << endl;
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this -> name = ch;
        
        this -> health = temp.health;
        this -> level = temp.level;
        
    }

    void print(){
        cout<<endl;
        cout<<"[ Name is: " << this->name << ", ";
        cout<<"Health is: " << this->health << ", ";
        cout<<"Level is: " << this->level <<  " ]";
        cout<<endl;
        
    }
    int getHealth(){
        return health;
    }
    void setHealth(int h){
        health = h;
    }
    int getLevel(){
        return level;
    }
    void setLevel(char l){
        level = l;
    }
    void setName(char name[]){
        strcpy(this -> name, name);
    }

    // ~Hero(){
    //     cout<<"Destructor called"<<endl;
    // }
    
};

int Hero :: timeToComplete = 3; 

int main(){
    
    
    cout<<Hero::timeToComplete<<endl;
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Anshul";
    hero1.setName(name);
    hero1.print();

    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'T';
    hero1.print();
    hero2.print();

    // //Static Allocation
    // // Hero h1;
    // // cout<<"Size: "<<sizeof(h1)<<endl;
    
    // h1.setHealth(70);
    // cout<<"Level is: "<<h1.level<<endl;
    // cout<<"Health is: "<<h1.getHealth()<<endl;

    Hero R(10,'C');
    //R.print();
    // cout << "R is: " << &R <<endl;
    // cout << "this and R has same address" << endl;

    //Copy Constructor 
    Hero S(R);
    //S.print();

    //Dynamic Allocation
    // Hero *b = new Hero();
    // b->setHealth(23); 
    // cout<<"Level is: "<<(*b).level<<endl;
    // cout<<"Health is: "<<(*b).getHealth()<<endl;

    
    // cout<<"Level is: "<< b->level << endl;
    // cout<<"Health is: "<< b->getHealth() << endl;


    return 0;
}