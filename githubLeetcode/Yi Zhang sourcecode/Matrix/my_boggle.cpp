#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dict.h"



//#define dim 4
//#define dim 4

/* Define constants from dict.c */

extern const int n_words;
extern const char * dictionary[];

/* The grid of boggle letters. */


template <int dim> 
struct boggle_grid
{
    char letter[dim][dim];
} ;

/* Shake the "dice" and create a boggle grid. */

//void create_boggle (boggle_grid * bg)
//{
//    int row;
//    unsigned seed = (unsigned) time (0);
//    srand (seed);
//    for (row = 0; row < dim; row++) {
//	int col;
//	for (col = 0; col < dim; col++) {
//	    bg->letter[row][col] = rand () % 26 + 'A';
//	}
//    }
//}

/* Print out the boggle grid. */

template <int dim>
void print_boggle (boggle_grid<dim> * bg)
{
    int row;
    for (row = 0; row < dim; row++) {
	int col;
	for (col = 0; col < dim; col++) {
	    printf ("%c", bg->letter[row][col]);
	}
	printf ("\n");
    }
}

/* Keep track of the letters in the boggle grid which have already
   been used. */

//typedef int used_letter_t[dim][dim];

/* The candidate answer. */

//#define MAX_ANSWER dim * dim + 1

template<int dim>
struct answer_t
{
    char letters[dim*dim+1];
    int length;
};

/* Reset the array of used letters to all zeros. */
template <int dim>
void used_letter_init (int used_letter[dim][dim])
{
    int start_row;
    for (start_row = 0; start_row < dim; start_row++) 
	{
		int start_col;
		for (start_col = 0; start_col < dim; start_col++)
		{
			used_letter[start_row][start_col] = 0;
		}
    }
}

/* Substring compare for valid_substr's bsearch. */

template<int dim>
int compare_substr (const void * vanswer, const void * vword)
{
    const answer_t<dim> * answer = (const answer_t<dim> *) vanswer;
    const char * const * word = ( const char * const * ) vword;
    int comp;
    comp = strncmp (answer->letters, *word, answer->length);
    return comp;
}

/* String compare for found_word's bsearch. */

template<int dim>
int compare_exact (const void * vanswer, const void * vword)
{
    const answer_t<dim> * answer = (const answer_t<dim> * ) vanswer;
    const char * const * word = (const char * const * ) vword;
    int result= strcmp (answer->letters, *word);
	return result;
}

/* Initialize the candidate answer to an empty string of zero
   length. */

template<int dim>
void answer_init (answer_t<dim> * answer)
{
    int letter = 0;
    for (letter = 0; letter <= dim*dim; letter++)
		answer->letters[letter] = '\0';
    answer->length = 0;
}

/* Return a true value if the candidate answer is a substring of any
   word in the dictionary. */
template<int dim>
void * valid_substr (answer_t<dim> * answer, const char * dictionary[])
{
    return bsearch (answer, dictionary, n_words, sizeof (char *), compare_substr<dim>);
}

/* Return a true value if an exact match for this word is in the
   dictionary. */
template<int dim>
void * found_word (answer_t<dim> * answer, const char * dictionary[])
{
    return bsearch (answer, dictionary, n_words , sizeof (char *), compare_exact<dim>);
}

/* Add a letter to the candidate answer. */
template<int dim>
void add_letter (answer_t<dim> * answer, char letter)
{
    answer->length++;
    answer->letters[answer->length - 1] = letter;
}

/* Remove a letter from the candidate answer. */
template<int dim>
void remove_letter (answer_t<dim> * answer)
{
    answer->length--;
    answer->letters[answer->length] = '\0';
}

/* Given a starting point in the grid, "row" x "col", move along one
   and see if there is another valid word. */

template<int dim>
void find_next (boggle_grid<dim> * bg, int row, int col, int used_letters[][dim], answer_t<dim> * answer, const char * dictionary[])
{
    int next_row;
    
	if (answer->length > dim*dim)
		return;
    for (next_row = row - 1; next_row <= row + 1; next_row++) 
	{
		int next_col;
		if (next_row < 0 || next_row >= dim)		continue;
			//break;

		for (next_col = col - 1; next_col <= col + 1; next_col++) 
		{
			if (next_col < 0 || next_col >= dim)    continue;
				//break;
			if (used_letters[next_row][next_col])     continue;
				//break;
			used_letters[next_row][next_col] = 1;
			add_letter (answer, bg->letter[next_row][next_col]);
			if (valid_substr (answer, dictionary)) 
			{
				if (found_word (answer,dictionary)) {	
					printf ("%s\n", answer->letters);
				}
				find_next<dim> (bg, next_row, next_col, used_letters, answer, dictionary);
			}
			used_letters[next_row][next_col] = 0;
			remove_letter<dim> (answer);
		}
    }
}

/* Find all the possible words in the grid and print them to stdout. */
template <int dim> 
void boggle_solver( boggle_grid<dim> *bg, const char * dictionary[] )
{
	int start_row;
	answer_t<dim> answer;
    int used_letters[dim][dim];

    used_letter_init<dim>  (used_letters);
    answer_init (& answer);
    for (start_row = 0; start_row < dim; start_row++) 
	{
		int start_col;
		for (start_col = 0; start_col < dim; start_col++) 
		{
			add_letter (& answer, bg->letter[start_row][start_col]);
			used_letters[start_row][start_col] = 1;
			find_next<dim> (bg, start_row, start_col, used_letters, & answer, dictionary);
			used_letters[start_row][start_col] = 0;
			remove_letter<dim> (& answer);
		}
    }
}
//void solve_boggle (boggle_grid * bg)
//{
//    int start_row;
//    int used_letters[dim][dim];
//    answer_t answer;
//    used_letter_init (used_letters);
//    answer_init (& answer);
//    for (start_row = 0; start_row < dim; start_row++) 
//	{
//		int start_col;
//		for (start_col = 0; start_col < dim; start_col++) 
//		{
//			add_letter (& answer, bg->letter[start_row][start_col]);
//			find_next (bg, start_row, start_col, used_letters, & answer, dictionary);
//			remove_letter (& answer);
//		}
//    }
//}

int main ()
{
# if 1
    /* This is the boggle grid posted on stackoverflow.com */
    boggle_grid<3> bg = 
	{
		{
			{'y','o','x'},
			{'r','b','a'},
			{'v','e','d'}
		 }
	};
#else
    //boggle_grid bg;
   create_boggle (& bg);

#endif /* 0 */
   // print_boggle (& bg);
    //solve_boggle (& bg);
	//boggle_solver<3>( (char**) bg.letter, dictionary);
	boggle_solver<3>( &bg, dictionary);
    return 0;
}
