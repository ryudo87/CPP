//Given a large document and a short pattern consisting of a few
//words (eg. W1 W2 W3), find the shortest string that has
//all the words in any order (for eg. W2 foo bar dog W1 cat W3
//-- is a valid pattern)

#include "all.h"

//binary search
float sqrt1(float n)
{
	float low=0,high=n,mid=(high+low)/2;
	while(abs(mid*mid-n)>0.001){
		if(mid*mid<n) low=mid;
		else high=mid;
		mid=(high+low)/2;
	}

	return mid;
}


//Newton's, that is Babilonian method
float sqrt2(float guess,float n)
{

	if(abs(guess*guess-n)<0.001) return guess;
	return sqrt2((guess+n/guess)/2,n);
}
int main(){
	//cout<<sqrt(9)<<endl;
	float n;
	cin>>n;
	cout<<sqrt2(n/2,n)<<endl;
}
