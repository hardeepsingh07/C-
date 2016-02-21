// Hardeep Singh
// Doing Matrix Calculations.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

int** createMatrix(int, int);
int** fillUpMatrix(int**, int, int);
void delete1(int**, int);
void mAdd(int**, int**, int, int, int, int);
void mSub(int**, int**, int, int, int, int);
void mMul(int**, int**, int, int, int, int);
void mTrans(int**, int**, int, int, int, int);

int main()
{
	int userPick;
	int **matrix1;
	int **matrix2;
	int x, y, x1, y1, number;
		cout << "\t***Welcome to Matrix Multiplication***\n";
		cout << "[1] Read from a File.\n";
		cout << "[2] Enter data manuelly.\n";
		cout << "[3] Exit.\n";
		cout << "How would you like to enter data, choose between 1 - 3: ";
		cin >> userPick;
		switch (userPick)
		{
		case 1:
			{
				cout << "\n\t\tMatrix Multiplications\n";
				string filename;
				cout << "Enter the file you want to read from, with extension: ";
				cin >> filename;
				ifstream inputfile;
				inputfile.open(filename);
				if (inputfile.fail())
				{
					cout << "File input invalid.";
					break;
				}
				inputfile >> x >> y;
				matrix1 = createMatrix(x, y);
				for (int i = 0; i < x; i++)
				{
					for (int j = 0; j < y; j++)
					{
						inputfile >> matrix1[i][j];
					}
				}
				inputfile >> x1 >> y1;
				matrix2 = createMatrix(x1, y1);
				for (int i = 0; i < x1; i++)
				{
					for (int j = 0; j < y1; j++)
					{
						inputfile >> matrix2[i][j];
					}
				}
				break;
			  }
		case 2:
			{
				cout << "\n\t\tMatrix Multiplications\n";
				cout << "Enter the order of Matrix1: ";
				cin >> x >> y;
				matrix1 = createMatrix(x, y);
				cout << "Enter the order of Matrix2: ";
				cin >> x1 >> y1;
				matrix2 = createMatrix(x1, y1);
				matrix1 = fillUpMatrix(matrix1, x, y);
				matrix2 = fillUpMatrix(matrix2, x1, y1);
			  }
		case 3: break;
		default: cout << "Invalid input.\n";
		}
		do
		{
			cout << " 1) Addition\n";
			cout << " 2) Subtraction\n";
			cout << " 3) Multiplication\n";
			cout << " 4) Transpose\n";
			cout << " 5) Exit\n";
			cout << " Enter your Choice :  ";
			cin >> number;
			switch (number)
			{
			case 1: if (x != x1 && y != y1)
						cout << "Matrix are not same size, they cannot be added.\n";
					else
						mAdd(matrix1, matrix2, x, y, x1, y1);
					break;
			case 2: if (x != x1 && y != y1)
						cout << "Matrix are not same size, they cannot be added.\n";
					else
						mSub(matrix1, matrix2, x, y, x1, y1);
					break;
			case 3: if (y != x1)
						cout << "Matrix1 column dont match Matrix2 row, Multiplication cannot be done. \n";
					else
						mMul(matrix1, matrix2, x, y, x1, y1);
					break;
			case 4: mTrans(matrix1, matrix2, x, y, x1, y1);
					break;
			case 5: //delete Matrix 1.
					delete1(matrix1, x);
					delete1(matrix2, x1);
					break;
				default: cout << "Invalid Number./n";
				break;
			}
		} while (number != 5);
	return 0;
}

void delete1(int **matrix, int x)
{
	for (int i = 0; i < x; i++)
		delete[] matrix[i];
	delete[] matrix;
}
int** createMatrix(int x, int y)
{
	int **a;
	a = new int *[x];
	for (int i = 0; i < x; i++)
		*(a + i) = new int[y];
	return a;
}
int** fillUpMatrix(int **matrix, int x, int y)
{
	cout << "Enter the elements of the array: \n";
	for (int i = 0; i < x; i++)
	for (int j = 0; j < y; j++)
		cin >> *(*(matrix + i) + j);

	return matrix;
}
void mAdd(int **matrix1, int **matrix2, int x, int y, int x1, int y1)
{
	int **result;
	result = createMatrix(x, y);
	// Add the values.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			*(*(result + i) + j) = (*(*(matrix1 + i) + j)) + (*(*(matrix2 + i) + j));

	// Print out the matrix.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cout << *(*(result + i) + j) << " ";
	cout << " \n";

	//delete the result array
	for (int i = 0; i < x; i++)
	{
		delete[]  result[i];
	}
	delete[] result;	
}
void mSub(int **matrix1, int **matrix2, int x, int y, int x1, int y1)
{
	int **result;
	result = createMatrix(x, y);

	// Subtract the values.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			*(*(result + i) + j) = (*(*(matrix1 + i) + j)) - (*(*(matrix2 + i) + j));

	// Print out the matrix.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cout << *(*(result + i) + j) << " ";
	cout << " \n";

	//delete the result array
	for (int i = 0; i < x; i++)
	{
		delete[]  result[i];
	}
	delete[] result;

}
void mMul(int **matrix1, int **matrix2, int x, int y, int x1, int y1)
{
	int **result;
	result = createMatrix(x, y1);

	// Multiply the values.
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y1; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < y; k++)
			{
				*(*(result + i) + j) = *(*(result + i) + j) + (*(*(matrix1 + i) + k) * *(*(matrix2 + k) + j));
			}
		}
	}
	// Print out the matrix.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cout << *(*(result + i) + j) << " ";
	cout << " \n";

	//delete the result array
	for (int i = 0; i < x; i++)
	{
		delete[]  result[i];
	}
	delete[] result;
}
void mTrans(int **matrix1, int **matrix2, int x, int y, int x1, int y1)
{
	//Matrix1 transpose
	int temp;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			temp = *(*(matrix1 + i) + j);
			*(*(matrix1 + i) + j) = *(*(matrix1 + j) + i);
			*(*(matrix1 + j) + i) = temp;
		}
	}
	// Print out the matrix.
	cout << "Matrix1 transpose is ";
	for(int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cout << *(*(matrix1 + i) + j) << " ";
	cout << "\n";



	//Matrix1 transpose
	int temper;
	for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < y1; j++)
		{
			temper = *(*(matrix2 + i) + j);
			*(*(matrix2 + i) + j) = *(*(matrix2 + j) + i);
			*(*(matrix2 + j) + i) = temper;
		}
	}
	// Print out the matrix.
	cout << "Matrix2 transpose is ";
	for (int i = 0; i < x1; i++)
		for (int j = 0; j < y1; j++)
			cout << *(*(matrix2 +i) + j) << " ";
	cout << "\n";
}
