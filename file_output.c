extern new_arr** batch_data;
extern course_node* courses;

extern int no_of_branches;
extern int no_of_courses;
extern int no_of_colors;

extern char** course_names;
extern char** batch_names;
extern char** color_names;

void outfile(new_arr** batch_data)
{
	FILE* file = fopen("Schedule.txt","w");
	fprintf(file,"-----------------------------------------\n          COURSES SCHEDULE\n-----------------------------------------\n\n\n");
	for(int i=0;i<no_of_batches;i++)
	{
		fprintf(file,"---------------------------\n%s \n-----------------\n",batch_names[i]);
		for(int j =0;j<batch_data[i]->length;j++)
		{
			int n=batch_data[i]->arr[j];
			fprintf(file,"%s  -  %s\n",course_names[n], color_names[courses[n].color]);
        	}
		fprintf(file,"---------------------------\n\n\n");
	}
	fclose(file);
}