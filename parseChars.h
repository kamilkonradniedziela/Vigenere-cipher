/** @file */

/*

VIGENERE

*/

#pragma once
#include <iostream>

using namespace std;

/**Funkcja sprawdzaj¹ca poprawnoœæ klucza szyfruj¹cego
@param key klucz szyfru¹cy do sprawdzenia
*/
int checkKey(string key);

/**Funkcja znajduj¹ca wartoœci przesuniêæ liter w pliku wyjœciowym na podstawie klucza szyfruj¹cego
@param key tekst wzglêdem którego zosta³ zakodowany plik wyjœciowy
*/
string encryptionKeyShift(string key);

/**Funkcja szyfruj¹ca znaki
@param c litery z pliku wejœciowego
@param shift litery wskazuj¹ce o jak¹ wartoœæ nale¿y przesun¹æ litery w pliku wejœciowym aby otrzymaæ litery w pliku wyjœciowym
*/
char encryptChar(unsigned char c, char shift);

/**Funkcja zwracaj¹ca zaszyfrowany tekst
@param inputText treœæ tekstu wejœciowego
@param keyShifts wartoœci o jakie nale¿y przesun¹æ tekst wejœciowy
*/
vector<char> encrypt(vector<char> inputText, const string& keyShifts);

/**Funkcja deszyfruj¹ca znaki
@param c litery z pliku wejœciowego
@param shift litery wskazuj¹ce o jak¹ wartoœæ nale¿y przesun¹æ litery w pliku wejœciowym aby otrzymaæ litery w pliku wyjœciowym
*/
char decryptChar(unsigned char c, char shift);

/**Funkcja zwracaj¹ca tekst po deszyfrowaniu
@param inputText treœæ tekstu wejœciowego
@param keyShifts wartoœci o jakie nale¿y przesun¹æ tekst wejœciowy
*/
vector<char> decrypt(vector<char> inputText, const string& keyShifts);

/**Funkcja szukaj¹ca klucza szyfruj¹cego
@param inputText treœæ pliku wejœciowego
@param outputFile nazwa pliku wyjœciowego
@param key nazwa pliku z kluczem szyfruj¹cym
@param encryption zmienna informuj¹ca o szyfrowaniu pliku
@param decryption zmienna informuj¹ca o deszyfrowaniu pliku
@param breakingTheKey zmienna informuj¹ca o ³amaniu klucza szyfruj¹cego
*/
vector<char> lookForTheKey(vector <char>& inputText, string outputFile, string key, bool encryption, bool decryption, bool breakingTheKey);