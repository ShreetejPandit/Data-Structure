//


// Bubble sort (time Complexity n^2)
// for Increasing order

import java.util.*;

class Sorting
{
	public void BubbleSort(int arr[])
	{
		int pass=0,j=0,temp=0;
		int size=arr.length;
		boolean flag=false;
		
		for(pass=0; pass<size; pass++)
		{
			flag = false;
			
			for(j=0; j<size-pass-1; j++)
			{
				if(arr[j] > arr[j+1])
				{
					flag=true;
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
			if(flag == false)
			{
				break;
			}
			
			System.out.println("Data After Pass:"+pass);
			for(int i=0; i<arr.length; i++)
			{
				System.out.print(arr[i]+" ");
			}
			System.out.println();
		}
	}
}

class Program258
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
		
		obj.BubbleSort(arr);
		
		System.out.println("Data after Function call");
		for(int i=0; i<arr.length; i++)
		{
			System.out.println(arr[i]);
		}
	}

}