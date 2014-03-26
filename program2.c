#include <stdio.h>

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

      
  numNodes = argv[2]; //from user argument ;
  
  if ( ( myPtr = fopen( argv[1], "r" ) ) == NULL )
    printf( "File could not be opened\n" );
  else
    {

      int i;    
      for (i=0; i<numNodes; i++)
	{
	  struct vertex *v = malloc(sizeof(vertex));
	  v->vertexKey= i;
	  v->edgePtr=NULL;
	  v->vertexPtr=NULL;
	  
	  if (start==NULL)
	    {
	      start = v;
	      currvertex = v;
	    }
	  else
	    {
	      currvertex->vertexPtr = v;
	      currvertex = v;
	      
	    }
	  for (j=0; j<numNodes; j++)
	    {
	      if (!feof(argv[1])) 
		{
		  fscanf(myPtr,cw);
		  printf("Current Weight on edge within edge for loop: %d \n", cw);
		}
	      else 
		{
		  printf("Too few arguments");
		  fclose(myPtr);
		 
		};
    
	      if (cw<=0) {}  //if edge weight is 0 or -1, no need to create new edge
	      else
		{
		  struct edge *e= //allocate space for edge
		    e->weight = ??
		    e->vertexIndex = ??;
		  e->edgePtr = null;
    
		}
    
    if (v->edgePtr == NULL)  //first edge for this vertex
    {
    
    v->edgePtr= ??
    curredge = ??
    }
    else
    {
    ??
    ??
    }
    
    
    }
    }
    }

  

}

