//查集的C++实现
//2009-05-07 21:42
//实现这个数据结构主要有三个函数：如下：
//
//void UFset()   //初始化
//{
//for(int i=0;i<N;i++)
//   parent[i]=-1;
//}
//
//
//
//int Find(int x)   //返回第Ｘ节点所属集合的根结点
//{
//for(int i=x;parent[i]>=0;i=parent[i]);
//while(i!=x)    //优化方案――压缩路径
//{
//   int tmp=parent[x];
//   parent[x]=i;
//      x=tmp;
//}
//return i;
//}
//
//
//
//void Union(int R1,int R2)   //将两个不同集合的元素进行合并，使两个集合中任两个元素都连通
//{
//int tmp=parent[R1]+parent[R2];
//if(parent[R1]>parent[R2]) //优化方案――加权法则
//{
//   parent[R1]=R2;
//   parent[R2]=tmp;
//}
//else
//{
//   parent[R2]=R1;
//   parent[R1]=tmp;
//}
//}
//
//在Ｆｉｎｄ函数中如果仅仅靠一个循环来直接得到节点的所属集合根结点的话。通过多次的Ｕｎｉｏｎ操作就会有很多节点在树的比较深层次中，再Ｆｉｎｄ起来就会很费时。通过加一个Ｗｈｉｌｅ循环（压缩路径）每次都把从i到集合根结点的路过结点的双亲直接设为集合的根结点。虽然这增加了时间，但以后的Ｆｉｎｄ会快。平均效能而言，这是个高效方法。
//
//
//
//
//两个集合并时，任一方可做为另一方的孩子。怎样来处理呢，现在一般采用加权合并，把两个集合中元素个数少的做为个数多的孩子。有什么优势呢？直观上看，可以减少集合树的深层元素的个数，减少Ｆｉｎｄ时间。
//
//如从０开始到Ｎ不断合并i和i+1结点会怎样呢？
//
//
//
//
//这样Ｆｉｎｄ任一节点所属集合的时间复杂度几乎都是Ｏ(1)！！
//
//不用加权规则就会得到
//
//
//
//
//这就是典型的退化树现象，再Ｆｉｎｄ起来就会很费时（如找Ｎ－１节点看看）。
//
//以下是读入等价对后的parent[N]查找合并过程状态：
//
//
//
//
//
//
//
//再说一个并查集应用最完美的地方：最小生成树的kruskal算法：
//
//算法基本思想是：
//
//开始把所有节点作为各自的一个单独集合，以为每次从边信息中得到一个最短的边，如果这个边邻接了两个不同集合的节点，就把这两个节点的所属集合结合起来，否则继续搜索。直至所有节点都同属一个集合，就生成了一个最小生成树。int kruskal(int parent[],int N)
//{
//int i,j,k,x,y;
//int min;
//while(k<=N-1) //产生Ｎ－１条边
//{
//   min=MAX_INT;
//   for(i=1;i<=N;i++) 
//    for(j=1;j<=N;j++)
//    {
//     if(sign[i][j]==0&&i!=j) //sign[N][N]是标志节点是否被访问过或已被排除……
//     {
//      if(arcs[i][j]<min)　//arcs[N][N]存放边的长度
//      {
//       min=arcs[i][j];
//       x=i;
//       y=j;
//      }//if
//     }//if
//    }//for
//   if(Find(parent,x)==Find(parent,y)) //如Ｘ，Ｙ已经属同一连通分量，则不合并，排除……
//    sign[x][y]=1;
//   else
//    {
//     Union(parent,x,y);
//     Sign[x][y]=1;
//    }
//k++;
//}//while
//}


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
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <cassert>
#include <strstream>
#include <new>

using namespace std;


template<size_t N>
class UnionFindSet{
public:
	int parent[N+1];
	UnionFindSet()   //初始化
	{
		for(size_t i=0;i<=N;i++)
		   parent[i]=-1;
	}
	int Find(int x)   //返回第Ｘ节点所属集合的根结点
	{
		int i;
		for(i=x;parent[i]>=0;i=parent[i]);
		while(i!=x)    //优化方案――压缩路径
		{
		   int tmp=parent[x];
		   parent[x]=i;
			  x=tmp;
		}
		return i;
	}



	void Union(int R1,int R2)   //将两个不同集合的元素进行合并，使两个集合中任两个元素都连通
	{
		int tmp=parent[R1]+parent[R2];
		if(parent[R1]>parent[R2]) //优化方案――加权法则
		{
		   parent[R1]=R2;
		   parent[R2]=tmp;
		}
		else
		{
		   parent[R2]=R1;
		   parent[R1]=tmp;
		}
	}
};
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
void Kruskal(priority_queue<Edge>& pri)
{
	UnionFindSet<N> ufset;
	set<Edge> edgeSet;
	for(size_t k=0;k<N-1;)
	{
		Edge e=pri.top();
		pri.pop();
		if(ufset.Find(e.src)!=ufset.Find(e.dst))//该边不会形成环
		{
			ufset.Union(e.src,e.dst);
			edgeSet.insert(e);
			++k;
		}
	}

	for(set<Edge>::iterator it=edgeSet.begin();it!=edgeSet.end();++it)
	{
		strstream str;
		str<<it->src;
		string s;
		str>>s;
		cout<<it->len<<":"+s+","<<it->dst<<endl;
	}
}

int main()
{
	priority_queue<Edge> pri;
	pri.push(Edge(9,1,3));
	pri.push(Edge(10,1,2));
	pri.push(Edge(8,1,5));

	pri.push(Edge(18,2,3));
	pri.push(Edge(5,2,4));
	pri.push(Edge(6,2,6));

	pri.push(Edge(25,3,5));
	pri.push(Edge(19,3,6));
	pri.push(Edge(11,4,6));

	Kruskal<6>(pri);
}

