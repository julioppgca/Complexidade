/* Roteadores.c
 * author: julio santos <julio.ppgca@gmail.com>
 * date: 06/06/2016
 * solution for URI's problem 1774
 *
 * kruskal algorithm adapted from:
 * http://www.c-program-example.com/2012/01/c-program-implement-kruskals-algorithm.html
 *
 *
 *
 */
#include <stdio.h>
#include <time.h>

// time variables
#define START_TIME_MES	{Ticks[0] = clock();}
#define STOP_TIME_MES	{Ticks[1] = clock();printf("Kruskal Takes: %g ms to process %d nodes and %d edges with mincost of %d.\n", (double)((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC),r,edges,cost);}

// problem parameters
#define INF 			10001
#define MAX_VERTICES	101

int matrix[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];

// kruskal functions
int kruskal(int vertices);
int find(int);
int uni(int,int);

int main(void)
{
int r,c,v,w,p,i,j,cost,edges;
clock_t Ticks[2];
	scanf("%d %d",&r,&c); //r=vertice c=arestas
	for(i=1;i<=r;i++)for(j=1;j<=r;j++)matrix[i][j]=INF; // init matrix with INF
	edges=c;
	while(c)
	{
		scanf("%d %d %d",&v,&w,&p);
		// only get the smallast edge if vertice already exists
		if((matrix[v][w]==INF)||(matrix[v][w]>p))	matrix[w][v]=matrix[v][w]=p;
		c--;
	}
	START_TIME_MES
	cost=kruskal(r);
	STOP_TIME_MES
//	printf("%d\n",cost);
return 0;
}

int kruskal(int vertices)
{
int cost=0, ne=1;
int i,j,min,u,v,a,b;
	while(ne<vertices)
	{
		for(i=1,min=INF;i<=vertices;i++)
		{
		  for(j=1;j<=vertices;j++)
		  {
		   if(matrix[i][j]<min)
		   {
		    min=matrix[i][j];
		    a=u=i;
		    b=v=j;
		   }
		  }
		}
	matrix[u][v]=matrix[v][u]=INF;
	u=find(u);
	v=find(v);
	if(uni(u,v))
	{
	printf("Connected %d to %d with cost: %d\n", a,b,min);
	 cost += min;
	 ne++;
	}
	}
return cost;
}

int find(int i)
{
while(parent[i]) i=parent[i];
return i;
}

int uni(int i,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;
}
