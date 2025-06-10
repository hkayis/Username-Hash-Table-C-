#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist_int.h"
#define hsize 10

void initArr(node_t* nodes[]) {

	for (int k = 0; k < hsize; k++) {
		nodes[k] = NULL;
	}
}
int code(char name[]) {
	int stlen=strlen(name);
	int sum = 0;
	for (int i = 0; i < stlen; i++) {
		sum += name[i];
	}
	return(sum);
}
int hashcode(int tot) {
	int hash = tot % hsize;
	return(hash);
}

node_t* searchuser(node_t* headp, char item[50]) {
	while (headp != NULL && strcmp(headp->data.name, item) != 0)
		headp = headp->next;
	return(headp);
}


void insertuser(node_t* headp[], LType item) {
	int total = code(item.name);
	printf("Total of ascii code is %d", total);
	int hash = hashcode(total);
	node_t* addr, * ptr;
	addr=searchuser(headp[hash], item.name);
	if (addr != NULL) {
		addr->data = item;
	}
	else {
		ptr = headp[hash];
		if (ptr == NULL) {
			headp[hash]=addBeginning(ptr, item);
		}
		else {
			while (ptr->next != NULL)
				ptr = ptr->next;
			addAfter(ptr, item);
		}
	}
	
	
}
node_t * removeuser(node_t* headp[], char name[]) {
	int total = code(name);
	LType dm;
	int hash = hashcode(total);
	node_t* addr = searchuser(headp[hash], name);
	if (addr != NULL) {
		if (strcmp(headp[hash]->data.name, name)==0) {
			headp[hash] = deleteFirst(headp[hash], &dm);
		}
		else {
			node_t* ptr = headp[hash];
			while (ptr != NULL && ptr->next != NULL) {
				if (strcmp(ptr->next->data.name, name) == 0)
					deleteAfter(ptr, &dm);
				else {
					ptr = ptr->next;
				}
			}
		}
	}
	else
		printf("The username is not in the node");
	
	return(headp[hash]);
}
void displayhash(node_t* hashtable[]) {
	node_t* dum;
	
	for (int k = 0; k < hsize; k++) {
		dum = hashtable[k];
		if (dum == NULL) {
			printf("Hastbale[%d] has no items\n", k);
		}
		else {
			printf("Hashtable[%d]", k);
			while (dum != NULL) {
				printf("%s  %s-> ", dum->data.name, dum->data.pass);
				dum = dum->next;
			}
			printf("NULL\n");
		}
	}

}
int main(void) {

	node_t* arr[hsize];
	LType item;
	initArr(arr);

	printf("1. Insert a supply into hash table\n2. Remove a supply from Hash table\n3. Display a hash table\n4.Exit");
	int ans;
	char name[50];
	int total;
	int hash;
	do {
		do {
			printf("\nEnter your choice");
			scanf("%d", &ans);
		} while (ans > 4 && ans < 1);
		switch (ans) {
		case 1:
			printf("Enter your username and password: ");
			scanf("%s  %s", item.name, item.pass);
			insertuser(arr, item);
			break;
		case 2:
			printf("Enter username to delete: ");
			
			scanf("%s", name);
			total = code(name);

			hash = hashcode(total);
			arr[hash] = removeuser(arr, name);
			break;
		case 3:
			displayhash(arr);
			break;
		case 4:
			return(0);

		}
	} while (ans != 4);


}