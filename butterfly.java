import java.util.*;
import java.io.*;
public class butterfly
{
   /*
    * In this problem, we perform additions when we visit a queen butterfly and
    * multiplications when we visit a monarch butterfly. The observation used in
    * this solution is that the additions can be viewed independently. For each
    * addition, it can be placed before all the multiplications, after one
    * multiplication, after two multiplications, and so on with equal probability.
    * 
    * If we have no additions and b multiplications, the answer would be x^b. Now
    * suppose we have 1 addition. The possible values (without including the x^b
    * from before) are x, x^2, x^3, ..., x^(b+1). Each of these has equal probability,
    * so to compute the expected value, we have to add them up and divide by b + 1.
    * 
    * If we have a additions, each of them is independent of the others, so we
    * multiply the result from above with a.
    * 
    * Finally, we have to add x^b to the expected value because the 1 skill level
    * we started with also gets multiplied b times.
    */
   public static void main(String[] args) throws IOException
   {
      Scanner in = new Scanner(System.in);
      
      // Iterate through test cases
      int t = in.nextInt();
      for(int i = 0; i < t; i++)
      {
         int x = in.nextInt();
         int a = in.nextInt();
         int b = in.nextInt();
         
         // Compute powers of x
         long[] pow = new long[b + 2];
         pow[0] = 1;
         for(int j = 1; j < pow.length; j++)
         {
            pow[j] = pow[j - 1] * x;
         }
         
         // Compute sum of x, x^2, x^3, ..., x^(b+1)
         long sum = 0;
         for(int k = 1; k <= b + 1; k++)
         {
            sum += pow[k];
         }
         
         // Compute expected value as the average value for one addition multiplied
         // by the number of additions
         double result = ((double)(sum * a) / (b + 1));
         
         // Add in the x^b from the 1 skill level we started with
         result += pow[b];
         
         System.out.printf("Scenario #%d: %f\n", i + 1, result);
      }
   }
}
