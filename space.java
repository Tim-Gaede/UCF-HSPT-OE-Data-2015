import java.util.*;
import java.io.*;

public class space {
   public static void main(String[] args) throws IOException
   {
      Scanner input = new Scanner(System.in);
      int T = input.nextInt();
      for(int t = 0; t<T; t++)
      {
         String s = input.next();
         int length = s.length();
         String res = "";
         res += s.charAt(0);
         for(int i = 1; i<s.length(); i++)
         {
            char cur = s.charAt(i); //Look at the next character
            char prev = s.charAt(i-1);
            if(cur >= 'A' && cur <= 'Z')
            {
               res += ' '; //This letter was capitalized so it should be preceded by a space.
               if(prev == '.')
               {
                  res += cur; //This is the first character in the sentence, so add the uppercase character.
               }
               else
               {
                  if(cur == 'I' && (i == length - 1 || s.charAt(i+1) > 'z' || s.charAt(i+1) < 'a'))
                  {
                     //The current character is 'I' and it is not followed by a lowercase letter.
                     //Therefore it represents the word "I" which is capitalized.
                     res += cur;
                  }
                  else
                  {
                     //This letter starts a new word but not a new sentence, so add the lowercase version of the character.
                     res += (char)(cur - 'A' + 'a');
                  }
               }
            }
            else res += cur;
         }
         System.out.println(res);
      }
   }
}
