#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;  // Pointer to the previous node
};

// Function to create and insert elements into the doubly linked list
void createElement(struct node **head) {
    int choice = 1;
    struct node *temp, *newnode;

    while (choice == 1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {  // Check for memory allocation failure
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if (*head == NULL) {
            *head = newnode;  // If the list is empty, make the new node the head
        } else {
            temp = *head;
            // Traverse to the end of the list
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;  // Append the new node to the end of the list
            newnode->prev = temp;  // Set the previous pointer of the new node
        }

        printf("For continue 1 or 0: ");
        scanf("%d", &choice);
    }
}

// Function to delete the last node in the doubly linked list
void DeleteatLast(struct node **head) {
    struct node *temp;

    if (*head == NULL) {  // Check if the list is empty
        printf("List is empty, nothing to delete.\n");
        return;
    }

    temp = *head;

    // If there's only one node in the list
    if (temp->next == NULL) {
        *head = NULL;  // Make the list empty
        free(temp);  // Free the memory of the single node
        printf("Last node deleted (only node).\n");
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;  // Update the second last node's next to NULL
    free(temp);  // Free the memory of the last node
    printf("Last node deleted.\n");
}

// Function to print the elements of the doubly linked list
void printNode(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) {
            printf(" <-> ");
        }
    }
    printf("\n");  // Print newline at the end of the list
}

int main() {
    struct node *head = NULL;
    int choice = 1;

    while (choice == 1) {
        int ch;
        printf("1 for Create Element:\n2 for Delete Last Node:\n3 for Print Node Element:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                createElement(&head);
                break;
            case 2:
                DeleteatLast(&head);
                break;
            case 3:
                printNode(head);
                break;
            default:
                printf("Please enter a valid choice.\n");
                break;
        }

        printf("\nFor continue press 1 or any other key to exit: ");
        scanf("%d", &choice);
    }

    // Free the allocated memory
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
