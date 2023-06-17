/*
Print statement after the recursive function call makes sure of the backtracking.
*/

#include<iostream>
using namespace std;

// Print from N to 1 using backtracking
void func(int i, int n)
{
    if(i > n)
        return;

    func(i+1,n);
    cout<<i<<" ";   
}

// Parametrised Recursion
void summ(int i, int sum)
{
    if(i < 1)
    {
        cout<<sum<<endl;
        return;
    }

    summ(i-1, sum+i);
}

//Functional Recursion
int sum(int n)
{
    if(n==0) return 0;
    return n + sum(n-1);
}

int main()
{
    int n=5;
    func(1,5);
    cout<<endl;
    summ(5,0);
    cout << sum(3) << endl;
}