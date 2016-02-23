// Hardeep Singh
// Doing Matrix Calculations.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

double** createMatrix(int, int);
double** fillUpMatrix(double**, int, int);
void delete1(double**, int);
void mAdd(double**, double**, int, int, int, int);
void mSub(double**, double**, int, int, int, int);
void mMul(double**, double**, int, int, int, int);
void print(double **, int, int);

int main() {
	double **matrix1;
	double **matrix2;
	int x, y, x1, y1, number;
	cout << "\t***Welcome to Matrix Multiplication***\n";

	cout << "\n\t\tMatrix Multiplications\n";
	cout << "Enter the order of Matrix1(n <space> n): ";
	cin >> x >> y;
	matrix1 = createMatrix(x, y);

	cout << "Enter the order of Matrix2(n <space> n): ";
	cin >> x1 >> y1;
	matrix2 = createMatrix(x1, y1);

	matrix1 = fillUpMatrix(matrix1, x, y);
	cout << endl;
	matrix2 = fillUpMatrix(matrix2, x1, y1);
	cout << endl;

	do {
		cout << "***Operations***\n";
		cout << " 1) Addition\n";
		cout << " 2) Subtraction\n";
		cout << " 3) Multiplication\n";
		cout << " 4) Exit\n";
		cout << " Enter your Choice :  ";
		cin >> number;
		switch (number) {
		case 1:
			if (x != x1 && y != y1)
				cout << "Matrix are not same size, they cannot be added.\n";
			else
				mAdd(matrix1, matrix2, x, y, x1, y1);
			break;
		case 2:
			if (x != x1 && y != y1)
				cout << "Matrix are not same size, they cannot be added.\n";
			else
				mSub(matrix1, matrix2, x, y, x1, y1);
			break;
		case 3:
			if (y != x1)
				cout
						<< "Matrix1 column don't match Matrix2 row, Multiplication cannot be done. \n";
			else
				mMul(matrix1, matrix2, x, y, x1, y1);
			break;
		case 4:
			cout << "Good Bye!";
			delete1(matrix1, x);
			delete1(matrix2, x1);
			break;
		default:
			cout << "Invalid Number./n";
			break;
		}
	} while (number != 4);
	return 0;
}

void delete1(double **matrix, int x) {
	for (int i = 0; i < x; i++)
		delete[] matrix[i];
	delete[] matrix;
}

double** createMatrix(int x, int y) {
	double **a;
	a = new double *[x];
	for (int i = 0; i < x; i++)
		*(a + i) = new double[y];
	return a;
}

void print(double **result, int s, int q) {
	for (int i = 0; i < s; i++) {
		cout << endl;
		for (int j = 0; j < q; j++) {
			cout << *(*(result + i) + j) << " ";
		}
	}
	cout << endl;
}

double** fillUpMatrix(double **matrix, int x, int y) {
	cout << "Enter the elements of the array: \n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << "Enter  " << i << ":" << j << "th: ";
			cin >> *(*(matrix + i) + j);
		}
	}

	//print the matrix
	cout << endl;
	cout << "Matrix: ";
	print(matrix, x, y);

	return matrix;
}
void mAdd(double **matrix1, double **matrix2, int x, int y, int x1, int y1) {
	double **result;
	result = createMatrix(x, y);
	// Add the values.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			*(*(result + i) + j) = (*(*(matrix1 + i) + j))
					+ (*(*(matrix2 + i) + j));

	// Print out the matrix.
	cout << endl << "Result: ";
	print(result, x, y);
	cout << endl;

	//delete the result array
	delete1(result, x);
}
void mSub(double **matrix1, double **matrix2, int x, int y, int x1, int y1) {
	double **result;
	result = createMatrix(x, y);

	// Subtract the values.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			*(*(result + i) + j) = (*(*(matrix1 + i) + j))
					- (*(*(matrix2 + i) + j));

	// Print out the matrix.
	cout << endl << "Result: ";
	print(result, x, y);
	cout << endl;

	//delete the result array
	delete1(result, x);

}
void mMul(double **matrix1, double **matrix2, int x, int y, int x1, int y1) {
	double **result;
	result = createMatrix(x, y1);

	// Multiply the values.
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y1; j++) {
			result[i][j] = 0;
			for (int k = 0; k < y; k++) {
				*(*(result + i) + j) = *(*(result + i) + j)
						+ (*(*(matrix1 + i) + k) * *(*(matrix2 + k) + j));
			}
		}
	}
	// Print out the matrix.
	cout << endl << "Result: ";
	print(result, x, y);
	cout << endl;

	//delete the result array
	delete1(result, x);
}
