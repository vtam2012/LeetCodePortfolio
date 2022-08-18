/* Author:  Vincent Tam
 * CS5008 Summer 2022
 * LeetCode 148 Sorted List
 * https://leetcode.com/problems/sort-list/
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* function to merge two linkedlists */
struct ListNode* merge(struct ListNode* l, struct ListNode* r){
    if(l != NULL && r != NULL){
        if( l->val <= r->val){
            l->next = merge(l->next, r);
            return l;
        }
        else {
            r->next = merge(l, r->next);
            return r;
        }
    }
    if(l == NULL){
        return r;
    } 
    return l;
}

/* function to get middle node of a linked list 
 * uses two pointers slow and fast initially pointing to head
 * slow increments once while fast increments twice
 * when fast is out of bounds, slow will be the middle node
 * */

struct ListNode* getMidNode(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* mid = slow->next;
    slow->next = NULL;
    return mid;
}

struct ListNode* sortList(struct ListNode* head){
    /* check 1st node exists,
     * check 2nd node exists (head ->next != NULL)
     */
    if(head == NULL || head->next == NULL) {
        return head;
    }
    /* head->next is not null, so 2nd node exists, check if 3rd node exists 
     * if 3rd node does not exist and if the value in 2nd node is less than 1st node
     * swap head pointer to point to the 2nd node
     */
    if(head->next->next == NULL) {
        if(head->next->val < head->val){
            struct ListNode* temp = head->next;
            temp->next = head;
            head->next = NULL;
            head = temp;
        }
        return head;
    }
    /* get middle node */
    struct ListNode* mid = getMidNode(head);
    /* recursive call to sort left side starting at head pointer */
    struct ListNode* left = sortList(head);
    /* recursive call to sort right side starting at middle node */
    struct ListNode* right = sortList(mid);
    
    /* return merged sorted list */
    return merge(left, right);
}
