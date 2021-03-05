#include<iostream>
using namespace std;

class Node{             // class for linked list nodes
	public:
	int data;
	Node* next;
	};

void insert(int input,Node** head); // declaring functions
void repetition(Node* head);
void printlist(Node* list);
void sorting(Node* list);

int main()
{
	Node* head = new Node();        // making first node
	head = NULL;   
    
    int input,length;               //user input
    cout<<"length of list>>";
    cin>>length;
    for(int i{0}; i < length; i++)
    {
        cout<<"enter data >>>";
        cin>> input;
        insert(input,&head);
    }
    
    repetition(head);
    sorting(head);
    printlist(head);

}

void insert(int input,Node** head)    // function to insert nodes
{
	Node* new_node = new Node();
	Node* last = *head;	
	
	new_node->data = input;
	new_node->next = NULL;
	
	if(*head == NULL)
	{
		*head = new_node;
		return;
	}
	while(last->next != NULL)
	{
		last = last->next;	
	}
	last->next = new_node;
}

void del_node(Node* head) //HEAD IS THE NODE PRIOR TO ONE BEING DELETED
{
	
	Node* del = head -> next;
	head->next = del ->next; // deleting node
	delete del;              // freeing memory
}

void repetition(Node* head)// to get rid of all repetitions
{
    Node* check;            // function to check for repititions
    while(head->next != NULL)
    {
        check = head;
        
        while(check->next != NULL)  // loop to compare check
        {
            if(head->data == check->next->data)
            {
                del_node(check);    // deleting repeated node
            }
            else
            {
                check = check->next;
            }
        }
        if(head->next != NULL) // FOR REPETITION AT END
        {
            head = head->next;
            // if last node is deleted,next node would be null
            // head = NULL will cause errors in loop
        }
    }
}

void sorting(Node* list)    // function to sort list
{
    // taking every element and checking for smaller elements after it
    // if smaller element found,swap it with bigger element
    
    // list is starting element
    // head is selected element
    // check is all elements after head
    
    
    Node* head = list;  
    Node* check; 
    while(head->next != NULL)// transversing through the list
    {
        check = head; 
        
        while(check->next != NULL)// checking all elements after head  
        {
            if(head->data > check->next->data)
            {   
                // code to swap nodes without "temp"
                head->data += check->next->data;
                check->next->data = head->data - check->next->data;
                head->data -= check->next->data;
                head = list;
                break;
            }
            else
            {
                check = check->next;// moving to next element
            }
        }
        if(head->next != NULL and check->next == NULL) // FOR ELEMENT AT END
        {
            head = head->next;
            //for element at end,next element is NULL
            // if head = NULL, loop will have errors
        }
    }
}

int binary (int number) // convert integer to binary
{
    int count = 0;
    int factor = 1;
    while(number>0)
    {
        // double dabble method
        // AKA dividing number over and over by 2,the remainders(%) become the
        // digits of corrosponding binary number
        count = count + (int(number)%2)*factor;
        number = number/2;
        factor = factor*10;
    }
    return count;
}


void printlist(Node* list)
{
	if (list == NULL)
	{
		cout<<endl;
		return;
	}
	cout<<binary(list->data)<<"  ";
	printlist(list->next);
}
