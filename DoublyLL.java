
// Doubly linear Linked List in JAVA

class Node
{
	public int data;
	public Node next;
	public Node prev;
}

class DoublyLinear
{
	private Node first;
	private int size;
	
	public DoublyLinear()
	{
		this.first=null;
		this.size=0;
	}
	
	public void InsertFirst(int no)
	{
		Node newn=null;
	    newn = new Node();
		
		newn.next=null;
		newn.prev=null;
		newn.data=no;
		
		if(size == 0)
		{
			newn=first;
		}
		else
		{
			newn.next=first;
			first.prev=newn;
			newn=first;
		}
		this.size++;
	}
	
	
	/*public void InsertLast(int no)
	{
		Node newn = new Node();
		
		newn.next=null;
		newn.prev=null;
		newn.data=no;
		
		if(size == 0)
		{
			newn=first;
		}
		else
		{
			Node temp = first;
			
			while(temp.next != null)
			{
				temp=temp.next;
			}
			temp.next=newn;
			newn.prev=temp;
		}
		this.size++;
	}*/
	
	public void Display()
	{
		Node temp = first;
		
		while(temp != null)
		{
			System.out.print("|"+temp.data+"|-> ");
			temp=temp.next;
		}
		System.out.println("null");
	}
	
	public int Count()
	{
		return this.size;
	}
	
}

class DoublyLL
{
	public static void main(String args[])
	{
		DoublyLinear obj = new DoublyLinear();
		
		obj.InsertFirst(51);
		obj.InsertFirst(21);
		obj.InsertFirst(11);
		
		obj.Display();
		
		System.out.println("Elements are:"+obj.Count());
	}
}