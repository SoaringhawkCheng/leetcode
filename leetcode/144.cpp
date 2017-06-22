//
//  144.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/9.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        _preorderTraversal(root);
        return result;
    }
private:
    vector<int> result;
    void _preorderTraversal(TreeNode *root){
        if(root==NULL) return;
        result.push_back(root->val);
        _preorderTraversal(root->left);
        _preorderTraversal(root->right);
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        stack<TreeNode *> stk;
        while(root){
            result.push_back(root->val);
            if(root->right) stk.push(root->right);
            root=root->left;
        }
        while(!stk.empty()){
            root=stk.top();
            stk.pop();
            while(root){
                result.push_back(root->val);
                if(root->right) stk.push(root->right);
                root=root->left;
            }
        }
        return result;
    }
};

class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()){
            root=stk.top();
            stk.pop();
            result.push_back(root->val);
            if(root->right) stk.push(root->right);
            if(root->left) stk.push(root->left);
        }
        return result;
    }
};

class Solution4 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        while(root){
            if(!root->left){
                result.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode *node=root->left;
                while(node->right&&node->right!=root) node=node->right;
                if(!node->right){
                    result.push_back(root->val);
                    node->right=root;
                    root=root->left;
                }
                else{
                    node->right=NULL;
                    root=root->right;
                }
            }
        }
        return result;
    }
};

int main(int argc,const char *argv[]){
    vector<TreeNode> tree={0,1,2,3,4,5,6,7,8,9};
    tree[1].left=&tree[2];
    tree[1].right=&tree[7];
    tree[2].left=&tree[3];
    tree[2].right=&tree[4];
    tree[4].left=&tree[5];
    tree[4].right=&tree[6];
    tree[7].right=&tree[8];
    tree[8].left=&tree[9];
    Solution4 s;
    vector<int> result=s.preorderTraversal(&tree[1]);
    for(auto res:result) cout<<res<<" ";
    cout<<endl;
}
