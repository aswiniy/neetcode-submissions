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
    ListNode* reverse(ListNode* curr){
        ListNode*prev=NULL;
        while(curr){
            ListNode*next=curr->next;
            curr->next= prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        int n=0;
        ListNode*curr=head;

        while(curr){
            n++;
            curr= curr->next;
        }

        curr=head;

        int k=n/2;
        ListNode* mid= head;

        for(int i=0;i<k-1;i++){
            mid=mid->next;
        }
        mid->next = reverse(mid->next);

        mid=mid->next;
        int res=0;

        while(mid){
          int sum= curr->val + mid->val;
          res= max(res,sum);
          curr = curr->next;
          mid = mid->next;
        }

        return res;
        
    }
};