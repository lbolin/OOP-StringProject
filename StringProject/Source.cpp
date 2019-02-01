#include "String.h"
#include<iostream>

using std::cout;
using std::endl;
void main() {

	String s;
	s.set(74);
	s.contains(7);

	String sentence;
	sentence.set("First Last");
	sentence.insert(5, 5);
	sentence.write(cout);

	String Test;
	Test.set("Computer's are amazing machines");
	char c = Test.at(8);
	std::cout << std::endl << c << std::endl;

	String Test2(Test.subString(0, 15));
	Test2.write(cout);

	if (Test2.equals("ter"))
	{
		std::cout << std::endl << "New Line" << std::endl;
	}

	Test2.toUpper();
	Test2.write(cout);

	Test2.toLower();
	Test2.write(cout);

	std::cout << std::endl << std::endl;

	String Test3("    Grad Lobby       ");
	Test3.write(cout);
	std::cout << std::endl;
	Test3.trimStart();
	Test3.write(cout);
	Test3.write(cout);
	std::cout << std::endl;
	Test3.trimEnd();
	Test3.write(cout);
	Test3.write(cout);

	std::cout << std::endl << std::endl;
	String Test4("    Searcy Lobby       ");
	Test4.write(cout);
	std::cout << std::endl;
	Test4.trim();
	Test4.write(cout);
	Test4.write(cout);

	std::cout << std::endl << std::endl;
	String Test5("In the beginning was the Word, and the Word was with God, and the Word was God.");
	Test5.write(cout);
	std::cout << std::endl;
	Test5.replace("Word", "Dude");
	Test5.write(cout);



}