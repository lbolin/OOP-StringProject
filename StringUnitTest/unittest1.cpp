#include "stdafx.h"
#include "CppUnitTest.h"
#include "String.h"
#include "..\StringProject\String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestString
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(StringDefaultConstructor)
		{
			String Test;
			if (!Test.isEmpty())
			{
				Assert::Fail(L"Did not create empty list");
			}
		}

		TEST_METHOD(StringCopyConstructor)
		{
			String Test = "Original String";
			String Test2(Test);
			if (!Test2.equals(Test))
			{
				Assert::Fail(L"Copied list did not match");
			}
			Test2 = Test2.subString(0, 8);
			if (Test2.equals(Test))
			{
				Assert::Fail(L"Copy was a shallow copy");
			}
		}

		TEST_METHOD(StringConversionConstructorForCstyleString)
		{
			String Test = "Test";
			String Test2 = "Test2";
			if (Test2.equals(Test))
			{
				Assert::Fail(L"String from C-Style did match Despite being unequivalent");
			}
			if (Test2.at(4) != '2')
			{
				Assert::Fail(L"The End of the C-Style String may not be getting properly converted");
			}
		}

		TEST_METHOD(StringConversionConstructorForInt)
		{
			String Test = 7;
			String Test2 = "7";
			String Test3 = 45;
			if (!Test2.equals(Test))
			{
				Assert::Fail(L"String from Integer did not match string of number");
			}
			if (Test2.equals(Test3))
			{
				Assert::Fail(L"Integers are being coverted to the wrong number");
			}
		}

		TEST_METHOD(StringConversionConstructorForChar)
		{
			String Test = 'C';
			String Test2 = 'C';
			String Test3 = 'D';
			if (!Test2.equals(Test))
			{
				Assert::Fail(L"String from Char did not match same Char");
			}
			if (Test2.equals(Test3))
			{
				Assert::Fail(L"All Chars are being coverted to the same String");
			}
		}

		TEST_METHOD(StringIsEqualNulls)
		{
			String Test;
			String Test2;
			String Test3 = "Something";
			String Test4 = "";
			if (!(Test2.equals(Test)))
			{
				Assert::Fail(L"Equal Strings came back as Unequal");
			}
			if (Test3.equals(Test))
			{
				Assert::Fail(L"Unequal Strings came back as equal");
			}
			if (Test.equals(Test3))
			{
				Assert::Fail(L"Unequal Strings came back as equal");
			}
			if (!Test.equals(Test4))
			{
				Assert::Fail(L"Empty String did not equal null string");
			}
		}

		TEST_METHOD(StringIsEqualStrings)
		{
			String Test = "Test";
			String Test2 = "Test2";
			String Test3 = "Test";
			if (Test2.equals(Test))
			{
				Assert::Fail(L"Unequal Strings came back as equal");
			}
			if (Test.equals(Test2))
			{
				Assert::Fail(L"Unequal Strings came back as equal");
			}
			if (!Test.equals(Test3))
			{
				Assert::Fail(L"Equal Strings are coming back as unequal");
			}
			if (!Test.equals(Test))
			{
				Assert::Fail(L"String does not equal it's self");
			}
		}

		TEST_METHOD(StringIsEqualCStyle)
		{
			String Test = "Test";
			String Test2 = "Test2";
			if (Test.equals("Test2"))
			{
				Assert::Fail(L"Unequal Strings came back as equal");
			}
			if (Test2.equals("Test"))
			{
				Assert::Fail(L"Unequal Strings came back as equal");
			}
			if (!Test.equals("Test"))
			{
				Assert::Fail(L"Equal Strings are coming back as unequal");
			}
		}

		TEST_METHOD(StringIsEqualChar)
		{
			String Test = "A";
			if (Test.equals('C'))
			{
				Assert::Fail(L"Unequal Strings came back as equal");
			}
			if (!Test.equals('A'))
			{
				Assert::Fail(L"Equal Strings are coming back as unequal");
			}
		}

		TEST_METHOD(StringIsEqualInts)
		{
			String Test = 1;
			if (Test.equals(2))
			{
				Assert::Fail(L"Unequal Strings came back as equal");
			}
			if (!Test.equals(1))
			{
				Assert::Fail(L"Equal Strings are coming back as unequal");
			}
		}

		TEST_METHOD(StringIsEmpty)
		{
			String Test;
			String Test2 = "";
			String Test3 = "Something";
			if (!Test.isEmpty())
			{
				Assert::Fail(L"isEmpty returned false on a null string");
			}
			if (!Test2.isEmpty())
			{
				Assert::Fail(L"isEmpty returned false on an empty string (pointer to a null character)");
			}
			if (Test3.isEmpty())
			{
				Assert::Fail(L"String containing characters returned empty");
			}

		}

		TEST_METHOD(StringSetNull)
		{
			String Test = "Something";
			String Test2;
			Test.set(Test2);
			if (!Test.isEmpty())
			{
				Assert::Fail(L"String was not set to an empty string");
			}

			String Test3;
			String Test4 = "Something Else";
			Test3.set(Test4);
			if (!Test.isEmpty())
			{
				Assert::Fail(L"Empty string was not set to the correct string");
			}

		}

		TEST_METHOD(StringSetString)
		{
			String Test = "Something";
			String Test2 = "Something Else";
			String Test3 = "Something";
			Test.set(Test2);
			if (!Test.equals(Test2))
			{
				Assert::Fail(L"String was not set to the correct string");
			}
			if (Test.equals(Test3))
			{
				Assert::Fail(L"String was not changed");
			}
			Test3.set(Test3);
			if (!Test3.equals(Test3))
			{
				Assert::Fail(L"String was not copied to itself");
			}
		}

		TEST_METHOD(StringSetCStyleStrings)
		{
			String Test = "Something";
			Test.set("Something Else");
			if (!Test.equals("Something Else"))
			{
				Assert::Fail(L"String was not set to the correct string");
			}
			if (Test.equals("Something"))
			{
				Assert::Fail(L"String was not changed");
			}
		}

		TEST_METHOD(StringSetChars)
		{
			String Test = 'A';
			Test.set('B');
			if (!Test.equals('B'))
			{
				Assert::Fail(L"String was not set to the correct character");
			}
			if (Test.equals('A'))
			{
				Assert::Fail(L"String was not changed");
			}
		}

		TEST_METHOD(StringSetInts)
		{
			String Test = 1;
			Test.set(2);
			if (!Test.equals(2))
			{
				Assert::Fail(L"String was not set to the correct number");
			}
			if (Test.equals(1))
			{
				Assert::Fail(L"String was not changed");
			}
		}

		TEST_METHOD(StringAppendNull)
		{
			String Test = "abc";
			String Test2;
			Test.append(Test2);
			if (!Test.equals("abc"))
			{
				Assert::Fail(L"Null string was not correctly appended");
			}

			String Test3;
			String Test4 = "def";
			Test3.append(Test4);
			if (!Test3.equals("def"))
			{
				Assert::Fail(L"String was not correctly appended to null string");
			}
		}

		TEST_METHOD(StringAppendString)
		{
			String Test = "abc";
			String Test2 = "def";
			String Test3 = "abcdef";
			String Test4 = "abc";
			Test.append(Test2);
			if (!Test.equals(Test3))
			{
				Assert::Fail(L"String was not correctly appended");
			}
			if (Test.equals(Test4))
			{
				Assert::Fail(L"String was not appended");
			}
		}

		TEST_METHOD(StringAppendCStyleString)
		{
			String Test = "abc";
			Test.append("def");
			if (!Test.equals("abcdef"))
			{
				Assert::Fail(L"String was not correctly appended");
			}
			if (Test.equals("abc"))
			{
				Assert::Fail(L"String was not appended");
			}
		}

		TEST_METHOD(StringAppendCharacters)
		{
			String Test = 'a';
			Test.append('b');
			if (!Test.equals("ab"))
			{
				Assert::Fail(L"String was not correctly appended");
			}
			if (Test.equals("a"))
			{
				Assert::Fail(L"String was not appended");
			}
		}

		TEST_METHOD(StringAppendInts)
		{
			String Test = 1;
			Test.append(2);
			if (!Test.equals("12"))
			{
				Assert::Fail(L"String was not correctly appended");
			}
			if (Test.equals("1"))
			{
				Assert::Fail(L"String was not appended");
			}
		}


		TEST_METHOD(StringPrependNull)
		{
			String Test = "abc";
			String Test2;
			Test.prepend(Test2);
			if (!Test.equals("abc"))
			{
				Assert::Fail(L"Null string was not correctly prepended");
			}

			String Test3;
			String Test4 = "def";
			Test3.prepend(Test4);
			if (!Test3.equals("def"))
			{
				Assert::Fail(L"String was not correctly prepended to null string");
			}
		}

		TEST_METHOD(StringPrependString)
		{
			String Test = "abc";
			String Test2 = "def";
			String Test3 = "defabc";
			String Test4 = "abc";
			Test.prepend(Test2);
			if (!Test.equals(Test3))
			{
				Assert::Fail(L"String was not correctly prepended");
			}
			if (Test.equals(Test4))
			{
				Assert::Fail(L"String was not prepended");
			}
		}

		TEST_METHOD(StringPrependCStyleString)
		{
			String Test = "abc";
			Test.prepend("def");
			if (!Test.equals("defabc"))
			{
				Assert::Fail(L"String was not correctly prepended");
			}
			if (Test.equals("abc"))
			{
				Assert::Fail(L"String was not prepended");
			}
		}

		TEST_METHOD(StringPrependCharacters)
		{
			String Test = 'a';
			Test.prepend('b');
			if (!Test.equals("ba"))
			{
				Assert::Fail(L"String was not correctly prepended");
			}
			if (Test.equals("a"))
			{
				Assert::Fail(L"String was not prepended");
			}
		}

		TEST_METHOD(StringPrependInts)
		{
			String Test = 1;
			Test.prepend(2);
			if (!Test.equals("21"))
			{
				Assert::Fail(L"String was not correctly prepended");
			}
			if (Test.equals("1"))
			{
				Assert::Fail(L"String was not prepended");
			}
		}

		TEST_METHOD(StringContainsNull)
		{
			String Test = "Something";
			String Test2;
			if (Test.contains(Test2))
			{
				Assert::Fail(L"Contained null string");
			}

			String Test3;
			String Test4 = "Something";
			if (Test3.contains(Test4))
			{
				Assert::Fail(L"Null string contained a string");
			}

		}

		TEST_METHOD(StringContainsStrings)
		{
			String Test = "Something";
			String Test2 = "Some";
			String Test3 = "Else";
			if (!Test.contains(Test2))
			{
				Assert::Fail(L"String did not contain substring");
			}
			if (Test.contains(Test3))
			{
				Assert::Fail(L"String contained nonmatching string");
			}
			if (!Test.contains(Test))
			{
				Assert::Fail(L"String did not contain itself");
			}
		}

		TEST_METHOD(StringContainsCStyleStrings)
		{
			String Test = "Something";
			if (!Test.contains("Some"))
			{
				Assert::Fail(L"String did not contain substring");
			}
			if (Test.contains("Else"))
			{
				Assert::Fail(L"String contained nonmatching string");
			}
			if (!Test.contains("Something"))
			{
				Assert::Fail(L"String did not contain itself");
			}
		}

		TEST_METHOD(StringContainsCharacters)
		{
			String Test = "Something";
			if (!Test.contains('S'))
			{
				Assert::Fail(L"String did not contain first character");
			}
			if (!Test.contains('g'))
			{
				Assert::Fail(L"String did not contain last character");
			}
			if (Test.contains("y"))
			{
				Assert::Fail(L"String contained nonmatching character");
			}
		}

		TEST_METHOD(StringContainsInteger)
		{
			String Test = 1456832;
			if (!Test.contains(1))
			{
				Assert::Fail(L"String did not contain first digit");
			}
			if (!Test.contains(2))
			{
				Assert::Fail(L"String did not contain last digit");
			}
			if (Test.contains(9))
			{
				Assert::Fail(L"String contained nonmatching digit");
			}
		}

		TEST_METHOD(StringInsertNull)
		{
			String Test = "Something";
			String Test2;
			Test.insert(Test2, 3);
			if (!Test.equals("Something"))
			{
				Assert::Fail(L"Insertion of Null String Failed");
			}

			String Test3;
			String Test4 = "Something";
			Test3.insert(Test4, 3);
			if (!Test3.equals("Something"))
			{
				Assert::Fail(L"Insertion into Null String Failed");
			}
		}

		TEST_METHOD(StringInsertString)
		{
			String Test = "Something Else";
			String Test2 = " or";
			String Test3 = "Begin ";
			String Test4 = " End";
			Test.insert(Test2, 9);
			if (!Test.equals("Something or Else"))
			{
				Assert::Fail(L"Insertion of String Failed");
			}
			Test.insert(Test3, -45);
			if (!Test.equals("Begin Something or Else"))
			{
				Assert::Fail(L"Insertion of String at negative index Failed");
			}
			Test.insert(Test4, 45);
			if (!Test.equals("Begin Something or Else End"))
			{
				Assert::Fail(L"Insertion of String at \"beyond the end\" index Failed");
			}
		}

		TEST_METHOD(StringInsertCStyleString)
		{
			String Test = "Something Else";
			Test.insert(" or", 9);
			if (!Test.equals("Something or Else"))
			{
				Assert::Fail(L"Insertion of String Failed");
			}
			Test.insert("Begin ", -45);
			if (!Test.equals("Begin Something or Else"))
			{
				Assert::Fail(L"Insertion of String at negative index Failed");
			}
			Test.insert(" End", 45);
			if (!Test.equals("Begin Something or Else End"))
			{
				Assert::Fail(L"Insertion of String at \"beyond the end\" index Failed");
			}
		}

		TEST_METHOD(StringInsertCharacters)
		{
			String Test = "Something Else";
			Test.insert('s', 9);
			if (!Test.equals("Somethings Else"))
			{
				Assert::Fail(L"Insertion of Character Failed");
			}
			Test.insert('A', -45);
			if (!Test.equals("ASomethings Else"))
			{
				Assert::Fail(L"Insertion of Character at negative index Failed");
			}
			Test.insert('O', 45);
			if (!Test.equals("ASomethings ElseO"))
			{
				Assert::Fail(L"Insertion of Character at \"beyond the end\" index Failed");
			}
		}

		TEST_METHOD(StringInsertIntegers)
		{
			String Test = "Something Else";
			Test.insert(5, 9);
			if (!Test.equals("Something5 Else"))
			{
				Assert::Fail(L"Insertion of Integer Failed");
			}
			Test.insert(1, -45);
			if (!Test.equals("1Something5 Else"))
			{
				Assert::Fail(L"Insertion of Integer at negative index Failed");
			}
			Test.insert(9, 45);
			if (!Test.equals("1Something5 Else9"))
			{
				Assert::Fail(L"Insertion of Integer at \"beyond the end\" index Failed");
			}
		}

		TEST_METHOD(StringLength)
		{
			String Test;
			String Test2 = "";
			String Test3 = "A";
			String Test4 = "Something";
			if (Test.length() != 0)
			{
				Assert::Fail(L"Length of Null String was not 0");
			}
			if (Test2.length() != 0)
			{
				Assert::Fail(L"Length of Empty String was not 0");
			}
			if (Test3.length() != 1)
			{
				Assert::Fail(L"Length of one character String was not 1");
			}
			if (Test4.length() != 9)
			{
				Assert::Fail(L"Length of String \"Something\" was not 9");
			}
		}

		TEST_METHOD(StringSubStringNull)
		{
			String Test;
			String Test2 = Test.subString(4, 7);
			if (!Test.isEmpty())
			{
				Assert::Fail(L"Substring grabbed data from null pointer");
			}
		}

		TEST_METHOD(StringSubString)
		{
			String Test = "Something";
			String Test2 = Test.subString(4, 5);
			String Test3 = Test.subString(4, 9);
			String Test4 = Test.subString(-1, 4);
			if (!Test2.equals("thing"))
			{
				Assert::Fail(L"Substring did not correctly extract the right string");
			}
			if (!Test3.equals("thing"))
			{
				Assert::Fail(L"Substring did not correctly extract the right string when given too long of length");
			}
			if (!Test4.equals("Some"))
			{
				Assert::Fail(L"Substring did not correctly extract the right string when given negative index");
			}
		}

		TEST_METHOD(StringAtNull)
		{
			String Test;
			if (Test.at(0) != '\0')
			{
				Assert::Fail(L"At function did not properly handle null string");
			}
		}

		TEST_METHOD(StringAt)
		{
			String Test = "Something";
			if (Test.at(4) != 't')
			{
				Assert::Fail(L"At did not retieve the correct character");
			}
			if (Test.at(-3) != '\0')
			{
				Assert::Fail(L"At did not retieve the correct character when given negative index");
			}
			if (Test.at(45) != '\0')
			{
				Assert::Fail(L"At did not retieve the correct character when given too large of index");
			}
		}

		TEST_METHOD(StringToUpperNull)
		{
			String Test;
			Test.toUpper();
			if (!Test.isEmpty())
			{
				Assert::Fail(L"To Upper modified a null string");
			}
		}

		TEST_METHOD(StringToUpper)
		{
			String Test = "Aa'{";
			Test.toUpper();
			if (!Test.equals("AA'{"))
			{
				Assert::Fail(L"ToUpper failed to correctly capitalize Test");
			}
		}

		TEST_METHOD(StringToLowerNull)
		{
			String Test;
			Test.toLower();
			if (!Test.isEmpty())
			{
				Assert::Fail(L"ToLower modified a null string");
			}
		}

		TEST_METHOD(StringToLower)
		{
			String Test = "Aa@[";
			Test.toLower();
			if (!Test.equals("aa@["))
			{
				Assert::Fail(L"ToLower failed to correctly capitalize Test");
			}
		}

		TEST_METHOD(StringTrimStartNull)
		{
			String Test;
			Test.trimStart();
			if (!Test.isEmpty())
			{
				Assert::Fail(L"TrimStart modified a null string");
			}
		}

		TEST_METHOD(StringTrimStart)
		{
			String Test = "Something";
			String Test2 = "   Else";
			Test.trimStart();
			if (!Test.equals("Something"))
			{
				Assert::Fail(L"TrimStart edited a string with no leading whitespace");
			}
			Test2.trimStart();
			if (Test.equals("Else"))
			{
				Assert::Fail(L"TrimStart did not remove all leading whitespace correctly");
			}
		}

		TEST_METHOD(StringTrimEndNull)
		{
			String Test;
			Test.trimEnd();
			if (!Test.isEmpty())
			{
				Assert::Fail(L"TrimEnd modified a null string");
			}
		}

		TEST_METHOD(StringTrimEnd)
		{
			String Test = "Something";
			String Test2 = "Else   ";
			Test.trimEnd();
			if (!Test.equals("Something"))
			{
				Assert::Fail(L"TrimEnd edited a string with no trailing whitespace");
			}
			Test2.trimEnd();
			if (Test.equals("Else"))
			{
				Assert::Fail(L"TrimEnd did not remove all trailing whitespace correctly");
			}
		}

		TEST_METHOD(StringTrimNull)
		{
			String Test;
			Test.trim();
			if (!Test.isEmpty())
			{
				Assert::Fail(L"Trim modified a null string");
			}
		}

		TEST_METHOD(StringTrim)
		{
			String Test = "Something";
			String Test2 = "   Else   ";
			Test.trim();
			if (!Test.equals("Something"))
			{
				Assert::Fail(L"Trim edited a string with no leading or trailing whitespace");
			}
			Test2.trim();
			if (Test.equals("Else"))
			{
				Assert::Fail(L"TrimEnd did not remove all leading or trailing whitespace correctly");
			}
		}
		TEST_METHOD(StringReplaceNull)
		{
			String Test = "";
			String Test2 = "";
			String Test3 = "";
			String Test4 = "Something";
			String Test5 = "Else";

			Test.replace(Test2, Test3);
			if (!Test.isEmpty())
			{
				Assert::Fail(L"Replace modified a null string, Replaced a Empty string with an Empty String in an Empty String");
			}

			Test4.replace(Test2, Test3);
			if (!Test4.equals("Something"))
			{
				Assert::Fail(L"Replace modified a string, Replaced a Empty string with an Empty String");
			}

			Test4.replace(Test5, Test3);
			if (!Test4.equals("Something"))
			{
				Assert::Fail(L"Replace modified a string, Replaced a string with an Empty String");
			}

			Test4.replace(Test2, Test5);
			if (!Test4.equals("Something"))
			{
				Assert::Fail(L"Replace modified a string, Replaced a Empty string with a String");
			}
		}

		TEST_METHOD(StringReplaceString)
		{
			String Test = "something";
			String Test2 = "else";
			String Test3 = "I";
			String Test4 = "I cant think of another word, I will have to think of something else";
			String Test5 = "what word should i use know";

			Test4.replace(Test, Test2);
			if (!Test4.equals("I cant think of another word, I will have to think of else else"))
			{
				Assert::Fail(L"Replace did not correctly swap the givin strings");
			}

			Test4.replace(Test3, Test2);
			if (!Test4.equals("else cant think of another word, else will have to think of else else"))
			{
				Assert::Fail(L"Replace did not correctly swap the givin strings with multiple occurences");
			}

			Test5.replace(Test, Test2);
			if (!Test5.equals("what word should i use know"))
			{
				Assert::Fail(L"Edited a string with no occurence");
			}


		}

	};
}