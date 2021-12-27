#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * The solution to this problem uses the Floyd-Warshall algorithm for all-pairs shortest path.
 * We set up the graph, run Floyd-Warshall, the search for the best bases that matches our conditions.
 */
int main()
{
    // two of these added together fits into an int32
    int infinity = 987654321;

    // use standard in
    FILE *in = stdin;

    // read the number of tests
    int tests;
    fscanf(in, "%d", &tests);

    // loop through each test
    for(int t = 1; t<=tests; t++)
    {
        // read the number of bases and passages
        int bases, passages;
        fscanf(in, "%d %d", &bases, &passages);

        // initialize the graph with every edge equal to infinity except for self-loops
        int adj[bases][bases];
        for(int i = 0; i<bases; i++)
            for(int j = 0; j<bases; j++)
                adj[i][j] = infinity;
        for(int i = 0; i<bases; i++)
            adj[i][i] = 0;

        // read in each passage and add them to the graph
        int x, y;
        for(int i = 0; i<passages; i++)
        {
            fscanf(in, "%d %d", &x, &y);
            x--; y--; // offset to zero based indexing
            adj[x][y] = adj[y][x] = 1;
        }

        // run Floyd-Warshall
        for(int k = 0; k<bases; k++)
            for(int i = 0; i<bases; i++)
                for(int j = 0; j<bases; j++)
                    if(adj[i][k] + adj[k][j] < adj[i][j])
                        adj[i][j] = adj[i][k]+adj[k][j];

        // find the best node
        int bestStart = 0;
        int bestMax = infinity;
        for(int i = 0; i<bases; i++)
        {
            // get the distance to the farthest node
            int farthest = 0;
            for(int j = 0; j<bases; j++)
                if(adj[i][j] > farthest)
                    farthest = adj[i][j];

            // update the best node
            if(bestMax > farthest)
            {
                bestMax = farthest;
                bestStart = i;
            }
        }

        // print the result
        printf("Map #%d: Signal base %d! It is at most %d squirrel paths away!\n", t, bestStart+1, bestMax);
    }

    // fin
    fclose(in);
}
