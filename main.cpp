/** @file */

/*

VIGENERE

*/

#include <iostream>
#include "mainProgramFunctions.h"
#include <vector>

using namespace std;

int main(int amountOfArguments, char * arguments[])
{
	// Parametry programu
	string inputFile, outputFile, fileWithEncryptionKey;
	bool encryption = false, decryption = false, breakingTheKey = false;
	vector<char>textBuffer, encryptedOrDecryptedOutputText, keyYouAreLookingFor;

	cout << "PROGRAM ZOSTAL URUCHOMIONY!" << endl;

	// Wczytywanie przelacznikow podanych przez liste polecen
	if (loadSwitches(amountOfArguments, arguments, fileWithEncryptionKey, inputFile, outputFile, encryption, decryption, breakingTheKey))
	{
		//Wczytanie danych wejœciowych do bufora
		textBuffer = loadDataToBuffer(inputFile);

		//Operacje na danych wejœciowych
		vigenere(textBuffer, encryptedOrDecryptedOutputText, keyYouAreLookingFor, fileWithEncryptionKey, outputFile, encryption, decryption, breakingTheKey);

		//Zapis danych z bufora do pliku
		saveToFile(encryptedOrDecryptedOutputText, keyYouAreLookingFor, fileWithEncryptionKey, outputFile, encryption, decryption, breakingTheKey);

		cout<<"Program zostal wykonany pomyslnie, zamykanie programu.\n";
	}
	else
	{
		cout<<"Nie udalo sie poprawnie wczytac przelacznikow, zamykanie programu.\n";
	}

	return 0;
}