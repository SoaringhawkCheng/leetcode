//
//  662.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/8/20.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        deque<TreeNode *> curr;
        deque<TreeNode *> next;
        deque<TreeNode *> dup;
        curr.push_back(root);
        int maxwidth=1;
        while(true){
//            dup=curr;
            int index=0;
            int width=0;
            vector<int> border;
            while(!curr.empty()){
                TreeNode *p=curr.front();
                curr.pop_front();
                if(p){
                    next.push_back(p->left);
                    if(p->left) border.push_back(index);
                    ++index;
                    next.push_back(p->right);
                    if(p->right) border.push_back(index);
                    ++index;
                }
                else{
                    next.push_back(NULL);
                    ++index;
                    next.push_back(NULL);
                    ++index;
                }
            }
            if(border.empty()) break;
            else maxwidth=max(maxwidth,border.back()-border.front()+1);
            while(next.front()==NULL) next.pop_front();
            while(next.back()==NULL) next.pop_back();
            swap(curr,next);
        }
        return maxwidth;
    }
};

int main(int argc, const char *argv[]){
    TreeNode tree[8]={0,1,2,3,4,5,6,7};
    tree[0].left=&tree[1];
    tree[0].right=&tree[2];
    tree[1].left=&tree[3];
    tree[1].left=&tree[4];
    tree[2].right=&tree[5];
    tree[4].right=&tree[6];
    tree[5].right=&tree[7];
    Solution s;
    cout<<s.widthOfBinaryTree(&tree[0])<<endl;
}
