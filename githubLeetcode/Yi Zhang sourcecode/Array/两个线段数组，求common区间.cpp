#include "all.h"
//两个线段数组，求common区间 A［1，5］［10，15］ B [3,12] return [3,5],[10,12]

//question:
//SORTED??
//open ended or closed ended
//duplicates?
//invalid interval
//negative

//TEST CASE:
//A［1，5］［10，15］ B [-1,0]
//A［1，5］［10，15］ B [0,3] [4,5]
//A［1，5］［10，15］ B [0,6]
//A［1，5］［10，15］ B [0,12]
//A［1，5］［10，15］ B [0,15]


//A［1，5］［10，15］ B [3,4]
//A［1，5］［10，15］ B [3,7]
//A［1，5］［10，15］ B [3,12]
//A［1，5］［10，15］ B [3,16]
//A［1，5］［10，15］ B [6,9]
//A［1，5］［10，15］ B [6,12]
//A［1，5］［10，15］ B [6,17]

//A［1，5］［10，15］ B [12,14]
//A［1，5］［10，15］ B [12,16]

//A［1，5］［10，15］ B [16,17]

//guarantee p1->first  <=  p2->first
bool merge(pair<int,int> p1, pair<int,int> p2, deque< pair<int,int> >& res)
{	pair<int, int> pa;
	if(p1.second < p2.first){//no overlap
		return false;
	}
	else if(p1.second < p2.second){
		res.push_back(pair<int,int>(p2.first,p1.second));
		return false;
	}
	else{
		res.push_back(p2);
		return true;
	}
}
deque< pair<int,int> > overlap_interval(const deque< pair<int,int> >& A, const deque< pair<int,int> >& B)
{
	deque< pair<int,int> > res;
	int i=0,j=0, m=A.size(),n=B.size();
	while(i<m && j<n){
		if(A[i].first > B[j].first){
			if( merge(B[j],A[i],res)==false ){//empty
				++j;
			}
			else{
				++i;
			}
		}
		else{
			if( merge(A[i],B[j],res)==false ){
				++i;
			}
			else{
				++j;
			}
		}
	}

	return res;
}
//A［1，5］［10，15］ B [-1,0]
//A［1，5］［10，15］ B [0,3] [4,5]
//1,3
//4,5

//A［1，5］［10，15］ B [0,6]	1,5
//A［1，5］［10，15］ B [0,12]	1,5   10,12
//A［1，5］［10，15］ B [0,15]	1,5		10,15

//A［1，5］［10，15］ B [3,4]	3,4
//A［1，5］［10，15］ B [3,7] 3,5
//A［1，5］［10，15］ B [3,12]	3,5		10,12
//A［1，5］［10，15］ B [3,16] 3,5		10,15
//A［1，5］［10，15］ B [6,9]	....
//A［1，5］［10，15］ B [6,12]	10,12
//A［1，5］［10，15］ B [6,17]	10,15

//A［1，5］［10，15］ B [12,14]	12,14
//A［1，5］［10，15］ B [12,16]	12,15

//A［1，5］［10，15］ B [16,17]	....
int main()
{
	deque< pair<int,int> > A,B;
	A.push_back(pair<int,int>(1,5));
	A.push_back(pair<int,int>(10,15));
	B.push_back(pair<int,int>(16,17));
	//B.push_back(pair<int,int>(4,5));

	deque< pair<int,int> > res=overlap_interval(A,B);
	for(unsigned i=0;i<res.size();++i){
		cout<<res[i].first<<","<<res[i].second<<endl;
	}
	cout<<endl;
	return 0;
}
