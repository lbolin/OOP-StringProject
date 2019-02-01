#include<iostream>
#include<string>
#include<sstream>
#include"String.h"
using namespace std;

String::String()//Default 
{
	pString = NULL;
}
String::String(const char* const newString)//Conversion
{
	pString = NULL;
	set(newString);
}

String::String(int i)//Conversion
{
	pString = NULL;
	set(i);
}

String::String(char c)//Conversion
{
	pString = NULL;
	set(c);
}


String::String(const String& newString)//Copy
{
	pString = NULL;
	set(newString.pString);
}

String::~String()
{
	destroy();
}

void String::destroy()
{
	if (pString != NULL)
	{
		delete[]pString;
		pString = NULL;
	}
}

void String::set(const char* const newString)
{
	if (newString != pString)
	{
		destroy();
		if (newString != NULL)
		{
			int size = strlen(newString) + 1;
			pString = new char[size];
			strcpy_s(pString, size, newString);
		}
		else
		{
			pString = NULL;
		}
	}
}

void String::set(const String& newString)
{
	set(newString.pString);
}

void String::set(char c)
{
	destroy();
	pString = new char[2];
	pString[0] = c;
	pString[1] = '\0';
}

void String::set(int i)
{
	destroy();
	const int MAX_LENGTH = 16;
	pString = new char[MAX_LENGTH];
	_itoa_s(i, pString, MAX_LENGTH, 10);
}

bool String::isEmpty()
{
	//when pString is null the condition will short circuit
	return (pString == NULL || strlen(pString) == 0);
}

void String::write(ostream& out)
{
	if (pString != NULL)
	{
		out << pString;
	}
}

int String::length()
{
	int result = 0;
	if (!isEmpty())
	{
		result = strlen(pString);
	}

	return result;
}

void String::append(String postfix)
{
	int newLength = length() + postfix.length() + 1;
	char* result = new char[newLength];
	if (isEmpty())
	{
		result[0] = '\0';
	}
	else
	{
		strcpy_s(result, newLength, pString);
	}
	// then add on the other string
	if (postfix.isEmpty())
	{
		//do nothing
	}
	else
	{
		strcat_s(result, newLength, postfix.pString);
	}
	set(result);
}

void String::prepend(String prefix)
{
	String result(prefix);
	result.append(pString);
	set(result);
}

bool String::contains(String s)
{
	bool result = false;
	if (strstr(pString, s.pString) != NULL)
	{
		result = true;
	}
	return result;
}

void String::insert(String insertString, int index)
{
	String result;
	String sBegin;
	String sEnd;
	if (index <= length())
	{
		for (int i = 0; i < index; i++)
		{
			sBegin.append(pString[i]);
		}
		for (int j = length(); j >= index; j--)
		{
			sEnd.prepend(pString[j]);
		}
	}
	else
	{
		sBegin.set(pString);
	}
	result.append(sBegin);
	result.append(insertString);
	result.append(sEnd);
	set(result);
}


String String::subString(int startIndex, int aLength)
{
	String result;

	if (startIndex < 0)
	{
		startIndex = 0;
	}

	if (startIndex > length())
	{
		result = '\0';
	}

	for (int i = 0; i < aLength && startIndex + i < length(); i++)
	{
		result.append(pString[i + startIndex]);
	}
	result.append('\0');

	return result;
}

bool String::equals(String stringToCompare)
{
	bool result = false;

	if (!(isEmpty() || stringToCompare.isEmpty()))
	{
		if (strcmp(pString, stringToCompare.pString) == 0)
		{
			result = true;
		}
	}

	return result;
}

char String::at(int index)
{
	char result = '\0';

	if (pString != NULL)
	{
		if (index < length())
		{
			result = pString[index];
		}
	}

	return result;
}

void String::toUpper()
{
	String result;

	if (!isEmpty())
	{
		for (int i = 0; i < length(); i++)
		{
			char letter;
			letter = at(i);

			if ((int)letter >= 97 && (int)letter <= 122)
			{
				letter = (char)((int)letter - 32);
			}
			result.append(letter);
		}
		set(result);
	}
}

void String::toLower()
{
	String result;

	if (!isEmpty())
	{
		for (int i = 0; i < length(); i++)
		{
			char letter;
			letter = at(i);

			if ((int)letter >= 65 && (int)letter <= 90)
			{
				letter = (char)((int)letter + 32);
			}
			result.append(letter);
		}
		set(result);
	}
}


void String::trimStart()
{
	bool reachedNonspaceCharacter = false;
	if (!isEmpty())
	{
		while (!reachedNonspaceCharacter)
		{
			if (at(0) == ' ')
			{
				remove(0, 1);
			}
			else
			{
				reachedNonspaceCharacter = true;
			}
		}
	}
}

void String::trimEnd()
{
	bool reachedNonspaceCharacter = false;
	if (!isEmpty())
	{
		while (!reachedNonspaceCharacter)
		{
			if (at(length() - 1) == ' ')
			{
				remove(length() - 1, 1);
			}
			else
			{
				reachedNonspaceCharacter = true;
			}
		}
	}
}

void String::trim()
{
	trimStart();
	trimEnd();
}

void String::replace(String stringToReplace, String replacementString)
{
	if (!isEmpty())
	{
		int indexOfStringToReplace = match(*this, stringToReplace);
		while (indexOfStringToReplace != -1)
		{
			remove(indexOfStringToReplace, stringToReplace.length());
			insert(replacementString, indexOfStringToReplace);
			indexOfStringToReplace = match(*this, stringToReplace);
		}
	}
}

void String::remove(int startIndex, int aLength)
{
	if (!isEmpty())
	{
		String result;
		String sBegin;
		String sEnd;
		sBegin = subString(0, startIndex);
		int endIndex = startIndex + aLength;
		sEnd = subString(endIndex, length() - endIndex);
		result.append(sBegin);
		result.append(sEnd);
		set(result);
	}
}

int String::match(String lookingIn, String lookingFor)
{
	int result = -1;
	if (!(lookingFor.isEmpty() || lookingIn.isEmpty()))
	{
		bool foundResult = false;

		for (int i = 0; i < (lookingIn.length() - lookingFor.length()) && !foundResult; i++)
		{
			bool charMatch = true;
			int j = 0;
			while (charMatch && j < lookingFor.length())
			{
				if (lookingIn.at(i + j) != lookingFor.at(j))
				{
					charMatch = false;
				}
				j++;
			}
			if (charMatch)
			{
				foundResult = true;
				result = i;
			}
		}
	}
	return result;
}


//ignore this

String& String::operator = (const String& toAssign)
{
	this->set(toAssign);
	return *this;
}