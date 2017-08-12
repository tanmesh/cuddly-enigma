#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct node {
	int data;
	struct node* next;
}node;

void build(node** headRef) {
	int n;
	cout << "n\n";
	cin >> n;
	cout << "give data\n";
	int x;
	cin >> x;
	node* newNode=(node*)malloc(sizeof(node));
	newNode->data=x;
	*headRef=newNode;
	for(int i=1;i<n;++i){
		int x;
		cin >> x;
		node* newNode=(node*)malloc(sizeof(node));
		newNode->data=x;
		newNode->next=*headRef;
		*headRef=newNode;
	}
}

void print(node* head) {
	node* current=head;
	while(current != NULL){
		cout << current->data << " ";
		current=current->next;
	}
	cout << endl;
}

void reverse(node** head) {
	node* reverseHead=NULL;
	node* nextCurrent;
	node* current=*head;
	while(current != NULL) {
		nextCurrent=current->next;
		current->next=reverseHead;
		reverseHead=current;
		current=nextCurrent;
	}
	*head=reverseHead;
}

int main() {
	node* head = (node*)malloc(sizeof(node));
	build(&head);

	reverse(&head);

	print(head);

	return 0;
}