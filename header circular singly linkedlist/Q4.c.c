/*
Shradhey Pathak
20198111
IT 3B
HEADER CIRCULAR SINGLY LINKED LIST
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int menu();
struct Node* createNode(int data);
void insertAtStart(int data);
void insertAtEnd(int data);
void insertBefore_x(int x);
void insertAfter_x(int x);
void deleteFirstElement();
void displayList();
void deleteLastElement();
void delete_x(int x);
void nodeCount();

struct Node* head = NULL;
struct Node* last = NULL;

int main(){
    printf("HEADER CIRCULAR SINGLY LINKED LIST\n");
    while(1){
        int choice = menu();
        int n;
        switch (choice)
        {
        case 1:
            printf("Enter an element : ");
            scanf("%d", &n);
            insertAtStart(n);
            break;
        case 2:
            printf("Enter an element : ");
            scanf("%d", &n);
            insertAtEnd(n);
            break;
        case 3:
            printf("Enter x : ");
            scanf("%d", &n);
            insertBefore_x(n);
            break;
        case 4:
            printf("Enter x : ");
            scanf("%d", &n);
            insertAfter_x(n);
            break;
        case 5:
            deleteFirstElement();
            break;
        case 6:
            deleteLastElement();
            break;
        case 7:
            printf("Enter x : ");
            scanf("%d", &n);
            delete_x(n);
            break;
        case 8:
            displayList();
            break;
        case 9:
            nodeCount();
            break;
        case 10:
            exit(0);
        default:
            printf("Enter a valid choice\n");
        }
    }
}

int menu(){
    printf("\nChoose an option\n");
    printf("1. Insert At Start\t2. Insert At End\t3. Insert before x\t4. Insert after x\t5. Delete First Element\n6. Delete last element\t7. Delete x\t8. Display list\t9. Node Count\t10. Exit\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void insertAtStart(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        struct Node* headerNode = createNode(0);
        head = headerNode;
    }
    newNode -> next = head -> next;
    head -> next = newNode;
    if(newNode -> next == NULL)
        last = newNode;
    last -> next = head;
    head -> data++;
    return;
}

void insertAtEnd(int data){
    if(head == NULL || head -> next == NULL){
        insertAtStart(data);
        return;
    }
    struct Node* newNode = createNode(data);
    last -> next = newNode;
    last = newNode;
    last -> next = head;
    head -> data++;
    return;
}

void insertBefore_x(int x){
    if(head == NULL || head -> next == NULL){
        printf("List is Empty.\n");
        return;
    }
    if(head -> next -> data == x){
        printf("Enter an element to insert : ");
        int data;
        scanf("%d", &data);
        insertAtStart(data);
        return;
    }    
    struct Node* temp = head -> next;
    while(temp -> next != head){
        if(temp -> next -> data == x){
            printf("Enter an element to insert : ");
            int data;
            scanf("%d", &data);
            struct Node* newNode = createNode(data);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            head -> data++;
            return;
        }
        temp = temp -> next;
    }
    printf("No such element exists.\n");
    return;
}

void insertAfter_x(int x){
    if(head == NULL || head -> next == NULL){
        printf("List is Empty.\n");
        return;
    }
    struct Node* temp = head -> next;
    while(temp != head){
        if(temp -> data == x){
            printf("Enter an element to insert : ");
            int data;
            scanf("%d", &data);
            if(temp == last){
                insertAtEnd(data);
                return;
            }
            struct Node* newNode = createNode(data);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            head -> data++;
            return;
        }
        temp = temp -> next;
    }
    printf("No such element exists.\n");
    return;
}

void deleteFirstElement(){
    if(head == NULL || head -> next == NULL){
        printf("List is Empty.\n");
        return;
    }
    struct Node* temp = head -> next;
    head -> next = head -> next -> next;
    free(temp);
    if(head -> next == NULL)
        last = NULL;
    head -> data--;
    return;
}

void deleteLastElement(){
     if(head == NULL || head -> next == NULL){
        printf("List is Empty.\n");
        return;
    }
    if(head -> next -> next == head){
        deleteFirstElement();
        return;
    }
    struct Node* temp = head -> next;
    while (temp -> next -> next != head)
        temp = temp -> next;
    struct Node* temp1 = temp -> next;
    last = temp;
    last -> next = head;
    free(temp1);
    head -> data--;
    return;
}

void delete_x(int x){
    if(head == NULL || head -> next == NULL){
        printf("List is Empty.\n");
        return;
    }
    if(head -> next -> data == x){
        deleteFirstElement();
        return;
    }
    struct Node* temp = head -> next;
    while (temp -> next != head)
    {
        if(temp -> next -> data == x){
            if(temp -> next == last){
                deleteLastElement();
                return;
            }
            struct Node* temp1 = temp -> next;
            temp -> next = temp -> next -> next;
            free(temp1);
            head -> data--;
            return;
        }
        temp = temp -> next;
    }
    printf("No such element exists.\n");
    return;
}

void displayList(){
    if(head == NULL || head -> next == NULL){
        printf("List is Empty.\n");
        return;
    }
    struct Node* temp = head -> next;
    while(temp != head){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    return;
}

void nodeCount(){
    if(head == NULL){
        printf("No List exists.\n");
        return;
    }
    printf("Total Nodes = %d", head -> data);
    return;
}

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
