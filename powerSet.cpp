#include<iostream>
#include<string>
#include<vector>
using namespace std;

void powerSet(string s)
{
    int n = s.size();
    for(int num = 0; num <= ((1 << n) - 1); num++)
    {
        string sub = "";
        for(int i=0; i<n; i++)
        {
            if(num & (1 << i))
                sub += s[i];
        }
        cout<<sub<<" ";
    }

}

void printSubsequence(int idx, vector<int> &ds, int arr[], int n)
{
    if(idx >= n){
        for(int i=0; i<ds.size(); i++){
            cout<<ds[i]<<" ";
        }
        cout<<endl;
        return;
    }
    // take or pick a particular index into the subsequence
    ds.push_back(arr[idx]);
    printSubsequence(idx+1, ds, arr, n);
    ds.pop_back();

    // not pick or not take condition, this element is not added in the subsequence
    printSubsequence(idx+1, ds, arr, n);
}

int main()
{
    string s = "abc";
    int arr[] = {3,1,2};
    int n=3;
    vector<int> ds;
    printSubsequence(0, ds, arr, n);
    // powerSet(s);
}