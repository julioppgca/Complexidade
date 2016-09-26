/* Roteadores.c
 * author: julio santos <julio.ppgca@gmail.com>
 * date: 06/06/2016
 * solution for URI's problem 1774
 *
 * prim algorithm adapted from:
 * http://www.mycomputerscience.net/2012/10/c-program-implement-prims-algorithm.html#
 *
 */
#include<stdio.h>
#include<time.h>

#define INF 			10001
#define MAX_VERTICES	101

// time variables
#define START_TIME_MES	{Ticks[0] = clock();}
#define STOP_TIME_MES	{Ticks[1] = clock();printf("Prim Takes: %g ms to process %d nodes and %d edges with mincost of %d.\n", (double)((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC),r,edges,cost);}

int matrix[MAX_VERTICES][MAX_VERTICES];

int prim(int n, int vs);
#define True 1
#define False 0

int main()
{
clock_t Ticks[2];
	int r,c,v,w,p,i,j,cost,edges;
//	clock_t Ticks[2];
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
		cost=prim(r,v); //call the prim functionprintf("n");
		STOP_TIME_MES
//printf("%d\n",cost);
return 0;
}
/*The input number of vertices and the starting vertex are passed as parameters*/
int prim(int n, int vs)
{
int selected[n],nv,i,j,x,y,cost=0,min;
	for(i=1;i<=n;i++)	selected[i]=False;/*Initially no vertices are selected*/
	selected[vs]=True;/*Starting vertex is selected at first*/
	nv=1;
	while(nv<n)/*Iteration will be considered until all the vertices are selected*/
	{
		min=INF;/*min is initialized by a large value*/
		for(i=1;i<=n;i++)
		{
			//min=INF;/*min is initialized by a large value*/
			if(selected[i]==True)/*Iteration will be considered iff i th vertex is already selected*/
			{
				for(j=1;j<=n;j++)
				{
					if(selected[j]==False)/*Iteration will be considered iff j th vertex is not already selected*/
					{
						if(matrix[i][j]!=0)/*Iteration will be considered iff there is a path between i th and j th vertex*/
						{
							if(matrix[i][j]<min)/*Search for an edge with minimum weight*/
							{
								min=matrix[i][j];
								x=i;
								y=j;
							}
						}
					}
				}
			}
		}
		if(x!=y)
		{
			cost=cost+min;/*Updation of previous cost by adding it to cost of newly selected edge*/
			selected[y]=True;
			nv++;
			matrix[x][y]=matrix[y][x]=INF;
			printf("Connected %d to %d with cost: %d\n", x,y,min);
		}
	}
return cost;
}
