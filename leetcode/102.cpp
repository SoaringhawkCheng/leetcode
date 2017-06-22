//
//  102.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/9.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        _levelOrder(root,0);
        return result;
    }
private:
    vector<vector<int>> result;
    void _levelOrder(TreeNode *root,int level){
        if(root){
            if(result.size()<=level) result.push_back(vector<int>());
            result[level].push_back(root->val);
            _levelOrder(root->left,level+1);
            _levelOrder(root->right,level+1);
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode *> current;
        queue<TreeNode *> next;
        int level=0;
        current.push(root);
        while(!current.empty()){
            result.push_back(vector<int>());
            while(!current.empty()){
                TreeNode *tmp=current.front();
                current.pop();
                result[level].push_back(tmp->val);
                if(tmp->left) next.push(tmp->left);
                if(tmp->right) next.push(tmp->right);
            }
            level=level+1;
            swap(current,next);
        }
        return result;
    }
};

class Solution3 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode *> current;
        current.push(root);
        int level=0;
        while(!current.empty()){
            result.push_back(vector<int>());
            int size=current.size();
            for(int i=0;i<size;++i){
                TreeNode *tmp=current.front();
                current.pop();
                result[level].push_back(tmp->val);
                if(tmp->left) current.push(tmp->left);
                if(tmp->right) current.push(tmp->right);
            }
            level=level+1;
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
    Solution1 s;
    vector<vector<int>> result=s.levelOrder(&tree[1]);
    for(auto res:result){
        for(auto r:res)
            cout<<r<<" ";
        cout<<endl;
    }
    cout<<endl;
}
