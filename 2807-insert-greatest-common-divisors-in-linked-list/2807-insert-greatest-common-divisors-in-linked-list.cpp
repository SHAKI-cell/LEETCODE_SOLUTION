/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   int gcd(int t1,int t2){
    if(t2==0) return t1;
    return gcd(t2,t1%t2);
   }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
            while(temp!=NULL && temp->next!=NULL){
            int t1=temp->val;
            int t2=temp->next->val;
            int t=gcd(t1,t2);
            ListNode* temp1=new ListNode(t);
            temp1->next=temp->next;
             temp->next=temp1;
            temp=temp1->next;
         }
        return head;
    }
};