#include<iostream>
#include<vector>
using namespace std;

/*
There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. 
There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B,
Serve 75 ml of soup A and 25 ml of soup B,
Serve 50 ml of soup A and 50 ml of soup B, and
Serve 25 ml of soup A and 75 ml of soup B.
When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will 
choose from the four operations with an equal probability 0.25. If the remaining volume of 
soup is not enough to complete the operation, we will serve as much as possible. We stop once 
we no longer have some quantity of both types of soup.

Note that we do not have an operation where all 100 ml's of soup B are used first.

Return the probability that soup A will be empty first, plus half the probability that A and B
 become empty at the same time. Answers within 10-5 of the actual answer will be accepted.
*/


/*
Intuition
Hint-1: We do not have an operation where all 100 ml's of soup B are used first.
Hint-2: Answers within 10^-5 of the actual answer will be accepted.
Hint-3: 0 <= n <= 10^9

Approach
From Hint-1 and given 4 operation we can easily say that probability of A to get empty is 
always greater than B to get empty.

From Hint-2 we can say that probability greater than 0.999995 is treated as 1.

So from Hint-1 and Hint-2 we know we have to find N which have probabilty 0.999995.

Now If we observe time complexity of dp approach is almost O(N^2) and we need new n which 
is sqrt(10^9) approx 10^4.

Now we can further optimze the N to get probability = 0.999995 which is N=4800.

But its not intutive to get N=4800 in interview.

But if interviewer ask for smallest N where probability is 1 then we can do a binary 
search to find it.
*/
vector<pair<int,int> > serves{{100,0}, {75, 25}, {50, 50}, {25, 75}};
    vector<vector<double> > dp;

    double solve(double A, double B){
        if(A <= 0 && B <= 0)
            return 0.5;
        if(A <= 0)
            return 1.0;
        if(B <= 0)
            return 0.0;

        if(dp[A][B] != -1)
            return dp[A][B];

        double prob = 0.0;

        for(auto &p:serves){

            double A_serve = p.first;
            double B_serve = p.second;

            prob += 0.25 * solve(A-A_serve, B-B_serve);
        }    
        return dp[A][B] = prob;            
    }
double soupServings(int n) {
    
    if(n >= 5000) //I hate this part.
        return 1.0;
    
    dp.resize(n+1, vector<double>(n+1, -1.0));
    return solve(n, n);
}