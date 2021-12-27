import java.io.File;
import java.util.Scanner;


public class professor {
   public static void main(String[] args) throws Exception {
      
      // Open file for input
      Scanner in = new Scanner(System.in);
      
      // Get number of test cases
      int testCases = in.nextInt();
      
      // Process each test case
      for (int caseNum = 1; caseNum <= testCases; caseNum++) {
         
         // Get the test case
         int stones = in.nextInt();
         int m = in.nextInt();
         
         // Print test case header
         System.out.printf("Game #%d: ", caseNum);
         
         // Let us remove a stone from the game, since the last stone is the losing one
         stones--;
         
         // Obvious, 0 stones is a losing state
         // 1 through m stones is a winning state because I can take all the stones
         // Thus m + 1 stones is also a losing state because it only goes to winning states
         // By repeating this logic, it's a losing state if the number of stones is divisible by m + 1
         // It is a winning state otherwise         
         if (stones % (m + 1) == 0) {
            System.out.println("Gentlemen don't cry.");
         }
         else {
            System.out.println("So long, Motchsteke!");
         }
         
      }
      
   }
}
