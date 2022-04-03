#include <stdio.h>
#include <ctype.h>

/* Return 1 if a word with length len is a palindrome(case-sensitive).
 * Example: "Mom" is not a palindrome
 */
int isPalindrome(const char *str, const int len)
{
	int i;
    for(i=0;i<len/2;i++){
        if (str[i]!=str[len-i-1])
            return 0;
    }
    return 1;
}

/*
 * This function does not check the validity of a word. If needed, let me know.
 * Words consist of only letters. "12-year-old" is not a word while "year" and "old" are words.
 */
char* find_first_palindrome (char* input)
{
	if(!input) return NULL;
    int i;
    char* begin =input;
    while(*begin)
    {
    	while((*begin) && !isalpha(*begin)) ++begin;
    	for(i=0;;i++){
        	if(!begin[i]) return NULL;
        	if(!isalpha(begin[i])){
                break;
            }
        }
        if(isPalindrome(begin,i)){
            return begin;
        }
        begin += i+1;
    }

    return NULL;
}





