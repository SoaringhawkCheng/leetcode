//
//  145.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/9.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
//struct TreeNode{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x):val(x),left(NULL),right(NULL){}
//};
//
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> result;
//        if(!root) return result;
//        TreeNode *pre=NULL,*cur=root;
//        stack<TreeNode *> stk;
//        while(cur){
//            stk.push(cur);
//            cur=cur->left;
//        }
//        while(!stk.empty()){
//            cur=stk.top();
//            if(!cur->right||cur->right==pre){
//                result.push_back(cur->val);
//                pre=cur;
//                stk.pop();
//            }
//            else{
//                cur=cur->right;
//                while(cur){
//                    stk.push(cur);
//                    cur=cur->left;
//                }
//            }
//        }
//        return result;
//    }
//};
//
//int main(int argc,const char *argv[]){
//    vector<TreeNode> tree={0,1,2,3,4,5,6,7,8,9};
//    tree[1].left=&tree[2];
//    tree[1].right=&tree[7];
//    tree[2].left=&tree[3];
//    tree[2].right=&tree[4];
//    tree[4].left=&tree[5];
//    tree[4].right=&tree[6];
//    tree[7].right=&tree[8];
//    tree[8].left=&tree[9];
//    Solution s;
//    vector<int> result=s.postorderTraversal(&tree[1]);
//    for(auto res:result) cout<<res<<" ";
//    cout<<endl;
//}
