#include "linkedList.h"


int DetectLoop(node *head)
{
  //Write code here.
	node *check = head;
	check = check->next;
	node *prev = head;
	while (check != NULL && check->next != NULL && prev != NULL)
	{
		if (check == prev)
		{
			return 1;
		}
		check = check->next->next;
		prev = prev->next;
	}
	return 0;
}

node *CopyList(node *head)
{
   //Insert Code here. You can change the return statement given.
   	node *copy = malloc(sizeof(node));
	node *current = head;
	node *check = copy;
	/*while (head != NULL)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
	printf("\n\n\n");*/
	head = current;
	while (head->next != NULL)
	{
		copy->value = head->value;
		copy->next = malloc(sizeof(node));
		head = head->next;
		copy = copy->next;
	}
	copy->value = head->value;
   	copy->next = NULL;
	head = current;
	copy = check;
	/*while (check != NULL)
	{
		printf("%d\n", check->value);
		check = check->next;
	}*/
	node *temp = copy;
	while (head != NULL)
	{
		if (head->arbit == NULL)
		{
			copy->arbit = NULL;
		}
		else
		{
			while (temp != NULL)
			{
				if (temp->value == head->arbit->value)
				{
					copy->arbit = temp;
					break;
				}
				temp = temp->next;
			}
			//temp = copy;
		}
   		head = head->next;
		copy = copy->next;
		temp = check;
	}
	copy = check;
	head = current;
	/*while (head != NULL)
	{
		if (head->arbit == NULL)
			printf("0\n");
		else
			printf("%d\n", head->arbit->value);
	head = head->next;
	}
	printf("\n\n");
	while (copy!= NULL)
	{
		//printf("0000\n");
		if (copy->arbit == NULL)
			printf("0\n");
		else
			printf("%d\n", copy->arbit->value);
		copy = copy->next;
		//printf("0000\n");
	}
	copy = check;*/
   return copy;
}
