#include<iostream>
using namespace std;

class Node{ // node class for doubly linked list
	public:
	int data;
	Node* next;
	Node* prev;
	};
	
	/* Difference between singly linked and doubly linked list is that the node
	 * of a singly linked list points to the next node while the node in the
	 * doubly linked list points to both the next as well as previous node*/

void insert(int input,Node** head);
void printlist(Node* list);

int main()
{
	Node* head = new Node();
	head->data = 1;
	head->next = NULL;
	head->prev = NULL;
	insert(21,&head);
	insert(34,&head);
	insert(44,&head);
	insert(56,&head);
	insert(88,&head);
	printlist(head);
}

void insert(int input,Node** head)
{
	Node* new_node = new Node();    // new node declaration
	Node* last = *head;	
	
	while(last->next != NULL)
	{
		last = last->next;	        // finding last node
	}

	new_node->data = input;         // new node data
	new_node->next = NULL;
	new_node->prev = last;          // previous pointer
	
	last->next = new_node;          // adding new node to list
}

void printlist(Node* list)      // literally same as singly linked list
{
	if (list == NULL)
	{
		cout<<endl;
		return;
	}
	cout<<list->data<<"  ";
	printlist(list->next);
}
