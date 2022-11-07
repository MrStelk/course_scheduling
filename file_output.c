#include<stdio.h>
int main(){
int i;
    FILE *file;
    file = fopen(".\\Courses Schedule.txt","w");
    fprintf(file,"    COURSES SCHEDULE\n\n");
    for(i=0;i<no_of_batches;i++)
    {
        fprintf(file,"%s \n",batch_names[i]);
        for(int j =0;j<batch_data[i]->length;j++)
        {
            int n=batch_data[i]->arr[j];
            fprintf(file,"%s  -  %s\n",course_names[n], sessions[ courses[n].color]);
        }
        fprintf(file,"\n\n\n");
    }

}