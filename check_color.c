#include<stdio.h>

/*
	check_color() is a function that takes two integer arguments one for course and other for color
	here we check whether the given course can be colored with the given color or not by checking its neighbor courses colors
*/


typedef struct{
	int length;
	int* arr;
}new_arr;


int main(void)
{
	batch_data = (new_arr**)malloc(sizeof(new_arr*)*no_of_batches);
	heap = (heap_node*)malloc(sizeof(heap_node)*no_of_courses);

	batch_data[0] = (new_arr*)malloc(sizeof(new_arr));
	batch_data[1] = (new_arr*)malloc(sizeof(new_arr));
	batch_data[2] = (new_arr*)malloc(sizeof(new_arr));
	batch_data[3] = (new_arr*)malloc(sizeof(new_arr));
	
	batch_data[0]->length = 4;
	batch_data[1]->length = 2;
	batch_data[2]->length = 6;
	batch_data[3]->length = 3;

	batch_data[0]->arr = (int*)malloc(sizeof(int)*4);
	batch_data[1]->arr = (int*)malloc(sizeof(int)*2);
	batch_data[2]->arr = (int*)malloc(sizeof(int)*6);
	batch_data[3]->arr = (int*)malloc(sizeof(int)*3);	

	batch_data[0]->arr[0] = 2;
	batch_data[0]->arr[1] = 4;
	batch_data[0]->arr[2] = 7;
	batch_data[0]->arr[3] = 6;

	batch_data[1]->arr[0] = 3;
	batch_data[1]->arr[1] = 1;

	batch_data[2]->arr[0] = 5;
	batch_data[2]->arr[1] = 0;
	batch_data[2]->arr[2] = 2;
	batch_data[2]->arr[3] = 6;
	batch_data[2]->arr[4] = 4;
	batch_data[2]->arr[5] = 3;

	batch_data[3]->arr[0] = 1;
	batch_data[3]->arr[1] = 6;
	batch_data[3]->arr[2] = 0;
	
	int** p = make_graph();

}

int check_color(int course_index , int color)
{
	new_arr neigh = neighbours(course_index, graph); //neighbor() is a function that return the struct node type array contains neighbour courses that are connected with the given course.

	for(int i = 0 ; i < neigh.length; i++)
	{
		if((courses[neigh.arr[i]].colored == 1) && (courses[neigh.arr[i]].color == courses[course_index].color))
		{
			return 0; //returns 0 if neighbor course color matches with the given color(i.e we should not give this color to the given course).
		}
	}
	return 1; //return 1 indicates we can give the color to the course.
}


// Returns an array of neighbours for a given course.
new_arr neighbours(int course_index, int** graph)
{
	new_arr neigh;
	neigh.length = 0;
	neigh.arr = (int*)malloc(sizeof(int));
	for(int i=0; i<no_of_courses; i++)
	{
		if(graph[course_index][i])
		{
			neigh.length++;
			neigh.arr = (int*)realloc(neigh.arr, neigh.length);
			neigh.arr[neigh.length-1] = i;
		}
	}
	if(!(neigh.length))
	{
		free(neigh.arr);
		neigh.arr = NULL;
	}	
	return neigh;
}