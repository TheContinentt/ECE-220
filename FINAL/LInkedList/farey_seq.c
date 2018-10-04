#include <stdio.h>
#include <stdlib.h>
#include "farey_seq.h"

int main()
{
	int n;
	printf("Please enter n: ");
	scanf("%d", &n);
	node * head;
	head = farey_seq(n);
	if(head == NULL)
	{
		printf("The linked list is empty");
	}
	print_list(head, n);
	delete_list(head);
}

node * farey_seq(int n)
{
	int i = 1;
	node * current = (node *)malloc(sizeof(node));
	node * previous = (node *)malloc(sizeof(node));
	node * head = (node *)malloc(sizeof(node));
	node * end = (node *)malloc(sizeof(node));
	head->next = end;
	head->numerator = 0;
	head->denominator = 1;
	end->numerator = 1;
	end->denominator = 1;
	end->next = NULL;
	current->numerator = 1;
	current->denominator = 1;
	previous = head;
	current = end;
	for (i = 1; i <= n - 1; i++)
	{
		while(current != NULL)
		{
		if(previous->denominator + current->denominator <= n)
		{
			node * temp = (node *)malloc(sizeof(node));
			temp->numerator = current->numerator + previous->numerator;
			temp->denominator = current->denominator + previous->denominator;
			previous->next = temp;
			temp->next = current;
			previous = current;
			current = current->next;
		}
		else
		{
			previous = current;
			current = current->next;
		}
		}
		current = head->next;
		previous = head;
	}
	/*if (current->denominator + previous->denominator > n)
	{
		return head;
	}
	else
	{
		while (current->denominator + previous->denominator <= n)
		{
			node * neww = (node *)malloc(sizeof(node));
			neww->numerator = current->numerator + previous->numerator;
			neww->denominator = current->denominator + previous->denominator;
			previous->next = NULL;
			previous->next = neww;
			neww->next = current;
			current = neww;
		}
	}*/
	//head = previous;
	return head;
	/*You code goes here*/
}

void print_list(node * head, int n)
{
	if(head == NULL)
		return;	
	printf("level %d: ", n);
	while(head != NULL)
	{
		printf("%d/%d ", head->numerator, head->denominator);
		head = head->next;
	}
	printf("\n");
}

void delete_list(node * head)
{
	node * temp;	
	while(head != NULL){
		temp = head->next;
		free(head);
		head = temp;
	}
}
