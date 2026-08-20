
#include <stdio.h>
#include <stdlib.h>

struct Block {
    int blockNo;
    struct Block *next;
};

int main() {
    int n;
    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    struct Block *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int b;
        printf("Enter block number %d: ", i + 1);
        scanf("%d", &b);

        struct Block *newBlock = (struct Block *)malloc(sizeof(struct Block));
        newBlock->blockNo = b;
        newBlock->next = NULL;

        if (head == NULL) {
            head = newBlock;
            tail = newBlock;
        } else {
            tail->next = newBlock;
            tail = newBlock;
        }
    }

    printf("\nLinked Allocation\n");
    printf("Directory entry -> First Block: %d, Last Block: %d\n",
           head->blockNo, tail->blockNo);

    printf("\nBlock chain: ");
    struct Block *temp = head;
    while (temp != NULL) {
        printf("[Block %d", temp->blockNo);
        if (temp->next != NULL)
            printf(" -> next: %d] -> ", temp->next->blockNo);
        else
            printf(" -> next: NULL] ");
        temp = temp->next;
    }
    printf("\n");


    temp = head;
    while (temp != NULL) {
        struct Block *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }

    return 0;
}
