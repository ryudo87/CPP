
#include "all.h"

#define sigma 0.00000001
double myPow(double a, int b)
{
	if(abs(a-0)<sigma) return 0;
	if(b<0) return 1.0/pow(a,-b);
	double res=1,curBase=a;
	while(b){
		if(b%2==1){
			res*=curBase;
		}
		b/=2;
		curBase*=curBase;
	}

	return res;
}


double mypow(double a, int b) {
  if (b==0) {
    return 1;
  }
  
  if (b<0) {
    return 1.0/pow(a, -b);
  }
  
  if(abs(a-0)<sigma) return 0;
  if (b%2==1) {
    return a*pow(a, b-1);
  }
  double tmp = pow(a,b/2);
  return tmp*tmp;
}
//Implement pow(x, n).
// Submission Result: Accepted

// overflow?
// x==0?  (1.1, 0) (1.00000, 100) (1.1, 2) (1.1, 3) (-2, -3) (-0.3, -1)

double pow(double x, int n) {
  if (abs(x-1)<0.0000001) {
    return x;
  }
  if (abs(x+1)<0.0000001) {
    if (n%2==0){
      return -x;
    } else {
      return x;
    }
  }
  if (n<0) {
    return 1/pow(x, -n);
  }
  
  if (n==0){
    return 1;
  }
  if (n==1) {
    return x;
  }
  
  
  if(n%2==0){
    double tmp=pow(x,n/2);
    return tmp*tmp;
  } else {
    return x*pow(x, n-1);
  }
}


int main()
{
	double a;int b;
	cin>>a>>b;
	cout<<myPow(a,b);

}
