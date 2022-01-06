//


// Selection sort (time Complexity n^2)
// for Increasing order

import java.util.*;

class Sorting
{
	public void SelectionSort(int arr[])
	{
		int i=0, j=0, minindex = 0;
		int size = arr.length;
		int temp=0;
		
		for(i=0; i<size; i++)
		{
			minindex=i;
			for(j=i; j<size; j++)
			{
				if(arr[minindex] > arr[j])
				{
					minindex = j;
				}
			}
			temp=arr[i];
			arr[i]=arr[minindex];
			arr[minindex]=temp;
		}
		
	}	
}

class Program261
{
	public static void main(String args[])
	{
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter the size of array");
		int size = sobj.nextInt();
		
		int arr[]= new int[size];
		
		System.out.println("Enter the elements");
		for(int i=0; i<arr.length; i++)
		{
			arr[i]=sobj.nextInt();
		}
		
		Sorting obj = new Sorting();
		
		obj.SelectionSort(arr);
		
		System.out.println("Data after Function call");
		for(int i=0; i<arr.length; i++)
		{
			System.out.println(arr[i]);
		}
	}

}