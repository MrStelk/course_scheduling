# course_scheduling
This is a program that assigns slots to university courses so that there are no temporal clashes. A clash is said to exist if two courses are alloted in a same time slot with a student enrolled in both the courses. We used the [Backtracking](https://en.wikipedia.org/wiki/Backtracking) algorithm with [DSATUR heuristic](https://en.wikipedia.org/wiki/DSatur) to solve this problem. Additional details about the working and theroritical aspects are [here](./Report_zip_file_Group_34.pdf).
[ReadME_Group_34.txt](ReadME_Group_34.txt) contains compile instructions and input formats expected by the program.
Repo is organized as:
* main.c contains the actual program that needs to be run.
* DWSTAR.c contains the heuritic.
* check_color.c contains code to check color for nodes.
* data.txt is the input file to the program.
* file_output.c prints the result of the program to a file.
* file_parser.c processes the input file data.txt
* graph_init.c initialises the graph.
* heap.c builds the heap to pick nodes according to DSATUR.
* update_course_nodes.c updates colors and no of edges for all courses.

This project was made as part of CS201 Data structures and Algorithms course.
