#include<stdio.h>
#include<stdlib.h>

// NODE STRUCTURE

struct Node
{
    int data;
    struct Node *Llink;
    struct Node *Rlink;
};

struct Node *header = NULL;

// CREATE NEW NODE


struct Node *CreateNode(int data)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->Llink = NULL;
    newnode->Rlink = NULL;
    return newnode;
}

// INSERT AT FRONT


void insertAtFront(int data)
{
    struct Node *newnode;
    newnode = CreateNode(data);

    if (header == NULL)
    {
        header = newnode;
    }
    else
    {    
        newnode->Rlink = header;
        header->Llink = newnode;
        header = newnode;
    }
}

// INSERT AT END


void insertAtEnd(int data)
{
    struct Node *ptr;
    struct Node *newnode;
    newnode = CreateNode(data);
    
    if (header == NULL)  
    {
        header = newnode; 
    }
    else
    {
        ptr = header;
        while (ptr->Rlink != NULL)  
        {
            ptr = ptr->Rlink;
        }
        ptr->Rlink = newnode;  
        newnode->Llink = ptr;  
    }
}

// INSERT AT ANY


void insertAtAny(int key, int data)
{
    struct Node *ptr = header;
    struct Node *newnode;
    
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->Rlink;
    }

    if (ptr == NULL)
    {
        printf("Key not found, insertion not possible\n");
        return;
    }

    newnode = CreateNode(data);
    newnode->Rlink = ptr->Rlink;
    if (ptr->Rlink != NULL)  
    {
        ptr->Rlink->Llink = newnode;
    }
    ptr->Rlink = newnode;
    newnode->Llink = ptr;
}

// DELETE AT FROND


void deleteAtFront()
{
    struct Node *ptr;
    if (header == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr = header;
        header = header->Rlink;
        if (header != NULL) 
        {
            header->Llink = NULL;
        }
        free(ptr);
        printf("Node deleted from the front\n");
    }
}

// DELETE AT END


void deleteAtEnd()
{
    if (header == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node *ptr;
        struct Node *ptr1;
        ptr = header;
        while (ptr->Rlink != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->Rlink;
        }
        ptr1->Rlink = NULL;
        free(ptr);
        printf("Node deleted from the end\n");
    }
}

// DELETE AT ANY


void deleteAtAny(int key)
{
    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *ptr = header;
    struct Node *Llink = NULL;

    while (ptr != NULL && ptr->data != key)
    {
        Llink = ptr;
        ptr = ptr->Rlink;
    }

    if (ptr == NULL)
    {
        printf("Key not found, deletion not possible\n");
        return;
    }

    if (Llink == NULL)  
    {
        header = ptr->Rlink;
    }
    else
    {
        Llink->Rlink = ptr->Rlink;
    }

    if (ptr->Rlink != NULL)
    {
        ptr->Rlink->Llink = Llink; 
    }

    free(ptr);
    printf("Node with key %d deleted\n", key);
}

// TRAVERSAL

 
void traversal()
{
    struct Node *ptr = header;
    if (ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->Rlink;
    }
    printf("\n");
}

// SEARCH


void searchNode(int key)
{
    struct Node *ptr = header;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {    
            printf("Key %d found in the list\n", key);
            return;
        }
        ptr = ptr->Rlink;
    }
    printf("Key %d not found in the list\n", key);
}

// MAIN FUNCTION


int main()
{
    int choice, data, key;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete at any position\n");
        printf("7. Traverse the list\n");
        printf("8. Search a node\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter key to insert after: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtAny(key, data);
                break;
            case 4:
                deleteAtFront();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteAtAny(key);
                break;
            case 7:
                traversal();
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &key);
                searchNode(key);
                break;
            case 9:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice !!! \n");
        }

    } while (choice != 9);  
    return 0;
}
