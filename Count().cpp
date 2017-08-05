#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node{
	int data;
	struct node* next;
}node;

void Push(node** headRef,int data){
	node* newNode=(node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

node* BuildOneTwoThree(){
	node* head =NULL;
	Push(&head,1);
	Push(&head,2);
	Push(&head,3);
	return head;
}

// void print(node* head){
// 	node* current = head;
// 	while(current != NULL){
// 		cout << current->data << " ";
// 		current = current->next;
// 	}
// 	cout << endl;
// }

int Count(struct node* head, int searchFor) {
	node* current = head;
	int cnt=0;
	while(current != NULL){
		if(current->data == searchFor)++cnt;
		current = current->next;
	}
	return cnt;
}

void CountTest() {
   node* myList = BuildOneTwoThree();      // build {1, 2, 3}
   int count = Count(myList, 2);    // returns 1 since there's 1 '2' in the list
   cout << count << "\n";
}

int main(){
	node* head =BuildOneTwoThree();
	// print(head);
	CountTest();
	return 0;
}













