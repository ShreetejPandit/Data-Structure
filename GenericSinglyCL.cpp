

//////////////////////////////////////////////////////
//Program: Singly Circular Linked List
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
class SinglyCL
{
private:
    node<T>* first;
	node<T>* last;
	int size;
	
public:
    SinglyCL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
    
};

/////////////////////////////////////////////////////////////////////////////////////////

    template<class T>
    SinglyCL<T> :: SinglyCL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}
	
	template<class T>
	void SinglyCL<T> :: InsertFirst(T no)
	{
		node<T>* newn = new node<T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if((first == NULL) && (last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		last->next=first;
		size++;
	}
	
	template<class T>
	void SinglyCL<T> :: InsertLast(T no)
	{
		node<T>* newn = new node<T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if((first == NULL) && (last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			last->next=newn;
		    last=newn;
		}
		last->next=first;
		size++;
	}
	
	template<class T>
	void SinglyCL<T> :: InsertAtPos(T no, int ipos)
	{
		if((ipos < 1) || (ipos > (size+1)))
		{
			return;
		}
		if(ipos == 0)
		{
			InsertFirst(no);
		}
		if(ipos == size+1)
		{
			InsertLast(no);
		}
		else
		{
            node<T>* newn = new node<T>;
            
			newn->data=no;
			newn->next=NULL;
			
			node<T>* temp=first;
			
			for(int i=1; i < ipos-1; i++)
			{
				temp=temp->next;
			}
			
			newn->next=temp->next;
			temp->next=newn;
			
			size++;
		}
	}
	
	template<class T>
	void SinglyCL<T> :: DeleteFirst()
	{
		if(size == 0)
		{
			return;
		}
		else if(first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			first=first->next;
			delete last->next;
			last->next=first;
		}
		size--;
	}
	
	template<class T>
	void SinglyCL<T> :: DeleteLast()
	{
		node<T>* temp=first;
		
		if(size == 0)
		{
			return;
		}
		else if(first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			while(temp->next != last)
			{
				temp=temp->next;
			}
			delete last;
			last=temp;
			last->next=first;
		}
		size--;
	}
	
	template<class T>
	void SinglyCL<T> :: DeleteAtPos(int ipos)
	{
		if((ipos < 1) || (ipos > size))
		{
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
			
			node<T>* targeted = temp->next;
			
			temp->next=targeted->next;
			delete targeted;
			
			size--;
		}
	}
	
	template<class T>
	void SinglyCL<T> :: Display()
	{
		node<T>* temp=first;
		
		if((first == NULL) && (last == NULL))
		{
			return;
		}
		
		do
		{
			cout<<"|"<<temp->data<<"| ->";
			temp=temp->next;
		}while(temp != last->next);
		
		cout<<"NULL"<<"\n";
	}
	
	template<class T>
	int SinglyCL<T> :: Count()
	{
		
		return size;
	}

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	SinglyCL<int> obj;
	int iRet=0;
	
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	obj.InsertLast(101);
	
	obj.InsertAtPos(55,4);
	
	obj.Display();
	
	iRet=obj.Count();
	cout<<"Number of elements are:"<<iRet<<"\n";
	
	obj.DeleteAtPos(4);
	
	obj.DeleteFirst();
	obj.DeleteLast();
	
	obj.Display();
	
	iRet=obj.Count();
	cout<<"Number of elements are:"<<iRet<<"\n";
	
	return 0;
}