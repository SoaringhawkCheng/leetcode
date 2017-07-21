#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp=0,result=INT_MIN;
        for(auto num:nums){
            tmp=max(tmp+num,num);
            result=max(result,tmp);
        }
        return result;
    }
};
