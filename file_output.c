extern new_arr** batch_data;
extern course_node* courses;

extern int no_of_branches;
extern int no_of_courses;
extern int no_of_colors;

extern char** course_names;
extern char** batch_names;

void outfile(new_arr** batch_data)
{
	FILE* file = fopen("Schedule.txt","w");
	fprintf(file,"    COURSES SCHEDULE\n\n");
	for(int i=0;i<no_of_batches;i++)
	{
		fprintf(file,"%s \n",batch_names[i]);
		for(int j =0;j<batch_data[i]->length;j++)
		{
			int n=batch_data[i]->arr[j];
			fprintf(file,"%s  -  %d\n",course_names[n], courses[n].color);
        	}
		fprintf(file,"\n\n\n");
	}
}