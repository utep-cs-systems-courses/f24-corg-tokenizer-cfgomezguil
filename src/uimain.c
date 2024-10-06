#include <stdio.h>
#include <string.h>


int main(){
  
  char input[100];
  printf("Welcome to the Tokenizer! Please type in the text below to tokenize. Type EXIT to exit\n");
  printf("$ ");
  
  fflush(stdout);
  if (fgets(input, sizeof(input), stdin) != NULL) {

    // Process the input here

    printf("You entered: %s", input);



  } else {

    printf("Error reading input.\n");
  }
  return(0);
}

