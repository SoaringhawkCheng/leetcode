//
//  25.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/22.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
// 
//class Solution {//自己的搓方法
//public:
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        //特殊情况特殊处理
//        if(head==NULL||head->next==NULL||k==0||k==1) return head;
//        //k>=2
//        ListNode dummy(-1);
//        dummy.next=head;
//        head=&dummy;
//        bool flag=true;
//        while(flag){
//            ListNode *prev,*cur;
//            cur=head->next;
//            int index=0;
//            for(;index<k;++index){
//                cout<<"fuck you"<<endl;
//                if(cur==NULL) break;
//                cur=cur->next;
//            }
//            if(index!=k) break;
//            ListNode *new_cur=cur;
//            prev=head->next;
//            cur=prev->next;
//            while(cur!=new_cur){
//                prev->next=cur->next;
//                cur->next=head->next;
//                head->next=cur;
//                cur=prev->next;
//            }
//            head=prev;
//        }
//        return dummy.next;
//    }
//};
//
//class Solution1 {
//public:
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        if(head==NULL||head->next==NULL||k<2)
//            return head;
//        ListNode *next_group=head;
//        for(int i=0;i<k;++k){
//            if(next_group) next_group=next_group->next;
//            else return head;
//        }
//        ListNode *new_next_group=reverseKGroup(next_group, k);
//        ListNode *prev=NULL;
//        ListNode *curr=head;
//        while(curr!=next_group){
//            
//        }
//    }
//};
//
//
//int main(int argc,const char *argv[]){
//    vector<ListNode> list={0,1,2,3,4,5,6};
//    list[0].next=&list[1];
//    list[1].next=&list[2];
//    list[2].next=&list[3];
//    list[3].next=&list[4];
//    list[4].next=&list[5];
//    list[5].next=&list[6];
//    ListNode *head=&list[0];
//    Solution s;
//    head=s.reverseKGroup(head, 2);
//    while(head){
//        cout<<head->val<<" ";
//        head=head->next;
//    }
//    cout<<endl;
//    return 0;
//}
