#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
Max area of reactangle in binary matrix with all 1s
int maxArea(int M[MAX][MAX], int n, int m) {
       
        //Step1 : Compute area for first row
        int area = largestRectangleArea(M[0],m);
        
        //Step2a : Update row by adding previous row's value
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j] != 0)
                    M[i][j] += M[i-1][j]; 
                else
                    M[i][j] = 0;
            }
            
            //Step2b: entire current row will be updated
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
        
        
    }
*/


vector<int> nextSmallerElement(vector<int>& heights, int n){
        stack<int> st;
        vector<int> next(n);

        st.push(-1);

        for(int i = n-1; i>=0; i--){
            int curr = heights[i];

            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;

    }

    vector<int> prevSmallerElement(vector<int>& heights, int n){
        stack<int> st;
        vector<int> prev(n);

        st.push(-1);

        for(int i = 0; i<n; i++){
            int curr = heights[i];

            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }

int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        
        for(int i=0; i<n; i++){
            int l = heights[i];
            

            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }

    return area;
    }

    int main(){
        int arr[6] = { 2, 1, 5, 6, 2, 3 };
        vector<int> heights; 
        cout<<"Largest area is : " << largestRectangleArea(heights) << endl;
        return 0; 

    }