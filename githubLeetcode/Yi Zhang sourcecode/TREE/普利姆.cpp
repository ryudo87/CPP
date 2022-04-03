
#include <iostream>
#include <fstream>
using namespace std;
#define Max 100
int main()
{
	ifstream fin("in.txt");
	int G[10][10]={-1},in[10]={0},path[10][2];
	int i,j,k,min=10;
	int v1,v2,num,tmp,start=0;
	num=5;

	for(j=0;j<num;j++)
		for(k=0;k<num;k++)
		{
			if(j==k)
				G[j][k]=Max;
			else if(j<k)
			{
				fin>>tmp;

				if(tmp==-1)
					tmp=Max;
				G[j][k]=G[k][j]=tmp;
			}
		}

	in[start]=1;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num;j++)
			for(k=0;k<num;k++)
				if((G[j][k]<min)&&in[j]&&!in[k])
				{
					v1=j;v2=k;min=G[j][k];
				}

		if(!in[v2])
		{
			path[i][0]=v1;
			path[i][1]=v2;
			in[v1]=1;
			in[v2]=1;
			min=Max;
		}
		else cout<<"f"<<endl;
	}
	cout<<"::::";
	for(i=0;i<num-1;i++)
		cout<<"("<<path[i][0]<<", "<<path[i][1]<<")"<<endl;
	return 0;
}
