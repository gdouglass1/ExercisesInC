#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int a_flag = 0;
  int size = 8192;
  char ch;
  char input[size];
  FILE *output;

  if(argc < 1){
    fprintf(stderr, "Please specify at least one file\n");
    return 1;
  }

  while ((ch = getopt(argc, argv,"a"))!=EOF){ /*check options*/
    switch (ch) {
      case 'a'/* append mode initiated */:
        a_flag = 1;
        break;
      default:
        fprintf(stderr, "Unknown option: '%s'\n", optarg);
        return 1;
    }
}
    argc -= optind;
    argv += optind;

  while (fgets(input, size, stdin)){ /* Write to data stream*/
    for(int i = 0; i < argc; i++){
      if (a_flag){
        output = fopen(argv[i],"a");
      }
      else{
        output = fopen(argv[i],"w");
      }
      fprintf(output, "%s", input);
      fclose(output);
    }
    fprintf(stdout,"%s",input);
  }
  return 0;
}

/*
Question 3: I got a segmentation fault when i accidentally include
argc -= optind and etc in the while loop. I also did not check if the file
exist or not. Next time I would add this check. But in terms of implementing
checking options and write to data stream, i followed the book example.

Question 4: The professional code implemnt the -i option and used a dynamically
allocated array for the buffer. The professional solution also implemented
warning with errno.

*/
