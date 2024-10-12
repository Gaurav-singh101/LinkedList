#include<stdio.h>
#include<stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *next;
};

// Function to insert a new node at the beginning
void insertAtBeginning(struct node **head, int newData) {
    // Allocate memory for the new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    // Assign data to the new node
    newNode->data = newData;

    // Make the new node point to the current head
    newNode->next = *head;

    // Update the head to point to the new node
    *head = newNode;
}

// Function to print the linked list
void printList(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL, *temp, *newnode;
    int choice = 1;

    // Initial loop to add elements at the end
    while(choice == 1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    
        printf("Enter 1 if you want to add element and 0 to stop: ");
        scanf("%d", &choice);
    }

    // Option to insert elements at the beginning

        int data;
        printf("Enter data to insert at the beginning: ");
        scanf("%d", &data);

        // Insert the new data at the beginning
        insertAtBeginning(&head, data);



    // Print the linked list
    printf("Linked list: ");
    printList(head);

    return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////


// #include<stdio.h>
// #include<stdlib.h>

// // Define the structure of a node
// struct node {
//     int data;
//     struct node *next;
// };

// // Function to insert a new node at the beginning
// void insertAtBeginning(struct node **head, int newData) {
//     // Allocate memory for the new node
//     struct node *newNode = (struct node*)malloc(sizeof(struct node));

//     // Assign data to the new node
//     newNode->data = newData;

//     // Make the new node point to the current head
//     newNode->next = *head;

//     // Update the head to point to the new node
//     *head = newNode;
// }

// // Function to print the linked list
// void printList(struct node *head) {
//     struct node *temp = head;
//     while(temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     struct node *head = NULL, *temp, *newnode;
//     int choice = 1;

//     // Initial loop to add elements at the end
//     while(choice == 1) {
//         newnode = (struct node*)malloc(sizeof(struct node));
//         printf("Enter data: ");
//         scanf("%d", &newnode->data);
//         newnode->next = NULL;

//         if(head == NULL) {
//             head = temp = newnode;
//         } else {
//             temp->next = newnode;
//             temp = newnode;
//         }

//         printf("Enter 1 if you want to add element and 0 to stop: ");
//         scanf("%d", &choice);
//     }

//     // Option to insert elements at the beginning
//     // int x;
//     // printf("Enter 1 to insert element at the beginning: ");
//     // scanf("%d", &x);

//     // while(x == 1) {
//         int data;
//         printf("Enter data to insert at the beginning: ");
//         scanf("%d", &data);

//         // Insert the new data at the beginning
//         insertAtBeginning(&head, data);

//         // printf("Enter 1 to insert more elements at the beginning or 0 to stop: ");
//         // scanf("%d", &x);
//     // }

//     // Print the linked list
//     printf("Linked list: ");
//     printList(head);

//     return 0;
// }

