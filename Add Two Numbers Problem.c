#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* create(int value, struct ListNode* head) {
    struct ListNode* temp =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    temp->val = value;
    temp->next = head;

    return temp;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    int carry = 0;
    int step = 1;

    printf("\n===== TRACE START =====\n");
    while (l1 != NULL || l2 != NULL || carry != 0) {
        printf("\n--- STEP %d ---\n", step++);

        int sum = carry;
        printf("carry in = %d\n", carry);

        if (l1 != NULL) {
            printf("l1 value = %d\n", l1->val);
            sum += l1->val;
            l1 = l1->next;
        } else {
            printf("l1 value = NULL\n");
        }

        if (l2 != NULL) {
            printf("l2 value = %d\n", l2->val);
            sum += l2->val;
            l2 = l2->next;
        } else {
            printf("l2 value = NULL\n");
        }

        printf("sum = %d\n", sum);

        carry = sum / 10;
        int digit = sum % 10;

        printf("new digit = %d\n", digit);
        printf("new carry = %d\n", carry);

        struct ListNode* newNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = digit;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;

        printf("added node = %d\n", digit);
    }

    printf("\n===== TRACE END =====\n\n");
    return dummy.next;
}

void DisplayList(struct ListNode* head, char title[]) {
    struct ListNode* temp = head;

    printf("---- %s ----\n", title);

    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    struct ListNode* L1 = NULL;
    struct ListNode* L2 = NULL;

    L1 = create(1, L1);
    L1 = create(2, L1);
    L1 = create(3, L1);
    L1 = create(4, L1);
    DisplayList(L1, "LIST #1");
    
    L2 = create(6, L2);
    L2 = create(17, L2);
    L2 = create(2, L2);
    L2 = create(3, L2);
    DisplayList(L2, "LIST #2");
    
    struct ListNode* result = addTwoNumbers(L1, L2);
    DisplayList(result, "RESULT");

    return 0;
}