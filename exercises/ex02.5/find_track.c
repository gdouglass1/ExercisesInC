/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regex.h"

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern in a regular expression.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
  regex_t regexCompiled; //regex_t object where the function can
                          //store the compiled regular expression.
  size_t maxMatches = 1; // The maximum number of matches to record
  regmatch_t groupArray[maxMatches+1]; // An array of regmatch_t objects where
                                      // the function can record the matches

  if (regcomp(&regexCompiled, pattern, 0)) // Compile a regular expression
                                            // zero is success
  {
    printf("Could not compile regular expression.\n");
    exit(1);
  }
  else{
    for (int i=0; i<NUM_TRACKS; i++) {
        if(regexec(&regexCompiled, tracks[i], maxMatches, groupArray, 0) == 0){
          printf("Track %i: '%s'\n", i, tracks[i]);
        }
        }
    regfree(&regexCompiled);
  }
  }


// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);
    find_track(search_for);

    printf("Search for regular expression: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);
    find_track_regex(search_for);

    return 0;
}
