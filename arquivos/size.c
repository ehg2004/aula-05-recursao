/* */
#include "list.h"
int size (List *l)
{
    if(l==NULL)
        return(0);
    else
        return(1+size(l->next));
}

int maxElem (List *l)
{
    if(l->next==NULL)
        return (l->data);
    else
    {   
        int k = maxElem(l->next);
        if(l->data>=k)
            return(l->data);
        else
            return(k);
    }


}

int similar (List *A, List *B)
{
  if(A==NULL&&B==NULL)
    return 1;
  if(A==NULL&&B!=NULL||B==NULL&&A!=NULL)
    return 0;
  if(A->data!=B->data)
    return 0;
  else 
    return (similar(A->next,B->next));
}

List* copy (List *A)
{
  if(A==NULL)
    return NULL;
  else
  {
    List * B = (List*) malloc(1*sizeof(List));
    B->next=NULL;
    B->data=A->data;
    B->next=copy(A->next);
    return(B);
  }

}
List* intersection (List *A, List *B)
{
  if(A==NULL)
    return(NULL);
  else
  { //if(A==NULL&&B==NULL)
    if(A->data==B->data)
    { List * C = A;
      C->next=intersection(A->next,B->next);
      return(C);
    }
    else
    {
      List * C = intersection(A,B->next);
      if (C==NULL)
        return(intersection(A->next,B));
      else 
        return(intersection(A->next,B->next));
    }
    else if (B==NULL)
    {
      return(NULL);
    }
   
  }

}

int main () {
  int k;
  List *A = NULL;
  for (k = 0; k <= 14; k += 2) {
    A = insert_back (A, k);
  }
  printf("Lista = ");
  print (A);
  printf("\n");

  List *B = NULL;
  for (k = 1; k <= 9; k += 2) {
    B = insert_back (B, k);
  }




  printf("Lista = ");
  print (B);
  printf("\n");

  return 0;
}