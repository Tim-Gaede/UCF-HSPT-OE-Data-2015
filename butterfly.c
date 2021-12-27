#include <stdio.h>
#include <stdlib.h>

/*
 First, the solution when we don't care about how fast our code runs.
 If have a group of butterflies and choose one, our level is the level
 you get from every other butterfly plus the effect of the one you chose.
 Say you have 2 of each type and you choose an addition butterfly.  Your
 level is X+the level you would be from 2 multiplication and 1 addition butterfly.
 Zero of both butterflys results in level one. From here, a recursive fuction 
 can be created to get the level you would be choosing an addition or multiplication
 butterfly and multiply that by the chance of it happening to get your expected level.
 This runs fast when a and b are lower than 10, but is too slow for the max case.
 

 Now, how do we make this run in time?  For any pair of a and b you have 
 to calculate every lower pair to know the answer.  This isn't so bad,  
 except that each pair can be run many times being called by every greater pair.
 Every time you run your function with the same inputs you get the same result.
 If you make an array (typically called a memo in computer science) you can
 store the answers and not have to recalculate them.  This makes the code
 run much faster.  Try it with the 10 15 15 test case.
 
 
 To read more on this type of problem, see the Wikipedia page for 
 dynamic programming or the tutorial on TopCoder.
 */

long double prob(int x, int a, int b);
long double memo[16][16];

main(void)
{
   FILE* fp = stdin;
   int cases, caseNum = 0;
   fscanf(fp, "%d", &cases);
   int x, a, b, i, j;
   
   while (caseNum++ < cases) {
      //set each spot in our memo to unknown
      for (i = 0; i < 16; i++) {
         for (j = 0; j < 16; j++) {
            memo[i][j] = -1;
         }
      }
      fscanf(fp, "%d %d %d", &x, &a, &b);
      double ans = prob(x, a, b);
      printf("Scenario #%d: %f\n", caseNum, ans);
   }
}


long double prob(int x, int a, int b) {
   if (memo[a][b] != -1)
      return memo[a][b];
      
   if (a == 0 && b == 0)
      return memo[a][b] = 1;
   if (a == 0)
      return memo[a][b] = x * prob(x, a, b-1);
   if (b == 0)
      return memo[a][b] = x + prob(x, a - 1, b);
   
   long double butterflys = a + b;
   long double bVal = (x * prob(x, a, b-1)) * b;
   long double aVal = (x + prob(x, a-1, b)) * a;
   return memo[a][b] = (aVal + bVal) /butterflys;
}
