//============================================================================
// Name        : V3MatrixOperation.cpp
// Author      : Hardeep Singh
// Version     :
// Copyright   : Your copyright notice
// Description : Matrix Operations
//============================================================================

#include <iostream>
using namespace std;

class Matrix {
private:
	double **matrix1;
	double **matrix2;
public:
	int x, y, x1, y1;
public:
	Matrix(double **, double **, int, int, int, int);
	void mAdd();
	void mSub();
	void mMul();
	void fillUpMatrix(double **, int, int);
	void delete1(double**, int);
	void print(double **, int, int);
};

double** createMatrix(int, int);

int main() {
	double **matrix1;
	double **matrix2;
	int x, y, x1, y1, choice;
	bool done = false;

	cout << "\t***Welcome to Matrix Multiplication***\n";

	cout << "\n\t\tMatrix Multiplications\n";
	cout << "Enter the order of Matrix1(n <space> n): ";
	cin >> x >> y;
	matrix1 = createMatrix(x, y);

	cout << "Enter the order of Matrix2(n <space> n): ";
	cin >> x1 >> y1;
	matrix2 = createMatrix(x1, y1);

	//Call constructor and fill up the array
	Matrix m(matrix1, matrix2, x, y, x1, y1);

	while (!done) {
		cout << endl << "***Matrix Operation***" << endl;
		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "4. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (x != x1 && y != y1)
				cout << "Matrix are not same size, they cannot be added.\n";
			else
				m.mAdd();
			break;
		case 2:
			if (x != x1 && y != y1)
				cout << "Matrix are not same size, they cannot be added.\n";
			else
				m.mSub();
			break;
		case 3:
			if (y != x1)
				cout
					<< "Matrix1 column don't match Matrix2 row, Multiplication cannot be done. \n";
			else
				m.mMul();
			break;
		case 4:
			m.delete1(matrix1, x);
			m.delete1(matrix2, x1);
			cout << "Good Bye!";
			done = true;
			break;
		}
	}

}

double** createMatrix(int x, int y) {
	double **a;
	a = new double *[x];
	for (int i = 0; i < x; i++)
		*(a + i) = new double[y];
	return a;
}

Matrix::Matrix(double **matrix1, double **matrix2, int x, int y, int x1,
		int y1) {
	this->matrix1 = matrix1;
	this->matrix2 = matrix2;
	this->x = x;
	this->y = y;
	this->x1 = x1;
	this->y1 = y1;

	//fill up the arrays
	fillUpMatrix(matrix1, x, y);
	fillUpMatrix(matrix2, x1, y1);
}

void Matrix::fillUpMatrix(double **matrix, int x, int y) {
	cout << endl;
	cout << "Enter the elements of the Matrix: \n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << "Enter  " << i << ":" << j << "th: ";
			cin >> *(*(matrix + i) + j);
		}
	}
	cout << endl;
	cout << "Matrix: ";
	print(matrix, x, y);
}

void Matrix::delete1(double **finish, int x) {
	for (int i = 0; i < x; i++)
		delete[] finish[i];
	delete[] finish;
}

void Matrix::print(double **result, int s, int q) {
	for (int i = 0; i < x; i++) {
		cout << endl;
		for (int j = 0; j < y; j++) {
			cout << *(*(result + i) + j) << " ";
		}
	}
	cout << endl;
}

void Matrix::mAdd() {
	double **result;
	result = createMatrix(x, y);
	// Add the values.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			*(*(result + i) + j) = (*(*(matrix1 + i) + j))
					+ (*(*(matrix2 + i) + j));

	// Print out the matrix.
	cout << endl;
	cout << "Result: ";
	print(result, x, y);

	//delete the result array
	delete1(result, x);
}

void Matrix::mSub() {
	double **result;
	result = createMatrix(x, y);
	// Add the values.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			*(*(result + i) + j) = (*(*(matrix1 + i) + j))
					- (*(*(matrix2 + i) + j));

	// Print out the matrix.
	cout << endl;
	cout << "Result: ";
	print(result, x, y);

	//delete the result array
	delete1(result, x);
}

void Matrix::mMul() {
	double **result;
	result = createMatrix(x, y);

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
	cout << endl;
	cout << "Result: ";
	print(result, x, y);

	//delete the result array
	delete1(result, x);
}

