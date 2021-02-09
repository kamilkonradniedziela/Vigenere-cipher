/** @file */

/*

VIGENERE

*/

#include <iostream>
#include "help.h"

void programInstruction()
{
	puts("INSTRUKCJA PROGRAMU\n"
		"Aby poprawnie wywolac program musisz podac nastepujaca sekwencje przelacznikow:\n"
		"--------------------------------------------------------------------------------\n"
		"1. Szyfrowanie plikow teksowych metoda Vigenere'a\n"
		"-en <-(flaga szyfrowania)\n"
		"-i + plik tekstowy wejscowy jawny z rozszerzeniem .txt\n"
		"-o + plik tekstowy wyjscowy zaszyfrowany z rozszerzeniem .txt\n"
		"-k + plik tekstowy z kluczem szyfrujacym\n"
		"-h <-(wswietlenie wszystkich mozliwych przelacznikow oraz krotka instrukcje)\n"
		"Przyklad: <sciezka do pliku z projektem> Vinegere.exe -en -i jawny -k klucz -o zaszyfrowany\n"
		"---------------------------------------------------------------------------------\n"
		"2. Deszyfrowanie plikow teksowych metoda Vigenere'a\n"
		"-de <-(flaga deszyfrowania)\n"
		"-i + plik tekstowy wejsciowy zaszyfrowany z rozszerzeniem .txt\n"
		"-o + plik tekstowy wyjsciowy jawny z rozszerzeniem .txt\n"
		"-k + plik tekstowy z kluczem szyfrujacym\n"
		"-h <-(wswietlenie wszystkich mozliwych przelacznikow oraz krotka instrukcje)\n"
		"Przyklad: <sciezka do pliku z projektem> Vinegere.exe -de -k klucz -o odszyfrowany -i tajny\n"
		"---------------------------------------------------------------------------------\n"
		"3. Lamanie plikow teksowych zaszyfrowanych metoda Vigenere'a\n"
		"-br <-(flaga lamania szyfru)\n"
		"-i + plik tekstowy wejscowy zaszyfrowany z rozszerzeniem .txt\n"
		"-o + plik tekstowy wyjscowy jawny z rozszerzeniem .txt\n"
		"-k <- plik tekstowy zawierajacy klucz szyfrujacy\n"
		"-h <-(wswietlenie wszystkich mozliwych przelacznikow oraz krotka instrukcje)\n"
		"Przyklad: <sciezka do pliku z projektem> Vinegere.exe -br -o odszyfrowany -i tajny -k klucz\n"
		"---------------------------------------------------------------------------------\n");
}