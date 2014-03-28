#include <stdio.h>
#include<stdlib.h>

struct edge
{
  int vertexIndex;
  int vertexWeight;
  struct edge *edgePtr;
}edge;

struct vertex
{
  int vertexKey;
  struct edge *edgePtr;
  struct vertex *vertexPtr;
}vertex;

struct vertex *start;
struct vertex *currvertex;
struct edge *curredge;

int main(int argc, char *argv[]){
  FILE *myPtr;
  int numNodes;
  int cw;

      
  numNodes =atoi(argv[2]); //from user argument ;
  printf("At the beginning");  
  if ( ( myPtr = fopen( argv[1], "r" ) ) == NULL )
    printf( "File could not be opened\n" );

    else
    {
      printf("beginning of else");
      int i;
      int j;    
       for (i=0; i<numNodes; i++)
	{
	  struct vertex *v = malloc(sizeof(vertex));
	  struct edge *e = malloc(sizeof(edge));
	  v->vertexKey= i;
	  v->edgePtr=NULL;
	  v->vertexPtr=NULL;
	  printf("The vertex Key is %d", v->vertexKey); 
	  if (start==NULL)
	    {
	      start = v;
	      currvertex = v;
	      printf("I made it here: if start==NULL");
	    }
	  else
	    {
	      currvertex->vertexPtr = v;
	      currvertex = v;
	      printf("I made it here: else if start doesnt equal NULL");
	    }
	   for (j=0; j<numNodes; j++)
	    {
	      if (!feof(argv[1])) 
		{
		  //  fscanf(myPtr,cw);
		  printf("Current Weight on edge within edge for loop: %d \n", cw);
		}
	      else 
		{
		  printf("Too few arguments");
		  fclose(myPtr);
		  
		};
	      
	      if (cw<=0) {
		printf("current weight was = to 0 or less");
	      }  //if edge weight is 0 or -1, no need to create new edge
	      else
		{
		  
		  e->vertexWeight = cw;
		  e->vertexIndex = v->vertexKey;
		  e->edgePtr = NULL;
		  printf("current weight = %d",cw);
		  
		}
	      
	      if (v->edgePtr == NULL)  //first edge for this vertex
		{
		  
		  v->edgePtr = e;
		  curredge = e;
		  printf("I made it here edgePtr == NULL");
		}
	      else
		{
		  curredge->edgePtr = e;
		  curredge = e;
		  printf("I made it here edgePtr didnt equal NULL");
		}
	      
	      
	    }
	}
    }
  
  fclose(myPtr);
  
}

  

}

