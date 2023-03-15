#include <iostream>
#include<vector>
#include<numeric>
//#include <bits/stdc++.h>
using namespace std;
vector<int> minx(vector<int>& arr, int N){
	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	sort(arr.begin(),arr.end());
	int new_sum = 0;
	int x = arr[0];
	for(int i=1; i<N; i++){
		int curr_sum = (N - i) * arr[i-1];
        if ((curr_sum + (N-i)*(x - arr[i-1])) >= sum) {
            x = arr[i-1] + (sum - new_sum) / (N - i);
            break;
        }
        new_sum += curr_sum;
        x = arr[i];
	}
	for(int i=1; i<N; i++){
		arr[i] = x;
	}
	return arr;
	


}
int main() {
	//int num;
	//cin >> num;    //Reading input from STDIN
	//cout << "Input number is " << num << endl;	// Writing output to STDOUT
	int N,a;
	cin>>N;
	vector<int> arr;
	for(int i=0; i<N; i++){
		cin>>a;
		arr.push_back(a);
	}
	vector<int> updated_A = minx(arr,N);
    for (int x : updated_A) {
        cout << x << " ";
    }
	return 0;
}