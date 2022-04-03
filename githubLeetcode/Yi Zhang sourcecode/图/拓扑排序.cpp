Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices

Time Complexity: The above algorithm is simply DFS with an extra stack. So time complexity is same as DFS which is O(V+E).




#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string.h>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <list>
#include <memory>
using namespace std;

int adj[][4]={{0,1,1,0},{0,0,0,0}, {0,0,0,0},{1,0,0,0}};
int N=4;

int get_no_in()
{
	for(int i=0;i<N;i++)
	{
		int j=0;
		for(;j<N;j++){
			if(adj[j][i]==1) break;
		}
		if(j==N) return i;
	}

	return -1;
}
void delete_edge(int no_in)
{
	for(int i=0;i<N;i++)
	{
		adj[no_in][i]=0;
	}
	adj[no_in][no_in]=1;
}
void topological_sort()
{
	deque<int> dq;
	while(true)
	{
		int no_in=get_no_in();
		if(no_in== -1) break;
		dq.push_back(no_in);
		delete_edge(no_in);
	}

	ostream_iterator<int> os(cout, " ");
	copy(dq.begin(),dq.end(),os);
}


int _tmain(int argc, _TCHAR* argv[])
{
	topological_sort();
	return 0;
}


