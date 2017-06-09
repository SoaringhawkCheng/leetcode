
//
//  204.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/6.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

class Solution1 {
public:
    int countPrimes(int n) {
        vector<int> primes(n,1);
        primes[0]=primes[1]=0;
        int limit=sqrt(n);
        for(int i=2;i<=limit;++i){
            if(primes[i]){
                int j=i*i;
                while(j<n){
                    primes[j]=0;
                    j+=i;
                }
            }
        }
//        int count=0;
//        for(int i=2;i<n;++i){
//            if(primes[i]) {
//                ++count;
//                cout<<i<<" ";
//            }
//        }
//        cout<<endl;
//        return count;
        return count_if(primes.begin(),primes.end(),bind1st(equal_to<int>(),1));
    }
};

class Solution2 {
public:
    int countPrimes(int n) {
        vector<int>
    }
};

int main(int argc,const char *argv[]){
    Solution s;
    cout<<s.countPrimes(100)<<endl;
}
