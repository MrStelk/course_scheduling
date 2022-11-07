extern int no_of_courses;
extern int no_of_batches;

extern new_arr** batch_data;

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