/*
input - ()(())
output - 2
explain - (+)((+))
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int solve(string s){

    stack<char> st;
    int count = 0;
    bool open = false;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == '(' && open == true){
            
        }
        else if(ch == '('){
            st.push(ch);
            open = true;
        }

            

    }
}

int main(){
    string s = "()(())";
    cout << solve(s) << endl;
    return 0;
}