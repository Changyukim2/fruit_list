#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
	char name[100];
}
element;


typedef struct listnode {
	struct listnode* link;
	element data;
}listnode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

listnode* insert_first(listnode* head, element value) {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

listnode* insert(listnode* head, listnode* pre, element value) {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

listnode* delete_first(listnode* head) {
	listnode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;

}

listnode* delete(listnode* head, listnode* pre) {

	listnode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(listnode* head) {
	for (listnode* p = head; p != NULL; p = p->link)
		printf("%s -> ", p->data.name);
	printf("NULL\n");
}

listnode* search_fruit(listnode* head, char a[50]) {
	listnode* p = head;
	while (p != NULL) {
		if (strcmp(p->data.name, a) == 0)
			return p;
		p = p->link;
	}
	return NULL;
}



int main(void) {
    listnode* head = NULL;
    element data;

    strcpy(data.name, "Peach");
    head = insert_first(head, data);

    strcpy(data.name, "Banana");
    head = insert_first(head, data);

    strcpy(data.name, "Raspberry");
    head = insert_first(head, data);

    strcpy(data.name, "Guava");
    head = insert_first(head, data);

    strcpy(data.name, "Plum");
    head = insert_first(head, data);

    strcpy(data.name, "Cherry");
    head = insert_first(head, data);

    strcpy(data.name, "Grape");
    head = insert_first(head, data);

    strcpy(data.name, "Apple");
    head = insert_first(head, data);

    strcpy(data.name, "Orange");
    head = insert_first(head, data);

    strcpy(data.name, "Mango");
    head = insert_first(head, data);

    char fruit[50];
    int num;

    listnode* deleted_head = NULL;  

    while (1) {
        printf("*** MENU ****\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. PRINT the deleted list\n");
        printf("4. EXIT\n\n");
        printf("Enter the menu: ");
        scanf("%d", &num);

        switch (num) {
        case 1:
            printf("Fruit name to add: ");
            scanf("%s", fruit);
            if (search_fruit(head, fruit) != NULL) {
                printf("%s already exists.\n", fruit);
            }
            else {
                strcpy(data.name, fruit);
                head = insert_first(head, data);
                printf("%s has been added.\n\n", fruit);
                print_list(head);
            }
            break;
        case 2:
            printf("Fruit name to delete: ");
            scanf("%s", fruit);

            listnode* found = search_fruit(head, fruit);
            if (found != NULL) {
                head = delete(head, found);
                
                deleted_head = insert_first(deleted_head, found->data);
                printf("%s has been deleted.\n", fruit);
            }
            else {
                printf("%s not found in the list.\n", fruit);
            }
            print_list(head);
            break;
        case 3:
            printf("Deleted list of fruits:\n");
            print_list(deleted_head);  
            break;
        case 4:
            printf("Exit the program.\n");
            exit(0);
        default:
            printf("Invalid menu option.\n");
            break;
        }
    }
    return 0;
}













