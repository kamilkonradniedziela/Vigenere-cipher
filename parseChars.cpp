/** @file */

/*

VIGENERE

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "help.h"
#include "parseArguments.h"

using namespace std;

int checkKey(string key)
{
	int p = key.length();

	for (int i = 0; i < p; i++)
	{
		if ((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z'))
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//----SZYFR I DESZYFR--------
string encryptionKeyShift(string key)
{
	for (char& c : key)
	{
		if (c >= 'A' && c <= 'Z')
		{
			c -= 'A';
		}
		else if (c >= 'a' && c <= 'z')
		{
			c -= 'a';
		}
	}

	return key;
}

//----------SZYFROWANIE-----------
char encryptChar(unsigned char c, char shift)
{
	if (c >= 'A' && c <= 'Z')
	{
		if ((c = c + shift) > 'Z')
		{
			c -= 26;
		}
	}
	else if (c >= 'a' && c <= 'z')
	{
		if ((c = c + shift) > 'z')
		{
			c -= 26;
		}
	}
	return c;
}

vector<char> encrypt(vector<char> inputText, const string& keyShifts)
{
	int i = 0;

	for (char& c : inputText)
	{
		c = encryptChar(c, keyShifts[i++]);
		if (i == keyShifts.size())
		{
			i = 0;
		}
	}
	return inputText;
}


//-----------DESZYFROWANIE--------------
char decryptChar(unsigned char c, char shift)
{
	if (c >= 'A' && c <= 'Z')
	{
		if ((c = c - shift) < 'A')
		{
			c += 26;
		}
	}
	else if (c >= 'a' && c <= 'z')
	{
		if ((c = c - shift) < 'a')
		{
			c += 26;
		}
	}

	return c;
}

vector<char> decrypt(vector<char> inputText, const string& keyShifts)
{
	int i = 0;

	for (char& c : inputText)
	{
		c = decryptChar(c, keyShifts[i++]);
		if (i == keyShifts.size())
		{
			i = 0;
		}
	}

	return inputText;
}


vector<char> lookForTheKey(vector <char>& inputText, string outputFile, string key, bool encryption, bool decryption, bool breakingTheKey)
{
	string  outputLine;
	vector <char> keyBuffer, correctEncryptionKey;

	outputLine = getlineFromFile(outputFile, key, encryption, decryption, breakingTheKey);

	int i = 0;
	for (char& c : inputText)
	{
		if (c >= 'A' && c <= 'Z')
		{
			c = outputLine[i] - c;
			if (c < 0)
			{
				c += 26 + 'A';
			}
			else if (c >= 0)
			{
				c += 'A';
			}
		}
		else if (c >= 'a' && c <= 'z')
		{
			c = outputLine[i] - c;
			if (c < 0)
			{
				c += 26 + 'a';
			}
			else if (c >= 0)
			{
				c += 'a';
			}
		}
		keyBuffer.push_back(c);
		i++;
	}

	correctEncryptionKey = extractEncryptionKey(keyBuffer);

	return correctEncryptionKey;
}