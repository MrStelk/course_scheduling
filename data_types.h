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