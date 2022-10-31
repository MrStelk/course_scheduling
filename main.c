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



// We'll create a hashmap from course_index to name of course.
typedef struct{
	int course_index;
	int colored;
	int color;
	int edges;
	new_arr neighbours;
}course_node;


// Heaping will happen on edges.
typedef struct{
	int course_index;
	int edges;
}heap_node;

course_node* courses; // Courses should be an array of course_nodes.
new_arr** batch_data; // Array of batches and their courses.
heap_node* heap; // heap

int heap_size = no_of_courses;

int** make_graph(); creates graph.
void Build_heap(heap_node* heap);
heap_node Extract_max(heap_node* heap);
void Max_heapify(heap_node* heap, int idx);


void update_course_nodes(int** graph, course_node* courses);


int main(void)
{
	batch_data = (new_arr**)malloc(sizeof(new_arr*)*no_of_batches);
	heap = (heap_node*)malloc(sizeof(heap_node)*no_of_courses);
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

	update_course_nodes(p, courses); // Todo

	build_heap(heap);

	int result = backtrack();
	if(result)
	{
		print_data(); // Todo.
	}
	else
	{
		print_no_solution(); // Todo.
	}
		
	clear_memory(); // Todo
	return;
}


int backtrack()
{
	if(heap_size)
	{
		heap_node course = Extract_max(heap);
		for(int i=0; i<no_of_colors; i++)
		{
			if(check_color(course.course_idx, colors[i])
			{	
				courses[course_index].color = colors[i];
				courses[course_index].colored = 1;
		
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



void Build_heap(heap_node* heap)
{
	for(int i=0; i<no_of_courses; i++)
	{	
		heap[i].course_index = i;
		heap[i].edges = courses[i].edges;
	}
	for(int i=no_of_courses/2; i>=0; i--)
	{	
		Max_heapify(heap, i);
	}
}


void Max_heapify(heap_node* heap, int idx)
{
	int left = idx*2+1;
	int right = (idx+1)*2;
	int largest = idx;

	if((left < heap_size) && (heap[left].edges > heap[largest].edges))
	{
		largest = left;
	}

	if((right < heap_size) && (heap[right].edges > heap[largest].edges))
	{
		largest = right;
	}
	
	if(largest != idx)
	{
		heap_node tmp = heap[idx];
		heap[idx] = heap[largest];
		heap[largest] = tmp;
		
		Max_heapify(heap, largest);
	}
	return;
}

heap_node Extract_max(heap_node* heap)
{
	heap_node result =  heap[0];
	heap_size--;
	heap[0] = heap[heap_size];
	
	Max_heapify(heap, 0);
	return result;
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
