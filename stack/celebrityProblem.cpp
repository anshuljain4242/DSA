#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(vector<vector<int> > &M, int n, int a, int b)
{
    if (M[a][b] == 1)
        return true;
    else
        return false;
}

// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int> > &M, int n)
{
    // code here
    stack<int> s;

    // step1 : push all elements inside stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step2
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(M, n, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int candidate = s.top();
    // step3: single element in stack -  might be a potential celebrity, so verify it
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount != n)
    {
        return -1;
    }

    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount != n - 1)
    {
        return -1;
    }

    return candidate;
}

int main(){
    int nums[3][3] = 
    vector<vector<int> > Members 
    {{0 1 0},{0 0 0},{0 1 0}};

   
          
         

}