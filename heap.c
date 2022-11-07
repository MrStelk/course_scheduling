extern int heap_size;
extern int no_of_courses;
extern course_node* courses;

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

void Build_heap(heap_node* heap)
{
	heap_size = no_of_courses;
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


heap_node Extract_max(heap_node* heap)
{
	heap_node result =  heap[0];
	heap_size--;
	heap[0] = heap[heap_size];
	
	Max_heapify(heap, 0);
	return result;
}