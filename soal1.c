#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    char ID[20];
    int wait;
    struct queue *next;
}queue;

queue *makeNode(char *ID, int wait){
    queue *q = malloc(sizeof(queue));
    q->next = NULL;
    strcpy(q->ID, ID);
    q->wait = wait;
}

queue *addNode(queue *head, char *ID, int wait){
    if (head == NULL)
    {
        return makeNode(ID, 0);
    }
    else
    {
        queue *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        queue *new = makeNode(ID, wait);
        curr->next = new;
        new->wait = new->wait + curr->wait;
        return head;
    }
}

void printOutput(queue *head){
    if (head == NULL)
    {
        printf("ORDER\n"
                "WAIT\n");
    }
    else
    {
        int total = 0;
        queue *curr = head;
        printf("ORDER");
        while (curr->next != NULL)
        {
            printf(" %s", curr->ID);
            total = total + curr->wait;
            curr = curr->next;
        }
        printf(" %s\n", curr->ID);
        total = total + curr->wait;
        printf("WAIT %d", total);
    }
}

int main(){
    int n;
    int temp;
    char buffer[20];
    queue *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            scanf("%s", buffer);
            head = addNode(head, buffer, 0);
        }
        else
        {
            scanf("%d %s", &temp, buffer);
            head = addNode(head, buffer, temp);
        }
    }
    printOutput(head);
}
