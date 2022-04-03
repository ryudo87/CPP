#include <stdio.h>
#include <ctype.h>
#include <memory.h>
void print_seg(unsigned N,char* prefix,unsigned index)
{
	if(N==0){
		printf("%s\n",prefix);return;
	}
	unsigned i;
	for( i=0;i<10;++i){
		
		prefix[index]=i+'0';
		print_seg(N-1,prefix,index+1);
	}
}

void print_1_N(unsigned N)
{
	//unsigned quota=N/3;
	//unsigned remainer=N%3;
	
	char *prefix=(char*)malloc(N+1);
	memset(prefix,0,sizeof(N+1));
	print_seg(N,prefix,0);
}

int main(int argc,char* argv[] )
{
	printf("%s\n",argv[1]);
	print_1_N(atoi(argv[1]));
}
