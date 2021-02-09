/** @file */

/*

VIGENERE

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "help.h"
#include "parseChars.h"

using namespace std;

bool checkSwitches(int counter, char* arguments[], string& fileWithEncryptionKey, string& inputFile, string& outputFile, bool& isInput, bool& isOutput, bool& isEncryptionKey)
{
	fstream file;
	if ((strcmp(arguments[counter], "-i") == 0) || (strcmp(arguments[counter], "-o") == 0))
	{
		if (strcmp(arguments[counter], "-i") == 0)
		{
			file.open(arguments[counter + 1], ios::in | ios::out);
		}
		else if (strcmp(arguments[counter], "-o") == 0)
		{
			file.open(arguments[counter + 1], ios::out | ios::app);
		}

		// Sprawdzanie poprawnosci pliku wejsciowego lub wyjsciowego
		if (file.good() == true)
		{
			//cout << komunikatOtwarciaPliku;
			if (strcmp(arguments[counter], "-i") == 0)
			{
				isInput = true;
				inputFile = arguments[++counter];
			}
			else if (strcmp(arguments[counter], "-o") == 0)
			{
				isOutput = true;
				outputFile = arguments[++counter];
			}
			file.close();
		}
		else
		{
			cout << "Podanego pliku nie udalo sie otworzyc (pamietaj o dopisaniu .txt)!" << endl;
			return false;
		}
	}
	else if (strcmp(arguments[counter], "-k") == 0)
	{
		file.open(arguments[counter + 1], ios::in | ios::out);
		if (file.good() == true)
		{
			//Sprawdzenie poprawnosci pliku z kluczem szyfrujacym
			string line;
			if (getline(file, line) && checkKey(line))
			{
				isEncryptionKey = true;
				fileWithEncryptionKey = arguments[++counter];
				file.close();
			}
			else
			{
				cout << "Podany klucz szyfrujacy jest niepoprawny, pamietaj ze moze skladac sie jedynie z malych oraz wielkich liter alfabetu lacinskiego!" << endl;
				file.close();
				return false;
			}
		}
		else
		{
			file.open(arguments[counter + 1], ios::out);
			isEncryptionKey = true;
			fileWithEncryptionKey = arguments[++counter];
			file.close();
		}
	}
}

string getlineFromFile(string outputFile, string key, bool encryption, bool decryption, bool breakingTheKey)
{
	fstream file;
	string outputLine;
	if (encryption == true || decryption == true)
	{
		file.open(key, ios::in | ios::out);
	}
	else if (breakingTheKey == true)
	{
		file.open(outputFile, ios::in | ios::out);
	}
	getline(file, outputLine);
	file.close();
	return outputLine;
}


//Funkcja sprawdza d³ugoœæ pods³owa
size_t checkSubstring(const vector<char>& contentOfEncryptionKey, int iteration)
{
	size_t c = 0;
	int i;

	for (i = 0; i < contentOfEncryptionKey.size() + 1 - iteration; i += iteration)
	{
		if (!equal(contentOfEncryptionKey.begin(), contentOfEncryptionKey.begin() + iteration, contentOfEncryptionKey.begin() + i))
		{
			break;
		}
		++c;
	}

	if (i < contentOfEncryptionKey.size() && !equal(contentOfEncryptionKey.begin() + i, contentOfEncryptionKey.end(), contentOfEncryptionKey.begin()))
	{
		c = 0;
	}
	return c;
}

//Funkcja znajduje najd³u¿sze pods³owo w wektorze, na podstawie tego zwraca prawid³owy klucz szyfruj¹cy
vector<char> extractEncryptionKey(const vector<char>& contentOfEncryptionKey)
{
	size_t max_n = 0, substr_len = 0;

	for (int i = contentOfEncryptionKey.size() - 1; i > 0; --i)
	{
		size_t n = checkSubstring(contentOfEncryptionKey, i);
		if (n > max_n)
		{
			max_n = n;
			substr_len = i;
		}
	}

	return max_n == 0 ? contentOfEncryptionKey : vector<char>(contentOfEncryptionKey.begin(), contentOfEncryptionKey.begin() + substr_len);
}
