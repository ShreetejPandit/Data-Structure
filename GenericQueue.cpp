
// Queue using Singly Linear Linked List in CPP

#include<iostream>
using namespace std;

template<typename T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Queue     // Singly Linear Linked List
{
private:
    node<T>* first;
    int size;
    
public:
    Queue();
	void Enqueue(T);
	int Dequeue();
	void Display();
	int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T> :: Queue()
    {
        first = NULL;
        size = 0;
    }
    
	template<class T>
    void Queue<T> :: Enqueue(T no)   // InsertLast()
    {
       node<T>* newn=new node<T>;		
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
    int Queue<T> :: Dequeue()   // DeleteFirst()
    {
        node<T>* temp=first;
		T iValue=0;
		if(temp == NULL)
		{
			cout<<"Queue is empty..!"<<endl;
			return -1;
		}
		
		if(size == 1)
		{
			iValue=temp->data;
			delete temp;
			first=NULL;
		}
		else
		{
			first=temp->next;
			iValue=temp->data;
			delete temp;
		}
		size--;
		return iValue;
    }
    
	template<class T>
    void Queue<T> :: Display()
    {
		node<T>* temp=first;
		
		for(int i=1; i <= size; i++)
		{
			cout<<"|"<<temp->data<<"|-> ";
			temp=temp->next;
		}
		cout<<"NULL"<<"\n";
	}
    
	template<class T>
    int Queue<T> :: Count()
    {
        return size;
    }

////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Queue<int> obj;
	int iret=0;
    
    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);
	
	obj.Display();
	iret=obj.Count();
	cout<<"Size of queue is: "<<iret<<"\n\n";
    
    iret = obj.Dequeue();       
    cout<<"Removed Element: "<<"|"<<iret<<"|"<<"\n\n";                     
    
    obj.Display();          
    iret = obj.Count();     
    
    cout<<"Size of queue is : "<<iret<<"\n";        
    
    return 0;
}
