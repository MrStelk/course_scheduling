extern  int no_of_batches;
extern int no_of_colors;
extern int no_of_courses;

extern char** course_names;
extern char** batch_names;
extern char** color_names;

extern new_arr** batch_data;

unsigned power(unsigned a, unsigned b)
{
	int i=1;
	for(int j=0; j<b;j++, i*=a);
	return i;
}


int strleng(char* str)
{
	int n=0;
	for(;str[n] != '\0';n++);
	return n;
}


int strtoint(char* num)
{
	int sum=0, multiplier=1;
	int i=strleng(num)-1, j=0;
	if(num[0] == '-')
	{
		i--; j++;
		multiplier = -1;
	}
	for(; i>=0; i--, j++)
	{
		sum+=power(10,i)*(num[j]-48)*multiplier;
	}
	return sum;
}


int strcopy(char* destination, char* source)
{
	int p = strleng(source);
	for(int i=0; i<p; i++)
	{
		*(destination+i) = *(source+i);
	}
	destination[strleng(source)] = '\0';
	return 1;
}
void parsefile(FILE* file, new_arr** batchu_data)
{
	char str[30];
	int lines = 0, done=0;
	while(!feof(file))
	{
		fgets(str, 30, file);
		if(str[0] == '\n')
		{
			continue;
		}

		switch(lines)
		{
			case(0):
			{
				str[strleng(str)-1] = '\0';
				no_of_courses = strtoint(&str[16]);
				lines++;
				continue;

			}
			case(1):
			{
				str[strleng(str)-1] = '\0';
				no_of_colors = strtoint(&str[17]);
				lines++;
				continue;
			}
			case(2):
			{
				course_names = (char**)malloc(sizeof(char*)*no_of_courses);
				for(int i = 0; i<no_of_courses; i++)
				{
					course_names[i] = (char*)malloc(sizeof(char)*30);
					fgets(course_names[i], 30, file);
					lines++;
				}
				continue;
			}
		}

		if(lines == 2+no_of_courses)
		{
			batch_names = (char**)malloc(sizeof(char*)*no_of_batches);

			for(int i = 0, course_num; i<no_of_batches; i++)
			{
				batchu_data[i] = (new_arr*)malloc(sizeof(new_arr));

				batch_names[i] = (char*)malloc(sizeof(char)*40);
				char tmp[40];
				fgets(tmp, 40, file);
				tmp[strleng(tmp)-1] = '\0';
				for(int j=strleng(tmp)-1; j>=0; j--)
				{
					if(tmp[j] == ':')
					{
						tmp[j] = '\0';
						course_num = strtoint(&tmp[j+2]);
						batchu_data[i]->length = course_num;
						batchu_data[i]->arr = (int*)malloc(sizeof(int)*course_num);
						break;
					}
				}
				strcopy(batch_names[i], tmp);
				lines++;
			}
		}

		fgets(str, 30, file);
		if(str[0] == '\n')
		{
			continue;
		}

		if(lines == 2+no_of_courses+no_of_batches)
		{
			for(int k=0; k<no_of_batches; k++)
			{
				for(int i=0; i<batchu_data[k]->length; i++)
				{
					fgets(str, 30, file);
					lines++;
					for(int j=0; j<no_of_courses; j++)
					{
						if(strcmp(str, course_names[j]) == 0)
						{
							batchu_data[k]->arr[i] = j;
							break;
						}
					}
				}
				fgets(str, 30, file);
				if(feof(file))
				{
					done = 1;
					break;
				}
				while(str[0] == '\n')
				{
					fgets(str, 30, file);
				}
			}
		}
		
		if(lines != 2+no_of_courses+no_of_batches)
		{
			color_names = (char**)malloc(sizeof(char*)*no_of_colors);
			for(int i=0; i<no_of_colors; i++)
			{
				fgets(str, 30, file);
				color_names[i] = (char*)malloc(sizeof(char)*30);
				strcopy(color_names[i], str);
				lines++;
			}
			break;
		}
		if(done)
		{
			break;
		}
	}
	return;
}
