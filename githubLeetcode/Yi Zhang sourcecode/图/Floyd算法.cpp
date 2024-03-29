
#include <iostream>
#include <fstream>
#include <strstream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
#include <new>
#define MAX 100

//finding shortest paths in a weighted graph with positive or negative edge weights

Path reconstruction[edit]
The Floyd–Warshall algorithm typically only provides the lengths of the paths between all pairs of vertices.



void Floyd(vector< vector<int> > &graph,int n)
{
	int i,j,k;

	for(k=0;k<n;k++)
  {
		for(i=0;i<n;i++)
    {
      if(i==k) continue;
			
      for(j=0;j<n;j++)
			{
				if(i==j||i==k||j==k) continue;
				if(graph[i][k]+graph[k][j]<graph[i][j])	
					graph[i][j]=graph[i][k]+graph[k][j];
			}
		}
  }
  
  
}



int dist[11][11][11];
int n=10;
int path[11][11];
vector< vector<int> > mapG(n+1,vector<int>(n+1,MAX));
void init()
{
	
	for(int i=1;i<=n;i++)	mapG[i][i]=0;
	mapG[1][2]=2,mapG[1][4]=20,mapG[2][5]=1;
	mapG[3][1]=3,mapG[4][3]=8,mapG[4][6]=6;
	mapG[4][7]=4,mapG[5][3]=7,mapG[5][8]=3;
	mapG[6][3]=1,mapG[7][8]=1,mapG[8][6]=2;
	mapG[8][10]=2,mapG[9][7]=2,mapG[10][9]=1;

}

void floyd_dp()
{
	int i,j,k;
	for(i=1;i<=n;i++)
		 for(j=1;j<=n;j++)
			 dist[i][j][0]=mapG[i][j], path[i][j]=0;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				dist[i][j][k]=dist[i][j][k-1];
				if(dist[i][k][k-1]+dist[k][j][k-1]<dist[i][j][k])
					dist[i][j][k]=dist[i][k][k-1]+dist[k][j][k-1],path[i][j]=k;

			}

}


void output(int i,int j){
     if(i==j) return;
     if(path[i][j]==0) cout<<j<<' ';
     else{
         output(i,path[i][j]);
         output(path[i][j],j);
     }
}


int _tmain(int argc, _TCHAR* argv[])
{	
	//int n;
	//cin>>n;
	//vector< vector<int> > graph(n, vector<int>(6, MAX));
	//graph[0][1]=1;
	//graph[0][4]=2;
	//graph[1][2]=2;
	//graph[1][3]=8;
	//graph[2][4]=4;
	//graph[2][3]=3;
	//graph[4][0]=6;


	int u,v;
	init();
	floyd_dp();
	cin>>u>>v;


    if(dist[u][v][n]==MAX) cout<<"+∞"<<endl;
    else output(u,v);


	
}
