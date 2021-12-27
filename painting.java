import java.util.*;
import java.io.*;

public class painting {
   static final double PI = 3.141592653589793;

   public static void main(String[] args) throws Exception{
      Scanner in = new Scanner(System.in);

      int t = in.nextInt();
      for (int z = 0; z < t; z++) {

         // take in input
         int n = in.nextInt();
         int radius = in.nextInt();

         double[] angle = new double[n];

         for (int i = 0; i < n; i++) {
            angle[i] = in.nextInt();
            angle[i] = angle[i] * (PI / 180);
         }
         // starting the total at 0
         double unpainted = 0;

         // for each of the given angles:
         for (int i = 0; i < n; i++) {

            /*
             * We are making a right triangle with half of the starting
             * angle, 90 degrees, and centerAngle The center angle is half
             * of the angle formed between the two points where the rays of
             * the angle are tangent to the circle and the circle's center
             * point. The area of two of these triangles represents the
             * unpainted area plus the area of the sector of the circle
             * formed by the center angle.
             * 
             * We are also finding the area of the sector of the given
             * circle that is formed from the center angle. Subtracting this
             * from the triangle area will give us the area of the corner,
             * or unpainted area.
             */

            // Halving the starting angle
            double halfAngle = angle[i] / 2;

            /*
             * Here we are solving for the center angle using the formula
             * center angle=PI-PI/2-halfAngle (this works because all angles
             * of a triangle add to 2*PI and we know the other 2)
             */
            double centerAngle = PI / 2 - halfAngle;

            /*
             * Here we are solving for the distance between the vertex of
             * the angle and the points where the angle is tangent to the
             * circle using the tangent function.
             */
            double sideB = radius / Math.tan(halfAngle);

            /*
             * Here we are solving for twice the area formed by the triangle
             * described above using the formula (sideB*radius)*2/2, where
             * sideB and radius are the legs of the right triangle.
             */
            double triangleArea = (sideB * radius);

            /*
             * Here we are solving for the ares of the sector described
             * above using the formula PI*radius*radius*centerAngle*2/2
             */
            double sectorArea = (centerAngle * radius * radius);

            /*
             * The area of the corner, or unpainted area, is the triangle
             * area-the sector area
             */
            double cornerArea = triangleArea - sectorArea;

            // add the area of this corner to the total
            unpainted += cornerArea;
         }

         // print answer
         System.out.print("Canvas #" + (z + 1) + ": ");
         System.out.printf("%.4f\n", unpainted);

      }

   }
}
