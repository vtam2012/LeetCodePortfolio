/* Author:  Vincent Tam
 * CS5008 Summer 2022
 * LeetCode 155 Min Stack
 * https://leetcode.com/problems/min-stack/
 */

/* linked list node containing value as int */
typedef struct {
   int val;
   struct ListNode* next;
} ListNode;

/* stack data structure */
typedef struct {
    struct ListNode* top;
    int count;
} MinStack;

/* Create stack function */
MinStack* minStackCreate() {
    MinStack* minstack = (MinStack*)malloc(sizeof(MinStack));
    minstack->top = (struct ListNode*)malloc(sizeof(struct ListNode));
    minstack->top->next = NULL;
    minstack->count = 0;
    return minstack;
}

void minStackPush(MinStack* obj, int val) {
    /* allocate memory for new node, set value of node to be val */
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    
    /* set new node to top if new node is first node */ 
    if(obj->top == NULL){
        obj->top = new_node;
        new_node->next = NULL;
    }
	/* new node is not first node, insert new node on top of stack */
    else {
        new_node->next = obj->top;
        obj->top = new_node;
    }
    obj->count++;
}
/* function to pop from stack */
void minStackPop(MinStack* obj) { 
	/* have temp pointer point to top, move top pointer to next item on stack, free temp pointer */
    struct ListNode* temp = obj->top;
    obj->top = obj->top->next;
    free(temp);
    obj->count--;
}
/* function to get top value of stack */
int minStackTop(MinStack* obj) {
  return obj->top->val;
}

/* get minimum of stack, iterate through linkedlist and compare min value each time */
int minStackGetMin(MinStack* obj) {
    struct ListNode* current = obj->top->next;
    int min = obj->top->val;
    while(current != NULL) {
      if(current->next){
        if(min > current->val){
            min = current->val;
        }
      }
      current = current->next;
    }
    free(current);
    return min;
}
/* function to free all memory used */
void minStackFree(MinStack* obj) {
    struct ListNode* current = obj->top;
    while(current != NULL){
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
        obj->count--;
    }
    free(current);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
