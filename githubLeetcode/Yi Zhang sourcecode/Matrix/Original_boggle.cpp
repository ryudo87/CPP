#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dictMy.h"
#define BOGGLE_ROWS 4
#define BOGGLE_COLUMNS 4

/* Define constants from dict.c */

extern const int n_words;
extern const char * dictionary[];

/* The grid of boggle letters. */

typedef struct
{
    char letter[BOGGLE_ROWS][BOGGLE_COLUMNS];
}
boggle_grid;

/* Shake the "dice" and create a boggle grid. */

void create_boggle (boggle_grid * bg)
{
    int row;
    unsigned seed = (unsigned) time (0);
    srand (seed);
    for (row = 0; row < BOGGLE_ROWS; row++) {
	int col;
	for (col = 0; col < BOGGLE_COLUMNS; col++) {
	    bg->letter[row][col] = rand () % 26 + 'A';
	}
    }
}

/* Print out the boggle grid. */

void print_boggle (boggle_grid * bg)
{
    int row;
    for (row = 0; row < BOGGLE_ROWS; row++) {
	int col;
	for (col = 0; col < BOGGLE_COLUMNS; col++) {
	    printf ("%c", bg->letter[row][col]);
	}
	printf ("\n");
    }
}

/* Keep track of the letters in the boggle grid which have already
   been used. */

typedef int used_letter_t[BOGGLE_ROWS][BOGGLE_COLUMNS];

/* The candidate answer. */

#define MAX_ANSWER BOGGLE_ROWS * BOGGLE_COLUMNS + 1

typedef struct
{
    char letters[MAX_ANSWER];
    int length;
}
answer_t;

/* Reset the array of used letters to all zeros. */

void used_letter_init (used_letter_t used_letter)
{
    int start_row;
    for (start_row = 0; start_row < BOGGLE_ROWS; start_row++) {
	int start_col;
	for (start_col = 0; start_col < BOGGLE_COLUMNS; start_col++) {
	    used_letter[start_row][start_col] = 0;
	}
    }
}

/* Substring compare for valid_substr's bsearch. */

int compare_substr (const void * vanswer, const void * vword)
{
    const answer_t * answer =(const answer_t * ) vanswer;
    const char * const * word = ( const char * const * ) vword;
    int comp;
    comp = strncmp (answer->letters, *word, answer->length);
    return comp;
}

/* String compare for found_word's bsearch. */

int compare_exact (const void * vanswer, const void * vword)
{
    const answer_t * answer = (const answer_t * ) vanswer;
    const char * const * word = (const char * const * ) vword;
    return strcmp (answer->letters, *word);
}

/* Initialize the candidate answer to an empty string of zero
   length. */

void answer_init (answer_t * answer)
{
    int letter = 0;
    for (letter = 0; letter < MAX_ANSWER; letter++)
	answer->letters[letter] = '\0';
    answer->length = 0;
}

/* Return a true value if the candidate answer is a substring of any
   word in the dictionary. */

void * valid_substr (answer_t * answer)
{
    return bsearch (answer, dictionary, n_words,
		    sizeof (char *), compare_substr);
}

/* Return a true value if an exact match for this word is in the
   dictionary. */

void * found_word (answer_t * answer)
{
    return bsearch (answer, dictionary, n_words - 1,
		    sizeof (char *), compare_exact);
}

/* Add a letter to the candidate answer. */

void add_letter (answer_t * answer, char letter)
{
    answer->length++;
    answer->letters[answer->length - 1] = letter;
}

/* Remove a letter from the candidate answer. */

void remove_letter (answer_t * answer)
{
    answer->length--;
    answer->letters[answer->length] = '\0';
}

/* Given a starting point in the grid, "row" x "col", move along one
   and see if there is another valid word. */

void find_next (boggle_grid * bg, int row, int col,
		used_letter_t used_letters, answer_t * answer)
{
    int next_row;
    if (answer->length >= MAX_ANSWER)
	return;
    for (next_row = row - 1; next_row <= row + 1; next_row++) {
	int next_col;
	if (next_row < 0 || next_row >= BOGGLE_ROWS)
	    break;
	for (next_col = col - 1; next_col <= col + 1; next_col++) {
	    if (next_col < 0 || next_col >= BOGGLE_COLUMNS)
		break;
	    if (used_letters[next_row][next_col]) {
		break;
	    }
	    used_letters[next_row][next_col] = 1;
	    add_letter (answer, bg->letter[next_row][next_col]);
	    if (valid_substr (answer)) {
		if (found_word (answer)) {	
		    printf ("%s\n", answer->letters);
		}
		find_next (bg, next_row, next_col, used_letters, answer);
	    }
	    used_letters[next_row][next_col] = 0;
	    remove_letter (answer);
	}
    }
}

/* Find all the possible words in the grid and print them to stdout. */

void solve_boggle (boggle_grid * bg)
{
    int start_row;
    int used_letters[BOGGLE_ROWS][BOGGLE_COLUMNS];
    answer_t answer;
    used_letter_init (used_letters);
    answer_init (& answer);
    for (start_row = 0; start_row < BOGGLE_ROWS; start_row++) {
	int start_col;
	for (start_col = 0; start_col < BOGGLE_COLUMNS; start_col++) {
	    add_letter (& answer, bg->letter[start_row][start_col]);
	    find_next (bg, start_row, start_col, used_letters, & answer);
	    remove_letter (& answer);
	}
    }
}

int main ()
{
# if 0
    /* This is the boggle grid posted on stackoverflow.com */
    boggle_grid bg = 
	{{{'F','X','I','E'},
	  {'A','M','L','O'},
	  {'E','W','B','X'},
	  {'A','S','T','U'}}};
#else
    boggle_grid bg;
    create_boggle (& bg);
#endif /* 0 */
    print_boggle (& bg);
    solve_boggle (& bg);
    return 0;
}
