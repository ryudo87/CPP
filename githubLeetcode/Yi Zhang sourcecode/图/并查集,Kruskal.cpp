//�鼯��C++ʵ��
//2009-05-07 21:42
//ʵ��������ݽṹ��Ҫ���������������£�
//
//void UFset()   //��ʼ��
//{
//for(int i=0;i<N;i++)
//   parent[i]=-1;
//}
//
//
//
//int Find(int x)   //���صڣؽڵ��������ϵĸ����
//{
//for(int i=x;parent[i]>=0;i=parent[i]);
//while(i!=x)    //�Ż������D�Dѹ��·��
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
//void Union(int R1,int R2)   //��������ͬ���ϵ�Ԫ�ؽ��кϲ���ʹ����������������Ԫ�ض���ͨ
//{
//int tmp=parent[R1]+parent[R2];
//if(parent[R1]>parent[R2]) //�Ż������D�D��Ȩ����
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
//�ڣƣ��亯�������������һ��ѭ����ֱ�ӵõ��ڵ���������ϸ����Ļ���ͨ����εģգ��������ͻ��кܶ�ڵ������ıȽ������У��٣ƣ��������ͻ�ܷ�ʱ��ͨ����һ���ף����ѭ����ѹ��·����ÿ�ζ��Ѵ�i�����ϸ�����·������˫��ֱ����Ϊ���ϵĸ���㡣��Ȼ��������ʱ�䣬���Ժ�ģƣ����졣ƽ��Ч�ܶ��ԣ����Ǹ���Ч������
//
//
//
//
//�������ϲ�ʱ����һ������Ϊ��һ���ĺ��ӡ������������أ�����һ����ü�Ȩ�ϲ���������������Ԫ�ظ����ٵ���Ϊ������ĺ��ӡ���ʲô�����أ�ֱ���Ͽ������Լ��ټ����������Ԫ�صĸ��������٣ƣ���ʱ�䡣
//
//��ӣ���ʼ���β��Ϻϲ�i��i+1���������أ�
//
//
//
//
//�����ƣ�����һ�ڵ��������ϵ�ʱ�临�Ӷȼ������ǣ�(1)����
//
//���ü�Ȩ����ͻ�õ�
//
//
//
//
//����ǵ��͵��˻��������٣ƣ��������ͻ�ܷ�ʱ�����ңΣ����ڵ㿴������
//
//�����Ƕ���ȼ۶Ժ��parent[N]���Һϲ�����״̬��
//
//
//
//
//
//
//
//��˵һ�����鼯Ӧ���������ĵط�����С��������kruskal�㷨��
//
//�㷨����˼���ǣ�
//
//��ʼ�����нڵ���Ϊ���Ե�һ���������ϣ���Ϊÿ�δӱ���Ϣ�еõ�һ����̵ıߣ����������ڽ���������ͬ���ϵĽڵ㣬�Ͱ��������ڵ���������Ͻ���������������������ֱ�����нڵ㶼ͬ��һ�����ϣ���������һ����С��������int kruskal(int parent[],int N)
//{
//int i,j,k,x,y;
//int min;
//while(k<=N-1) //�����Σ�������
//{
//   min=MAX_INT;
//   for(i=1;i<=N;i++) 
//    for(j=1;j<=N;j++)
//    {
//     if(sign[i][j]==0&&i!=j) //sign[N][N]�Ǳ�־�ڵ��Ƿ񱻷��ʹ����ѱ��ų�����
//     {
//      if(arcs[i][j]<min)��//arcs[N][N]��űߵĳ���
//      {
//       min=arcs[i][j];
//       x=i;
//       y=j;
//      }//if
//     }//if
//    }//for
//   if(Find(parent,x)==Find(parent,y)) //��أ����Ѿ���ͬһ��ͨ�������򲻺ϲ����ų�����
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
	UnionFindSet()   //��ʼ��
	{
		for(size_t i=0;i<=N;i++)
		   parent[i]=-1;
	}
	int Find(int x)   //���صڣؽڵ��������ϵĸ����
	{
		int i;
		for(i=x;parent[i]>=0;i=parent[i]);
		while(i!=x)    //�Ż������D�Dѹ��·��
		{
		   int tmp=parent[x];
		   parent[x]=i;
			  x=tmp;
		}
		return i;
	}



	void Union(int R1,int R2)   //��������ͬ���ϵ�Ԫ�ؽ��кϲ���ʹ����������������Ԫ�ض���ͨ
	{
		int tmp=parent[R1]+parent[R2];
		if(parent[R1]>parent[R2]) //�Ż������D�D��Ȩ����
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
		if(ufset.Find(e.src)!=ufset.Find(e.dst))//�ñ߲����γɻ�
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

