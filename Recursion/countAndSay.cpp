#include<iostream>
using namespace std;

/* Example
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
*/

string countAndSay(int n) {

        //base case
        if(n == 1){
            string str = "";
            str += '1';
            return str;
        }
           
        
        //recursive call
        string str = countAndSay(n-1);
        
        string ans = "";
        int num;
        for(int index = 0; index < str.size(); index++){
            int count = 1;
            while(str[index] == str[index+1] && index != str.size()-1){
                count++;
                index++;
            }
            
            ans += (count + '0');
            ans += str[index];
            
        }
        return ans;

    }

int main(){
    string s = countAndSay(4);
    cout <<  s << endl;
}    