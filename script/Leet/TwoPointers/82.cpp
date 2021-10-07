// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Date: 2021.09.21

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        int cur = 200;
        ListNode *ptr = head;
        ListNode *prev = head;
        
        while(ptr != NULL){
            
            // 현재 값이 중복 원소인지 체크하기 위한 cur 업데이트
            if(ptr->next != NULL && ptr->next->val == ptr->val)
                cur = ptr->val;
            
            // 현재 값이 cur과 같다면 제거 대상
            if(ptr->val == cur){
                ListNode *tmp = ptr;
                
                // head일 경우 head 업데이트
                if(ptr == head){
                    head = head->next;
                    ptr = head;
                    prev = head;
                }
                // prev와 ptr->next 연결하여 리스트에서 ptr 제거
                else{
                    prev->next = ptr->next;
                    ptr = prev->next;                    
                }           
                // ptr 값 메모리 해제     
                delete tmp;
            }
            else{
                // 다음 노드로 이동
                prev = ptr;
                ptr = prev->next;
            }
        }
        return head;
    }
};