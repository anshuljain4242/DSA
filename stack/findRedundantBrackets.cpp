#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        //either ch is an opening bracket or an operator
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        //either ch is a closing bracket or a lower case english letter
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();     
                }
                if(isRedundant == true){
                    return true;
                }
                st.pop();

            }  
        }
    }
    return false;
}

int main(){

    string s = "(a+c*b)+(c))";
    cout<<findRedundantBrackets(s);
    return 0;
}