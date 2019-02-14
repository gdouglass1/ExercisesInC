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
  int rc;
  char buffer[100]; // buffer to store error code

  if ((rc = regcomp(&regexCompiled, pattern, 0)) != 0) // Compile a regular expression
                                            // zero is success
  {
    regerror(rc, &regexCompiled, buffer, 100);
    printf("regcomp() failed with '%s'\n", buffer);
    exit(1);
  }
  else{
    for (int i=0; i<NUM_TRACKS; i++) {
        rc = regexec(&regexCompiled, tracks[i], (size_t) 0, NULL, 0);
        if(rc == 0){
          printf("Track %i: '%s'\n", i, tracks[i]);
        }
        else if(rc == REG_NOMATCH){
          continue;
        }
        else{
          regerror(rc, &regexCompiled, buffer, 100);
          printf("regexec() failed with '%s'\n", buffer);
        }
        }
    // free up space
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
    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
