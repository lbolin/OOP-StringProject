# StringProject

Comp 345
Assignment 3
Topic: Strings Part 1
Points: 25
Goals
        1. Review use of pointers
        2. Review dynamic memory
        3. Make good use of encapsulation and information hiding
        Instructions
        1. Start with the code below:
        2. Implement the functions that are commented out in the header file. Functions should
        be removed if they will work using a conversion constructor.
        3. Be sure to check for NULL pointers in every possible scenario.
        4. Make sure your test program thoroughly tests your string class.
Details
      When writing your insert functions:
      When the index to insert into the string is < 0 use the prepend functionality of your class.
      When the index to insert into the string is > the length of pString use the append
      functionality of your class.
Hints
      You should only have to implement the logic of your functions in one place per function
      type. For example you should only have to write the append functionality once. Use that
      function from all of your other functions. I recommend placing your logic in the functions
      that take the char*. It is ease to create one of those and call it from the others.
Files to Submit
      string.h
      string.cpp
      test.cpp
      String.h
      

Topic: Strings Part 2 Points: 25
Goals
    1. Learn proper usages of constant parameters.
    2. Learn proper usages of constant functions.
    3. Learn proper usages of constant return values.
    4. Review use of pointers
    5. Review dynamic memory
    6. Make good use of encapsulation and information hiding
Instructions
      1. Start with your files from the previous string assignment (or files given to you)
      2. Make all paramters const that should not be changed.
      3. Make all member functions const that should not change member variables.
      4. Make all return values const that point or reference a member variable.
      5. Be sure your header file can be included multiple times. Use: #pragma once or
          #ifndef STRING_H
          #define STRING_H
          class definition
          #endif
      6. Be sure you have no duplicate code. (Use the functions you have written.)
      7. Make all functions "this safe".
      8. Implement the functions described below.
      9. Be sure to check for NULL pointers in every possible scenario.
Functions to Add
      1. subString - returns a String by value. It should take a starting index and a length.
          If the starting index is < 0 start a 0.
          If the starting index is > the length of the string return an empty string.
          If the length goes past the end of the string, just stop at the end.
      2. equals - return true if the two values are equal. false otherwise. It should take a
        String, char*, char or int.
      3. at - returns a char at the given index.
        It should take an integer as a parameter.
        If there is not a character at the given index return '\0'.
      4. toUpper - should change all of the characters in the string to upper case.
      5. toLower - should change all of the characters in the string to lower case.
      6. trimStart - removes all of the white-space from the beginning of the String.
      7. trimEnd - removes all of the white-space from the end of the String.
      8. trim - removes all of the white-space from the beginning and end of the String.
      9. replace - should take two parameters.
Search for all occurrences of the first parameter and replace it with the second
parameter.

This function can be called in 16 ways.
replace(String, String)
replace(String, char*)
replace(String, int)
replace(String, char)
replace(char*, String)
replace(char*, char*)
replace(char*, int)
replace(char*, char)
replace(int, String)
replace(int, char*)
replace(int, int)
replace(int, char)
replace(char, String)
replace(char, char*)
replace(char, int)
replace(char, char)

Be sure not to replace parts of the String that you just added
Hints
You should only have to write one replace function. See the Conversion Constructor
Example
Sorry to tell you now but this was true for all of the functions you have written.
