
#include <iostream>
#include <fstream>

using namespace std;

int main() {
   // Variables
   int testCases, redlightDuration, straightTime, rightTime, observedTime;

   // Get the number of test cases
   cin >> testCases;

   // Process each test case
   for (int caseNum = 1; caseNum <= testCases; caseNum++) {
      // Read in the parameters
      cin >> redlightDuration >> straightTime >> rightTime >> observedTime;

      // Print the test case header
      cout << "Intersection #" << caseNum << ": ";

      // If it saves is time to wait, then do so
      // Otherwise, we turn
      if (redlightDuration - observedTime + straightTime < rightTime) {
         cout << "Wait it out.\n";
      }
      else {
         cout << "Right on red!\n";
      }
   }

   // Done!
   return 0;
}

