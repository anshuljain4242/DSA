#include <iostream>
#include <vector>
using namespace std;

void printK(int idx, vector<int> &ds, int arr[], int n, int sum, int k)
{
    if (idx == n)
    {
        if (sum == k)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[idx]);
    sum += arr[idx];
    printK(idx + 1, ds, arr, n, sum, k);
    ds.pop_back();
    sum -= arr[idx];
    printK(idx + 1, ds, arr, n, sum, k);
}

bool printOneSubsq(int idx, vector<int> &ds, int arr[], int n, int sum, int k)
{
    if (idx == n)
    {
        // condition satisfied
        if (sum == k)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " ";
            }
            cout << endl;
            return true;
        }
        // condition not satisfied
        return false;
    }

    ds.push_back(arr[idx]);
    sum += arr[idx];
    if (printOneSubsq(idx + 1, ds, arr, n, sum, k) == true)
        return true;

    ds.pop_back();
    sum -= arr[idx];

    if (printOneSubsq(idx + 1, ds, arr, n, sum, k) == true)
        return true;

    return false;
}

int countSubsq(int idx, int arr[], int n, int sum, int k)
{
    if (idx == n)
    {
        // condition satisfied
        if (sum == k) return 1;
        // condition not satisfied
        else return 0;
    }

    sum += arr[idx];
    int l = countSubsq(idx + 1, arr, n, sum, k);

    sum -= arr[idx];
    int r = countSubsq(idx + 1, arr, n, sum, k);

    return l+r;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int k = 2;
    vector<int> ds;
    // printK(0, ds, arr, n, 0, k);
    // printOneSubsq(0, ds, arr, n, 0, k);
    cout<<"Number of Subsequences with sum K- "<<countSubsq(0, arr, n, 0, k)<<endl;
}