#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
   // Read in the number of descriptions.   
   int T;
   cin >> T;

   for (int t=0; t<T; t++) {
      // Read in the times.
      int D, U;
      cin >> D >> U;

      // Read in the description.
      string line;
      cin >> line;

      // Output the title.
      cout << "Toilet #" << t+1 << " flush times:";

      // Initialize some variables.
      int mode = 0; // 0 means we haven't seen anyone yet, 1 means we have seen someone, but haven't seen a gap yet.
      char last = '-'; // The last character we saw.
      int currentLength = 0; // The current run length of this character.
      int seen = 0; // How many answers we've output so far.

      for (int i=0; i<line.length();i++) {

         // If we're changing characters, reset the length count.
         if (line[i] != last) {
            currentLength = 0;
            last = line[i];
         }

         // Increment the length count (we've seen another).
         currentLength++;

         // If we're in mode 0 and we've detected enough "something" in a row, update the mode.
         if (mode == 0 && last == '#' && currentLength >= D)
            mode = 1;
         // Or if we're in mode 1 and we've detected enough nothing in a row, output this answer and reset.
         else if (mode == 1 && last == '-' && currentLength >= U) {
            mode = 0;
            cout << " " << i+1;
            seen++;
         }
      }

      // If we haven't done anything, output "none".
      if (!seen)
         cout << " None";

      // Don't let our cases run together.
      cout << endl;
   }

   return 0;
}
