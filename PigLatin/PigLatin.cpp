// Hardeep Singh
// Change english to pigLatin. 
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;
string pigLatinConversion(string);

int main()
{
	string word;
	string pigLatin;
	string original;
	cout << "Enter a group of words or enter quit to exit: ";
	while (true)
	{
		
		cin >> word;
		if (word == "quit")
			break;
		original += word + " ";
		pigLatin += pigLatinConversion(word) + " ";
		if (cin.peek() == '\n')
		{
			cout << "\n" << "English String: " << original << "\n";
			cout << "Pig Latin String: " << pigLatin << "\n";
			//empty the variables for next word use.
			original = "";
			pigLatin = "";
			cout << "Enter a group of words or press ENTER to quit: ";
		}
	}
	return 0;
}
string pigLatinConversion(string word)
{
	string firstLetter = word.substr(0, 1);
	string remainingLetters = word.substr(1, word.size() - 1);

	return remainingLetters + firstLetter + "ay";
}