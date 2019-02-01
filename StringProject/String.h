#pragma once
#include<iostream>
class String
{
public:
	String();
	String(const String& newString);
	String(const char* const newString);
	String(int i);
	String(char c);
	~String();
	void set(const char* const newString);
	void set(const String& newString);
	void set(int i);
	void set(char c);
	void write(std::ostream& out);
	// append takes an int, char, char* or String&
	void append(String postfix);
	// prepend takes an int, char , char* or String&
	void prepend(String prefix);
	//bool contains( char c);
	bool contains(String s);
	// bool contains( const char* const s );
	// bool contains( int i );
	// void insert String, char*, int, char, at an index
	void insert(String insertString, int index);
	bool isEmpty(); // empty when the pointer is null or the first character is \0
	int length();
	String subString(int startIndex, int length);
	bool equals(String stringToCompare);
	char at(int index);
	void toUpper();
	void toLower();
	void trimStart();
	void trimEnd();
	void trim();
	void replace(String stringToReplace, String replacementString);
	String& operator= (const String& toAssign);
private:
	char* pString;
	void destroy();
	void remove(int startIndex, int aLength);
	int match(String lookingIn, String lookingFor);

};

