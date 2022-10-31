#include <stdio.h>
#include <stdlib.h>

#define no_of_courses 8

typedef struct{
	int course_index;
	int edges;
}heap_node;

typedef struct{
	int course_index;
	int colored;
	int color;
	int edges;
}course_node;


int heap_size = no_of_courses;
course_node* courses;

heap_node* heap;

void Build_heap(heap_node* heap);
heap_node Extract_max(heap_node* heap);
void Max_heapify(heap_node* heap, int idx);

int main(void)
{
	heap = (heap_node*)malloc(sizeof(heap_node)*no_of_courses);
	courses = (course_node*)malloc(sizeof(course_node)*no_of_courses);
	
	courses[0].edges = 5;
	courses[1].edges = 18;
	courses[2].edges = 10;
	courses[3].edges = 2;
	courses[4].edges = 2;
	courses[5].edges = 18;
	courses[6].edges = 7;
	courses[7].edges = 13;
		
	Build_heap(heap);
	
	for(int i=0; i<heap_size; i++)
	{
		printf("%d ", heap[i].edges);
	}
	
	printf("\n\n");
	while(heap_size)
	{
		heap_node tmp = Extract_max(heap);
		printf("%d\n",tmp.edges);

		for(int i=0; i<heap_size; i++)
		{
			printf("%d ", heap[i].edges);
		}
		printf("\n");
	}
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
