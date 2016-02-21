//by Hardeep Singh
// Math Tutor gives problem with random number in addition, subtraction, multiplication and division. 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	int option;
	srand(time(0));
	do
	{
		cout << "Welcome to Math Tutor. \n";
		cout << "1. Addition. \n";
		cout << "2. Subtraction. \n";
		cout << "3. Multiplication. \n";
		cout << "4. Division. \n";
		cout << "5. Exit. \n";
		cout << "Please choose an option from 1-5: ";
		cin >> option;
		while (option < 0 || option > 5)
		{
			cout << "Please enter a valid input: ";
			cin >> option;
		}
		switch (option)
		{
		case 1: {
					int a = (1 + (rand() % 1000));
					int b = (1 + (rand() % 1000));
					int total = (a + b);
					int number;
					cout << setw(5) << a << "\n";
					cout << "+ " << setw(3) << b << "\n";
					cout << "---------\n";
					cout << "Enter your answer: ";
					cin >> number;
					if (total == number)
						cout << "Congratulation you got it right.\n";
					else
						cout << "Sorry that was wrong, correct answer is " << total << ".\n";
					break;
				}
		case 2: {
					int a = (1 + (rand() % 1000));
					int b = (1 + (rand() % 1000));
					int total = (a - b);
					int number;	
					cout << setw(5) << a << "\n";
					cout << "- " << setw(3) << b << "\n";
					cout << "---------\n";
					cout << "Enter your answer: ";
					cin >> number;
					if (total == number)
						cout << "Congratulation you got it right.\n";
					else
						cout << "Sorry that was wrong, correct answer is " << total << ".\n";
					break; 
				}
		case 3: {
					int a = (1 + (rand() % 1000));
					int b = (1 + (rand() % 1000));
					int total = (a * b);
					int number;
					cout << setw(5) << a << "\n";
					cout << "* " << setw(3) << b << "\n";
					cout << "---------\n";
					cout << "Enter your answer: ";
					cin >> number;
					if (total == number)
					cout << "Congratulation you got it right.\n";
					else
						cout << "Sorry that was wrong, correct answer is " << total << ".\n";
					break;
				}
		case 4: {
					int a = (1 + (rand() % 1000));
					int b = (1 + (rand() % 1000));
					int total = (a / b);
					int number;
					cout << setw(5) << a << "\n";
					cout << "/ " << setw(3) << b << "\n";
					cout << "---------\n";
					cout << "Enter your answer: ";
					cin >> number;
					if (total == number)
						cout << "Congratulation you got it right./n";
					else
						cout << "Sorry that was wrong, correct answer is " << total << ".\n";
					break; 
				}
		case 5: {
					cout << "Thank you for using Math Tutor.\n";
					break; 
				}
		}
	} while (option != 5);
	return 0;

}