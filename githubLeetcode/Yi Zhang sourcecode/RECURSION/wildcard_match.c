#include <stdio.h>

int wildcard_match(const char* str, const char* pat)
{
	printf("str:%s,pat:%s\n",str,pat);

	if(!str || !pat) return -1;
	if((*pat)==0  && (*str)!=0) return -1;
	if((*pat)==0 && (*str)==0) return 1;
	if((*str)==0){
		while((*pat)=='*') pat++;
		if((*pat)!=0) return -1;
		else return 1;
		//return wildcard_match(str,pat);
	}
	if((*pat)=='*'){
		while(*str){
			if(wildcard_match(str,pat+1)==1)
				return 1;
			str++;
		}
		return wildcard_match(str,pat+1);
	}
	else if((*pat)=='?'){
	 
	}
	else{
		if((*pat)==(*str)) return wildcard_match(str+1,pat+1);
		else return -1;
	}
}
int main()
{
char str[20];
char pat[20];
printf("str:");
scanf("%s",str);
printf("pat:");
scanf("%s",pat);
printf("%d\n",wildcard_match(str,pat));
return 0;	
}
