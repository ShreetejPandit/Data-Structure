//


// Insertion sort (time Complexity n^2)
// for Increasing order

import java.util.*;

class Sorting
{
	public void InsertionSort(int arr[])
	{
		int i=0, j=0, key=0;
		int size=arr.length;
		
		for(i=1; i<size; i++)
		{
			key = arr[i];
			for(j= i-1; (j >= 0) && (arr[j] > key); j--)
			{
				arr[j+1] = arr[j];
			}
			arr[j+1]= key;
		}
		
	}	
}

class Program262
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
		
		obj.InsertionSort(arr);
		
		System.out.println("Data after Function call");
		for(int i=0; i<arr.length; i++)
		{
			System.out.println(arr[i]);
		}
	}

}