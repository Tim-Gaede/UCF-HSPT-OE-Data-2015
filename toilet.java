import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;


public class toilet {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt();
    for (int toiletOn = 1; toiletOn <= cases; toiletOn++) {
      // Count of the number seconds until the toilet recognizes there is an
      // entity.
      int d = in.nextInt();
      // Count of the number of seconds until the toilet recognizes there isn't
      // an entity.
      int u = in.nextInt();
      // The sensor output from the toilet.
      char[] detection = in.next().toCharArray();
      
      // Store all of the times that the toilet flushes.
      ArrayList<Integer> flushTimes = new ArrayList<Integer>();
      
      // The count of the number of seconds that the last character has been
      // seen
      int cnt = 0;
      // the last character that has been seen
      // Initially set to '0' as it isn't an input that will be seen in the set
      char prevCh = '0';
      // Store whether or not there is currently an entity on the toilet.
      boolean hasEntity = false;
      for (int i = 0; i < detection.length; i++) {
        char nextLetter = detection[i];
        
        // If the next letter is equal to the previous letter than we have seen
        // that letter for one more second.
        if (nextLetter == prevCh) {
          cnt++;
        } else {
          // otherwise this is the first second we have seen the entity.
          cnt = 1;
          prevCh = nextLetter;
        }
        
        // If the last character seen is '#' and the cnt is greater than or
        // equal to d than we know there is an entity using the toilet.
        if (prevCh == '#' && cnt >= d) hasEntity = true;
        
        // If there is currently an entity and the amount of time to recognize
        // there is no longer an entity the toilet should flush.
        if (hasEntity && prevCh == '-' && cnt >= u) {
          hasEntity = false;
          // The actual flush time is i+1 because the output is 1-based instead
          // of 0-based.
          flushTimes.add(i + 1);
        }
      }
      
      System.out.printf("Toilet #%d flush times:", toiletOn);
      if (flushTimes.isEmpty()) {
        // If there are no flushes than we print 'None'
        System.out.println(" None");
      } else {
        // Otherwise we print every flush time.
        for (int t : flushTimes)
          System.out.printf(" %d", t);
        System.out.println();
      }
    }
  }
}
