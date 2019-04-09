#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_iterator(gpointer item, gpointer postfix) {
 printf("%s %s", (char*)item, (char*)postfix);
}

void iterator(gpointer key, gpointer value, gpointer user_data) {
 printf(user_data, (char*)key, *(gint*)value);
}

GSList* get_word_list(char *line, GSList *list){
  const char delimiters[] = " .,;:!-?""()\t";
  char* token;
  token = strtok(line, delimiters);
  list = g_slist_append(list, token);
  while(token != NULL){
    token = strtok(NULL, delimiters);
    if(token != NULL){
      list = g_slist_append(list, token);
    }
  }
  return list;
}

void histogram(gpointer key, gpointer hash){
  GHashTable *hashtable = (GHashTable *)hash;
  char* key = (char*) key;
  char* old_key;
  int* old_value;
  int* new_value = malloc(sizeof(int));
  gpointer item_ptr = g_hash_table_lookup_extended(hashtable, key, &old_key, &old_value);
  if(key[0] < 65){
    return;
  }
  if(item_ptr != NULL){
    *new_value = (*old_value) + 1;
    g_hash_table_insert(hashtable, g_strdup(key), new_value);
    g_free(old_key);
    g_free(old_value);
  }
  else{
     *new_value = 1;
     g_hash_table_insert(hashtable, g_strdup(key), new_value);
  }
}

int main(int argc, char *argv[]){
  FILE *file;
  char *line = calloc(1024, sizeof(char));
  size_t len = 0;
  GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);
  //GSList *iterator = NULL;

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
    // g_slist_foreach(wordslist, print_iterator," ");
    // printf("The list is now %d items long\n", g_slist_length(wordslist));
    g_slist_foreach(wordslist, histogram,hash);
    g_hash_table_foreach(hash, (GHFunc)iterator, "key: %s value: %d\n");
    g_slist_free(wordslist);
  }

  free(line);
  g_hash_table_destroy(hash);
  fclose(file);
  exit(EXIT_SUCCESS);
  return 0;

}
