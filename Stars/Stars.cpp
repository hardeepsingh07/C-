//by Hardeep Singh
// Displays the pattern of stars in forward and backward manner. 
#include<iostream>
using namespace::std;
int main()
{
	int number;
	cout << "Enter number the stars between 1-20: ";
	cin >> number;
	while (number < 0 || number > 20)
	{
		cout << "Invalid input, please choose an input between 1 - 20: ";
		cin >> number;
	}
	cout << "Pattern A\n";
	for (int row = 1; row <= number; row++)
	{
		for (int col = 1; col <= row; col++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	cout << "Pattern B\n";

	for (int row = number; row >= 1; row--)
	{
		for (int col = row; col >= 1; col--)
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}