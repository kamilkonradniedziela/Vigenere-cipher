/** @file */

/*

VIGENERE

*/

#pragma once
#include <iostream>

using namespace std;

/**Funkcja odpowiadaj¹ca za operacje na plikach dla podanych prze³¹czników
@param counter aktualna iteracja pêtli funkcji nadrzêdnej
@param arguments nazwy argumentów wczytanych przez wiersz poleceñ
@param fileWithEncryptionKey nazwa pliku zawieraj¹cego klucz szyfruj¹cy
@param inputFile nazwa pliku zawieraj¹ca plik wejœciowy
@param outputFile nazwa pliku zawieraj¹ca plik wyjœciowy
@param isInput zmienna informuj¹ca o istnieniu pliku wejœciowego 
@param isOutput zmienna informuj¹ca o istnieniu pliku wyjœciowego
@param isEncryptionKey zmienna informuj¹ca o istnieniu pliku z kluczem szyfruj¹cym
*/
bool checkSwitches(int counter, char* arguments[], string& fileWithEncryptionKey, string& inputFile, string& outputFile, bool& isInput, bool& isOutput, bool& isEncryptionKey);

/**Funkcja wczytuj¹ca liniê tekstu z pliku
@param outputFile nazwa pliku wyjœciowego
@param key nazwa pliku zawieraj¹cego klucz szyfruj¹cy
@param encryption zmienna informuj¹ca o szyfrowaniu pliku
@param decryption zmienna informuj¹ca o deszyfrowaniu pliku
@param breakingTheCode zmienna informuj¹ca o ³amaniu klucza szyfruj¹cego z pliku wejœciowego
*/
string getlineFromFile(string outputFile, string key, bool encryption, bool decryption, bool breakingTheKey);

/**Funkcja sprawdzaj¹ca d³ugoœæ pods³owa
@param contentOfEncryptionKey treœæ klucza szyfruj¹cego w którym sprawdzane s¹ powtórzenia
@param iteration aktualna iteracja pêtli w funkcji nadrzêdnej
*/
size_t checkSubstring(const vector<char>& contentOfEncryptionKey, int iteration);

/**Funkcja znajduje najd³u¿sze pods³owo w wektorze, na podstawie tego zwraca prawid³owy klucz szyfruj¹cy
@param contentOfEncryptionKey treœæ klucza szyfruj¹cego
*/
vector<char> extractEncryptionKey(const vector<char>& contentOfEncryptionKey);

