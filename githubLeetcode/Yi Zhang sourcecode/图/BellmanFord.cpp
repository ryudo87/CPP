
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <cassert>
#include <strstream>
#include <new>

using namespace std;

algorithm that computes shortest paths from a single source vertex to all of the other vertices in a weighted digraph.

capable of handling graphs in which some of the edge weights are negative numbers.

Dijkstra's algorithm greedily selects the minimum-weight node that has not yet been processed, and performs this relaxation process on all of its outgoing edges; by contrast, the Bellman–Ford algorithm simply relaxes all the edges, and does this |V|-1 times,
Bellman–Ford runs in O(|V||E|) time, where |V| and |E| are the number of vertices and edges respectively.



function BellmanFord() {
  
  // Step 1: initialize graph
  for each vertex v in vertices:
    if v is source then weight[v] := 0
      else weight[v] := infinity
        predecessor[v] := null
        
        // Step 2: relax edges repeatedly
        for i from 1 to size(vertices)-1:
          for each edge (u, v) with weight w in edges:
            if weight[u] + w < weight[v]:
              weight[v] := weight[u] + w
              predecessor[v] := u
              
              // Step 3: check for negative-weight cycles
              for each edge (u, v) with weight w in edges:
                if weight[u] + w < weight[v]:
                  error "Graph contains a negative-weight cycle"
                  return weight[],predecessor[]
}





#define MAX 100

struct Edge
{
	int len;
	int src;
	int dst;
	Edge(int a,int b,int c):len(a),src(b),dst(c){}
	bool operator<(const Edge& e) const
	{
		return len>e.len;
	}
};

template<size_t N>
bool BellmanFord(int start,list<Edge>& edgeList)
{
	int d[N];
	for(size_t i=0;i<N;++i)	d[i]=MAX;
	d[start]=0;

	for(size_t i=0;i<edgeList.size()-1;++i)
		for(list<Edge>::iterator it=edgeList.begin();it!=edgeList.end();it++)
		{
			if(d[it->dst]>d[it->src]+it->len)
				d[it->dst]=d[it->src]+it->len;
		}
	for(list<Edge>::iterator it=edgeList.begin();it!=edgeList.end();++it)
		if(d[it->dst]>d[it->src]+it->len)
			return false;

	return true;
}
int main(int argc, char **argv)
{
	list<Edge> edgeList;
	edgeList.push_back(Edge(9,1,3));
	edgeList.push_back(Edge(10,1,2));


	edgeList.push_back(Edge(18,2,3));

	edgeList.push_back(Edge(6,2,6));

	edgeList.push_back(Edge(25,3,5));

	edgeList.push_back(Edge(11,6,4));
	BellmanFord<7>(1,edgeList);
    return 0;
}
