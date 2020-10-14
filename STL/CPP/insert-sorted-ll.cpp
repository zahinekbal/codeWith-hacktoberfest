//struct Node
// {
//     int data;
//     struct Node *next;
// }

Node *sortedInsert(struct Node* head, int data) {
    // Code here
    Node* temp = new Node(data);
    if(head == NULL)
        return temp;
    
    Node* temp2 = head;
    Node* parent = head;
    while( temp2->data < data ){
        parent = temp2;
        temp2 = temp2->next;
        if(temp2 == NULL)
            break;
    }
    
    if(temp2 == head){
        temp->next = temp2;
        head = temp;
    }
    else{
        temp->next = temp2;
        parent->next= temp;
    }
    return head;
}