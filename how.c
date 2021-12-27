#include <stdio.h>
#include <stdlib.h>

// this solution uses a two pointer method. Both scoreboards are sorted when they are read in, 
// thus you can imagine both scoreboards as two long lines, where at each timestep you can 
// remove the best item at the head of one line and print it out, then continue this process 
// until all teams have been printed.

main(void)
{
   FILE* fp = stdin;
   int cases, caseNum = 0;
   char line[10000];
   fgets(line, sizeof(line), fp);
   sscanf(line, "%d", &cases);

   while (caseNum++ < cases) {
      printf("Competition #%d:\n", caseNum);
      long int A,B;      
      fgets(line, sizeof(line), fp);
      sscanf(line, "%ld %ld", &A, &B);

      char namesA[A][11];
      char namesB[B][11];

      long int scoreA[A];
      long int scoreB[B];

      long int penaltyA[A];
      long int penaltyB[B];

      long int a=0, b=0, pos=1;

      //read in first scoreboard
      for(a=0;a<A;a++){
         fgets(line, sizeof(line), fp);
         sscanf(line, "%s %ld %ld", namesA[a], &scoreA[a], &penaltyA[a]);
      }

      //read in second scoreboard
      for(b=0;b<B;b++){
         fgets(line, sizeof(line), fp);
         sscanf(line, "%s %ld %ld", namesB[b], &scoreB[b], &penaltyB[b]);
      }

      a=0;
      b=0;
      //while I still have teams to print out
      while(a!=A||b!=B){
         //if the team from list A is better than the team from list B, or list B is empty
         if(b==B||(a!=A&&(scoreA[a]>scoreB[b]||(scoreA[a]==scoreB[b]&&penaltyA[a]<penaltyB[b])))){
            printf("%ld %s %ld %ld\n",pos,namesA[a],scoreA[a],penaltyA[a]);
            a++;
         }
         //if the team from list B is better than the team from list A, or list A is empty
         else{
            printf("%ld %s %ld %ld\n",pos,namesB[b],scoreB[b],penaltyB[b]);
            b++;
         }
         pos++;
      }
      printf("\n");
   }
   fclose(fp);
   return 0;
}
