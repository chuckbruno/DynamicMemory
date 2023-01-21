// Encryption.cpp : Defines the entry point for the application.
//

#include <iostream>

//void assignValue(char* &data)
char* assignValue()
{

	const char* word = "hello world!";
	size_t bufferSize = (strlen(word) + 1);
	char* p = new char[bufferSize];
	strcpy_s(p, bufferSize, word);

	return p;
}

void assignValue(char** ptr)
{
	const char* word = "hello world!!";
	size_t bufferSize = (strlen(word) + 1);
	*ptr = new char[bufferSize];
	strcpy_s(*ptr, bufferSize, word);
}

void assignValue(char*& ptr)
{
	const char* word = "hello world!!!";
	size_t bufferSize = (strlen(word) + 1);
	ptr = new char[bufferSize];
	strcpy_s(ptr, bufferSize, word);
}


int main(int args, char* argv[])
{
	char b[4] = "abc";
	char* a = b;
	char c[] = { 'c', 'd', '\0'};
	std::cout << a << std::endl;
	//std::cout << &a << std::endl;
	std::cout << sizeof(b) << std::endl;
	std::cout << sizeof(a) << std::endl;
	std::cout << c << std::endl;

	//method 1, return a char * pointer
	a = assignValue();
	std::cout << a << std::endl;
	delete[] a;

	//method 2, using char** pointer
	assignValue(&a);
	std::cout << a << std::endl;
	delete[] a;

	//method 3, using char* & argument
	assignValue(a);
	std::cout << a << std::endl;
	delete[] a;

	return 0;
}
