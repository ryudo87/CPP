

#include "all.h"
#include "tree.h"

class Flattener
{
	vector< vector<int> > myvv;
	unsigned i,j;
public:
	Flattener(const vector< vector<int> >  vv)
	{
		myvv=vv;i=j=0;
	}
	bool hasNext()
	{
		if(i==myvv.size()-1 && j==myvv[i].size()-1)
			return false;
		return true;
	}
	int next()
	{
		i=i+(j)/(myvv[i].size()-1);
		j=(j+1)%(myvv[i].size());
		return myvv[i][j];
	}
};


int main()
{
	vector< vector<int> > vec(3);
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
			vec[i].push_back(4*i+j);
	Flattener f(vec);
	while(f.hasNext())
		cout<<f.next()<<",";

	return 1;
}
