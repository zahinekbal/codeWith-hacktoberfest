// struct Node
// {
//     int data;
//     struct Node *next;
// }

struct Node* reverseList(struct Node *head)
{
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;
    
    if(curr == NULL || next == NULL)
        return head;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}