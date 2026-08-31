class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int idx=1;
        int fidx=-1;
        int sidx=-1;

        ListNode* slow=head;
        ListNode* fast=head->next;
        ListNode* curr=head->next->next;
        if(curr==NULL) return {-1,-1};
        while(curr){
             if((fast->val > slow->val && fast->val > curr->val) || (fast->val < slow->val && fast->val < curr->val)){
              if(fidx==-1) fidx=idx;
              else{
                sidx=idx;
              }

             }
               slow=slow->next;
                fast=fast->next;
                curr=curr->next;
                idx++;

        }
        if(sidx==-1) return {-1,-1};
        int maxd=sidx-fidx;
         int mind=INT_MAX;
         fidx=-1;
         sidx=-1;
         idx=1;
         slow=head;
         fast=head->next;
         curr=head->next->next;
         if(curr==NULL) return {-1,-1};
        while(curr){
         if((fast->val > slow->val && fast->val > curr->val) || (fast->val < slow->val && fast->val < curr->val)){
            fidx=sidx;
            sidx=idx;
            if(fidx!=-1){
            int d=sidx-fidx;
             mind=min(mind,d);
            }
         }
          slow=slow->next;
          fast=fast->next;
          curr=curr->next;
          idx++;
        }
      return {mind,maxd};
    }
};