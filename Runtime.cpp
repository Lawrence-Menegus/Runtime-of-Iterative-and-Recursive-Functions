// Name: Lawrence Menegus
// Date:9/6/23
// Course: Data Structures and Algorithms
// Description: This program to demonstrate the time diffences between Iterative and recursive functions



#include <iostream>    // needed to perform C++ I/O 
#include <string>
#include <cstdlib> //use absolute function
#include <time.h> //use clock_t start, stop;
using namespace std;

long double rabbit(int n);
long double IterativeRabbit(int n);
void writeBackward(string s);
void IterativewriteBackward(string s);
int binarySearch(const int anArray[], int first, int last, int target);
int IterativeBinarySearch(int array[], int size, int target);
void cheers(int n);
void verticalDigits(int num2);

const int SIZE = 40, SIZE2 = 10000;

int main()
{
	cout << "#4 - a: \n";
	int res, array[SIZE] = { }, array2[SIZE2] = {};
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = 2 * i + 1;
	}

	for (int i = 0; i < SIZE2; i++)
	{
		array2[i] = 2 * i + 1;
	}

	string s = "think";

	clock_t start, stop;



	//Rabbit functions
	start = clock();
	res = rabbit(SIZE);
	stop = clock();
	cout << "The return value of the rabbit function is " << res << endl;
	cout << "Running time for the function is " << static_cast<double>(stop - start) << endl; //in miliseconds
	cout << endl;

	start = clock();
	res = IterativeRabbit(SIZE);
	stop = clock();
	cout << "The return value of the IterativeRabbit function is " << res << endl;
	cout << "Running time for the function is  " << static_cast<double>(stop - start) << endl; //in miliseconds
	cout << endl;
	cout << "------------------------------------------------------------------\n\n";



	//writeBackward functions

	cout << "The return value of the writeBackward function is ";
	start = clock();
	writeBackward(s);
	stop = clock();
	cout << "\n Running time for the function is " << static_cast<double>(stop - start) << endl; //in miliseconds
	cout << endl;


	cout << "The return value of the IterativewriteBackward function is ";
	start = clock();
	IterativewriteBackward(s);
	stop = clock();
	cout << "\n Running time for the function is " << static_cast<double>(stop - start) << endl; //in miliseconds
	cout << endl;

	cout << "------------------------------------------------------------------\n\n";

	//binary search functions
	start = clock();
	res = binarySearch(array2, 0, SIZE2 - 1, 3261);
	stop = clock();
	cout << "The return value of the binarySearch function is " << res << endl;
	cout << "Running time for Ex1 is " << static_cast<double>(stop - start) << endl; //in miliseconds
	cout << endl;

	start = clock();
	res = IterativeBinarySearch(array2, SIZE2, 3261);
	stop = clock();
	cout << "The return value of the IterativeBinarySearch function is " << res << endl;
	cout << "Running time for Ex1 is " << static_cast<double>(stop - start) << endl; //in miliseconds
	cout << endl;
	cout << "------------------------------------------------------------------\n\n";

	//# 4- b
	cout << "# 4 - b: \n";
	int num = 3;
	cheers(num);

	cout << endl;

	int num2 = -1234;
	cout << "Let's print " << num2 << " stacked vertically: " << endl;
	verticalDigits(num2);

	return 0;
}


// Recursive Rabbit Function 
long double rabbit(int n)
{
	//base 
	if (n <= 2)
	{
		return	1;
	}
	//recursive 
	else
	{
		return rabbit(n - 1) + rabbit(n - 2);
	}
}

// Iterative Rabbit verison 
long double IterativeRabbit(int n)
{
		int prev = 1;  
		int curr = 1;  
		int next = 1; 

		for (int i = 3; i <= n; i++)
		{
			next = curr + prev;
			prev = curr;
			curr = next;
		}
		return next;

}
// Recursive version of writing a string backwards 
void writeBackward(string s)
{ 
	if (s.length() > 0)
	{
		cout << s.substr(s.length() - 1, 1);
		writeBackward(s.substr(0, s.length() - 1));
	}
}

// Iternative version of writing a string backwards 
void IterativewriteBackward(string s)
{ 
	while(s.length() > 0)
	{
		cout << s.substr(s.length() - 1, 1);
		s = s.substr(0, s.length() - 1);
	}
}

// Recursive Version of Binary Search 
int binarySearch(const int anArray[], int first, int last, int target)
{
	int mid = (first + last) / 2;
	if (last >= first)
	{
		if (anArray[mid] == target) // if middle of array equals target return middle value 
		{
			return mid;
		}
		else if (anArray[mid] > target)
		{
			return binarySearch(anArray, first, mid - 1, target); // if greater than target, binary search function is called again with first index before the middle index as the search area 
		}
		else
		{
			return binarySearch(anArray, mid + 1, last, target);// if less than target binary serach is called again with the middle to last indecies as search area 
		}
	}
}
	

// Iterative Version of Binary Search 
int IterativeBinarySearch(int array[], int size, int target)
{
	int first = 0; 
	int last = size - 1; 
	int mid = (last + first) / 2;
	while (last >= first)
	{
		if (array[mid] == target)
		{
			return mid;
		}
		if (array[mid] > target)
		{
			last = mid - 1;
		}
		else 
		{
			first = mid + 1;
		}
		mid = (first + last) / 2; 
	}
	return mid;
}

// Recursive way of printing Cheers
void cheers(int n)
{
	if (n <= 1)
	{
		cout << "Hurray" << endl;
	}
	else
	{
		cheers(n - 1);
		cout << "Hip" << endl;
	}

}

// Using recursion to print Digits Vertically
void verticalDigits(int num2)
{
	if (num2 < 0)
	{
		cout << "-" << endl;
		verticalDigits(abs(num2));
	}
	else if (num2 / 10 > 0)
	{
		
		verticalDigits(num2 / 10);  // if number greater than 10 divides by 10 and recalls itself
		cout << num2 % 10 << endl;
	}
	else {
		cout << num2 << endl;
	}

}
