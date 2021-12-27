#include <stdio.h>
#include <math.h>

#define PI   3.141592653589793

//converts degrees to radians
double toRadians(double angle){
    return angle*PI/180.0;
}

int main() {

    //reading in from the file
    FILE *filePointer, *out;
    filePointer = stdin;

    //reading in the number of cases
    int numCases;
    fscanf(filePointer,"%d",&numCases);
    int cse;
    for(cse = 1; cse <= numCases; cse++){

        //reading in the number of angles and the radius of the paintbrush
        int numCorners, radius;
        fscanf(filePointer,"%d",&numCorners);
        fscanf(filePointer,"%d",&radius);

        //loop for each corner, and add the unpainted area to a running sum
        double sum = 0;
        while(numCorners-->0){

            //reading in the angles
            double angle;
            fscanf(filePointer,"%lf",&angle);

            /*
    To understand this solution, you'll need to draw a sketch of the corner. After you draw the lines forming the corner draw a
circle wedged in that corner to represent the position of the brush when it's wedged into the corner as far as possible.
Draw two lines from the center of the circle to the lines forming the corner. Two Perpendicular angles are formed as the
lines from the center of the circle are perpendicular to the lines forming the corner as the corner lines are tangent to circle.
Finally, draw a line from the center of the circle to the angle of the corner, bisecting it in half to form two congruent right triangles.

    Now to get the unpainted area you'll need to find the area of the two right triangles and subtract out the area still occupied
in the circle, which would be painted. Take a look at one of the right triangles: we have one of it's sides (let's called its height), it's the radius of the circle.
We also have the angle opposite that side: it's half the original angle given. This means we can get the base of the triangle with tangent, and the area
of the triangle is 1/2 base*height. The area of both triangles is twice that. Now we need to find the portion occupied by the circle inside the triangles.
In your sketch, a "wedge" of the circle is inside the triangles, and you can find the area of this wedge by finding the fraction of the
total circle this wedge takes up. The angle of the wedge is easily found since it's the sum of two angles (which are the same) of the triangles already drawn.
The angle can be found using the fact that the angles of a triangle sum to 180 degrees and the other two angles in the triangle are 90 degrees and 1/2 the original angle.
Finally the area of the circle in the right triangles is CIRCLE_AREA*(WEDGE_ANGLE/360 degrees) or PI*(radius^2)*( 2*(180 -90 - .5*angle)/360  )

*/
            //base of the right triangle, found using tangent
            double base = radius/(tan(toRadians(angle)/2.0));

            //area of the two triangles minus the area of the wedge of the circle
            sum += base*radius - PI*radius*radius*(2*(90-.5*angle)/360.0);
        }

        //printing output to four decimal places using %.4lf
        printf("Canvas #%d: %.4lf\n",cse,sum);

    }



    fclose(filePointer);
    return 0;
}
