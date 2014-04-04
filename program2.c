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

struct vertex *start = NULL;
struct vertex *currvertex;
struct edge *curredge;
struct vertex *t = NULL;
int INFINITY = 2147483647;

void displayPath(int prev[], int source, int destination, int dist[], int numNodes){
  printf("%d-%d-%d",prev[source],prev[destination],dist[numNodes]); 
}


int main(int argc, char *argv[]){
  FILE *myPtr;
  int numNodes;
  int cw;
  int source;
  int destination;
  int newDist;
  int k;
  int minDist;
  t = start;
  
  
  int comp[numNodes]; // = 0; //for all
  comp[numNodes] = 0;
  
  int dist[numNodes]; // = INFINITY; //for all
  dist[numNodes] = INFINITY;
  
  int prev[numNodes]; // = -1; //for all
  prev[numNodes] = -1;
  
  comp[source] = 1;
  dist[source] = 0;
  prev[source] = source;
  
  int curr = source;
  
  
  numNodes = atoi(argv[2]); //from user argument ;
  source = atoi(argv[3]);
  destination = atoi(argv[4]);
  
  printf("At the beginning\n");
  if ( ( myPtr = fopen( argv[1], "r" ) ) == NULL )
    printf( "File could not be opened\n" );
  
  else
    {
      printf("beginning of else\n");
      int i;
      int j;
      for (i=0; i<numNodes; i++)
	{
	  struct vertex *v = malloc(sizeof(vertex));
	  
	  v->vertexKey= i;
	  v->edgePtr=NULL;
	  v->vertexPtr=NULL;
	  printf("The vertex Key is %d\n", v->vertexKey);
	  if (start==NULL)
	    {
	      start = v;
	      currvertex = v; //Added ->vertexPtr
	      printf("I made it here: if start==NULL\n");
	    }
	  else
	    {
	      currvertex->vertexPtr = v;
	      currvertex = v; //Added ->vertexPtr
	      printf("I made it here: else if start doesnt equal NULL\n");
	    }
	  for (j=0; j<numNodes; j++)
	    {
	      if (!feof(myPtr))
		{
		  //fscanf(myPtr,cw);
		  fscanf(myPtr, "%d", &cw); //read the edge weight into variable cw
		  printf("Current Weight on edge within edge for loop: %d \n", cw);
		}
	      else
		{
		  printf("Too few arguments\n");
		  fclose(myPtr);
		  
		}
	      
	      if (cw<=0) {
		printf("current weight was = to 0 or less\n");
	      }  //if edge weight is 0 or -1, no need to create new edge
	      else
		{
		  struct edge *e = malloc(sizeof(edge));
		  e->vertexWeight = cw;
		  e->vertexIndex = v->vertexKey;
		  e->edgePtr = NULL;
		  printf("current weight = %d\n",cw);
		  
		  if (v->edgePtr == NULL)  //first edge for this vertex
		    {
		      
		      v->edgePtr = e;
		      curredge = e; //added ->edgePtr
		      printf("I made it here edgePtr == NULL\n");
		    }
		  else
		    {
		      curredge->edgePtr = e;
		      curredge = e; //added ->edgePtr
		      printf("I made it here edgePtr didnt equal NULL\n");
		    }
		  
		}
	      
	      
	      
	      
	    }
	}
    }
  

  
  while(!allComp()){
     int i;
    minDist = INFINITY;
    
    for(i=0; i<numNodes; i++){
      if(comp[i] == 0) {
	newDist = dist[curr] + cost(curr, i); 
	
	if(newDist < dist[i]) {
	  dist[i] = newDist;
	  prev[i] = curr;
	}
	
	if(dist[i] < minDist) {
	  minDist = dist[i];
	  k = i;
	}
	//	curr = k;
	//	comp[curr] = 1;
      }
    }
    curr = k;
    comp[curr] = 1;
    // displayPath(prev, source, destination, dist, numNodes);
  }
   fclose(myPtr);
  
}

int allComp()
{
  struct vertex *start = t;
  
  while(t !=NULL)
    {
      t=t->vertexPtr;
    }
  return 1;
}
 
   int cost(int curr, int i)
{
  struct vertex *currvertex;
  currvertex = start;
  struct edge *curredge;
  int found=0;
  while (currvertex != NULL && currvertex->vertexKey != curr)
    {
      currvertex = currvertex->vertexPtr;
    }
  
  if (currvertex != NULL)
    {
      curredge = currvertex->edgePtr;
    }
    
  while (curredge != NULL && curredge->vertexIndex != i)
    {
      curredge = curredge->edgePtr;
    }
  
  if (curredge == NULL || curredge->vertexWeight == 0)
    {
      found = INFINITY;
      return found;
    }
  else
    {
      found = curredge->vertexWeight;
      return found;
    }
}
