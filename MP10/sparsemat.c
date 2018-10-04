#include "sparsemat.h"

#include <stdio.h>
#include <stdlib.h>
// Introduction: This function compute the multiplication and addition between two input files matrixes by using linked list.
// Thr first function is load_tuples which are set to load each nonzero value to a sequential list and each node contains one value
// and its coordinate. Then gv_tuples returns the value of a given coordinate in the list. Function set_tuples is used to set value when 
// the coordinate is given for a specific linked list. Then add_tuples and multiple_tuples are written for the computation between two input
// linked list pointers. The last destroy function are set to free all the memory and avoid memory leak.


//Comment: These are two helper function for sorting lists.
int compare_tuples(sp_tuples_node * a, sp_tuples_node * b);
void sort_tuples(sp_tuples ** mat_t);

// Comment: I set first as a pointer of struct sp_tuples. And thus first->tuples_head is a pointer of type sp_tuples_node.
// Then by using fscanf 
sp_tuples * load_tuples(char* input_file)
{
  FILE * file = fopen(input_file, "r");
  int row;
  int col;
  double value;
//first check if the file does not exist
  if(file == NULL)
    return NULL;
  sp_tuples *first = malloc(sizeof(sp_tuples));
  first->tuples_head = NULL;
  fscanf(file, "%d %d\n", &(first->m), &(first->n));
//this loop iterates untill the EOF
  while(feof(file) == 0)
  {
//start to scan each number into each part
    fscanf(file, "%d %d %lf\n", &row, &col, &value);
//call set_tuples to deal with the node
    set_tuples(first, row, col, value);
  }
  fclose(file);
  return first;
}


double gv_tuples(sp_tuples * mat_t,int row,int col)
{
  if (mat_t == NULL)
    return 0;
  sp_tuples_node * temp = mat_t->tuples_head;
  while (temp != NULL)// traverse the temp
  {
    if (temp->col == col && temp->row == row)
    {
      return temp->value;// return the value in this node
    }
    temp = temp->next;
  }
    return 0;
}



void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{
  if (mat_t == NULL)
    return;
  sp_tuples_node * temp = mat_t->tuples_head;
  sp_tuples_node * prev = mat_t->tuples_head;
  if (value == 0)
  {
//in this loop, delete the node with 0
    while (temp != NULL)
    {
      if (temp->row == row && temp->col == col)
        break;
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL)
      return;
    prev->next = temp->next;
    free(temp);
    temp = NULL;
    mat_t->nz--;
    return;
  }
  else
  {
//when we need to add a node or change the existed node
    if (temp == NULL)
    {
      sp_tuples_node * newone = (sp_tuples_node *)malloc(sizeof(sp_tuples_node));
      newone->row = row;
      newone->col = col;
      newone->value = value;
      newone->next = NULL;
      mat_t->tuples_head = newone;
      mat_t->nz++;
      return;
    }
    while (temp != NULL)
    {
//when we need to replace the old node
      if (temp->row == row && temp->col == col)
      {
        temp->value = value;
        return;
      }
      prev = temp;
      temp = temp->next;
    }
//outside the while node, it is time to add a now one
    sp_tuples_node * newone = (sp_tuples_node *)malloc(sizeof(sp_tuples_node));
    newone->row = row;
    newone->col = col;
    newone->value = value;
    newone->next = NULL;
    prev->next = newone;
    mat_t->nz++;
    sort_tuples(&mat_t);
    return;
    }
}



void save_tuples(char * file_name, sp_tuples * mat_t)
{
  if (mat_t == NULL)
    return;
  FILE * file;
  sp_tuples_node * temp = mat_t->tuples_head;
  file = fopen(file_name, "w");//open the file and ready to  write in it.
  fprintf(file, "%d %d\n", mat_t->m, mat_t->n);
  while (temp != NULL)// traverse the node to print them one by one
  {
    fprintf(file, "%d %d %lf\n", temp->row, temp->col, temp->value);
    temp = temp->next;
  }
  fclose(file);// close the file
  return;
}



sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB){
	
	
	if (matA->m != matB->m || matB->n != matA->n)
	{
		return NULL;//return NULL since two matrixes could not be added together.
	}
	else
	{
		int counter = 0;
		double value;
		sp_tuples * matC = (sp_tuples *)malloc(sizeof(sp_tuples_node));
		sp_tuples_node * a = matA->tuples_head;
		sp_tuples_node * b = matB->tuples_head;
		matC->tuples_head = NULL;
		matC->m = matA->m;
		matC->n = matA->n;
		while (a != NULL)// traverse the pointer a
		{
			value = gv_tuples(matC, a->row, a->col)+ a->value;
			set_tuples(matC, a->row, a->col, value);//set the node with the new value
			a = a->next;
		}
		while (b != NULL)//traverse the pointer b
		{
			value = gv_tuples(matC, b->row, b->col)+ b->value;
			set_tuples(matC, b->row, b->col, value);//set the node with the new value
			b = b->next;
		}
		sp_tuples_node * c = matC->tuples_head;
		while (c != NULL)//traverse the pointer c
		{
			counter++;
			c = c->next;
		}
		matC->nz = counter;//set the new natC->nz
//		sort_tuples(&matC);
		return matC;
	}
 
}



sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB){

  if (matA->n != matB->m)
  	return NULL;

    sp_tuples * matC = (sp_tuples *)malloc(sizeof(sp_tuples));//allocate dynamically memory for matC pointer
	matC->m = matA->m;
	matC->n = matB->n;
    matC->tuples_head = NULL;
	sp_tuples_node * ct;
 int  c, r;
  double value;
  int counter = 0;
	sp_tuples_node * aa = matA->tuples_head;
  sp_tuples_node * bb = matB->tuples_head;
    while (aa != NULL)// traverse the node in matA
    {
      c = aa->col;
      while (bb != NULL)// traverse the node in matB
      {
        r = bb->row;
        if (r == c)
        {
          value = gv_tuples(matC, aa->row, bb->col)+ (aa->value) * (bb->value);// set the value in the node as the sum of its initial value and value in matB node
	  set_tuples(matC, aa->row, bb->col, value);
        }
        bb = bb->next;
      }
	bb = matB->tuples_head;//reset the nodeB pointer to its head.
      aa = aa->next;
    }
    ct = matC->tuples_head;
    while (ct != NULL)//traverse the matC to count the number of nz.
      {
        counter++;
        ct = ct->next;
      }
      matC->nz = counter;//set counter to matC->nz
//	sort_tuples(&matC);
    return matC;
}



void destroy_tuples(sp_tuples * mat_t){
  if (mat_t != NULL)//traverse mat_t
  {
    sp_tuples_node * temp = mat_t->tuples_head;
    sp_tuples_node * tnext = NULL;
    while(temp != NULL)
    {
      tnext = temp->next; 
      free(temp);//free each passed node
      temp = tnext;
    }
    free(mat_t);//free the sp_tuples pointer.
    return;
  }
  return;
}

//return 0 if a should stand before b
//return 1 if a should stand after b
int compare_tuples(sp_tuples_node * a, sp_tuples_node * b){
  if (a->row < b->row)
    return 0;
  else if (a->row == b->row && a->col < b->col)//a is less than b, so return 0
    return 0;
  return 1;
}

//the helper function for the sort part
void sort_tuples(sp_tuples ** mat_t){
  sp_tuples_node * temp = (*mat_t)->tuples_head;
  if (temp->next == NULL)
    return;// return NULL if it is NULL
  int counter = 1;
  sp_tuples_node * tnext = (*mat_t)->tuples_head->next;
  sp_tuples_node * prev = (*mat_t)->tuples_head;
  while(counter != 0)// end when no change happens
  {
    counter = 0;
    prev = (*mat_t)->tuples_head;
    tnext = (*mat_t)->tuples_head->next;
    temp = (*mat_t)->tuples_head;
    while(tnext != NULL)//traverse the linked list of sp_tuples_node
    {
      if (compare_tuples(temp,tnext) == 0)//call compare function to determine whether temp is larger than the next.
      {
        prev = temp;
        temp = tnext;
        tnext = tnext->next;
        continue;
      }
      else
      {
        if (temp == (*mat_t)->tuples_head)//switch the position
        {
          (*mat_t)->tuples_head = tnext;
          temp->next = tnext->next;
          tnext->next = temp;
        }
        else
        {
          prev->next = tnext;
          temp->next = tnext->next;
          tnext->next = temp;
        }
        prev = temp;
        temp = tnext;
        tnext = tnext->next;
        counter++;
      }
    }
  }
  return;
}
