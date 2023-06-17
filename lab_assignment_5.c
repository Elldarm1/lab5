
#include <stdio.h>
#include <stdlib.h>
    typedef struct node
{
    char letter;
    struct node *next;
} node;
// Returns number of nodes in the linkedList.
int length(node *head)
{
    int count = 0;
    if(head == NULL) return 0;
    
    while(head != NULL){
        head = head->next;
        count++;
    }

    return count;
    
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char *toCString(node *head)
{
    node* temp = head;
    if(temp == NULL) return NULL;
    int len = length(head);
    char* result = (char*)malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        result[i] = temp->letter;
        temp = temp->next;
    }
    result[len] = '\0';
    return result;

}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c)
{
    node* new_node = malloc(sizeof(node));
    new_node->letter = c;
    new_node->next = NULL;
     
    node* temp = *pHead;

    if(*pHead == NULL){
        *pHead = new_node;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    
}
// deletes all nodes in the linkedList.
void deleteList(node **pHead)
{
    node* temp = *pHead;
    node* ptr;

    while(temp->next != NULL){
        ptr = temp->next;
        free(temp);
        temp = ptr;
    }
    *pHead = NULL;

}
int main(void)
{
    int i, strLen, numInputs;
    node *head = NULL;
    char *str;
    char c;
    FILE *inFile = fopen("input.txt", "r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}