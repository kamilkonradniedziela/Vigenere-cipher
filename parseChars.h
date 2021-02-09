/** @file */

/*

VIGENERE

*/

#pragma once
#include <iostream>

using namespace std;

/**Funkcja sprawdzaj�ca poprawno�� klucza szyfruj�cego
@param key klucz szyfru�cy do sprawdzenia
*/
int checkKey(string key);

/**Funkcja znajduj�ca warto�ci przesuni�� liter w pliku wyj�ciowym na podstawie klucza szyfruj�cego
@param key tekst wzgl�dem kt�rego zosta� zakodowany plik wyj�ciowy
*/
string encryptionKeyShift(string key);

/**Funkcja szyfruj�ca znaki
@param c litery z pliku wej�ciowego
@param shift litery wskazuj�ce o jak� warto�� nale�y przesun�� litery w pliku wej�ciowym aby otrzyma� litery w pliku wyj�ciowym
*/
char encryptChar(unsigned char c, char shift);

/**Funkcja zwracaj�ca zaszyfrowany tekst
@param inputText tre�� tekstu wej�ciowego
@param keyShifts warto�ci o jakie nale�y przesun�� tekst wej�ciowy
*/
vector<char> encrypt(vector<char> inputText, const string& keyShifts);

/**Funkcja deszyfruj�ca znaki
@param c litery z pliku wej�ciowego
@param shift litery wskazuj�ce o jak� warto�� nale�y przesun�� litery w pliku wej�ciowym aby otrzyma� litery w pliku wyj�ciowym
*/
char decryptChar(unsigned char c, char shift);

/**Funkcja zwracaj�ca tekst po deszyfrowaniu
@param inputText tre�� tekstu wej�ciowego
@param keyShifts warto�ci o jakie nale�y przesun�� tekst wej�ciowy
*/
vector<char> decrypt(vector<char> inputText, const string& keyShifts);

/**Funkcja szukaj�ca klucza szyfruj�cego
@param inputText tre�� pliku wej�ciowego
@param outputFile nazwa pliku wyj�ciowego
@param key nazwa pliku z kluczem szyfruj�cym
@param encryption zmienna informuj�ca o szyfrowaniu pliku
@param decryption zmienna informuj�ca o deszyfrowaniu pliku
@param breakingTheKey zmienna informuj�ca o �amaniu klucza szyfruj�cego
*/
vector<char> lookForTheKey(vector <char>& inputText, string outputFile, string key, bool encryption, bool decryption, bool breakingTheKey);