#include "all.h"

enum TRIANGLE_TYPE{SCALENE=1,ISOSCELES,EQUILATERAL,ERROR};
TRIANGLE_TYPE determin_triagle_type(int	 a,int b,int c)
{

	if(a<0 || b<0 || c<0 || a+b<=c || a+c<=b || b+c<=a)
		return ERROR;
	else if(a==b && a==c )
		return EQUILATERAL;
	else if(a==b || a==c || b==c)
		return ISOSCELES;
	else return SCALENE;
}
int main()
{
	cout<<simplifyPath("/////home/./b//foo///.//")<<endl;
       return 0;
}
