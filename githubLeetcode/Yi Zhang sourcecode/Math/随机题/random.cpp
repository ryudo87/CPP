

#include "all.h"

void select_k_from_stream()
{
	int input=1, cur=-1,i=0,k=2;
	vector<int> vec;
	cin>>input;
	while(input){
		vec.push_back(input);
		//print_vector<int>(vec,"vec");
		if(i<k){
			cur==input;
		}
		else{
			srand(time(0));
			//cout<<random()<<endl;
			//cout<<rand()<<endl;
			int randInt=rand()%(i+1);
			if(randInt<k){
				myswap<int>(vec[randInt],vec[i]);
			}
            
		}
		//print_vector<int>(vec,"vec");
		++i;
		cin>>input;
	}
	for(int i=0;i<k;++i){
		cout<<vec[i]<<endl;
	}
	//return cur;
}
int main()
{
	select_k_from_stream();
	return 1;
}
