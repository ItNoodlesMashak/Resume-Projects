// --------------------------------------------------------------------------------
// Class: CSuperString
// Abstract: Method definitions for the CSuperString Class.
// --------------------------------------------------------------------------------



// --------------------------------------------------------------------------------
// Include.
// --------------------------------------------------------------------------------
#include "CSuperString.h"

#pragma region "Constructors / Initialize"

// --------------------------------------------------------------------------------
// Class: Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString()
{
	Initialize("");
}



// --------------------------------------------------------------------------------
// Class: Parameterized Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const char* pstrStringToCopy)
{
	m_pstrSuperString = CloneString(pstrStringToCopy);
}



// --------------------------------------------------------------------------------
// Class: Bool Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const bool blnBooleanToCopy)
{
	const char* pstrValue = blnBooleanToCopy ? "true" : "false";
	m_pstrSuperString = CloneString(pstrValue);
}



// --------------------------------------------------------------------------------
// Class: Char Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const char chrLetterToCopy)
{
	char buffer[2] = { chrLetterToCopy, '\0' };
	m_pstrSuperString = CloneString(buffer);
}



// --------------------------------------------------------------------------------
// Class: Short Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const short shtShortToCopy)
{
	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%hd", shtShortToCopy);
	m_pstrSuperString = CloneString(buffer);
}



// --------------------------------------------------------------------------------
// Class: Int Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const int intIntegerToCopy)
{
	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%d", intIntegerToCopy);
	m_pstrSuperString = CloneString(buffer);
}



// --------------------------------------------------------------------------------
// Class: Long Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const long lngLongToCopy)
{
	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%ld", lngLongToCopy);
	m_pstrSuperString = CloneString(buffer);
}



// --------------------------------------------------------------------------------
// Class: Float Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const float sngFloatToCopy)
{
	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%f", sngFloatToCopy);
	m_pstrSuperString = CloneString(buffer);
}



// --------------------------------------------------------------------------------
// Class: Double Constructor.
// Abstract: Default Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const double dblDoubleToCopy)
{
	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%lf", dblDoubleToCopy);
	m_pstrSuperString = CloneString(buffer);
}



// --------------------------------------------------------------------------------
// Class: Copy Constructor.
// Abstract: Copy's the Constructor.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const CSuperString& ssStringToCopy)
{
	m_pstrSuperString = CloneString(ssStringToCopy.m_pstrSuperString);
}



	// --------------------------------------------------------------------------------
	// Class: Initialize.
	// Abstract: Set Class pointers to zero and then call set methods.
	// --------------------------------------------------------------------------------
	void CSuperString::Initialize(const char* pstrSource)
	{
		m_pstrSuperString = 0;

		//Funnel all memory allocation through the assignment operator.
		*this = pstrSource;
	}

#pragma endregion

#pragma region "Length"

// --------------------------------------------------------------------------------
// Class: Length.
// Abstract: The Assignment Operator.
// --------------------------------------------------------------------------------
long CSuperString::Length() const
{
	long lngLength = 0;
	
	lngLength = (long) strlen(m_pstrSuperString);
	
	return lngLength;
}

#pragma endregion

//Done
#pragma region "Operator ="

// --------------------------------------------------------------------------------
// Class: const char* - Operator = .
// Abstract: Assignment Operator, assigning from a (const char*).
// --------------------------------------------------------------------------------
void CSuperString::operator = (const char* pstrStringToCopy)
{
	//Self Assignment?
	if (m_pstrSuperString != pstrStringToCopy)
	{
		//No, clean up and...
		CleanUp();

		//Deep Copy.
		DeepCopy(pstrStringToCopy);
	}
}



// --------------------------------------------------------------------------------
// Class: const char - Operator = .
// Abstract: Assignment Operator, assigning from a single character.
// --------------------------------------------------------------------------------
void CSuperString::operator = (const char chrLetterToCopy)
{
	// Temporary two character array.
	char buffer[2] = { chrLetterToCopy, '\0' };
	
	//Initialize buffer.
	Initialize(buffer);
}



// --------------------------------------------------------------------------------
// Class: CSuperString - Operator = .
// Abstract: Assignment Operator, assigning from another CSuperString object.
// --------------------------------------------------------------------------------
void CSuperString::operator = (const CSuperString& ssStringToCopy)
{
	
	// Check if this is not a self-assignment.
	if (this != &ssStringToCopy)
	{
		// Initialize (Deep Copy).
		Initialize(ssStringToCopy.m_pstrSuperString);
	}
}

#pragma endregion

//Done
#pragma region "FindFirstindexOf / FindLastIndexOf"

// --------------------------------------------------------------------------------
// Class: char - FindFirstIndexOf.
// Abstract: Finding the first index of a character.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind)
{
	// Find first occurrence of chrLetterToFind in the string.
	const char* intIndex = strchr(m_pstrSuperString, chrLetterToFind);
	
	// Return Index, otherwise return -1.
	return intIndex ? (long)(intIndex - m_pstrSuperString) : -1;
}



// --------------------------------------------------------------------------------
// Class: char, long - FindFirstIndexOf.
// Abstract: Finding the first index of a character from a starting index.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex)
{
	// Check if starting index is valid.
	if (lngStartIndex < 0 || lngStartIndex >= Length())
	{
		return -1;
	}

	// Look for the character from the specified index.
	const char* StartingIndex = m_pstrSuperString + lngStartIndex;
	
	// Find first occurrence starting from StartingIndex.
	const char* intIndex = strchr(StartingIndex, chrLetterToFind);
	
	// Return Index, otherwise return -1.
	return intIndex ? (long)(intIndex - m_pstrSuperString) : -1;
}



// --------------------------------------------------------------------------------
// Class: char - FindLastIndexOf.
// Abstract: Finding the last occurrence of a character.
// --------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char chrLetterToFind)
{
	// Find the last occurrence of chrLetterToFind in the string.
	const char* intIndex = strrchr(m_pstrSuperString, chrLetterToFind);
	
	// Return Index, otherwise return -1.
	return intIndex ? (long)(intIndex - m_pstrSuperString) : -1;
}



// --------------------------------------------------------------------------------
// Class: char - FindFirstIndexOf.
// Abstract: Finding the first occurrence of a substring.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind)
{
	// Check if Substring is Valid.
	if (pstrSubStringToFind == nullptr || strlen(pstrSubStringToFind) == 0)
	{
		return -1;
	}

	// Find the first occurrence of the substring.
	const char* intIndex = strstr(m_pstrSuperString, pstrSubStringToFind);
	
	// Return Index, otherwise return -1.
	return intIndex ? (long)(intIndex - m_pstrSuperString) : -1;
}



// --------------------------------------------------------------------------------
// Class: char, long - FindFirstIndexOf.
// Abstract: Finding the first occurrence of a substring starting at index.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex)
{
	// Check if substring is valid.
	if (pstrSubStringToFind == nullptr || strlen(pstrSubStringToFind) == 0)
	{
		return -1;
	}

	// Check if starting index is valid.
	if (lngStartIndex < 0 || lngStartIndex >= Length())
	{
		return -1;
	}

	// Look for the substring from specified index.
	const char* StartingIndex = m_pstrSuperString + lngStartIndex;
	
	// Find the first occurrence of substring from StartingIndex.
	const char* intIndex = strstr(StartingIndex, pstrSubStringToFind);
	
	// Return Index, otherwise return -1.
	return intIndex ? (long)(intIndex - m_pstrSuperString) : -1;
}



// --------------------------------------------------------------------------------
// Class: char - FindLastIndexOf.
// Abstract: Finding the last occurrence of a substring.
// --------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char* pstrSubStringToFind)
{
	// Check if substring is valid.
	if (pstrSubStringToFind == nullptr || strlen(pstrSubStringToFind) == 0)
	{
		return -1;
	}

	// Look for the substring from the beginning of the string.
	const char* LastKnownIndex = nullptr;
	const char* intIndex = strstr(m_pstrSuperString, pstrSubStringToFind);

	// Loop through the string & find last occurrence of substring.
	while (intIndex != nullptr)
	{
		// Update LastKnownIndex to recent occurrence.
		LastKnownIndex = intIndex;

		// Next occurrence of substring.
		intIndex = strstr(intIndex + 1, pstrSubStringToFind);
	}

	// Return Index, otherwise return -1.
	return LastKnownIndex ? (long)(LastKnownIndex - m_pstrSuperString) : -1;
}

#pragma endregion

// Done
#pragma region "ToUpperCase / ToLowerCase"

// --------------------------------------------------------------------------------
// Class: ToUpperCase.
// Abstract: Converts all characters of the string to uppercase.
// --------------------------------------------------------------------------------
const char* CSuperString::ToUpperCase()
{
	// Get length of original string.
	size_t intLength = strlen(m_pstrSuperString);
	
	// Dynamically allocate memory for new string.
	char* chrUpperCaseResult = new char[intLength + 1];

	// Loop through each character in the original string and convert it to uppercase.
	for (size_t intIndex = 0; intIndex < intLength; intIndex += 1)
	{
		chrUpperCaseResult[intIndex] = toupper(m_pstrSuperString[intIndex]);
	}

	// Null-terminate the new string.
	chrUpperCaseResult[intLength] = '\0';
	
	// Return New String
	return chrUpperCaseResult;
}



// --------------------------------------------------------------------------------
// Class: ToLowerCase.
// Abstract: Converts all characters of the string to lowercase.
// --------------------------------------------------------------------------------
const char* CSuperString::ToLowerCase()
{
	// Get length of original string.
	size_t intLength = strlen(m_pstrSuperString);
	
	// Dynamically allocate memory for new string.
	char* chrLowerCaseResult = new char[intLength + 1];

	// Loop through each character in the original string and convert it to lowercase.
	for (size_t intIndex = 0; intIndex < intLength; intIndex += 1)
	{
		chrLowerCaseResult[intIndex] = tolower(m_pstrSuperString[intIndex]);
	}

	// Null-terminate the new string.
	chrLowerCaseResult[intLength] = '\0';

	// Return New String
	return chrLowerCaseResult;
}

#pragma endregion

// Done
#pragma region "TrimLeft / TrimRight / Trim"

// --------------------------------------------------------------------------------
// Class: TrimLeft.
// Abstract: Removes leading (left) whitespace from the string.
// --------------------------------------------------------------------------------
const char* CSuperString::TrimLeft()
{
	// Initialize pointer to beginning of string.
	const char* LeftTrim = m_pstrSuperString;

	// Run through the string until the first non-whitespace character is found.
	while (*LeftTrim != '\0' && isspace(*LeftTrim)) LeftTrim += 1;

	// Return new string, CloneString handles memory allocation and copying.
	return CloneString(LeftTrim);
}



// --------------------------------------------------------------------------------
// Class: TrimRight.
// Abstract: Removes trailing (right) whitespace from the string.
// --------------------------------------------------------------------------------
const char* CSuperString::TrimRight()
{
	// Get length of string.
	size_t intLength = strlen(m_pstrSuperString);
	
	// If string is empty, return empty.
	if (intLength == 0)
	{
		return CloneString("");
	}

	// Set a pointer to the end of string.
	const char* chrEndString = m_pstrSuperString + intLength - 1;
	
	// Move pointer backwards until first non-whitespace character is found.
	while (chrEndString >= m_pstrSuperString && isspace(*chrEndString)) chrEndString -= 1;

	// Calculate new length of trimmed string.
	size_t intNewLength = chrEndString - m_pstrSuperString + 1;
	
	// Dynamically allocate memory for the trimmed string.
	char* RightTrim = new char[intNewLength + 1];
	
	// Copy string up to the new length.
	strncpy_s(RightTrim, intNewLength + 1, m_pstrSuperString, intNewLength);
	
	// Null-terminate the trimmed string.
	RightTrim[intNewLength] = '\0';
	
	// Return new string.
	return RightTrim;
}



// --------------------------------------------------------------------------------
// Class: Trim.
// Abstract: Removes both leading and trailing whitespace from the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Trim()
{
	// Trim left side.
	const char* LeftTrim = m_pstrSuperString;
	while (*LeftTrim != '\0' && isspace(*LeftTrim)) LeftTrim += 1;

	// Trim right side.
	const char* RightTrim = m_pstrSuperString + strlen(m_pstrSuperString) - 1;
	while (RightTrim >= LeftTrim && isspace(*RightTrim)) RightTrim -= 1;

	// Calculate new length of trimmed string.
	size_t intNewLength = RightTrim - LeftTrim + 1;
	
	// Dynamically allocate memory for the trimmed string.
	char* TrimResult = new char[intNewLength + 1];
	
	// Copy trimmed portion of the string using strncpy_s.
	strncpy_s(TrimResult, intNewLength + 1, LeftTrim, intNewLength);
	
	// Null-terminate the trimmed string.
	TrimResult[intNewLength] = '\0';
	
	// Return new string.
	return TrimResult;
}

#pragma endregion

// Done
#pragma region "Reverse / Left / Right / Substring / Replace"

// --------------------------------------------------------------------------------
// Class: Reverse.
// Abstract: Reverses the characters in the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Reverse()
{
	// Get length of string.
	size_t intLength = strlen(m_pstrSuperString);
	
	// Dynamically allocate memory for reversed string.
	char* ReverseResult = new char[intLength + 1];

	// Loop through the string in reverse order and copy characters to new array.
	for (size_t intIndex = 0; intIndex < intLength; intIndex += 1)
	{
		ReverseResult[intIndex] = m_pstrSuperString[intLength - intIndex - 1];
	}

	// Null-terminate reversed string.
	ReverseResult[intLength] = '\0';

	// Return new string.
	return ReverseResult;
}



// --------------------------------------------------------------------------------
// Class: Left.
// Abstract: Returns the leftmost `lngCharactersToCopy` characters from the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Left(long lngCharactersToCopy)
{
	// If the number of characters to copy is non-positive, return an empty string.
	if (lngCharactersToCopy <= 0)
	{
		return CloneString("");
	}

	// Get length of string.
	size_t intLength = strlen(m_pstrSuperString);
	
	// Determine the number of characters to copy.
	size_t intCopyLength = (size_t)min(lngCharactersToCopy, (long)intLength);

	// Dynamically allocate memory for the left portion of the string.
	char* LeftResult = new char[intCopyLength + 1];
	
	// Copy the left portion of the string to the new string.
	strncpy_s(LeftResult, intCopyLength + 1, m_pstrSuperString, intCopyLength);
	
	// Null-terminate the new string.
	LeftResult[intCopyLength] = '\0';

	// Return new string.
	return LeftResult;
}



// --------------------------------------------------------------------------------
// Class: Right.
// Abstract: Returns the rightmost `lngCharactersToCopy` characters from the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Right(long lngCharactersToCopy)
{
	// Get length of string.
	size_t intLength = strlen(m_pstrSuperString);
	
	// If number of characters to copy is non-positive or string is empty, return empty string.
	if (lngCharactersToCopy <= 0 || intLength == 0)
	{
		return CloneString("");
	}

	// Determine number of characters to copy.
	size_t intCopyLength = (size_t)min(lngCharactersToCopy, (long)intLength);
	
	// Calculate the starting position for the rightmost characters.
	const char* intStartingPosition = m_pstrSuperString + (intLength - intCopyLength);

	// Dynamically allocate memory for the right portion of the string.
	char* RightResult = new char[intCopyLength + 1];
	
	// Copy the right portion of the string to the new string.
	strcpy_s(RightResult, intCopyLength + 1, intStartingPosition);
	
	// Return new string.
	return RightResult;
}



// --------------------------------------------------------------------------------
// Class: Substring.
// Abstract: Returns a substring starting at `lngStart` and having `lngSubStringLength` characters.
// --------------------------------------------------------------------------------
const char* CSuperString::Substring(long lngStart, long lngSubStringLength)
{
	// Get length of string.
	size_t intLength = strlen(m_pstrSuperString);
	
	// Check input parameters, return an empty string if valid.
	if (lngStart < 0 || lngSubStringLength <= 0 || (size_t)lngStart >= intLength)
	{
		return CloneString("");
	}
	
	// Calculate the maximum possible length of the substring.
	size_t intMaxLength = intLength - (size_t)lngStart;
	
	// Determine the number of characters to copy based on the start and length.
	size_t intCopyLength = (size_t)min((long)intMaxLength, lngSubStringLength);

	// Dynamically allocate memory for the substring.
	char* SubstringResult = new char[intCopyLength + 1];
	
	// Copy the desired substring from the original string.
	strncpy_s(SubstringResult, intCopyLength + 1, m_pstrSuperString + lngStart, intCopyLength);
	
	// Null-terminate the new substring.
	SubstringResult[intCopyLength] = '\0';
	
	// Return new string.
	return SubstringResult;
}



// --------------------------------------------------------------------------------
// Class: Replace.
// Abstract: Replaces all occurrences of `chrLetterToFind` with `chrReplace` in the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(char chrLetterToFind, char chrReplace)
{
	// Get length of string.
	size_t lngLength = strlen(m_pstrSuperString);
	
	// Dynamically allocate memory for the new string with replaced characters.
	char* ReplaceResult = new char[lngLength + 1];

	// Loop through original string and replace characters as needed.
	for (size_t intIndex = 0; intIndex < lngLength; intIndex += 1)
	{
		ReplaceResult[intIndex] = (m_pstrSuperString[intIndex] == chrLetterToFind) ? chrReplace : m_pstrSuperString[intIndex];
	}
	
	// Null-terminate the new string.
	ReplaceResult[lngLength] = '\0';

	// Return new string.
	return ReplaceResult;
}

#pragma endregion

// Done
#pragma region "DeepCopy / CloneString"

// --------------------------------------------------------------------------------
// Class: DeepCopy.
// Abstract: Memory-Allocated Copy.
// --------------------------------------------------------------------------------
void CSuperString::DeepCopy(const char* pstrSource)
{
	m_pstrSuperString = CloneString(pstrSource);
}



// --------------------------------------------------------------------------------
// Class: CloneString.
// Abstract: Allocates memory and creates a duplicate (clone) of the given string.
// --------------------------------------------------------------------------------
char* CSuperString::CloneString(const char* pstrSource)
{
	char* pstrClone = 0;
	long lngLength = 0;

	// Check if the input source string is not null.
	if (pstrSource != 0)
	{
		// Source is not null: get the length of the source string.
		lngLength = strlen(pstrSource);
		pstrClone = new char[lngLength + 1];
		strcpy_s(pstrClone, lngLength + 1, pstrSource); //To avoid Compiler warnings.
	}
	else
	{
		// Source is null: allocate memory for an empty string.
		pstrClone = new char[1];
		*(pstrClone + 0) = 0;
	}

	// Return cloned string.
	return pstrClone;
}

#pragma endregion

// Done
#pragma region "Destructor / CleanUp / DeleteString"

// --------------------------------------------------------------------------------
// Class: Destructor.
// Abstract: Clear out...
// --------------------------------------------------------------------------------
CSuperString::~CSuperString()
{
	CleanUp();
}



// --------------------------------------------------------------------------------
// Class: CleanUp.
// Abstract: Clear out...x2
// --------------------------------------------------------------------------------
void CSuperString::CleanUp()
{
	DeleteString(m_pstrSuperString);
}



// --------------------------------------------------------------------------------
// Class: DeleteString.
// Abstract: Delete the string and assign the pointer to zero.
// --------------------------------------------------------------------------------
void CSuperString::DeleteString(char*& pstrSource)
{
	// Check if the pointer is not already null.
	if (pstrSource != 0)
	{
		delete pstrSource;	// Free memory.
		pstrSource = 0;		// Nullify the pointer.
	}
}

#pragma endregion

// Done
#pragma region "Operator +="

// --------------------------------------------------------------------------------
// Class: const char* - Operator +=.
// Abstract: Appends (const char*) to the current CSuperString object.
// --------------------------------------------------------------------------------
void CSuperString::operator+=(const char* pstrStringToAppend)
{
	// If the input string is null, do nothing.
	if (pstrStringToAppend == nullptr) return;

	// Get lengths of existing string to append.
	size_t originalLen = strlen(m_pstrSuperString);
	size_t appendLen = strlen(pstrStringToAppend);
	size_t newLen = originalLen + appendLen + 1; // +1 for null terminator.
	
	// Allocate a new buffer large enough to hold both strings.
	char* pNewStr = new char[newLen];

	// Copy the original string into the new buffer.
	strcpy_s(pNewStr, newLen, m_pstrSuperString);
	
	// Append the new string to the copied string.
	strcat_s(pNewStr, newLen, pstrStringToAppend);

	// Initialize the internal string with the new combined string.
	Initialize(pNewStr);
	
	// Clean up temporary buffer.
	delete[] pNewStr;
}



// --------------------------------------------------------------------------------
// Class: const char - Operator +=.
// Abstract: Appends a single character to the current CSuperString object.
// --------------------------------------------------------------------------------
void CSuperString::operator+=(const char chrCharacterToAppend)
{
	// Create temporary buffer of two characters.
	char buffer[2] = { chrCharacterToAppend, '\0' };
	*this += buffer;
}



// --------------------------------------------------------------------------------
// Class: CSuperString - Operator +=.
// Abstract: Appends another CSuperString to the current CSuperString object.
// --------------------------------------------------------------------------------
void CSuperString::operator+=(const CSuperString& ssStringToAppend)
{
	// Delegate const char* version of operator+= using internal string.
	*this += ssStringToAppend.m_pstrSuperString;
}

#pragma endregion

// Done
#pragma region "ToString, ToBoolean, ToShort, ToInteger, ToLong, ToFloat, ToDouble"

// --------------------------------------------------------------------------------
// Class: ToString.
// Abstract: Returns the internal C-style string.
// --------------------------------------------------------------------------------
const char* CSuperString::ToString()
{
	// Return internal string pointer.
	return m_pstrSuperString;
}

// --------------------------------------------------------------------------------
// Class: ToBoolean.
// Abstract: Converts internal string to a boolean value.
// --------------------------------------------------------------------------------
bool CSuperString::ToBoolean()
{
	// If string is null, false.
	if (m_pstrSuperString == nullptr)
	{
		return false;
	}

	// Compare if string is "true".
	if (_stricmp(m_pstrSuperString, "true") == 0)
	{
		return true;
	}

	// Compare if string is "false".
	if (_stricmp(m_pstrSuperString, "false") == 0)
	{
		return false;
	}

	// Attempt to parse it as a number.
	char* chrPointer = nullptr;
	long lngValue = strtol(m_pstrSuperString, &chrPointer, 10);

	// Parsing succeeded and number is non-zero, return true.
	return(chrPointer != m_pstrSuperString) && (lngValue != 0);
}

// --------------------------------------------------------------------------------
// Class: ToShort.
// Abstract: Converts the internal string to a short integer.
// --------------------------------------------------------------------------------
short CSuperString::ToShort()
{
	// If string is null, 0.
	if (m_pstrSuperString == nullptr)
	{
		return 0;
	}

	// Attempt to parse string as long integer.
	char* chrPointer = nullptr;
	long lngValue = strtol(m_pstrSuperString, &chrPointer, 10);

	// Return parsed long value to short.
	return (short)lngValue;
}

// --------------------------------------------------------------------------------
// Class: ToInteger.
// Abstract: Converts the internal string to an integer.
// --------------------------------------------------------------------------------
int CSuperString::ToInteger()
{
	// If string is null, 0.
	if (m_pstrSuperString == nullptr)
	{
		return 0;
	}

	// Attempt to parse string as long integer.
	char* chrPointer = nullptr;
	long lngValue = strtol(m_pstrSuperString, &chrPointer, 10);

	// Return parsed long value to int.
	return (int)lngValue;
}

// --------------------------------------------------------------------------------
// Class: ToLong.
// Abstract: Converts the internal string to a long integer.
// --------------------------------------------------------------------------------
long CSuperString::ToLong()
{
	// If string is null, 0.
	if (m_pstrSuperString == nullptr)
	{
		return 0;
	}

	// Parse string directly to long.
	char* chrPointer = nullptr;
	
	// Return long string.
	return strtol(m_pstrSuperString, &chrPointer, 10);
}

// --------------------------------------------------------------------------------
// Class: ToFloat.
// Abstract: Converts the internal string to a (float).
// --------------------------------------------------------------------------------
float CSuperString::ToFloat()
{
	// If string is null, 0.0f.
	if (m_pstrSuperString == nullptr)
	{
		return 0.0f;
	}

	// Parse string as double.
	char* chrPointer = nullptr;
	double lngValue = strtod(m_pstrSuperString, &chrPointer);

	// Return double to float.
	return (float)lngValue;
}

// --------------------------------------------------------------------------------
// Class: ToDouble.
// Abstract: Converts the internal string to (double).
// --------------------------------------------------------------------------------
double CSuperString::ToDouble()
{
	// If string is null, 0.0.
	if (m_pstrSuperString == nullptr)
	{
		return 0.0;
	}

	// Parse string as double.
	char* chrPointer = nullptr;
	
	// Return double string.
	return strtod(m_pstrSuperString, &chrPointer);
}

#pragma endregion

// Done
#pragma region "Operator +"

// --------------------------------------------------------------------------------
// Class: operator+.
// Abstract: Concatenates two CSuperString objects and returns the result.
// --------------------------------------------------------------------------------
CSuperString operator+(const CSuperString& ssLeft, const CSuperString& ssRight)
{
	// Create copy of left-hand operand.
	CSuperString result(ssLeft);
	
	// Append right-hand operand to 'Result'.
	result += ssRight;

	// Return 'Result'.
	return result;
}

// --------------------------------------------------------------------------------
// Class: operator+.
// Abstract: Concatenates a const char*, CSuperString.
// --------------------------------------------------------------------------------
CSuperString operator+(const char* pstrLeftSide, const CSuperString& ssRightString)
{
	// Create CSuperString, initialized with left-side.
	CSuperString result(pstrLeftSide);
	
	// Append right-hand CSuperString to 'Result'.
	result += ssRightString;

	// Return 'Result'.
	return result;
}

// --------------------------------------------------------------------------------
// Class: operator+.
// Abstract: Concatenates a CSuperString, const char*.
// --------------------------------------------------------------------------------
CSuperString operator+(const CSuperString& ssLeftString, const char* pstrRightSide)
{
	// Create copy of the left-hand.
	CSuperString result(ssLeftString);
	
	// Append right-hand C-string to 'Result'.
	result += pstrRightSide;

	// Return 'Result'.
	return result;
}

#pragma endregion

// Done
#pragma region "Replace / Insert(Single Letter) / Insert(Full-Word)"

// --------------------------------------------------------------------------------
// Class: Replace.
// Abstract: Replaces all occurrences of a substring with another substring.
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(const char* pstrFind, const char* pstrReplace) 
{
	// If the search string is null or empty, clone original string.
	if (pstrFind == nullptr || strlen(pstrFind) == 0)
	{
		return CloneString(m_pstrSuperString);
	}

	// If the replacement string is null, empty string.
	if (pstrReplace == nullptr)
	{
		pstrReplace = "";
	}
		
	size_t lngFindLength = strlen(pstrFind);
	size_t lngLengthReplace = strlen(pstrReplace);
	size_t finalSize = strlen(m_pstrSuperString) + 1; 

	// Step 1: Calculate the size needed for the final string after all replacements.
	const char* chrCurrentString = m_pstrSuperString;
	
	while ((chrCurrentString = strstr(chrCurrentString, pstrFind)) != nullptr)
	{
		finalSize = finalSize - lngFindLength + lngLengthReplace;
		chrCurrentString += lngFindLength;
	}

	// Step 2: Allocate memory for the new string.
	char* pNewString = new char[finalSize];

	// Step 3: Build new string by copying and replacing.
	const char* chrSourceString = m_pstrSuperString;
	char* chrDestination = pNewString;

	while (*chrSourceString)
	{
		const char* pMatch = strstr(chrSourceString, pstrFind);
		
		if (pMatch == chrSourceString)
		{
			// Match? - Copy the replacement string.
			strcpy_s(chrDestination, finalSize - (chrDestination - pNewString), pstrReplace);
			chrDestination += lngLengthReplace;
			chrSourceString += lngFindLength;
		}
		else
		{
			// No Match? Copy one character.
			*chrDestination = *chrSourceString;
			chrDestination += 1;
			chrSourceString += 1;
		}
	}

	// Step 4: Null-terminate the result.
	*chrDestination = '\0';

	// Return 'pNewString'
	return pNewString;
}

// --------------------------------------------------------------------------------
// Class: Insert.
// Abstract: Inserts a single character at a specified index.
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char chrLetterToInsert, long lngIndex)
{
	size_t intLength = strlen(m_pstrSuperString);
	
	// Set index within bounds.
	if (lngIndex < 0 || lngIndex >(long)intLength)
	{
		lngIndex = intLength;
	}
	
	// Allocate memory for original string, new character, null terminator.
	char* chrInsertResult = new char[intLength + 2]; // +1 for char +1 for null
	
	// Copy before insertion point.
	strncpy_s(chrInsertResult, intLength + 2, m_pstrSuperString, lngIndex);
	
	// Insert character.
	chrInsertResult[lngIndex] = chrLetterToInsert;
	
	// Copy original string after the inserted character.
	strcpy_s(chrInsertResult + lngIndex + 1, intLength + 2 - (lngIndex + 1), m_pstrSuperString + lngIndex);
	
	// Return 'chrInsertResult'.
	return chrInsertResult;
}

// --------------------------------------------------------------------------------
// Class: Insert.
// Abstract: Inserts a substring at a specified index.
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char* pstrSubString, long lngIndex)
{
	// If substring is null, clone original string.
	if (!pstrSubString)
	{
		return CloneString(m_pstrSuperString);
	}

	size_t lngInsertLength = strlen(pstrSubString);
	size_t lngOriginalLength = strlen(m_pstrSuperString);

	// Set index within bounds.
	if (lngIndex < 0 || lngIndex >(long)lngOriginalLength)
	{
		lngIndex = lngOriginalLength;
	}
	
	// Allocate memory for new combined string.
	char* chrInsertResult = new char[lngOriginalLength + lngInsertLength + 1];
	
	// Copy before insertion point.
	strncpy_s(chrInsertResult, lngOriginalLength + lngInsertLength + 1, m_pstrSuperString, lngIndex);
	
	// Copy substring to insert.
	strcpy_s(chrInsertResult + lngIndex, lngOriginalLength + lngInsertLength + 1 - lngIndex, pstrSubString);
	
	// Copy after insertion point.
	strcpy_s(chrInsertResult + lngIndex + lngInsertLength, lngOriginalLength + lngInsertLength + 1 - (lngIndex + lngInsertLength), m_pstrSuperString + lngIndex);
	
	// Return 'chrInsertResult'
	return chrInsertResult;
}

#pragma endregion

// Done
#pragma region "Subscript Operator Const/Non-Const"

// --------------------------------------------------------------------------------
// Class: Subscript operator | Non-const.
// Abstract: Provides non-const access to characters in the string by index.
// --------------------------------------------------------------------------------
char& CSuperString::operator[](long lngIndex) 
{
	//Checking the bounds of the character.
	if (lngIndex < 0 || lngIndex >= (long)strlen(m_pstrSuperString))
	{
		cout << "Error: Index out of Bounds." << endl;
		
		//Return first character if out of bounds.
		return m_pstrSuperString[0];
	}

	// Return reference to the specified index.
	return m_pstrSuperString[lngIndex];
}

// --------------------------------------------------------------------------------
// Class: Subscript operator | Const.
// Abstract: Provides const access to characters in the string by index.
// --------------------------------------------------------------------------------
const char& CSuperString::operator[](long lngIndex) const
{
	//Checking the bounds of the character.
	if (lngIndex < 0 || lngIndex >= (long)strlen(m_pstrSuperString))
	{
		cout << "Error: Index out of Bounds." << endl;
		
		//Return first character if out of bounds.
		return m_pstrSuperString[0];
	}

	// Return reference to the specified index (read-only).
	return m_pstrSuperString[lngIndex];
}

#pragma endregion

// Done
#pragma region "operator<< / operator>>"

// --------------------------------------------------------------------------------
// Class: operator<<.
// Abstract: Overloads the output stream operator to allow printing CSuperString objects.
// --------------------------------------------------------------------------------
ostream& operator<<(ostream& osOut, const CSuperString& ssOutput)
{
	// If internal string is not null?
	if (ssOutput.m_pstrSuperString != nullptr)
	{
		osOut << ssOutput.m_pstrSuperString;
	}

	// Return the Output Stream.
	return osOut;
}

// --------------------------------------------------------------------------------
// Class: operator>>.
// Abstract: Overloads the input stream operator to allow reading into CSuperString objects.
// --------------------------------------------------------------------------------
istream& operator>>(istream& isIn, CSuperString& ssInput)
{
	// Temporary Buffer to Hold Input.
	char buffer[4096] = { 0 };

	// Read Up to Whitespace.
	isIn >> buffer;

	// Set it Into The CSuperString.
	ssInput = buffer;

	// Return Input Stream.
	return isIn;
}

#pragma endregion

// Done
#pragma region " Operator == / != / < / > / <= / >="

// --------------------------------------------------------------------------------
// Class: operator==.
// Abstract: Overloads the == operator to compare two CSuperString objects.
// --------------------------------------------------------------------------------
bool CSuperString::operator==(const CSuperString& other) const
{
	// Return true if both strings are identical.
	return strcmp(m_pstrSuperString, other.m_pstrSuperString) == 0;
}

// --------------------------------------------------------------------------------
// Class: operator!=.
// Abstract: Overloads the != operator to compare two CSuperString objects.
// --------------------------------------------------------------------------------
bool CSuperString::operator!=(const CSuperString& other) const
{
	// Return opposite of equality operator.
	return !(*this == other);
}

// --------------------------------------------------------------------------------
// Class: operator<.
// Abstract: Overloads the < operator for comparing two CSuperString objects.
// --------------------------------------------------------------------------------
bool CSuperString::operator<(const CSuperString& other) const
{
	// Return true if string is lexicographically less than the other.
	return strcmp(m_pstrSuperString, other.m_pstrSuperString) < 0;
}

// --------------------------------------------------------------------------------
// Class: operator>.
// Abstract: Overloads the > operator for comparing two CSuperString objects.
// --------------------------------------------------------------------------------
bool CSuperString::operator>(const CSuperString& other) const
{
	// Return true if string is lexicographically greater than the other.
	return strcmp(m_pstrSuperString, other.m_pstrSuperString) > 0;
}

// --------------------------------------------------------------------------------
// Class: operator<=.
// Abstract: Overloads the <= operator for comparing two CSuperString objects.
// --------------------------------------------------------------------------------
bool CSuperString::operator<=(const CSuperString& other) const
{
	// Return true if string is less than or equal to the other.
	return strcmp(m_pstrSuperString, other.m_pstrSuperString) <= 0;
}

// --------------------------------------------------------------------------------
// Class: operator>=.
// Abstract: Overloads the >= operator for comparing two CSuperString objects.
// --------------------------------------------------------------------------------
bool CSuperString::operator>=(const CSuperString& other) const
{
	// Return true if string is greater than or equal to the other.
	return strcmp(m_pstrSuperString, other.m_pstrSuperString) >= 0;
}

#pragma endregion

#pragma region "Print"

// --------------------------------------------------------------------------------
// Class: Print.
// Abstract: The numbers Mayson, what do they mean?.
// --------------------------------------------------------------------------------
void CSuperString::Print(const char* pstrCaption) const
{
	//Caption
	cout << endl;
	cout << pstrCaption << endl;
	cout << "------------------------------" << endl;
	         
	
	//Length not 0?
	if (Length() > 0)
	{
		//Yes, print.
		cout << m_pstrSuperString << endl;
	}
	else
	{
		//No, Print Empty String.
		printf("~Empty String\n");
	}

	cout << endl;
}

#pragma endregion