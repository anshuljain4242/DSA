#include<iostream>
using namespace std;

int fact(int n){
    if(n==0){
        return 1;
    }
    
    int factorial = n * fact(n-1);
    return factorial;
    
}

int power(int n){
    if(n==0)
        return 1;

    int smallerProblem = power(n-1);
    int biggerProblem = 2*smallerProblem;

    return biggerProblem;  
}

void print(int n){
    if(n == 0)
        return ;

    //cout<<n<<endl;
    print(n-1);   

    cout<<n<<endl; 
}

bool arraySorted(int arr[], int n){
    if(n==0 || n==1)
        return true;

    for(int i=1; i<n; i++){
        if(arr[i-1]>arr[i])
            return false;
        
    } 
    return true;   
}

int fib(int n){
    if(n==0 || n==1)
        return n;
    int sum = 0;
    for(int i=2; i<=n; i++)
    {
        sum += (i-1) + (i-2);
    }
    return sum;
}

void revArray(int *array, int n, int i)
{
    if( i >= n/2)
        return;

    swap(array[i], array[n-i-1]);
    revArray(array, n, i+1);    
}

int main(){
    int n;
    cin>>n;
    int arr[10];
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }

    if(arraySorted(arr,n)){
        cout<<"yes";
    }
    else{
        cout<<"No";
    }

    int array[5] = {3,4,2,1,5};
    revArray(array,5,0);

    for(int i=0;i<5; i++){
        cout<<array[i]<<" ";
    }
    
    //int ans = fact(n);
    //int ans = power(n);
    //print(n)
}


