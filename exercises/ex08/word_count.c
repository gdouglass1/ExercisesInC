#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Function to print each word from a words list.
item: pointer to a word.
postfix: user input to format the print statement. ex: whitespace, ","
*/
void print_iterator(gpointer item, gpointer postfix) {
 printf("%s %s", (char*)item, (char*)postfix);
}

/*
Function to print each key value pair from a dictionary.
key: pointer to a key
value: pointer to a value
user_data: pointer to a formated string ex: "%s: %d\n"
*/
void iterator(gpointer key, gpointer value, gpointer user_data) {
 printf(user_data, (char*)key, *(int*)value);
}


/*
Free a dynamically allocated memory. Used when creating a hashtable and passed
as a key and value destroy function. The function is also called when a key new_value
pair is removed from the hashtable.
data: pointer to data that needs to be freed.
*/
void free_data(gpointer data){
  memset(data,0,sizeof(*data));
  free(data);
}

/*
Separate individual words from a line and return pointer to a words list
stored in a glib singly linked linked list.
line: pointer to a line from text
list: Glib linked list to appends to
*/
GSList* get_word_list(char *line, GSList *list){
  const char delimiters[] = " .,;:\"\"!-?()\t\n'";
  char* token;
  token = strtok(line, delimiters); // remove punctuations
  list = g_slist_append(list, token); // append to linked list
  while(token != NULL){
    token = strtok(NULL, delimiters);
    if(token != NULL){
      list = g_slist_append(list, token);
    }
  }
  return list;
}

/*
Create a histogram of the words and update the hashtable.
key: pointer to a word
hash: pointer to hashtable to store the historgram
*/
void histogram(gpointer key, gpointer hash){
  GHashTable *hashtable = (GHashTable *)hash;
  char* new_key = (char*) key;
  char* old_key;
  int* old_value;
  int* new_value = calloc(1,sizeof(int));
  gboolean item_ptr = g_hash_table_lookup_extended(hashtable, new_key, (void**)&old_key, (void**)&old_value);
  if(item_ptr){
    *new_value = (*old_value) + 1;
    g_hash_table_remove(hashtable, new_key);
    g_hash_table_insert(hashtable, g_strdup(new_key), new_value);
  }
  else{
     *new_value = 1;
     g_hash_table_insert(hashtable, g_strdup(new_key), new_value);
  }
}

int main(int argc, char *argv[]){
  FILE *file;
  char *line = calloc(1024, sizeof(char));
  size_t len = 0;
  GHashTable *hash = g_hash_table_new_full(g_str_hash, g_str_equal, free_data,free_data);


  if (argc != 2) {
      fprintf(stderr, "Usage: %s <file>\n", argv[0]);
      exit(EXIT_FAILURE);
  }

  file = fopen(argv[1], "r");
  if (file == NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
  }

  while (getline(&line, &len, file) != -1) {
    if(line[0] < 65){ /*65: A*/
      continue;
    }
    GSList *wordslist = NULL;
    wordslist = get_word_list(line,wordslist);
    //g_slist_foreach(wordslist, print_iterator," ");
    //printf("The list is now %d items long\n", g_slist_length(wordslist));
    g_slist_foreach(wordslist, histogram,hash); // update histogram
    g_slist_free(wordslist);
  }
  g_hash_table_foreach(hash, (GHFunc)iterator, "%s: %d\n"); // print result
  free(line);
  g_hash_table_destroy(hash);
  fclose(file);
  exit(EXIT_SUCCESS);
  return 0;

}
