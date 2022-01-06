
//////////////////////////////////////////////////////
//Program: Singly Linear Linked List
//Input: 
//Output:
//Descreiption: 
//Author: Shreetej Pandit
//Date: 19/11/2021
/////////////////////////////////////////////////////

#include<iostream>

using namespace std;

template<typename T>
struct node
{
	T data;
	struct node *next;
};

template<class T>
class SinglyLL
{
private:
	node<T>* first;
	int size;
	
public:
    SinglyLL();
    void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};

///////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyLL<T> :: SinglyLL() // Constructor
	{
		first=NULL;
		size=0;
	}
	
	template<class T>
	void SinglyLL<T> :: InsertFirst(T no)
	{
		node<T>* newn=new node<T>;  // Memory allocation in CPP
		
		newn->data=no;
		newn->next=NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			newn->next=first;
			first = newn;
		}
		size++;
	}
	
	template<class T>
	void SinglyLL<T> :: InsertLast(T no)
	{
		node<T>* newn=new node<T>;		// Memory allocation in CPP
		node<T>* temp=first;

		newn->data=no;
		newn->next=NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next=newn;
		}
		size++;
	}
	
	template<class T>
	void SinglyLL<T> :: InsertAtPos(T no, int ipos)
	{
		if((ipos < 1) || (ipos > size+1)) //Filter
		{
			cout<<"Tnvalid Position...!"<<"\n";
			return;
		}
		
		if(ipos == 1) //Insert First
		{
			InsertFirst(ipos);
		}
		else if(ipos == size+1)  //Insert Last
		{
			InsertLast(ipos);
		}
		else                    // Insert in Between
		{
			node<T>* newn = new node<T>;
			node<T>* temp=first;
			
			newn->data=no;
			newn->next=NULL;
			
			for(int i=1; i < ipos-1; i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
		}
		size++;
	}
	
	template<class T>
	void SinglyLL<T> :: DeleteFirst()
	{
		node<T>* temp = first;
		if(first != NULL)
		{
			first= first->next;
			delete temp;
		}
		size--;
	}
	
	template<class T>
	void SinglyLL<T> :: DeleteLast()
	{
		node<T>* temp = first;
		
		if(first == NULL)
		{
			return;
		}
		else if(first->next == NULL)
		{
			delete first;
			first=NULL;
			size--;
		}
		else
		{
			while(temp->next->next != NULL)
			{
				temp=temp->next;
			}
			delete temp->next;
			temp->next=NULL;
			size--;
		}
	}
	
	template<class T>
	void SinglyLL<T> :: DeleteAtPos(int ipos)
	{
		if((ipos < 1) || (ipos > size))  //Filter
		{
			cout<<"Invalid Position...!";
			return;
		}
		
		if(ipos == 1)
		{
			DeleteFirst();
		}
		else if(ipos == size)
		{
			DeleteLast();
		}
		else
		{
			node<T>* temp=first;
			
			for(int i=1; i < ipos-1; i++)
			{
				temp=temp->next;
			}
			
            node<T>* targeted=temp->next;
			
			temp->next=targeted->next;
			delete targeted;
			size--;
		}
	}
	
	template<class T>
	void SinglyLL<T> :: Display()
	{
		node<T>* temp = first;
		
		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|->";
			temp= temp->next;
		}
		cout<<"NULL\n";
	}
	
	template<class T>
	int SinglyLL<T> :: Count()
	{
		return size;
	}

////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int iRet=0;
	
   	SinglyLL<int> obj;
	
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	obj.InsertLast(51);
	obj.InsertLast(101);
	
	obj.InsertAtPos(75,3);
	
	obj.Display();
	
    iRet=obj.Count();
	cout<<"Number of elements:"<<iRet<<"\n\n";
	
	obj.DeleteAtPos(3);
	
	obj.DeleteFirst();
	obj.DeleteLast();

	obj.Display();
	
    iRet=obj.Count();
	cout<<"Number of elements:"<<iRet<<"\n";
	
	return 0;
}