#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t, n, m, k, i;
   FILE* ifp = stdin;
   
   fscanf(ifp, "%d", &t);
   
   for (i = 0; i < t; i++)
   {
      fscanf(ifp, "%d %d", &n, &m);
      // Subtract one from the number of stones, game is now the player who cannot take a stone loses.
      n--;
      printf("Game #%d: ", i + 1);

      // 0 is a losing state.
      // 1 to m is a winning state, since the player can take up to m stones, and leave 0 for the next player.
      // m + 1 is a losing state, since no matter what happens, the player will leave 1 to m stones for the next player, which will be a winning state
      // for that player.
      // In general, if n is divisible by m + 1, the player is in a losing state, otherwise they are in a winning state.
      if (n % (m + 1) == 0)
         printf("Gentlemen don't cry.\n");
      else
         printf("So long, Motchsteke!\n");
   }
}
