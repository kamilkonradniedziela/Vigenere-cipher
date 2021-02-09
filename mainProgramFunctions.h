/** @file */

/*

VIGENERE

*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

/**Funkcja wczytuj�ca prze��czniki podane przez wiersz polece�
@param howManyArguments liczba argument�w wczytana przez wiersz polece�
@param arguments nazwy argument�w wczytanych przez wiersz polece�
@param fileWithEncryptionKey nazwa pliku zawieraj�cego klucz szyfruj�cy
@param inputFile nazwa pliku zawieraj�ca plik wej�ciowy
@param outputFile nazwa pliku zawieraj�ca plik wyj�ciowy
@param encryption zmienna informuj�ca o szyfrowaniu pliku
@param decryption zmienna informuj�ca o deszyfrowaniu pliku
@param breakingTheCode zmienna informuj�ca o �amaniu klucza szyfruj�cego z pliku wej�ciowego
*/
bool loadSwitches(int howManyArguments, char* arguments[], string& fileWithEncryptionKey, string& inputFile, string& outputFile, bool& encryption, bool& decryption, bool& breakingTheCode);

/**Funkcja wczytuj�ca zawarto�� pliku do bufora
@param inputFile nazwa pliku wej�ciowego
*/
vector<char> loadDataToBuffer(string inputFile);

/**Funkcja wykonuj�ca operacje(szyfrowanie/deszyfrowanie/�amanie szyfru)
@param inputText tre�� tekstu wej�ciowego
@param encryptedOrDecrypted tre�� pliku wyj�ciowego
@param foundKey tre�� znalezionego klucza szyfruj�cego
@param key nazwa pliku zawieraj�cego klucz szyfruj�cy
@param outputFile nazwa pliku zawieraj�ca plik wyj�ciowy
@param encryption zmienna informuj�ca o szyfrowaniu pliku
@param decryption zmienna informuj�ca o deszyfrowaniu pliku
@param breakingTheKey zmienna informuj�ca o �amaniu klucza szyfruj�cego
*/
void vigenere(vector <char>& inputText, vector <char>& encryptedOrDecrypted, vector <char>& foundKey, string key, string outputFile, bool encryption, bool decryption, bool breakingTheKey);

/**Funkcja zapisujaca dane wyjsciowe do pliku
@param encrypedOrDecrypedText wektor zawieraj�cy zaszyfrowany lub zdeszyfrowany tekst wyj�ciowy
@param foundKey wektor zaweiraj�cy klucz szyfruj�cy
@param fileWithEncryptionKey nazwa pliku zawieraj�cego klucz szyfruj�cy
@param outputFile nazwa pliku zawieraj�ca plik wyj�ciowy
@param encryption zmienna informuj�ca o szyfrowaniu pliku
@param decryption zmienna informuj�ca o deszyfrowaniu pliku
@param breakingTheKey zmienna informuj�ca o �amaniu klucza szyfruj�cego
*/
void saveToFile(vector <char> encrypedOrDecrypedText, vector <char>& foundKey, string& fileWithEncryptionKey, string outputFile, bool encryption, bool decryption, bool breakingTheKey);