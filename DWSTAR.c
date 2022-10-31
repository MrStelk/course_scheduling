void Build_heap(heap_node* heap)
{
	for(int i=0; i<no_of_courses; i++)
	{	
		heap[i].index = i;
		heap[i].edges = courses[i].edges;
	}
	for(int i=no_of_courses/2; i>=0; i--)
	{	
		max_heapify(heap, i);
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
		
		max_heapify(heap, largest);
	}
	return;
}

heap_node Extract_max(heap_node* heap)
{
	heap_node result =  heap[0];
	heap_size--;
	heap[0] = heap[heap_size];
	
	max_heapify(heap, 0);
	return result;
}
