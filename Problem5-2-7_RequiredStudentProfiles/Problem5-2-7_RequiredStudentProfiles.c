// Problem5-2-7_RequiredStudentProfiles.c : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma warning( disable : 4996 )

struct Student
{
	size_t sno;
	char sname[20];
};

typedef struct Student Student;


int main()
{
	size_t studentsLength;
	scanf("%zu", &studentsLength);
	Student *students = (Student *)malloc(sizeof(Student) * studentsLength);
	for (size_t i = 0; i < studentsLength; i++)
	{
		printf("Enter student number: ");
		scanf("%zu", &students[i].sno);
		getchar();
		size_t temp;
		for (temp = 0; temp < i; temp++)
		{
			if (students[temp].sno == students[i].sno)
			{
				break;
			}
		}
		if (temp < i)
		{
			printf("Invalid input\n");
			i--;
			continue;
		}
		printf("Enter student name: ");
		gets_s(students[i].sname, 20);
	}
	size_t *locations = (size_t *)malloc(sizeof(size_t) * studentsLength);
	size_t locationsLength = 0;
	for (size_t i = 0; i < studentsLength; i++)
	{
		if (students[i].sname[strlen(students[i].sname) - 1] == 'h')
		{
			locations[locationsLength] = i;
			locationsLength++;
		}
	}
	for (size_t i = 0; i < locationsLength; i++)
	{
		printf("%zu\n", students[locations[i]].sno);
		puts(students[locations[i]].sname);
	}
	free(locations);
	free(students);
    return 0;
}

