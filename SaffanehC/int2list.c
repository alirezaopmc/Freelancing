#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int value;
    node *next;
};

void int2list(int n, node **head);
void printChain(node **head);

int main()
{
    int n;
    scanf("%d", &n);

    node *head = (node *) malloc(sizeof(node));

    int2list(n, &head);
    // printf(":> %d\n", head->next->value);
    // printf(":> %d\n", head->next->next->value);
    printChain(&head);
}

void int2list(int n, node **head)
{
    node *a = (node *) malloc(sizeof(node));
    a->next = NULL;


    while (n) {
        node *b = (node *) malloc(sizeof(node));
        b->value = n % 10;
        b->next = a;
        // printf(":= %d\n", b->value);
        a = b;
        n /= 10;
    }

    (*head)->next = a;
}

void printChain(node **head)
{
    node *node = (*head)->next;
    while (node->next != NULL) {
        printf("-> %d ", node->value);
        node = node->next;
    }
}