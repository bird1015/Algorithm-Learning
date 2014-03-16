#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX  10
#define MAX_INT 100000

int graph[MAX_VERTEX][MAX_VERTEX];
bool visit[MAX_VERTEX];
int dist[MAX_VERTEX];

void Dijkstra(int st, int n) // IN: st : start vertex ; IN: n:  number of vertex
{
	int i,j,w;
	
	for( i = 0; i  < n; i++)  // init
	{
		dist[i] = MAX_INT;
		visit[i] = false;
	}
	
	dist[st] = 0;
	
	while(true)
	{
		 int u = -1;
		 int sd = MAX_INT;
		 for( i = 0; i < n; i++)  // greedy for the min weight
		 {
			if( !visit[i] && dist[i] < sd)
			{
				sd = dist[i];
				u = i;
			}
		 }
		 
		 if( -1 == u)
			break;
			
		visit[u] = true;
			
		for ( j = 0; j < n; j++)  //update new weight
		{
		
			if( u == j)
				continue;
				
			int nw = graph[u][j] + dist[u];
			
			if( nw < dist[j])
			{
				dist[j] = nw;
			}
			
		}
	}
	
}


void Test()
{
	memset(graph, 0, sizeof graph);
	
	const int n = 4;
	
	struct {
		int data[n][n];

		int st;
		int end;
		int result ;
	} test_1[] =
	{
			0, 2, MAX_INT, 4,
			2, 0, 3, MAX_INT,
			MAX_INT, 3, 0, 2,
			4, MAX_INT, 2, 0,
			1,
			3,
			4
	};
	
	for( int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			graph[i][j] = test_1[0].data[i][j];
			//printf("%d ",graph[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");
	
	
	Dijkstra(test_1[0].st - 1, n);
	
	if( test_1[0].result == dist[test_1[0].end ] )
	{
		printf("PASS! \n");
		printf("end = %d, result = %d\n",test_1[0].end,dist[test_1[0].end ]);
	}
	else
	{
		printf("FAILE! \n");
		printf("end = %d, result = %d\n", test_1[0].end,dist[test_1[0].end ]);
	}
	
}


int main()
{
	Test();
	
	return 0;
}
