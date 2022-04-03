//#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "dict.h"
using namespace std;
extern const int wordCount;
extern const char * dictionary[];

template <int dim> 
struct Board
{
    char letter[dim][dim];
} ;


/* Keep track of temporary string in the board  */
template<int dim>
struct CharArray
{
    char letters[dim*dim+1];
    int len;
};

 //init the array of used letters 
template <int dim>
void init_usedArray (int used_letter[][dim])
{
    int row;
    for (row = 0; row < dim; row++) 
	{
		int col;
		for (col = 0; col < dim; col++)
		{
			used_letter[row][col] = 0;
		}
    }
}

/* compare the prefix of strings */
template<int dim>
int compare_prefix (const void * targetStr, const void * sourceStr)
{
    const CharArray<dim> * tempStr = (const CharArray<dim> *) targetStr;
    const char * const * word = ( const char * const * ) sourceStr;
    int comp;
    comp = strncmp (tempStr->letters, *word, tempStr->len);
    return comp;
}

/* compare if two strings are the same */
template<int dim>
int compare_word (const void * targetStr, const void * sourceStr)
{
    const CharArray<dim> * tempStr = (const CharArray<dim> * ) targetStr;
    const char * const * word = (const char * const * ) sourceStr;
    int result= strcmp (tempStr->letters, *word);
	return result;
}

/* Initialize the temporary string by empty string */
template<int dim>
void init_tempStr (CharArray<dim> * tempStr)
{
    int letter = 0;
    for (letter = 0; letter <= dim*dim; letter++)
		tempStr->letters[letter] = '\0';
    tempStr->len = 0;
}

/* Return a true value if the candidate tempStr is a substring of any
   word in the dictionary. */
template<int dim>
void * is_prefix (CharArray<dim> * tempStr, const char * dictionary[])
{
    return bsearch (tempStr, dictionary, wordCount, sizeof (char *), compare_prefix<dim>);
}

/* Return a true value if an exact match for this word is in the
   dictionary. */
template<int dim>
void * is_word (CharArray<dim> * tempStr, const char * dictionary[])
{
    return bsearch (tempStr, dictionary, wordCount , sizeof (char *), compare_word<dim>);
}

/* Add a letter to the candidate tempStr. */
template<int dim>
void append_letter (CharArray<dim> * tempStr, char letter)
{
    tempStr->len++;
    tempStr->letters[tempStr->len - 1] = letter;
}

/* Remove a letter from the candidate tempStr. */
template<int dim>
void delete_letter (CharArray<dim> * tempStr)
{
    tempStr->len--;
    tempStr->letters[tempStr->len] = '\0';
}

/* Given a starting point in the grid, "row" x "col", move along one
   and see if there is another valid word. */

template<int dim>
void match_next (Board<dim> * my_board, int row, int col, int useRecord[][dim], CharArray<dim> * tempStr, const char * dictionary[])
{
    int next_row;
    
	if (tempStr->len > dim*dim)
		return;
    for (next_row = row - 1; next_row <= row + 1; next_row++) 
	{
		int next_col;
		if (next_row < 0 || next_row >= dim)		continue;

		for (next_col = col - 1; next_col <= col + 1; next_col++) 
		{
			if (next_col < 0 || next_col >= dim)    continue;
			if (useRecord[next_row][next_col])     continue;
			useRecord[next_row][next_col] = 1;
			append_letter (tempStr, my_board->letter[next_row][next_col]);
			if (is_prefix (tempStr, dictionary)) 
			{
				if (is_word (tempStr,dictionary)) 
				{	
					cout<<tempStr->letters<<endl;
				}
				match_next<dim> (my_board, next_row, next_col, useRecord, tempStr, dictionary);
			}
			useRecord[next_row][next_col] = 0;
			delete_letter<dim> (tempStr);
		}
    }
}

/* Find all the  words and print */
template <int dim> 
void boggle_solver( Board<dim> *my_board, const char * dictionary[] )
{
	int row;
	CharArray<dim> tempStr;
    int useRecord[dim][dim];

    init_usedArray<dim>  (useRecord);
    init_tempStr (& tempStr);
    for (row = 0; row < dim; row++) 
	{
		int col;
		for (col = 0; col < dim; col++) 
		{
			append_letter (& tempStr, my_board->letter[row][col]);
			useRecord[row][col] = 1;
			match_next<dim> (my_board, row, col, useRecord, & tempStr, dictionary);
			useRecord[row][col] = 0;
			delete_letter<dim> (& tempStr);
		}
    }
}


int main ()
{

    Board<3> my_board = 
	{
		{
			{'y','o','x'},
			{'r','b','a'},
			{'v','e','d'}
		 }
	};

	boggle_solver<3>( &my_board, dictionary);
    return 0;
}
