#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int main(){
  
  char input[100];
  char **tokens;
  // Value used to exit out of the loop
  char exit_Str[] = "EXIT";
  printf("Welcome to the Tokenizer! Please type in the text below to tokenize. Type EXIT to exit\n");
  
  while(1){
    
    printf("$ ");
  
    fflush(stdout);
  
    if(fgets(input, sizeof(input), stdin) != NULL) {
      if(input[0] == 'E' && input[1] == 'X' && input[2] == 'I' && input[3] == 'T'){
	goto out;
      }
      tokens = tokenize(input);
      print_tokens(tokens);
      //printf("You entered: %s", input);
    }
    else {
      printf("Error reading input.\n");
      goto out;
    }
  }
  
  out:
    printf("Bye, see you soon!\n");
    return(0);
}
