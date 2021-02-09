/** @file */

/*

VIGENERE

*/

#pragma once
#include <iostream>

using namespace std;

/**Funkcja odpowiadaj�ca za operacje na plikach dla podanych prze��cznik�w
@param counter aktualna iteracja p�tli funkcji nadrz�dnej
@param arguments nazwy argument�w wczytanych przez wiersz polece�
@param fileWithEncryptionKey nazwa pliku zawieraj�cego klucz szyfruj�cy
@param inputFile nazwa pliku zawieraj�ca plik wej�ciowy
@param outputFile nazwa pliku zawieraj�ca plik wyj�ciowy
@param isInput zmienna informuj�ca o istnieniu pliku wej�ciowego 
@param isOutput zmienna informuj�ca o istnieniu pliku wyj�ciowego
@param isEncryptionKey zmienna informuj�ca o istnieniu pliku z kluczem szyfruj�cym
*/
bool checkSwitches(int counter, char* arguments[], string& fileWithEncryptionKey, string& inputFile, string& outputFile, bool& isInput, bool& isOutput, bool& isEncryptionKey);

/**Funkcja wczytuj�ca lini� tekstu z pliku
@param outputFile nazwa pliku wyj�ciowego
@param key nazwa pliku zawieraj�cego klucz szyfruj�cy
@param encryption zmienna informuj�ca o szyfrowaniu pliku
@param decryption zmienna informuj�ca o deszyfrowaniu pliku
@param breakingTheCode zmienna informuj�ca o �amaniu klucza szyfruj�cego z pliku wej�ciowego
*/
string getlineFromFile(string outputFile, string key, bool encryption, bool decryption, bool breakingTheKey);

/**Funkcja sprawdzaj�ca d�ugo�� pods�owa
@param contentOfEncryptionKey tre�� klucza szyfruj�cego w kt�rym sprawdzane s� powt�rzenia
@param iteration aktualna iteracja p�tli w funkcji nadrz�dnej
*/
size_t checkSubstring(const vector<char>& contentOfEncryptionKey, int iteration);

/**Funkcja znajduje najd�u�sze pods�owo w wektorze, na podstawie tego zwraca prawid�owy klucz szyfruj�cy
@param contentOfEncryptionKey tre�� klucza szyfruj�cego
*/
vector<char> extractEncryptionKey(const vector<char>& contentOfEncryptionKey);

