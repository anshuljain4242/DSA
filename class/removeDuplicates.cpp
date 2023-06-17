#include <iostream>
#include<vector>
using namespace std;
//each unique element 1 time
int removeDuplicates(vector<int> nums){
    int addIndex = 1;

    for(int i=0 ; i < 6; i++){
        if(nums[i] < nums[i+1]){
            nums[addIndex] = nums[i+1];
            addIndex++;
        }
    }
    return addIndex;
}

// each element at most x times
int removeDuplicatestwo(vector<int> nums){
    int index,x = 2;
        for(int i = 2; i < nums.size(); i++){
          if(nums[i] != nums[index-x]){
            nums[index] = nums[i];
            index++;
          }
        }
    return index;
}

int main(){
    vector<int> nums {0,0,2,3,3,5,6};
    
    int k = removeDuplicates(nums);
    int j = removeDuplicatestwo(nums);
    cout<<k<<endl;
    for (int i = 0; i < k; i++) {
        cout<<nums[i];
    }
}





        
