#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	};


//simple function to test if linked list is circular
bool circle_test(Node* head,Node* tail)
{
if (head->next == NULL)
{
 return false;    // circular linked list never has a NULL pointer at node
}
if (head->next == tail)
{
 return true;    // last node points at starting node,so if pointer is repeated
                // linked list would be circular
}
 circle_test(head->next,tail); // calling itself for recursion
}
