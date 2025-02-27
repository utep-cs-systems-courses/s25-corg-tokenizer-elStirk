#include <stdio.h>
#include <stdlib.h>
int space_char(char c){
  return (c == ' ' || c == '\t');
}

int non_space_char(char c){
  return (c != '\0' && (space_char(c) == 0));
}

char *token_start(char *token){
  while(space_char(*token)){
    token++;
  }
  return token;
}

char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

int count_tokens(char *token){
  short count = 0;
  while(*token != '\0'){
    token = token_start(token);
    count++;
    token = token_terminator(token);
  }
  return count;
}

char *copy_str(char *inStr, short len){
  if(inStr == NULL || len < 0){
    return NULL;
  }
  char *newStr = malloc((size_t)len +1);
  if(newStr == NULL){
    return NULL;
  }

  for(short i = 0; i<len;i++){
    newStr[i] = inStr[i];
  }

  newStr[len] = '\0';

  return newStr;
}

char **tokenize(char* str){
  if(str == NULL || *str == '\0'){
    return NULL;
  }

  short num_tokens = count_tokens(str);

  char **tokens = malloc((num_tokens+1) * sizeof(char *));
  if(tokens == NULL) return NULL;

  //Temp pointer
  short index = 0;
  char *temp_pointer = str;
  while(*temp_pointer){
    char *start = token_start(temp_pointer);
    char *end = token_terminator(start);
    short token_length = end - start;

    char *token = copy_str(start, token_length);

    if(token == NULL){
      for(short i=0;i<index;i++){
	free(tokens[i]);
      }
      free(tokens);
      return NULL;
    }

    tokens[index++] = token;
    temp_pointer = end;
  }
  tokens[index] = 0;
  return tokens;
}

void print_tokens(char **tokens){
  if(tokens == NULL)return;

  for(short i = 0; tokens[i] != 0; i++){
    printf("arg[%d] = %s\n", i, tokens[i]);
  }
}

void free_tokens(char **tokens){
  if(tokens == NULL)return;
  for(int i=0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  free(tokens);
}

