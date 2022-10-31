#include<stdio.h>
#include<stdlib.h>


#define no_of_courses 8
#define no_of_batches 4

typedef struct{
	int length;
	int* arr;
}new_arr;

typedef struct{
	int course_index;
	int colored;
	int color;
	int edges;
	new_arr neighbours;
}course_node;

int** make_graph();
void update_course_nodes(int** graph, course_node* courses);

new_arr** batch_data; // Array of batches and their courses.
course_node* courses;

int main(void)
{
	batch_data = (new_arr**)malloc(sizeof(new_arr*)*no_of_batches);
	courses = (course_node*)malloc(sizeof(course_node)*no_of_courses);

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

	for(int i=0; i<no_of_courses; i++)
	{
		for(int k=0; k<no_of_courses; k++)
		{
			printf("%d ", p[i][k]);
		}
		printf("\n");
	}


	update_course_nodes(p, courses); // Todo

	for(int i=0; i<no_of_courses; i++)
	{
		printf("node = %d edges = %d neighbours len= %d.   ", i, courses[i].edges, courses[i].neighbours.length);
		for(int k=0; k<courses[i].neighbours.length; k++)
		{
			printf("%d ", courses[i].neighbours.arr[k]);	
		}
		printf("\n");
	}
}


// Updates no of edges for all courses.
void update_course_nodes(int** graph, course_node* courses) // Graph will be available globally.
{
	int i,k;
	for(k=0;k<no_of_courses;k++)
	{
		courses[k].edges = 0;
		courses[k].neighbours.length = 0;
		courses[k].neighbours.arr = (int*)malloc(sizeof(int));
	
		for(i=0;i<no_of_courses;i++)
		{
	        	if(graph[k][i])
         		{
              			courses[k].edges++;
				courses[k].neighbours.length++;
				courses[k].neighbours.arr = (int*)realloc(courses[k].neighbours.arr, sizeof(int)*courses[k].neighbours.length);
				courses[k].neighbours.arr[(courses[k].neighbours.length)-1] = i;
			}
      		}
      }
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