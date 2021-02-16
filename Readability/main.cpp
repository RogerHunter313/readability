#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define OUT 0
#define IN 1

//returns number of words in str
unsigned countWords(string text)
{
	int state = OUT;
	unsigned wc = 0; // word count

	// Scan all characters one by one
	for (int i = 0; i < text.length(); i++) {
		// If next character is a seperator, set the state as OUT, \n is new line, \t is tab
		if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
			state = OUT;
		//If next character is not a word seperator and
		//state is OUT, then set the state as IN and increment word count
		else if (state == OUT)
		{
			state = IN;
			++wc;
		}
	}
	return wc;
}

int main() {

	string text;
	unsigned int letters = 0;
	unsigned int punctuation = 0;
	unsigned int words;

	cout << "Text: " << flush;
	//need getline or string will terminate at a space
	getline(cin, text);
	cout << "You typed: " << text << endl;

	int n = text.length();

	cout << n << " is the length of text including seperators and punctuation." << endl;

	cout << "The text was copied into a character array as: " << flush;

	//counting how many letters are in the character array
	for (int i = 0; i < n; i++) {
		if (text[i] >= 'A' && text[i] <= 'z' || text[i] >= 'a' && text[i] <= 'z')
		{
			letters++;
		}

		else if (text[i] == '?' || text[i] == '.' || text[i] == '!')
		{
			punctuation++;
		}

		cout << text[i];
	}

	cout << endl << "Amount of letters: " << letters << endl;
	cout << "The text has " << countWords(text)
		<< " word(s)." << endl;
	cout << "The text has " << punctuation << " sentences" << endl;

	//average number of words per 100 letter, dividig integer values will make everything an integer
	float L = ((float)(letters) / (float)(countWords(text))) * 100.0000;
	//average number of sentences per 100 words
	float S = ((float)(punctuation) / (float)countWords(text)) * 100.0000;

	//float index = 0.0588 * L - 0.296 * S - 15.8;
	float index = (0.0588 * L) - (0.296 * S) - 15.8;

	//	cout << L << endl;
	//	cout << S << endl;
	//	cout << index << endl;
	if (index <= 1)
	{
		cout << "Coleman-Liau Index: (Grade 1)" << endl;
	}
	else if (index > 1 && index <= 12)
	{
		cout << "Coleman-Liau Index: (Grade " << round(index) << " )" << endl;
	}
	else
	{
		cout << "Coleman-Liau Index: (Grade 16+)" << endl;
	}

	return 0;

}
