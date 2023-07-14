#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_types.h"
#include "graph_init.c"
#include "heap.c"
#include "file_parser.c"
#include "file_output.c"

int no_of_batches;
int no_of_colors;
int no_of_courses;


char** course_names;
char** batch_names;
char** color_names;



course_node* courses; // Courses should be an array of course_nodes.
new_arr** batch_data; // Array of batches and their courses.
heap_node* heap; // heap


int backtrack();
int check_color(int course_index , int color);

int* colors;
int heap_size;

int main(void)
{
	FILE* file = fopen("data.txt", "r");
	char strin[30];
	fgets(strin, 30, file);

	strin[strleng(strin)-1] = '\0';
	no_of_batches = strtoint(&strin[16]);
	

	batch_data = (new_arr**)malloc(sizeof(new_arr*)*no_of_batches);
	parsefile(file, batch_data);
	colors = (int*)malloc(sizeof(int)*no_of_colors);
	
	heap = (heap_node*)malloc(sizeof(heap_node)*no_of_courses);
	courses = (course_node*)malloc(sizeof(course_node)*no_of_courses);

	int** p = make_graph();

	update_course_nodes(p, courses);
	Build_heap(heap);

	for(int i=0; i<no_of_colors; i++)
	{
		colors[i] = i;
	}

	int result = backtrack();
	if(result)
	{
		outfile(batch_data);
		printf("\n\n------------\nSolution found\n------------\n\n");
	}
	else
	{
		FILE* out = fopen("Schedule.txt", "w");
		fprintf(out, "----No solution was found");
		printf("\n\n------------\nNo Solution found\n------------\n\n");
		fclose(out);
	}
	fclose(file);
	return 0;
}


int backtrack()
{
	if(heap_size)
	{
		heap_node course = Extract_max(heap);
		for(int i=0; i<no_of_colors; i++)
		{
			if(check_color(course.course_index, colors[i]))
			{	
				courses[course.course_index].color = colors[i];
				courses[course.course_index].colored = 1;
		
				if(!backtrack())
				{
					continue;
				}
				return 1;
			}
		}
		return 0;
	}
	return 1;
}



// Checks if color can be assigned.
int check_color(int course_index , int color)
{
	for(int i = 0 ; i < courses[course_index].neighbours.length; i++)
	{
		if((courses[courses[course_index].neighbours.arr[i]].colored == 1) && (courses[courses[course_index].neighbours.arr[i]].color == color))
		{
			return 0; //returns 0 if neighbor course color matches with the given color(i.e we should not give this color to the given course).
		}
	}
	return 1; //return 1 indicates we can give the color to the course.
}
