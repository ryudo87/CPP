#include <stdio.h>
#include <memory.h>
void delete_chars_in_string(char* src, const char* del)
{
	unsigned i=0;
	char bitmap[256];
	memset(bitmap,0,sizeof(bitmap) );
	while(del[i]){
		bitmap[ del[i++] ] =1;
	}
	
	char *p1,*p2;
	p1=p2=src;
	while(*p2){
		if( bitmap[ *p2]==0 ){
			*p1++=*p2;
		}
	p2++;
	}
	*p1=0;
}

int main()
{
	char src[]="aa";
	const char del[]="";
	delete_chars_in_string(src,del);
	printf("%s\n",src);
}
