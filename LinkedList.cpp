#include<iostream>

using namespace std;
class LinkedList
{
public:
	LinkedList* head;
	LinkedList();
	~LinkedList();
	void insertAtBeg(int data);
	void insertAtEnd(int data);
	void insertAtPos(int data, int n);
	void deleteANode(int pos);
	void deleteAll();
	void display();
	void reverseList();
	void reversePrint(LinkedList* current);
private:
	int data;
	LinkedList* next;
};
LinkedList::LinkedList()
{
}
LinkedList::~LinkedList()
{
}
void LinkedList::insertAtBeg(int data) {
		LinkedList* root = new LinkedList();
		root->data = data;
		root->next = head;
		head = root;
}
void LinkedList::insertAtEnd(int data) {
	LinkedList* root = new LinkedList();
	root->data = data;
	root->next = NULL;
	LinkedList* temp = head;
	while (temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = root;
}
void LinkedList::insertAtPos(int data, int n) 
{
	LinkedList* temp = head;
	LinkedList* newList = new LinkedList();
	for (int i = 0; i < n - 2; i++) {
		if (temp->next !=NULL)
		{
			temp = temp->next;
		}
		else
		{
			cout << "Error:Invalid Position";
			return;
		}
	}
	newList->next = temp->next;
	temp->next = newList;
	newList->data = data;
}
void LinkedList::deleteANode(int pos) 
{
	LinkedList* temp = head;
	LinkedList* temp1 = NULL;
	for (int i = 0; i < pos - 2; i++) {
		if (temp->next != NULL)
		{
			temp = temp->next;
		}
		else
		{
			cout << "Error:Invalid Position";
			return;
		}
	}
	temp1 = temp->next; 
	temp->next = temp1->next;
	delete temp1;
}
void LinkedList::deleteAll() 
{
	LinkedList* current = head;
	LinkedList* next;
	while (current != NULL)
	{
		next = current->next;
		delete current;
		current = NULL;
		current = next;
	}
	head = NULL;
}
void LinkedList::display() 
{
	LinkedList* temp = head;
	while (temp !=NULL)
	{
		cout << "data is :" << temp->data << endl;
		temp = temp->next;
	}
}
void LinkedList::reverseList() 
{
	LinkedList* current = head;
	LinkedList* prev = NULL;
	LinkedList* next= NULL;
	while (current->next!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

// using recusrsive calls
void LinkedList::reversePrint(LinkedList* current)
{
	if (current != NULL)
	{
		reversePrint(current->next);
		cout << current->data << endl;
	}
}
int main() {
	LinkedList l;
	l.head = NULL;
	l.insertAtBeg(10); 
	l.insertAtBeg(5);
	l.insertAtBeg(7);
	l.insertAtBeg(9);
	l.insertAtEnd(6);
	l.insertAtPos(4,3);
	l.deleteANode(2);
	l.display();
	l.reverseList();
	cout << "Reverse List is:" << endl;
	l.display();
	cout << "Reverse printed List is:" << endl;
	l.reversePrint(l.head);
	l.deleteAll();
	l.display();
	system("pause");
	return 0;
}