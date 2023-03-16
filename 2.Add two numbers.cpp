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
private:

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder = 0;
        ListNode* dummy = new ListNode;
        ListNode* current = dummy;

        while(l1 != NULL || l2 != NULL || remainder !=0){
            int x = (l1!=NULL)? l1->val:0;          // if l1 is valid, x = l1->val
            int y = (l2!=NULL)? l2->val:0;
            int sum = x + y + remainder;

            remainder = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
            l1 = l1? l1->next :nullptr;             // if l1 (current )is valid, we move l1 to the next 
            l2 = l2? l2->next :nullptr;
        }
        return dummy->next;
    }
};