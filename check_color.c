#include<stdio.h>

struct node
{
    char *course_name;                    
    int colored;                            //it is to maintain whether the course is colored or not as a boolen (1 or 0)
    int color;                              //it stores the color name as an integer corresponds to that color if the course is colored    
};

/* check_color() is a function that takes to integer arguments one for course and other for color
   here we check whether the given course can be colored with the given color or not by checking its neighbor courses colors
 */

int check_color(int course , int color)
{
    struct node *neighbors = neighbor(course);            //neighbor() is a function that return the struct node type array contains neighbour courses that are connected with the given course.

    for(int i = 0 ; i< sizeof(neighbors) ; i++)
    {
          if(neighbors[i].colored == 1 && neighbors[i].color == color )
           {
             return 0;                                     //returns 0 if neighbor course color matches with the given color(i.e we should not give this color to the given course)
           }
    }

    return 1;                                              //return 1 indicates we can give the color to the course.
}