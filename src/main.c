#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  List *history = init_history();
  char input[100];
  while(1){
    printf("This is a UI for the tokenizer. You can type '!h' to look for the history. '!c' to stop the process.'!#' being # a number from the history to recall it from there. Finally, if you only want to write and tokenize the string, just type it in.\n");
  start:
    printf("$ ");
    if(fgets(input, sizeof(input), stdin) != NULL){
      if(input[0] == '!'){
	switch(input[1]){
	case 'h': {
	  printf("[!] Printing the history...\n\n");
	  print_history(history);
	  goto start;

	}
	case 'c': {
	  printf("[!] Stopping UI...\n");
	  return 0;

	}
	default: {
	  
	  int id = atoi(input+1);
	  char *recalled = get_history(history, id);
	  if(recalled == NULL){
	    printf("[!] No history item with ID -> %d\n", id);
	    goto start;
	  }
	  printf("[!] Recalled: %s\n", recalled);
	  char **tokens = tokenize(recalled);
	  print_tokens(tokens);
	  free_tokens(tokens);
	  goto start;
	}
	}
       
      }else{
	add_history(history, input);
	char **tokens = tokenize(input);
	print_tokens(tokens);;
	free_tokens(tokens);
	goto start;
      }
    }
  }
  free_history(history);
  return 0;
}
