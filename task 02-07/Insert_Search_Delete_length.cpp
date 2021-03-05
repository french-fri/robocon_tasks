#include<iostream>
using namespace std;

class Node{       // class for linked list nodes
	public:
	int data;
	Node* next;
	};

void insert(int input,Node** head);  // function declaration
void printlist(Node* list);
void del_node(int data,Node** head);


int search(int check,Node* head,int count = 0)  // TO SEARCH ELEMENTS
{
	if(head->data == check)                 // condition to end recursion
	{
		return count;
	}	
	if(head->next == NULL)                  // if reaches end of list
	{
		return -1;	                        // element not found
	}
	search(check,head->next,count+1);       // calling itself
}

int len_list(Node* head,int len = 0)            // TO FIND LENGTH OF LIST
{
	len++;                                  // counting elements
	if (head->next == NULL)                 // reached end of list
	{
		return len;                         // returning length
	}
	return len_list(head->next,len);        // returning itself
}

int main()
{
	Node* head = new Node();  // new node declaration
	head = NULL;
	while(1)                  // menu loop
	{
		unsigned int x;       // int for option selection
		int input;
		cout<<"1. Insert"<<endl<<"2. Search"<<endl
		<<"3. Delete"<<endl<<"4. Length"<<endl;
		cin>> x;
		switch(x)             // switch statement for menu
		{
		case 1:               // input new node
		cout<<"enter data >>>";
		cin>> input;
		insert(input,&head);
		break;
	
		case 2:               // search a node
		cout<<"enter data >>>";
		cin>> input;
		int element_pos;
		element_pos=search(input,head);
		if (element_pos > 0)  // search returns -1 if element not found
		{
		cout<<input<<" is element number "<<element_pos<<endl;	
		}else{
		cout<<"ELEMENT NOT PRESENT"<<endl;
		}
		break;
	
		case 3:               // delete a node
		cout<<"enter data >>>";
		cin>> input;
		del_node(input,&head);
		break;
	
		case 4:              // length of list
		cout<<"length of list is "<<len_list(head)<<endl;
		break;
	
		case 5:             // quit
		exit(1);
		break;
		
		default:            // invalid inputs
		cout<<"invalid input"<<endl;					
		}
	}
}

void insert(int input,Node** head)      // TO INSERT ELEMENTS
{
	Node* new_node = new Node();  // new node declaration
	Node* last = *head;	
	
	new_node->data = input;       // new node data
	new_node->next = NULL;
	
	if(*head == NULL)             // checking if head is NULL
	{
		*head = new_node;
		return;
	}
	while(last->next != NULL)     // finidng last node
	{
		last = last->next;	
	}
	last->next = new_node;        // adding new node to end
}

void printlist(Node* list)              // TO PRINT LISTS
{
	if (list == NULL)             // condition to end recursion
	{
		cout<<endl;
		return;
	}
	cout<<list->data<<"  ";       // just printing current element
	printlist(list->next);        // next recursion
}


void del_node(int data,Node** head)         // TO DELETE ELEMENT
{
	Node *target = *head;
	while(target->next->data != data)       // locating element
	{
		target = target-> next;	
	if(target->next == NULL)                // reached end of list
	{
	cout<<"ELEMENT NOT PRESENT"<<endl;      // element not found
	return;
		}
	}	
	
	Node* del = target -> next;             // removing node from list
	target ->next = target-> next ->next;
	delete del;                             // freeing memory of deleted node
}
