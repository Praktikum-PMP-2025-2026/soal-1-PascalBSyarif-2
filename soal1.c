#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    char *ID;
    int wait;
    struct queue *next;
}queue;

queue *makeNode(char *ID, int wait){
    queue *q = malloc(sizeof(queue));
    q->next = NULL;
    q->ID = strdup(ID);
    q->wait = wait;
}

queue *addNode(queue *head, char *ID, int wait){
    if (head == NULL)
    {
        return makeNode(ID, wait);
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
        queue *curr = head;
        printf("ORDER");
        while (curr->next != NULL)
        {
            printf(" %s", curr->ID);
            curr = curr->next;
        }
        printf(" %s\n", curr->ID);
        printf("WAIT %d", curr->wait);
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
        scanf("%s %d", buffer, &temp);
        head = addNode(head, buffer, temp);
    }
    printOutput(head);
}
