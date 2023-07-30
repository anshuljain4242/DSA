#include <iostream>
#include <vector>
using namespace std;
/*
A sequence is bitonic if it is first increasing and then decreasing.
ex- [1 2 1 2 1], seq -> 1,2,2,1

[1 2 1 3 4], seq -> 1,2,3,4
*/


int longestBitonicSequence(vector<int>& arr, int n) {

	// calculating dp1[]
	vector<int> dp1(n, 1);

    for(int i=0; i<n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && dp1[j] + 1 > dp1[i])
                dp1[i] = dp1[j] + 1;    
        }
    } 

	// calculatin dp2[]
	vector<int> dp2(n, 1);
	for(int i=n-1; i>=0; i--){
        for(int j = n-1; j > i; j--){
            if(arr[j] < arr[i] && dp2[j] + 1 > dp2[i])
                dp2[i] = dp2[j] + 1;    
        }
    } 
	int maxi = 1;

	for(int i=0; i<n; i++){
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	} 

	return maxi;
}