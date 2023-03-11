//Justin Ritchey 9/11/2020. This is for Machine problem 1 part 2. This cpp is meant to read a data file to eof or 20 students have been read. It will then print out all of studnets info and grades as well as print out the student with the highest grade

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

struct students
{
	string studentFName, studnetLName = "";
	int testScore = 0;
	char grade = '\0';
};

//Functions
void transferData(students dataArray[]);
void grading(students dataArray[]);
students highScore(students dataArray[]);
void print(students dataArray[], students check);


void main()
{
	   students check;
       students dataArray[20];

	   transferData(dataArray);
	   grading(dataArray);
	   check = highScore(dataArray);
	   print(dataArray, check);
	   
}

void transferData(students array[])
{
	int test, i = 0;
	
	string first, last;

	ifstream file("data1.txt");

	if (file.is_open());
	{
		while (file >> first >> last >> test)
		{
			array[i].studentFName = first;
			array[i].studnetLName = last;
			array[i].testScore = test;
			i++;
		}

	}
	cout << "\n";
}

void grading(students array[])
{
	for (int i = 0; i < 20;i++)
	{

		if (array[i].testScore >= 90) 
		{
			array[i].grade = 'A';
		}
		else if (array[i].testScore >= 80)
		{
			array[i].grade = 'B';
		}
		else if (array[i].testScore >= 70)
		{
			array[i].grade = 'C';
		}
		else if (array[i].testScore >= 60)
		{
			array[i].grade = 'D';
		}
		else
		{
			array[i].grade = 'F';
		}

	}
}

students highScore(students array[])
{
    students check;
	int high = 0;
	string winner = "";

	
	for (int i = 0;i < 20;i++)
	{
		if (array[i].testScore > high)
		{
			high = array[i].testScore;
			check = array[i];
		}
	}
	return check;

}

void print(students array[], students check)
{
	string words = "";
	int length = 0;

	cout << "The student with the highest score is: " << check.studentFName << ", " << check.studnetLName;
	cout << " with a score of: " << check.testScore << "\n\n";

	cout << "Here are the results for everyone: \n";
	
	for (int i = 0;i < 20;i++)
	{
		cout << left << array[i].studentFName << ", " << array[i].studnetLName;

		words += array[i].studentFName;
		words += array[i].studnetLName;

		length = size(words);
		length = 16 - length;

		for (int i = 0; i < length;i++)
		{
			cout << " ";
		}
		cout << array[i].testScore << "   " << array[i].grade << "\n";
		words = "";
		length = 0;
	}

}