//
//  138.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/22.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *curr=head;
        while(curr){
            RandomListNode *temp=new RandomListNode(curr->label);
            temp->next=curr->next;
            curr->next=temp;
            curr=temp->next;
        }
        curr=head;
        while(curr){
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        RandomListNode dummy(-1);
        RandomListNode *prev=&dummy;
        dummy.next=head;
        curr=head;
        while(curr){
            prev->next=curr->next;
            prev=prev->next;
            curr->next=curr->next->next;
            curr=curr->next;
        }
        return dummy.next;
    }
};

int main(int argc,const char *argv[]){
//    vector<RandomListNode> list={0,1,2,3,4,5,6,7,8,9};
    vector<RandomListNode> list={-1,-1};
    list[0].next=&list[1];
//    list[1].next=&list[2];
//    list[2].next=&list[3];
//    list[3].next=&list[4];
//    list[4].next=&list[5];
//    list[5].next=&list[6];
//    list[6].next=&list[7];
//    list[7].next=&list[8];
//    list[8].next=&list[9];
//    list[1].random=&list[4];
//    list[2].random=&list[8];
//    list[5].random=&list[7];
//    list[9].random=&list[0];
//    list[6].random=&list[3];
    RandomListNode *head=&list[0];
    Solution s;
    RandomListNode *newhead=s.copyRandomList(head);
    while(newhead){
        cout<<newhead->label<<" ";
//        if(newhead->random)
//            cout<<newhead->random->label;
//        cout<<endl;
        newhead=newhead->next;
    }
    return 0;
}
