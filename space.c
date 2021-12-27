/*
Solution sketch:
Let us consider in what ways we need to change the input string to get the
correctly formatted string.

For adding spaces, see that it is sufficient to add a space before every
uppercase character in the input (except the first one). 

For fixing the capitalization, check if a word is the first word after a
period (or the first word of a line). If so, it should be capitalized,
otherwise not. The one exception to this rule is if the word is just 'I'.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 500
#define TRUE 1
#define FALSE 0

// returns TRUE if c is an uppercase letter, FALSE otherwise
int isUpper(char c) {
  return c >= 'A' && c <= 'Z';
}

// returns TRUE if c is a lowercase letter, FALSE otherwise
int isLower(char c) {
  return c >= 'a' && c <= 'z';
}

// returns TRUE if c is a letter, FALSE otherwise
int isLetter(char c) {
  return isUpper(c) || isLower(c);
}

// if the input character is lowercase, returns the uppercase version
// otherwise returns the input character.
char toUpper(char c) {
  if(isLower(c))
    return c-'a'+'A';
  return c;
}

// if the input character is uppercase, returns the lowercase version
// otherwise returns the input character.
char toLower(char c) {
  if(isUpper(c))
    return c-'A'+'a';
  return c;
}

int main() {
  int numCases, curCase;
  scanf("%d", &numCases);

  for(curCase = 1; curCase <= numCases; curCase++) {
    // read the input
    char input[MAXLEN];
    scanf("%s", input);

    // output buffer and index into our current position.
    char output[MAXLEN] = {0}; // initializes the array to null characters.
    int index = 0;

    int curChar = 0;
    for(curChar = 0; curChar < strlen(input); curChar++) {
      // if this letter is capital and not the first character, add a space
      if(curChar != 0 && isUpper(input[curChar])) {
        output[index++] = ' ';
      }
      // add the letter as a lowercase letter
      output[index++] = toLower(input[curChar]);
    }

    for(curChar = 0; curChar < strlen(output); curChar++) {
      // the first letter in the input should be capitalized
      if(curChar == 0) {
        output[curChar] = toUpper(output[curChar]);
      }

      // the first letter after a period should be capitalized
      if(curChar >= 2 && output[curChar-2] == '.') {
        output[curChar] = toUpper(output[curChar]);
      }

      // the letter 'i' by itself should be capitalized
      if(curChar >= 1 && !isLetter(output[curChar-1]) &&
                         output[curChar] == 'i' &&
                         !isLetter(output[curChar+1])) {
        output[curChar] = toUpper(output[curChar]);
      }
    }

    // print the output
    printf("%s\n", output);
  }
}
