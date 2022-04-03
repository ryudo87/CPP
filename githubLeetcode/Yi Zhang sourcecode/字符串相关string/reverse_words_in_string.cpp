#include "all.h"



string reverseWord(string w) {
  int n = w.length()-1;
  for (int i = 0; i < n-i; ++i) {
    char c = w[i];
    w[i] = w[n-i];
    w[n-i] = c;
  }

  return w;
}

int findNextBegin(string str, int end) {
  int len = str.length();
  if (end > len) {
    return len;
  }
  int i = end;
  while (i < len && str[i] == ' ') {
    ++i;
  }
  return i;
}

int findEnd(string s, int begin) {
  int len = s.length();
  if (begin >= len) {
    return begin;
  }
  int end = begin + 1;
  while (end < len && s[end] != ' ') {
    ++end;
  }
  return end;
}

void reverseWords(string &s) {
  string result;
  s = reverseWord(s);
  int n = s.length();
  int end = 0;
  while (end <= n) {
    int begin = findNextBegin(s, end);
    if (begin >= n) {
      break;
    } else if (!result.empty()) {
      result.push_back(' ');
    }
    end = findEnd(s, begin);
    string word = reverseWord(s.substr(begin, end-begin));
    result.append(word);
  }

  s = result;
}

/////////////////////////////////////////////////////////////////////////////


void reverse(char *begin,char* end)
{
	//*end=0;cout<<begin<<endl;*end=' ';
	end--;
	while(begin<end){ *begin^=*end;*end^=*begin;*begin^=*end;
			begin++;end--;
	}

}
void reverse_words(char *oldhead)
{
	char* str=oldhead;
	if(!str||(*str)==0) return;
	reverse(str,str+strlen(str));

	cout<<str<<endl;
	char * head=str;

	while(*str){
		if((*str)==' '){
			if(head==str) {head++;str++;continue;}
			reverse(head,str);head=str+1;
		}
		str++;
	}
	if(str!=head) reverse(head,str);

	cout<<oldhead<<endl;

}
int main()
{
char head[20]="";
string line;
//getline(cin,line);
cout<<head<<endl;
reverse_words(NULL);
cout<<head<<endl;
}







void reverse_chars(char* str, int begin,int end)
{
	while(begin<end){//exchange chars without extra variable
		str[begin]^=str[end];
		str[end]^=str[begin];
		str[begin++]^=str[end--];
	}
}
void reverse_words(char* sentence)
{
	if(!sentence || !sentence[0]) return;
	//reverse by characters
	int len=-1;
	while(sentence[++len]);  //O(n)

	reverse_chars(sentence, 0,len-1);

	//reverse each word in the reversed string
	int wordBeg=0,wordEnd=0;
	while(wordEnd<len){
		while(sentence[wordEnd]!=' '&&sentence[wordEnd]) wordEnd++;

		reverse_chars(sentence,wordBeg,wordEnd-1);
		wordEnd=wordBeg=wordEnd+1;
	}

}





////////////////////////////////


void reverse_chars(char* str, int begin,int end)
{
	while(begin<end){//exchange chars without extra variable
		str[begin]^=str[end];
		str[end]^=str[begin];
		str[begin++]^=str[end--];
	}
}
void reverse_words(char* sentence)
{
	if(!sentence || !sentence[0]) return;
	//reverse by characters
	int len=-1;
	while(sentence[++len]);  //O(n)

	reverse_chars(sentence, 0,len-1);

	//reverse each word in the reversed string
	int wordBeg=0,wordEnd=0;
	while(wordEnd<len){
		while(sentence[wordEnd]!=' '&&sentence[wordEnd]) wordEnd++;

		reverse_chars(sentence,wordBeg,wordEnd-1);
		wordEnd=wordBeg=wordEnd+1;
	}

}




