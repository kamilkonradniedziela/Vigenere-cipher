/** @file */

/*

VIGENERE

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "parseArguments.h"
#include "parseChars.h"
#include "help.h"

using namespace std;

bool loadSwitches(int howManyArguments, char* arguments[], string& fileWithEncryptionKey, string& inputFile, string& outputFile, bool& encryption, bool& decryption, bool& breakingTheCode)
{
	// Sprawdzenie czy s¹ wszystkie prze³¹czniki
	bool keyExist = false, inputExist = false, outputExist = false, cipherExist = false, decryptionExist = false, breakingCodeExist = false, parametersExist = false;

	// Iterowanie po kazdym z przelacznikow
	for (int i = 1; i < howManyArguments; i++)
	{
		parametersExist = true;

		// Przelacznik pliku wejsciowego
		if (strcmp(arguments[i], "-i") == 0)
		{
			// Sprawdzenie czy istnieje nastepny argument
			if (i + 1 == howManyArguments)
			{
				cout << "Nie podano nazwy pliku wejsciowego po przelaczniku -i!" << endl;
				return false;
			}
			checkSwitches(i, arguments, fileWithEncryptionKey, inputFile, outputFile, inputExist, outputExist, keyExist);
		}

		// Przelacznik pliku wyjsciowego
		if (strcmp(arguments[i], "-o") == 0)
		{
			// Sprawdzenie czy istnieje nastepny argument
			if (i + 1 == howManyArguments)
			{
				cout << "Nie podano nazwy pliku wyjsciowego po przelaczniku -o!" << endl;
				return false;
			}
			checkSwitches(i, arguments, fileWithEncryptionKey, inputFile, outputFile, inputExist, outputExist, keyExist);
		}

		// Przelacznik klucza szyfrujacego
		if (strcmp(arguments[i], "-k") == 0)
		{
			// Sprawdzenie czy istnieje nastepny argument
			if (i + 1 == howManyArguments)
			{
				cout << "Nie podano nazwy pliku z kluczem szyfrujacym po przelaczniku -k!" << endl;
				return false;
			}
			checkSwitches(i, arguments, fileWithEncryptionKey, inputFile, outputFile, inputExist, outputExist, keyExist);
		}

		// Przelacznik instrukcji
		if (strcmp(arguments[i], "-h") == 0)
		{
			programInstruction();
			return false;
		}

		// Przelacznik szyfrowania
		if (strcmp(arguments[i], "-en") == 0)
		{
			if (decryptionExist || breakingCodeExist)
			{
				cout << "Nie mozna jednoczesnie szyfrowac oraz deszyfrowac lub lamac szyfru! Nastepnym razem wybierz jedna opcje" << endl;
				return false;
			}

			cipherExist = true;
			encryption = true;
		}

		// Przelacznik deszyfrowania
		if (strcmp(arguments[i], "-de") == 0)
		{
			if (cipherExist || breakingCodeExist)
			{
				cout << "Nie mozna jednoczesnie deszyfrowac oraz szyfrowac lub lamac szyfru! Nastepnym razem wybierz jedna opcje." << endl;
				return false;
			}

			decryptionExist = true;
			decryption = true;
		}

		// Przelacznik lamania szyfru
		if (strcmp(arguments[i], "-br") == 0)
		{
			if (cipherExist || decryptionExist)
			{
				cout << "Nie mozna jednoczesnie lamac szyfru oraz szyfrowac lub deszyfrowac! Nastepnym razem wybierz jedna opcje." << endl;
				return false;
			}

			breakingCodeExist = true;
			breakingTheCode = true;
		}

	}

	// Sprawdzam czy sa jakies parametry poza nazwa programu
	if (parametersExist == false)
	{
		cout << "Poniewaz podales tylko nazwe programu instrukcja wyswietlana jest automatycznie." << endl;
		programInstruction();
		return false;
	}

	// Sprawdzenie czy wszystkie potrzebne przelaczniki zostaly podane
	if ((!inputExist || !outputExist || !keyExist || (!decryptionExist && !cipherExist && !breakingCodeExist)))
	{
		cout << "Nie podano wszystkich wymaganych przelacznikow, w razie watpliwosci zajrzyj do instrukcji." << endl;
		return false;
	}

	return true;
}

vector<char> loadDataToBuffer(string inputFile)
{
	vector <char> assistantBuffer;
	fstream file;
	char c;
	file.open(inputFile, ios::in | ios::out);
	while (file >> c)
	{
		assistantBuffer.push_back(c);
	}
	file.close();
	return assistantBuffer;
}

void vigenere(vector <char>& inputText, vector <char>& encryptedOrDecrypted, vector <char>& foundKey, string key, string outputFile, bool encryption, bool decryption, bool breakingTheKey)
{
	if (encryption == true || decryption == true)
	{
		string lineWithKey = getlineFromFile(outputFile, key, encryption, decryption, breakingTheKey);

		if (encryption == true)
		{
			encryptedOrDecrypted = encrypt(inputText, encryptionKeyShift(lineWithKey));
		}
		else if (decryption == true)
		{
			encryptedOrDecrypted = decrypt(inputText, encryptionKeyShift(lineWithKey));
		}
	}
	else if (breakingTheKey == true)
	{
		foundKey = lookForTheKey(inputText, outputFile, key, encryption, decryption, breakingTheKey);

	}
}

void saveToFile(vector <char> encrypedOrDecrypedText, vector <char>& foundKey, string& fileWithEncryptionKey, string outputFile, bool encryption, bool decryption, bool breakingTheKey)
{
	fstream file;
	if (encryption == true || decryption == true)
	{
		file.open(outputFile, ios::in | ios::out);
		for (vector<char>::iterator it = encrypedOrDecrypedText.begin(); it != encrypedOrDecrypedText.end(); it++)
		{
			file << *it;
		}
	}
	else if (breakingTheKey == true)
	{
		file.open(fileWithEncryptionKey, ios::out);
		for (vector <char>::iterator i = foundKey.begin(); i != foundKey.end(); i++)
		{
			file << *i;
		}
	}
	file.close();
}