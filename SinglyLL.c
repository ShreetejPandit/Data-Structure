

/* Singly Linked List

InsertFirst(),InsertLast(),InsertAtPos(),
DeleteFirst(),DeleteLast(),DeleteAtPos(),
Display(),Count(). */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no) //Insert at first pos
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = no;
    newn->next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}
void InsertLast(PPNODE Head, int no) //Insert at Last Pos
{
	PNODE newn= NULL;
	PNODE temp= *Head;
	
	newn= (PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp= temp->next;
		}
		temp->next=newn;
	}
}
void DeleteFirst(PPNODE Head) // Delete first node
{
	PNODE temp = *Head;
	
	if(*Head != NULL)
	{
		*Head= (*Head)->next;
		free(temp);
	}
}
void DeleteLast(PPNODE Head) // Delete Last node
{
	PNODE temp = *Head;
	
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp= temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}
void Display(PNODE Head) //Display Linked List
{
    while (Head != NULL)
    {
        printf("|%d| -> ",Head->data);
        Head = Head -> next;
    }
    
    printf(" NULL\n");
}
int Count(PNODE Head) // Count data in LL
{
	int iCnt=0;
	int i=0;
	
	while(Head != NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}
void InsertAtPos(PPNODE Head, int no, int pos) //Insert At desired Position
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	int iSize=0;
	int i=0;
	
	iSize=Count(*Head);
	
	if((pos<1) || (pos >iSize+1)) //Filter
	{
		return;
		printf("Invalid Position...!");
	}
	
	if(pos == 1)  //Insert at first
	{
		InsertFirst(Head,no);
	}
	else if(pos == iSize+1) //Insert at Last
	{
		InsertLast(Head,no);
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));
		
		newn->data=no;
		newn->next=NULL;
		
		for(i=0; i< pos-1; i++)
		{
			temp= temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}
void DeleteAtPos(PPNODE Head, int pos) // Delete from desired Position
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	PNODE targeted=NULL;
	int iSize=0;
	int i=0;
	
	iSize=Count(*Head);
	
	if((pos<1) || (pos >iSize)) //Filter
	{
		return;
		printf("Invalid Position...!");
	}
	
	if(pos == 1)  //Delete at first
	{
		DeleteFirst(Head);
	}
	else if(pos == iSize) //Delete at Last
	{
		DeleteLast(Head);
	}
	else
	{
		for(i=0; i< pos-1; i++)
		{
			temp= temp->next;
		}
		targeted=temp->next;
		temp->next=targeted->next;
		free(targeted);
	}
}
int main()
{
	PNODE first = NULL;
	int iChoice=1, value=0, ipos=0, iRet=0;
	
	while(iChoice != 0)
	{
		printf("_____________________________________________________\n");
		printf("1: Insert at first position\n");
		printf("2: Insert at last Position\n");
		printf("3: Insert At Desired Position\n");
		printf("4: Delete at first position\n");
		printf("5: Delete at last position\n");
		printf("6: Delete At Desired Position\n");
		printf("7: Display Linked List\n");
		printf("8: Count data from Linked List\n");
		printf("0: Exit\n");
		printf("_____________________________________________________\n");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:
			    printf("Enter the Number:\n");
				scanf("%d",&value);
				InsertFirst(&first,value);
				break;
			case 2:
			    printf("Enter the Number:\n");
				scanf("%d",&value);
				InsertLast(&first,value);
				break;
			case 3:
			    printf("Enter the Number:\n");
				scanf("%d",&value);
				printf("Enter Position\n");
				scanf("%d",&ipos);
				InsertAtPos(&first,value,ipos);
				break;
			case 4:
				DeleteFirst(&first);
				break;
			case 5:
				DeleteLast(&first);
				break;
			case 6:
				printf("Enter Position\n");
				scanf("%d",&ipos);
			    DeleteAtPos(&first,ipos);
				break;
			case 7:
			    Display(first);
				break;
			case 8:
			    iRet=Count(first);
				printf("Number elements are: %d\n",iRet);
				break;
			case 0:
			    printf("Thank you for using appliation\n");
				break;
			default :
			    printf("Please Enter Proper Choice\n");
				break;
		}
		
	}
	return 0;
}

