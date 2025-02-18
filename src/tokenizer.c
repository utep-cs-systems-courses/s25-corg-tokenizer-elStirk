#include <stdio.h>

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

}

int main(){
  char papu[] = "Hello, my name is Pablo";
  char *pointer = &papu[0];
  printf("%d",count_tokens(pointer));
  return 0;
}
