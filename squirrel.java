/*
Problem: squirrel
Author: Antony Stabile

Solution sketch:
This problem is asking to find the base whose maximum shortest path to all
other bases is minimized. We can find all of the shortest paths using the 
Floyd-Warshall algorithm (alternatively, these distances could be found by
any other shortest-path-finding method e.g. breadth first search), then finding the best base by examining each base
as a candidate and finding its maximum shortest path.
*/

import java.util.*;
import java.io.*;

public class squirrel {
  static int inf = (int)1e9;
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    int numCases = in.nextInt();
    for(int curCase = 1; curCase <= numCases; curCase++) {
      // number of nodes, number of edges
      int n = in.nextInt(), m = in.nextInt();

      // with no edges, edge base is infinitely far away from all others
      // except itself
      int[][] g = new int[n][n];
      for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
          if(i==j)
            g[i][j] = 0;
          else
            g[i][j] = inf;

      // read in each path
      // a path from i to j means bases i and j are distance 1 away.
      for(int i=0; i<m; i++) {
        int x = in.nextInt()-1;
        int y = in.nextInt()-1;
        g[x][y] = g[y][x] = 1;
      }

      // run Floyd-Warshall's algorithm
      for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
          for(int j=0; j<n; j++)
            g[i][j] = Math.min(g[i][j], g[i][k]+g[k][j]);

      // loop over each base, and find its maximum shortest path
      // if it is our best answer so far, keep it
      int best = -1;
      int bestAns = inf;
      for(int i=0; i<n; i++) {
        int maxPath = 0;
        for(int j=0; j<n; j++)
          maxPath = Math.max(maxPath, g[i][j]);

        if(bestAns > maxPath) {
          bestAns = maxPath;
          best = i;
        }
      }

      // print the answer
      System.out.printf("Map #%d: Signal base %d! It is at most %d squirrel paths away!%n", curCase, best+1, bestAns);
    }
  }
}
