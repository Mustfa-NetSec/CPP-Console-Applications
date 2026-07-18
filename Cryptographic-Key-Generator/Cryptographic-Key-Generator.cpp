#include <iostream>
using namespace std;
/*
Generate Kyes ..
A program to read how many keys to genrate and print them on screen ...

Example :

Input :
2

Output :
Key [1] : ETAI-HJUV-KSLD-OEUP
Key [2] : JDSH-NSOX-PQBD-LSBZ

*/

enum enCharType
{
	SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4
};


int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}


char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));
		break;

	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;

	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));
		break;

	case enCharType::Digit:
		return char(RandomNumber(48, 57));
		break;

	}
}


int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);


	return Number;
}


string GenerateWord(enCharType CharType, short Length)
{
	string Word = "";

	for (int i = 1; i <= Length; i++)
	{
		Word = Word + GetRandomCharacter(CharType);
	}
	return Word;
}


string GenerateKey()
{
	string Key = "";
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}


void GenerateKeys(short NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "] : " << GenerateKey() << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));

	GenerateKeys(ReadPositiveNumber("Please enter positive number : "));

	return 0;
}