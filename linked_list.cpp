#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* next;
};

void print(struct node* head){
	struct node* tmp = head;
	while(tmp != NULL){
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout<<endl;
}
struct node* insert(struct node* head,int x){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=x;
	newNode->next=head;

	head=newNode;
	return head;
}

int main(){
	int n;
	struct node* head = NULL;
	cout << " give n" << endl;
	cin >> n;
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		head = insert(head,data);
	}
	print(head);

}