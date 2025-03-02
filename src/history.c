#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

typedef struct s_Item{
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List{
  Item *root;
} List;

List* init_history(){
  List *list = malloc(sizeof(List));
  if(list) list->root = NULL;

  return list;
}

short str_len(char *str){
  short len = 0;
  while(str[len] != '\0'){
    len++;
  }
  return len;
}
void add_history(List *list, char *str){

  if(list == NULL || str == NULL)return;

  Item *new_item = malloc(sizeof(Item));
  if(new_item == NULL) return;

  short length = str_len(str);

  new_item->str = copy_str(str, length);
  new_item->next = NULL;

  if(list->root == NULL){
    new_item->id = 0;
    list->root = new_item;
  }
  else{
    Item *current = list->root;
    while(current->next != NULL) current = current->next;

    new_item->id = current->id+1;
    current->next= new_item;

    
  }
  
}

char *get_history(List *list, int id){

  if(list == NULL)return NULL;

  Item *current = list->root;
  while(current != NULL){
    if(current->id == id) return current->str;
    current = current->next;
  }

  return NULL;
}

void print_history(List *list) {
  if (list == NULL)
    return;

  Item *current = list->root;
  while (current != NULL) {
    printf("[!] %d -> %s\n", current->id, current->str);
    current = current->next;
  }
}

void free_history(List *list){

  if(list == NULL) return;

  Item *current = list->root;
  while(current != NULL){

    Item *next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  free(list);
}
