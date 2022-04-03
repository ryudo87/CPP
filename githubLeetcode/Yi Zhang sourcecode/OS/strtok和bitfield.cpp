#include "stdafx.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <deque>
#include <memory>
#include <ctime>
#include <typeinfo>
#include <hash_set>
#include "tree.h"
using namespace std;

typedef struct AF
{
	size_t a:32; //>32不行
	//int  :0;//强制
	int b:1;
}BFAF;
struct BF{
	size_t a:32; //>32不行
	//int  :0;//强制
	int b:1;
	
};
enum week{mon,tue};
void main(void){
	char string[] = "This is a sentence with 7 tokens";
	char *tokenPtr;
	tokenPtr = strtok( string, " " );
	while ( tokenPtr != NULL ) {
		cout << tokenPtr << '\n';
		tokenPtr = strtok( NULL, " " );
	}

	/*week we=week::mon;
	cout<<we<<endl;
	BF bf;
	BFAF bbbb;
	bf.a=2;
	cout<< sizeof(BF) <<endl;*/
}