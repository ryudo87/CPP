/**
 * DIJKSTRA(简单版) 单源最短路径算法（不允许存在负边）
 * 输入：(1)图g；        // 有向图或者无向图
 *         (2)源点s。
 * 输出：(1)源点s到各点的最短路径长dist；
 *         (2)源点s到各点的最短路径prev。
 * 结构: 图g用邻接矩阵表示，最短路径长dist用数组表示。
 * 算法：Dijkstra算法
 * 复杂度：O(|V|^2)
 */


int n;                    // n : 顶点个数
vector<vector<int> > g; // g : 图(graph)(用邻接矩阵(adjacent matrix)表示)
int s;                    // s : 源点(source)
vector<bool> known;        // known : 各点是否知道最短路径
vector<int> dist;        // dist : 源点s到各点的最短路径长
vector<int> prev;        // prev : 各点最短路径的前一顶点

void Dijkstra()            // 贪心算法(Greedy Algorithm)
{
  known.assign(n, false);
  dist.assign(n, INT_MAX);
  prev.resize(n);            // 初始化known、dist、prev。
  dist[s] = 0;            // 初始化源点s到自身的路径长为0。
  for (;;)
  {
    int min = INT_MAX, v = s;
    for (int i = 0; i < n; ++i) {
      if (!known[i] && min > dist[i]) {
        min = dist[i], v = i;    // 寻找未知的最短路径长的顶点v，
      }
    }
    
    if (min == INT_MAX) break;        // 如果找不到，退出；
    known[v] = true;                // 如果找到，将顶点v设为已知，
    for (int w = 0; w < n; ++w)        // 遍历所有v指向的顶点w，
      if (!known[w] && g[v][w] < INT_MAX && dist[w] > dist[v] + g[v][w])
        dist[w] = dist[v] + g[v][w], prev[w] = v;    // 调整顶点w的最短路径长dist和最短路径的前一顶点 prev。
  }
}

void Print_SP(int v)
{
  if (v != s) Print_SP(prev[v]);
  cout << v << " ";
}

int main()
{
  n = 7;
  g.assign(n, vector<int>(n, INT_MAX));
  g[0][1] = 2; g[0][3] = 1;
  g[1][3] = 3; g[1][4] = 10;
  g[2][0] = 4; g[2][5] = 5;
  g[3][2] = 2; g[3][4] = 2; g[3][5] = 8; g[3][6] = 4;
  g[4][6] = 6;
  g[6][5] = 1;
  
  s = 0;
  Dijkstra();
  for(size_t i=0;i<dist.size();i++)
    cout <<dist[i] <<endl;
  //    copy(dist.begin(), dist.end(), std::ostreambuf_iterator<int> (cout, " "));
  
  for (int i = 0; i < n; ++i)
    if(dist[i] != INT_MAX)
    {
      cout << s << "->" << i << ": ";
      Print_SP(i);
      cout << endl;
    }
  
  return 0;
}




#include <iostream>
#include <fstream>
#include <strstream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
#include <new>
#define MAX 100

template<int size>
void Dijkstra(vector< vector<int> > &graph, int start)
{
	vector<int> dis(size,MAX);
	set<int> explored;
	int arr[]={0,1,2,3,4,5};

	set<int> un_finish(arr,arr+6);
	un_finish.erase(start);
	vector<int> prev(size,-1);

	explored.insert(start);	
	dis[start]=0;
	int cur=start;

	while(!un_finish.empty())
	{
		for(int dest=0;dest<size;dest++)
		{
			if(dest==cur) continue;
			if(graph[cur][dest]!=MAX)
			{
				if(graph[cur][dest]+dis[cur]<dis[dest])
				{
					dis[dest]=graph[cur][dest]+dis[cur];
					prev[dest]=cur;
				}
				
			}
		}
		int tmpMin=MAX, index=*un_finish.begin();
		for(set<int>::iterator it=un_finish.begin();it!=un_finish.end();it++)
		{
			if(dis[*it]<tmpMin)	
			{index=*it;tmpMin=dis[*it];}
		}
	
		
		cout<<index<<":"<<dis[index]<<"prev:";
		int tmp=index;
		while(tmp!=start&&prev[tmp]!=-1)
		{
			cout<<prev[tmp];tmp=prev[tmp];
		}
		
		cout<<endl;
		cur=index;
		explored.insert(index);
		un_finish.erase(index);
	}
		
	
	
}

int _tmain(int argc, _TCHAR* argv[])
{	
	vector< vector<int> > graph(6, vector<int>(6, MAX));
	graph[0][1]=1;
	graph[0][4]=2;
	graph[1][2]=2;
	graph[1][3]=8;
	graph[2][4]=4;
	graph[2][3]=3;

	graph[4][0]=6;
	
	Dijkstra<6>(graph,1);



}
