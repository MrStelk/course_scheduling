Name of students : 

 Dasaraju karthik (2021csb1081)
 Gattu pavithran  (2021csb1088)
 Kola sai datta   (2021csb1106)

Mentoring TA : Avadesh Gaur

PROJECT NAME : course scheduling with graph colouring

SUMMARY :
	The aim of this project is to design a time table that schedules the classes for all branches of students such that there is no overlapping of classes in the same time slot.

INPUT FILE FORMAT:-

NO.OF BATCHES = x
NO.OF COURSES = y
NO.OF SESSIONS = z

COURSES
XX201
XY201
YY201
YY203

BRANCH : NO.OF COURSES
Computer Science : a
Mathematics and Computing : b
Electrical : c

BRANCH : COURSES
Computer Science :
XX201
YY203
ZZ201

Mathematics and Computing :
XX201
XY201
YY201

Electrical :
XY201
YY201
YY203

SESSIONS
x:00 am - x:50 am
a:00 am - a:50 am
y:00 am - y:50 pm
---End
	    

COMPILING INSTRUCTION:
	gcc main.c -o p
	./p

OUTPUT FILE:
Output file named "Schedule.txt" will be created. If proper assigning is possible, this file will contain the time table. 

