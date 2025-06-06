#include <iostream>

using namespace std;

class Solution {
    public:
        static bool isPalindrome(int x){
            if(x<0){
                return false;
            }

            int rx = x%10; 
            for(int cl = x/10; cl;cl/=10){
                rx = rx*10 + cl%10;
            }
            return rx == x;
        }
};

int main(){

    //test
    cout << boolalpha << Solution::isPalindrome(10021) << '\n';
    cout << boolalpha << Solution::isPalindrome(-121) << '\n';
    cout << boolalpha << Solution::isPalindrome(121) << '\n';
    cout << boolalpha << Solution::isPalindrome(0) << '\n';
    cout.flush();
}