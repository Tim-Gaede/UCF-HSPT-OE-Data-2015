
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class redlight {

   public static void main(String[] args) {
      Scanner in = null;
     
      // Gets the number of intersections from the file
      in = new Scanner(System.in);
      int numIntersections = in.nextInt();
      
      for (int i = 0; i < numIntersections; i++) {
         // Time it takes for the light to turn green after it turns red
         int timeToGreen = in.nextInt(); 

         // Time it takes to get home if you go straight from a green light
         int straightTime = in.nextInt(); 

         // Time it takes to get home if you turn right
         int rightTime = in.nextInt(); 
         
         // Time that Aaron has observed the light being red
         int timeObservedRed = in.nextInt(); 
         
         // Figure out which way is best
         String result = calcMinTime(timeToGreen, timeObservedRed, 
                                     straightTime, rightTime);
         
         // Print answer
         System.out.println("Intersection #" + (i+1) + ": " + result);
      }
   }


   private static String calcMinTime(int timeToGreen, int timeObservedRed, 
                                     int straightTime, int rightTime) {
      // Calculates the max time left for the light to turn green
      int currTimeToGreen = timeToGreen - timeObservedRed; 

      // Calculates how long it will take to get home if you wait 
      // for the light to turn green
      int timeStraightHome = currTimeToGreen + straightTime; 
      
      // Unless going straight saves time, turn right
      if(timeStraightHome < rightTime)
         return "Wait it out.";
      else
         return "Right on red!";
   }
}
