#include<iostream>
using namespace std;

class Node{ // Making class for linked list nodes
	public:
	int data;
	Node* next;
	};

void insert(int input,Node** head); //declarations
void printlist(Node* list);

int main()
{
	Node* head = new Node();
	head->next = NULL;
    head->data = 32;
    insert(12,&head); // Appending random numbers
    insert(33,&head);
    insert(44,&head);
    insert(24,&head);
    printlist(head);  // printing values
}

void insert(int input,Node** head) // Function to append to list
{
	Node* new_node = new Node(); //make new node
	Node* last = *head;
	
	new_node->data = input; //new node data
	new_node->next = NULL;
	
	while(last->next != NULL) // go to last node
	{
		last = last->next;	
	}
	last->next = new_node; // add new node
}

void printlist(Node* list)
{
	if (list == NULL) // checking for list end
	{
		cout<<endl;
		return;
	}
	cout<<list->data<<"  "; //printing element
	printlist(list->next); //next element
}
