//----------------------------------------------------------------------------------------------------
// Name: Roman Mashak
// Class: SET-252 - C Programming #2
// Assignment: Final Project - CSuperString
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// Includes.
//----------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "CSuperString.h"

//----------------------------------------------------------------------------------------------------
// Constants.
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// User-Defined Types.
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// Prototypes.
//----------------------------------------------------------------------------------------------------

#pragma region "void parameters"

void Test1();
void Test2();
void Test_Constructor();
void Test_Assignment_Operators();
void Test_Concatination_Operators();
void Test_Plus_Operator();
void Test_Find_Function();
void Test_Modification_Function();
void Test_Substring_Replace_Insert();
void Test_Conversion_Functions();
void Test_Operator_Overloads();

#pragma endregion

void main()
{
    Test1();
    Test2();
    
    Test_Constructor();
    Test_Assignment_Operators();
    Test_Concatination_Operators();
    Test_Plus_Operator();
    Test_Find_Function();
    Test_Modification_Function();
    Test_Substring_Replace_Insert();
    Test_Conversion_Functions();
    Test_Operator_Overloads();

	system("pause");
}

void Test1()
{
    CSuperString ssTest;
    cout << "Test #1: " << ssTest << endl;
}

void Test2()
{
    CSuperString ssTest = "I Love Star Wars and I Love Star Trek";

    ssTest = ssTest.Replace("Love", "Really Love Love");

    cout << "Test #2: " << ssTest << endl;

    cout << endl;
}

void Test_Constructor()
{
	cout << "===============================" << endl;
	cout << "CSuperString Constructor Test" << endl;
	cout << "===============================" << endl;
	cout << endl;


	CSuperString ssDefault;
	ssDefault.Print("Default - [Should be Empty]");

	CSuperString ssFromCharStar("I Love Warframe");
	ssFromCharStar.Print("Const Char* - [I Love Warframe]");

    CSuperString ssFromBoolTrue(true);
    ssFromBoolTrue.Print("Bool True - [True]");

    CSuperString ssFromBoolFalse(false);
    ssFromBoolFalse.Print("Bool False - [False]");

    CSuperString ssFromChar('W');
    ssFromChar.Print("Char - [W]");

    CSuperString ssFromShort((short)8288013);
    ssFromShort.Print("Short - [8288013]");

    CSuperString ssFromInt(102030);
    ssFromInt.Print("Int - [102030]");

    CSuperString ssFromLong(1234567890L);
    ssFromLong.Print("Long - [1234567890]");

    CSuperString ssFromFloat(3.14159f);
    ssFromFloat.Print("Float - [3.14159]");

    CSuperString ssFromDouble(2.718281828);
    ssFromDouble.Print("Double - [2.718281828]");

    CSuperString ssCopy(ssFromCharStar);
    ssCopy.Print("Copy of \"I Love Warframe\"");

    cout << endl;
}

void Test_Assignment_Operators()
{
    cout << "========================================" << endl;
    cout << "CSuperString Assignment_Operators Test" << endl;
    cout << "========================================" << endl;
    cout << endl;


    CSuperString ssBuffer("Pizza");

    ssBuffer.Print("Assigned \"Pizza\" to ssBuffer"); // (Pizza)

    ssBuffer = 'A';
    ssBuffer.Print("Assigned 'A' to ssBuffer"); // (A)

    CSuperString ssBuffer2("Warframe");
    
    ssBuffer = ssBuffer2;
    ssBuffer.Print("Assigned \"Warframe\" to ssBuffer"); // (Warframe)

    ssBuffer = ssBuffer;
    ssBuffer.Print("Self-assignment - Should stay \"Warframe\"");  // (Warframe)

    cout << endl;
}

void Test_Concatination_Operators()
{
    cout << "========================================" << endl;
    cout << "CSuperString Concatination_Operators Test" << endl;
    cout << "========================================" << endl;
    cout << endl;
    

    CSuperString ssBuffer("Warframe");

    ssBuffer += " Cool";
    ssBuffer.Print("Concatenating const char* | After += [Cool]");

    ssBuffer += '!';
    ssBuffer.Print("Concatenating char | After += '!'");

    CSuperString ssToAppend(" Welcome!");
    ssBuffer += ssToAppend;
    ssBuffer.Print("Concatenating another CSuperString | After += CSuperString(Welcome!)");

    ssBuffer += ssBuffer;
    ssBuffer.Print("Self-concatenation test | After self-concatenation");

    cout << endl;
}

void Test_Plus_Operator()
{
    cout << "========================================" << endl;
    cout << "CSuperString +Operator Test" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    
    // Test 1: Operator + with two CSuperString objects.
    CSuperString ssBuffer1("Pizza, ");
    CSuperString ssBuffer2("Water!");

    // Using the operator+ for two CSuperString objects.
    CSuperString result1 = ssBuffer1 + ssBuffer2;  
    std::cout << "#1 - str1 + str2:         | " << result1.ToString() << std::endl;  // Expected: "Hello, World!"


    // Test 2: Operator + with a const char* and a CSuperString object
    const char* ssBuffer3 = "Goodbye, ";
    CSuperString ssBuffer4("Warframe!");

    // Using the operator+ for const char* and CSuperString.
    CSuperString result2 = ssBuffer3 + ssBuffer4;
    std::cout << "#2 - greeting + str3:     | " << result2.ToString() << std::endl;  // Expected: "Goodbye, Everyone!"


    // Test 3: Operator + with a CSuperString object and a const char*
    CSuperString ssBuffer5("Welcome ");
    const char* ssBuffer6 = "Roman!";

    // Using the operator+ for CSuperString and const char*
    CSuperString result3 = ssBuffer5 + ssBuffer6;
    std::cout << "#3 - str4 + name:         | " << result3.ToString() << std::endl;  // Expected: "Welcome Alice!"

    cout << endl;
}

void Test_Find_Function()
{
    cout << "===============================" << endl;
    cout << "CSuperString Find_Function Test" << endl;
    cout << "===============================" << endl;
    cout << endl;
    
    
    CSuperString ssBuffer("I Love Warframe, I Love Sleep!");

    long index = ssBuffer.FindFirstIndexOf('f');
    printf("#1 - FindFirstIndexOf(char) - First occurrence of 'f':                                       | %ld\n", index);

    index = ssBuffer.FindFirstIndexOf('o', 6);
    printf("#2 - FindFirstIndexOf(char, start index) - First occurrence of 'o' after index 6:            | %ld\n", index);

    index = ssBuffer.FindLastIndexOf('e');
    printf("#3 - FindLastIndexOf(char) - Last occurrence of 'e':                                         | %ld\n", index);

    index = ssBuffer.FindFirstIndexOf("Love");
    printf("#4 - FindFirstIndexOf(const char*) - First occurrence of [Love]:                             | %ld\n", index);

    index = ssBuffer.FindFirstIndexOf("Love", 7);
    printf("#5 - FindFirstIndexOf(const char*, start index) - First occurrence of [Love] after index 7:  | %ld\n", index);

    index = ssBuffer.FindLastIndexOf("Warframe");
    printf("#6 - FindLastIndexOf(const char*) - Last occurrence of [Warframe]:                           | %ld\n", index);

    index = ssBuffer.FindFirstIndexOf('z');
    printf("#7 - Not found cases (should return -1) - First occurrence of 'z':                           | %ld\n", index);

    index = ssBuffer.FindFirstIndexOf("Love");
    printf("#8 - First occurrence of [Love]:                                                             | %ld\n", index);

    cout << endl;
}

void Test_Modification_Function()
{
    cout << "=========================================" << endl;
    cout << "CSuperString Modification_Function Test" << endl;
    cout << "=========================================" << endl;
    cout << endl;


    CSuperString ssBuffer("  Hello Warframe!  ");

    cout << "#1 - Original:  |" << ssBuffer.ToString() << endl;

    cout << "\n#2 - Uppercase: |" << ssBuffer.ToUpperCase() << endl;

    cout << "\n#3 - Lowercase: |" << ssBuffer.ToLowerCase() << endl;
    
    cout << "\n#4 - TrimLeft:  |" << ssBuffer.TrimLeft() << "|" << endl;
    
    cout << "\n#5 - TrimRight: |" << ssBuffer.TrimRight() << "|" << endl;
    
    cout << "\n#6 - Trim:      |" << ssBuffer.Trim() << "|" << endl;
    
    cout << "\n#7 - Reverse:   |" << ssBuffer.Reverse() << endl;

    cout << endl;
}

void Test_Substring_Replace_Insert()
{
    cout << "============================================" << endl;
    cout << "CSuperString Substring_Replace_Insert Test" << endl;
    cout << "============================================" << endl;
    cout << endl;
    
    
    CSuperString ssBuffer("I Love Warframe Too Much!");

    cout << "Left(6):                        | " << ssBuffer.Left(6) << endl;
    
    cout << "Right(11):                      | " << ssBuffer.Right(11) << endl;
    
    cout << "Substring(7, 8):                | " << ssBuffer.Substring(7, 8) << endl;
    
    cout << "Replace ' ' with '_':           | " << ssBuffer.Replace(' ', '_') << endl;
    
    cout << "Replace [Love] with [Hate]:     | " << ssBuffer.Replace("Love", "Hate") << endl;
    
    cout << "Insert '!' at index 5:          | " << ssBuffer.Insert(',', 6) << endl;
    
    cout << "Insert [ Love] at index 6:      | " << ssBuffer.Insert(" Love", 6) << endl;

    cout << endl;
}

void Test_Conversion_Functions()
{
    cout << "============================================" << endl;
    cout << "CSuperString Conversion_Test" << endl;
    cout << "============================================" << endl;
    cout << endl;
    
    
    CSuperString ssTrue("1");
    CSuperString ssFalse("0");
    CSuperString ssNumber("5000");
    CSuperString ssFloat("5.12354");

    cout << "String '1' to bool:         | " << ssTrue.ToBoolean() << endl;
    cout << "String '0' to bool:         | " << ssFalse.ToBoolean() << endl;
    
    cout << "String '5000' to short:     | " << ssNumber.ToShort() << endl;
    cout << "String '5000' to int:       | " << ssNumber.ToInteger() << endl;
    cout << "String '5000' to long:      | " << ssNumber.ToLong() << endl;

    
    cout << "String '5.12354' to float:  | " << ssFloat.ToFloat() << endl;
    cout << "String '5.12354' to double: | " << ssFloat.ToDouble() << endl;

    cout << endl;
}

void Test_Operator_Overloads()
{
    cout << "=================================================" << endl;
    cout << "CSuperString Operator Overload / Subscript Test" << endl;
    cout << "=================================================" << endl;
    cout << endl;
    

    CSuperString ssBuffer1("Warframe");
    CSuperString ssBuffer2("Pizza");
    CSuperString ssBuffer3("Water");
     
    cout << "#1 - Check if Pizza == Water: (false)    | " << (ssBuffer2 == ssBuffer3) << endl;
    cout << "#2 - Check if Warframe != Water: (true)  | " << (ssBuffer1 != ssBuffer2) << endl;
    cout << "#3 - Check if Warframe < Water: (false)  | " << (ssBuffer1 < ssBuffer2) << endl;
    cout << "#4 - Check if Pizza > Warframe: (false)  | " << (ssBuffer2 > ssBuffer1) << endl;
    cout << "#5 - Check if Pizza <= Water: (true)     | " << (ssBuffer2 <= ssBuffer3) << endl;
    cout << "#6 - Check if Pizza >= Warframe: (false) | " << (ssBuffer2 >= ssBuffer1) << endl;

    cout << "\n[Subscript Operator]\n";

    cout << "Character at index 0 for 'Warframe': (W) | " << ssBuffer1[0] << endl;
    cout << "Character at index 4 for 'Pizza':    (a) | " << ssBuffer2[4] << endl;
    cout << "Character at index 4 for 'Water':    (t) | " << ssBuffer3[2] << endl;

    cout << endl;
}

