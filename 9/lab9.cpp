#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

list<string> read_lines()
{
	ifstream file("F1.txt");
	if (!file)
	{
		perror("Unable to open file F1.txt");
		exit(0);
	}
	list<string> lines;
	while (!file.eof())
	{
		string row;
		getline(file, row);
		lines.push_back(row);
	}
	file.close();
	return lines;
}

int number_of_vowels(string row)
{
	int n = 0;
	for (auto character: row)
	{
		switch(character)
		{
		case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': case 'E': case 'I': case 'O': case 'U': n++;
		}
	}
	return n;
}

void write_lines(list<string> lines, int ignore)
{
	ofstream file("F2.txt");
	int i = 1;
	for (auto row:lines)
	{
		if (i != ignore)
		{
			file << row << endl;
		}
		i++;
	}
	file.close();
}

int main()
{
	list<string> lines = read_lines();
	int max_vowels = 0, n_of_row = 0, i = 1;
	for (auto row: lines)
	{
		int vowels = number_of_vowels(row);
		if (vowels > max_vowels)
		{
			max_vowels = vowels;
			n_of_row = i;
		}
		i++;
	}
	if (max_vowels == 0)
	{
		cout << "No lines with vowels";
	}
	else
	{
		cout << "The line with the most vowels is the line number " << n_of_row;
	}
	write_lines(lines, n_of_row);
}
