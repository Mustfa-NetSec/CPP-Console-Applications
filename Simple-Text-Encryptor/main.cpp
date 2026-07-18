#include <iostream>
#include <string>
using namespace std;
/*
Problem 18 ...
Encipt , Decript Name ..
program to read Text then Encryipt , Decrypt Text ..

Input : 
Mohammed

Text Before encription : Mohammed
Text After encription : Oqjcoogf
Text after decription : Mohammed

*/

string ReadText()
{
	string Text;

	cout <<"Please enter a Text : \n";
	getline(cin, Text);

	return Text;
}

string Encryption(string Text , short EncryptionKye)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] + EncryptionKye);
	}
	return Text;
}


string Decryption(string Text , short EncryptionKye)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] - EncryptionKye);
	}
	return Text;
}

int main()
{

	short EncriptionKye = 2;
	string Text = ReadText();

	string   TextAfterEncryption = Encryption(Text, EncriptionKye);
	string   TextAfterDecryption = Decryption(TextAfterEncryption, EncriptionKye);

	cout << "\nText Before Encription : " << Text << endl;
	cout << "\nText After Encription : " << TextAfterEncryption << endl;
	cout << "\nText After Decription : " << TextAfterDecryption << endl;
		

	return 0;
}
