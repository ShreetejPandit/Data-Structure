
//////////////////////////////////////////////////////
//Program: Doubly Linear Linked List
//Input: 
//Output:
//Descreiption: 
//Author: Shreetej Pandit
//Date: 19/11/2021
/////////////////////////////////////////////////////


#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyLinearLL
{
private:
    int size;
    node <T>* first;

public:
    DoublyLinearLL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

/////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLinearLL<T>::DoublyLinearLL()
{
    size = 0;
    first = NULL;
}

template <class T>
void DoublyLinearLL<T>::Display()
{
    node <T>* temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLinearLL<T>::Count()
{
    return size;
}

template <class T>
void DoublyLinearLL<T>::InsertFirst(T no)
{
    node<T>* newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        newn->next->prev = newn;
        first = newn;
    }
    size++;
}

template <class T>
void DoublyLinearLL<T>::InsertLast(T no)
{
    node<T>* temp = first;
    node<T>* newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    size++;
}

template <class T>
void DoublyLinearLL<T>::InsertAtPos(T no, int ipos)
{
    node<T>* temp = first;
    if ((ipos < 1) || (ipos > size + 1))
    {
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        node<T>* newn = new node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size++;
    }
}

template <class T>
void DoublyLinearLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    size--;
}

template <class T>
void DoublyLinearLL<T>::DeleteLast()
{
    node<T>* temp = first;
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    size--;
}

template <class T>
void DoublyLinearLL<T>::DeleteAtPos(int ipos)
{
    node<T>* temp = first;
    if ((ipos < 1) || (ipos > size))
    {
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == size)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        size--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	DoublyLinearLL<int> obj;
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