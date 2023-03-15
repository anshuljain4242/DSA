#include <iostream>
#include <numeric>
#include <vector>
#include <stack>
using namespace std;

int sum(std::vector<int> h, int s, int e){
    int sum=0;
    for(int i=s; i<e ; i++){
        sum += h[i];
    }
    return sum;
}
int equalStacks(std::vector<int> h1, std::vector<int> h2, std::vector<int> h3){
    /*
    stack<int> stackh1;
    stack<int> stackh2;
    stack<int> stackh3;

    for(int i=h1.size()-1;i>=0; i--){
        stackh1.push(h1[i]);
    }

    for(int i=h2.size()-1;i>=0; i--){
        stackh2.push(h2[i]);
    }
    
    for(int i=h3.size()-1;i>=0; i--){
        stackh3.push(h3[i]);
    }
    */
    int sum1 = sum(h1,0,h1.size());
    int sum2 = sum(h2,0,h2.size());
    int sum3 = sum(h3,0,h3.size());

    int c1=0,c2=0, c3=0;

    while(sum1 != sum2 || sum2 != sum3 || sum3 != sum1){
        if(sum1>=sum2 && sum1 >= sum3){
            sum1 -= h1[c1];
            c1++;
        }
        else if(sum2 >= sum1 && sum2 >= sum3){
            sum2 -= h2[c2];
            c2++;
        }
        else if(sum3 >= sum1 && sum3 >= sum2){
            sum3 -= h3[c3];
            c3++;
        }
    }
    return sum1;
}

int main(){
    int len1,len2,len3;
    cout<<"Enter size of h1: ";
    cin>>len1;
    std::vector<int> h1;
    int k;
    for(int i=0; i<len1; i++){
        cin>>k;
        h1.push_back(k);
    }
    cout<<"h1 is: - "<<endl;
    for(int i=0; i<len1; i++){
        cout<<h1.at(i)<<" ";
    }
    cout<<endl;

    cout<<"Enter size of h2: ";
    cin>>len2;
    std::vector<int> h2;

    for(int i=0; i<len2; i++){
        cin>>k;
        h2.push_back(k);
    }
    cout<<"h2 is: - "<<endl;
    for(int i=0; i<len2; i++){
        cout<<h2.at(i)<<" ";
    }
    cout<<endl;

    cout<<"Enter size of h3: ";
    cin>>len3;
    std::vector<int> h3;

    for(int i=0; i<len3; i++){
        cin>>k;
        h3.push_back(k);
    }
    cout<<"h3 is: - "<<endl;
    for(int i=0; i<len3; i++){
        cout<<h3.at(i)<<" ";
    }
    cout<<endl;
    //int ans = min(sum(h1,0,len1), sum(h1,0,len2), sum(h1,0,len3));

    cout<<"Max height- "<<equalStacks(h1,h2,h3);

}