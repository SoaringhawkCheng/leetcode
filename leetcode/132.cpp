#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int size=s.size();
        vector<vector<bool>> pair(size,vector<bool>(size,false));
        vector<int> mCut(size+1,0);
        mCut[0]=0;
        for(int right=0;right<size;++right){
            mCut[right+1]=INT_MAX;
            for(int left=0;left<=right;++left){
                if(s[left]==s[right]&&(right-left<=1||pair[left+1][right-1])){
                    pair[left][right]=true;
                    if(left==0) mCut[right+1]=0;
                    else mCut[right+1]=min(mCut[left]+1,mCut[right+1]);
                }
            }
        }
        return mCut[size];
    }
};

int main(int argc,const char *argv[]){
    string s="fff";
    Solution solution;
    int mincut;
    mincut=solution.minCut(s);
    cout<<mincut<<endl;
}
