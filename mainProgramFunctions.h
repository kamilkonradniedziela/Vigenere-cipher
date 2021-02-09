/** @file */

/*

VIGENERE

*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

/**Funkcja wczytuj¹ca prze³¹czniki podane przez wiersz poleceñ
@param howManyArguments liczba argumentów wczytana przez wiersz poleceñ
@param arguments nazwy argumentów wczytanych przez wiersz poleceñ
@param fileWithEncryptionKey nazwa pliku zawieraj¹cego klucz szyfruj¹cy
@param inputFile nazwa pliku zawieraj¹ca plik wejœciowy
@param outputFile nazwa pliku zawieraj¹ca plik wyjœciowy
@param encryption zmienna informuj¹ca o szyfrowaniu pliku
@param decryption zmienna informuj¹ca o deszyfrowaniu pliku
@param breakingTheCode zmienna informuj¹ca o ³amaniu klucza szyfruj¹cego z pliku wejœciowego
*/
bool loadSwitches(int howManyArguments, char* arguments[], string& fileWithEncryptionKey, string& inputFile, string& outputFile, bool& encryption, bool& decryption, bool& breakingTheCode);

/**Funkcja wczytuj¹ca zawartoœæ pliku do bufora
@param inputFile nazwa pliku wejœciowego
*/
vector<char> loadDataToBuffer(string inputFile);

/**Funkcja wykonuj¹ca operacje(szyfrowanie/deszyfrowanie/³amanie szyfru)
@param inputText treœæ tekstu wejœciowego
@param encryptedOrDecrypted treœæ pliku wyjœciowego
@param foundKey treœæ znalezionego klucza szyfruj¹cego
@param key nazwa pliku zawieraj¹cego klucz szyfruj¹cy
@param outputFile nazwa pliku zawieraj¹ca plik wyjœciowy
@param encryption zmienna informuj¹ca o szyfrowaniu pliku
@param decryption zmienna informuj¹ca o deszyfrowaniu pliku
@param breakingTheKey zmienna informuj¹ca o ³amaniu klucza szyfruj¹cego
*/
void vigenere(vector <char>& inputText, vector <char>& encryptedOrDecrypted, vector <char>& foundKey, string key, string outputFile, bool encryption, bool decryption, bool breakingTheKey);

/**Funkcja zapisujaca dane wyjsciowe do pliku
@param encrypedOrDecrypedText wektor zawieraj¹cy zaszyfrowany lub zdeszyfrowany tekst wyjœciowy
@param foundKey wektor zaweiraj¹cy klucz szyfruj¹cy
@param fileWithEncryptionKey nazwa pliku zawieraj¹cego klucz szyfruj¹cy
@param outputFile nazwa pliku zawieraj¹ca plik wyjœciowy
@param encryption zmienna informuj¹ca o szyfrowaniu pliku
@param decryption zmienna informuj¹ca o deszyfrowaniu pliku
@param breakingTheKey zmienna informuj¹ca o ³amaniu klucza szyfruj¹cego
*/
void saveToFile(vector <char> encrypedOrDecrypedText, vector <char>& foundKey, string& fileWithEncryptionKey, string outputFile, bool encryption, bool decryption, bool breakingTheKey);