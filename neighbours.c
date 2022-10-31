#include <stdio.h>
#include <stdlib.h>

#define no_of_batches 4
#define no_of_colors 5
#define no_of_courses 8


// Array with a length attribute.
typedef struct{
	int length;
	int* arr;
}new_arr;

new_arr** batch_data; // Array of batches and their courses.


int** make_graph();
new_arr neighbours(int course_index, int** graph);

int main(void)
{
	batch_data = (new_arr**)malloc(sizeof(new_arr*)*no_of_batches);

	batch_data[0] = (new_arr*)malloc(sizeof(new_arr));
	batch_data[1] = (new_arr*)malloc(sizeof(new_arr));
	batch_data[2] = (new_arr*)malloc(sizeof(new_arr));
	batch_data[3] = (new_arr*)malloc(sizeof(new_arr));
	
	batch_data[0]->length = 4;
	batch_data[1]->length = 2;
	batch_data[2]->length = 3;
	batch_data[3]->length = 4;

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


	batch_data[3]->arr[0] = 1;
	batch_data[3]->arr[1] = 6;
	batch_data[3]->arr[2] = 0;
	batch_data[3]->arr[3] = 4;
	
	int** p = make_graph(); 
	new_arr ret = neighbours(3, p);
		
	for(int i=0; i<ret.length; i++)
	{	
		printf("%d ", ret.arr[i]);
	}

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

int** make_graph() 
{
	int** graph = malloc(sizeof(int*)*no_of_courses);
	for(int i=0; i<no_of_courses; i++)
	{
		graph[i] = malloc(sizeof(int)*no_of_courses);
	}
	
	for(int i=0; i<no_of_courses; i++)
	{
		for(int j=0; j<no_of_courses; j++)
		{
			graph[i][j] = 0;
		}
	}
	
	for(int i=0; i<no_of_batches; i++)
	{
		for(int j=0; j<batch_data[i]->length; j++)
		{
			for(int k=0; k<batch_data[i]->length; k++)
			{
				if(j != k)
				{
					graph[batch_data[i]->arr[j]][batch_data[i]->arr[k]] = 1;
				}
			}
		}
	}

	return graph;
}