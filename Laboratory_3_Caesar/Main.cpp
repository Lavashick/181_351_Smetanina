#include <iostream>
using namespace std;

void cezar(char fraza[], int len)
{
	const int alfavitLen = 26;
	char alfavit[alfavitLen] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	for (int i = 0; i < len; i++)
		if (fraza[i] != ' ')
			for (int j = 0; j < alfavitLen; j++)
				if (fraza[i] == alfavit[j])
				{
					fraza[i] = alfavit[(j + 3) % (alfavitLen - 1)];
					break;
				}
}

void printArray(char array[], int len)
{
	for (int i = 0; i < len; i++)
		cout << array[i];
}


int main()
{
	const int frazaLen = 20;
	char fraza[frazaLen] = { 'i',' ','l','o','v','e',' ','c','a','t','s',' ','a','n','d',' ','d','o','g','s' };

	cezar(fraza, frazaLen);
	printArray(fraza, frazaLen);
}