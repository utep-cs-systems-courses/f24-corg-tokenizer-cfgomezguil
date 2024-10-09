#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if((c == ' '|| c == '\t') && c != '\0'){
    return 1;
  }
  return 0;
}
   

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c == ' ' || c == '\t' || c == '\0'){
    return 0;
  }
  return 1;
}


/* returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */

char *token_start(char *tok){
  while(space_char(*tok)){
    tok++;
  }
  if(*tok == '\0'){
    return NULL;
  }
  else if(non_space_char(*tok)){
    return tok;
  }
  return NULL;
}


/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
 int count_tokens(char *str){
   char *temp = token_start(str);
   int count = 0;
   while(temp){
     if(non_space_char(*temp) == 1){
       count++;
     }
     temp = token_terminator(temp);
     temp = token_start(temp);

   }
   return count;
 }

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
 char *copy_str(char *inStr, short len){
   char *copy = malloc((len +1) * sizeof(char));
   int i = 0;
   for(i = 0; i < len; i++){
     copy[i] = inStr[i];
   }
   copy[i] = '\0';
   return copy;
 }

 int token_length(char *str){
   char *start = token_start(str);
   char *end = token_terminator(start);
   
   return end - start;

 }

 
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
 char **tokenize(char* str){
   int size = count_tokens(str);
   char **tokens = malloc((size + 1) * sizeof(char *));
   int i = 0;
   int len = 0;
   char *pt = str;
   for(i = 0;i < size;i++){
     pt = token_start(pt);
     len = token_length(pt);
     tokens[i] = copy_str(pt, len);
     pt = token_terminator(pt);
   }
   tokens[i] = '\0';

   return tokens;
 }

/* Prints all tokens. */
 void print_tokens(char **tokens){
   int i=0;
   printf("Here are your Tokens!\n");
   while (tokens[i]){
     printf("Token #%d = %s\n", (i+1), tokens[i]);
     i++;
   }
 }

/* Frees all tokens and the vector containing themx. */
//void free_tokens(char **tokens);

