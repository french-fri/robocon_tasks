#include<iostream>
using namespace std;

class Node{ // clase for linked list nodes
	public:
	int data;
	Node* next;
	};

void insert(int input,Node** head); // Function declarations

void printlist(Node* list,Node* last = NULL) //reverse print
{
	
    Node* head = list; // preserving first element
    
    if (list == last) // condition to end loop
	{
		return;
	}
    
    while(list->next != last) //finding element to print
	{
		list = list->next;
	}
    
	cout<<list->data<<"  "; //print element
	printlist(head,list);   // recalling itself for next element
}

int main()
{
	Node* head = new Node(); // node declaration
	head = NULL;   
    
    int input,length;        // taking user input
    cout<<"length of list>>";
    cin>>length;
    for(int i{0}; i < length; i++) //taking user inputs
    {
        cout<<"enter data >>>";
        cin>> input;
        insert(input,&head);
    }
    printlist(head); //printing backward

}

void insert(int input,Node** head) //list append function
{
	Node* new_node = new Node(); //new node
	Node* last = *head;	
	
	new_node->data = input; // new node data
	new_node->next = NULL;
	
	if(*head == NULL) // checking if head is null
	{
		*head = new_node;
		return;
	}
	while(last->next != NULL) // finding  end of list
	{
		last = last->next;	
	}
	last->next = new_node; // appending element
}
