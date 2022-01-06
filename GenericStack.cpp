
//////////////////////////////////////////////////////
//Program: Stack using Linked List
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
class Stack     // Singly Linear Linked List
{
private:
    node<T>* first;
    int size;
    
public:
    Stack();
	void push(T);
	int pop();
	void Display();
	int Count();
};

///////////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T> :: Stack()
    {
        first = NULL;
        size = 0;
    }
    
	template<class T>
    void Stack<T> :: push(T no)   // InsertFirst()
    {
        node<T>* newn = new node<T>;
		node<T>* temp=first;
		
		newn->data=no;
		newn->next=NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		size++;
    }
    
	template<class T>
    int Stack<T> :: pop()   // DeleteFirst()
    {
       node<T>* temp=first;
		T iValue=0;
		if(temp == NULL)
		{
			cout<<"Stack is empty..!"<<endl;
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
    void Stack<T> :: Display()
    {
		node<T>* temp=first;
		
		for(int i=1; i <= size; i++)
		{
			cout<<"|"<<temp->data<<"| "<<"\n";
			temp=temp->next;
		}
		cout<<"\n";
	}
    
	template<class T>
    int Stack<T> :: Count()
    {
        return size;
    }

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack<int> obj;
	int iret=0;
    
    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);
    
	cout<<"Elements of Stack :"<<"\n";
    obj.Display();
	iret=obj.Count();
	cout<<"Size of Stack is: "<<iret<<"\n\n";
    
    iret = obj.pop();       
    cout<<"Poped Element: "<<"|"<<iret<<"|"<<"\n\n";                    
    
    cout<<"Elements of Stack :"<<"\n";
	obj.Display();          
    iret = obj.Count();     
    
    cout<<"Size of Stack is : "<<iret<<"\n";        
    
    return 0;
}
