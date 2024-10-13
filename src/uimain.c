#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
int main(){
  
  char input[100];
  char *token;
  char **tokens;
  // Create the history for the program
  List *history = init_history();
  printf("Welcome to the Tokenizer! Please type in the text below to tokenize. Type EXIT to exit\n");
  
  while(1){
    
    printf("$ ");
  
    fflush(stdout);
  
    if(fgets(input, sizeof(input), stdin) != NULL) {
      // If the user types in EXIT, exit the program
      if(input[0] == 'E' && input[1] == 'X' && input[2] == 'I' && input[3] == 'T'){
	goto out;
      }
      //Access the History using key '#'
      if(input[0] == '#'){
	//History functionality
	int h_id = input[1] - '0';
	char *h_input = get_history(history, h_id);
 

      if(h_input != NULL){
	printf("The history selected for #%d is: \n",h_id);
	tokens = tokenize(h_input);
	print_tokens(tokens);
	free_tokens(tokens);
      }
      else{
	printf("There is no value set at %d. \n", h_id);
      }
    }
      else{
      //Tasks for the tokenizer
      tokens = tokenize(input);
      print_tokens(tokens);
      add_history(history, input);
    }
    }
    else {
      printf("Error reading input.\n");
      goto out;
    }
  }
  
  out:
    printf("Bye, see you soon!\n");
    free_history(history);
    return(0);
    
}
