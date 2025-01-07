
#include <stdio.h>
#include <stdlib.h>
struct Node {

	int data;
	struct Node* next;

};
struct Node* head = NULL;
void insertAtFront(int new_data) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;

}
void insertAtEnd(int new_data) {

    	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	if (head == NULL) {

        	head = new_node;

   	 } else {

        	struct Node* temp = head;
               while (temp->next != NULL) {
			temp = temp->next;

	}

        temp->next = new_node;

    }

}

void insertAtPosition(int new_data, int position) {

    	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	if (position == 0) {
		new_node->next = head;
		head = new_node;
		return;

    }
	struct Node* temp = head;
	for (int i = 0; i < position - 1 && temp != NULL; i++) {
		temp = temp->next;

	}
	if (temp == NULL) {

		printf("Position out of bounds.\n");
		free(new_node);

	} else {

		new_node->next = temp->next;
		temp->next = new_node;

	}

}

void deleteAtFront() {

	if (head == NULL) {
		printf("The list is empty.\n");
		return;

	}
	struct Node* temp = head;
	head = head->next;
	free(temp);
	printf("Node deleted from the front.\n");

}

void deleteAtEnd() {

	if (head == NULL) {
		printf("The list is empty.\n");
		return;

	}
	struct Node* temp = head;
	struct Node* prev = NULL;
	if (head->next == NULL) {

		free(head);
		head = NULL;
		printf("Node deleted from the end.\n");
		return;

	}
	while (temp->next != NULL) {

		prev = temp;
		temp = temp->next;

	}
	prev->next = NULL;
	free(temp);
	printf("Node deleted from the end.\n");

}
void deleteAtPosition(int position) {

	if (head == NULL) {
		printf("The list is empty.\n");
		return;

	}
	struct Node* temp = head;
	struct Node* prev = NULL;
	if (position == 0) {

		head = head->next;
		free(temp);
		printf("Node deleted from position 0.\n");
		return;

	}

	for (int i = 0; i < position && temp != NULL; i++) {
		prev = temp;
		temp = temp->next;

	}

	if (temp == NULL) {
		printf("Position out of bounds.\n");

	} else {

		prev->next = temp->next;
		free(temp);
		printf("Node deleted from position %d.\n", position);

	}

}
void search(int value) {

	struct Node* temp = head;
	int position = 0;
	while (temp != NULL) {
		if (temp->data == value) {
			printf("Value %d found at position %d.\n", value, position);
			return;
		}
	temp = temp->next;
	position++;
	}
	printf("Value %d not found in the list.\n", value);

}

void displayList() {

	struct Node* temp = head;
	if (head == NULL) {
		printf("The list is empty.\n");
	} else {
		while (temp != NULL) {
			printf("%d -> ", temp->data);
			temp = temp->next;
	}
	printf("NULL\n");
}
}
int main() {
	int choice, data, position, value;
	while (1) {
	printf("\nMenu:\n");
	printf("1. Insert at the Front\n");
	printf("2. Insert at the End\n");
	printf("3. Insert at a Specific Position\n");
	printf("4. Delete from the Front\n");
	printf("5. Delete from the End\n");
	printf("6. Delete from a Specific Position\n");
	printf("7. Search for a Value\n");
	printf("8. Display the List\n");
	printf("9. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		printf("Enter the data to insert at the front: ");
		scanf("%d", &data);
		insertAtFront(data);
		break;
	case 2:
		printf("Enter the data to insert at the end: ");
		scanf("%d", &data);
		insertAtEnd(data);
		break;
	case 3:
		printf("Enter the data to insert: ");
		scanf("%d", &data);
		printf("Enter the position to insert at: ");
		scanf("%d", &position);
		insertAtPosition(data, position);
		break;
	case 4:
		deleteAtFront();
		break;
	case 5:
		deleteAtEnd();
		break;
	case 6:
		printf("Enter the position to delete from: ");
		scanf("%d", &position);
		deleteAtPosition(position);
		break;
	case 7:
		printf("Enter the value to search for: ");
		scanf("%d", &value);
		search(value);
		break;
	case 8:
		printf("The linked list is: ");
		displayList();
		break;
	case 9:
		printf("Exiting...\n");
		exit(0);
	default:
		printf("Invalid choice! Please try again.\n");
}
}
return 0;
}
