//
//  8.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/24.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int num=0;
        int sign=1;
        int index=0;
        while(str[index]==' ') ++index;
        if(str[index]=='+') ++index;
        else if(str[index]=='-'){
            ++index;
            sign=-1;
        }
        for(;index<str.size();++index){
            if(!isdigit(str[index])) break;
            if((num==INT_MAX/10&&str[index]-'0'>INT_MAX%10)\
               ||num>INT_MAX/10)
                return sign==1?INT_MAX:INT_MIN;
            num=num*10+str[index]-'0';
        }
        return num*sign;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
