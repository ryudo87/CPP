#include "all.h"

bool mycomp(char* p1, char* p2)
{
	if(strcmp(p1,p2)<0) return true;
	return false;
}
int comlen(char *p1, char*p2)
{	
	char* s=p1;
	int i=0;
	while((*p1) && (*p1++==*p2++)){
		i++;
	}
	//*p1=0;
	//cout<<s<<endl;
	return i;
}
int main(){	
	char str[100];
	char* p[100];
	cin>>str;cout<<str<<endl;
	int i=0;
	while(str[i]){
		p[i]=&str[i++];
	}

	sort(p,p+i,mycomp);
	int maxlen=0,t;
	for(int j=0;j<i-1;j++){
		if((t=comlen(p[j],p[j+1]))>maxlen)
			maxlen=t;
	}
	cout<<"max repetitive substring:"<<maxlen<<endl;
return 0;
}
