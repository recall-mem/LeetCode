#include <iostream>

using namespace std;

class Solution {
    public:
    static int reverse(int64_t x) {

        if (x < INT32_MIN || x > INT32_MAX){
            return 0;
        }
        if((x < 10 && x >= 0)){
            return x;
        }
        int64_t copy = 0;
        for(; x!=0; x/=10){
            copy = copy*10 + x%10;
        }
        if (copy < INT32_MIN || copy > INT32_MAX){
            return 0;
        }
        return copy;
    }

};


int main(){
    std::cout << Solution::reverse(1534236469) << '\n';
    std::cout << Solution::reverse(-123123) << '\n';
    std::cout << Solution::reverse(10003) << '\n';
    std::cout << Solution::reverse(12000) << std::endl;
}