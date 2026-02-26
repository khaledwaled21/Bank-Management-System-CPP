#pragma once
#include<iostream>
#include <vector>
using namespace std;
class clsString
{
private:
	string _Value;
public:
	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value) {
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string	Value;
	
	static short Length(string Si)
	{
		return Si.length();
	}

	short Length()
	{
		return Length(_Value);
	}

	static short CountWords(string S1)
	{
		string delim = " ";  
		short Counter = 0;
		short pos = 0;
		string sWord;  
		 
		 
			while ((pos = S1.find(delim)) != std::string::npos)
			{
				sWord = S1.substr(0, pos);  
				if (sWord != "")
				{
					Counter++;
				}
			 
				S1.erase(0, pos + delim.length());
			}
		if (S1 != "")
		{
			Counter++; 
		}
		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		cout << "\nFirst letters of this string: \n";
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				cout << S1[i] << endl;
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	string UpperFirstLetterOfEachWord()
	{
		return UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	string LowerFirstLetterOfEachWord()
	{
		return LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	string UpperAllString()
	{
		return UpperAllString(_Value);
	}

	string LowerAllString()
	{
		return LowerAllString(_Value);
	}

	static char InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string InvertAllStringLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	string InvertAllStringLettersCase()
	{
		return InvertAllStringLettersCase(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				
				Counter++;
			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				
				Counter++;
		}
		return Counter;
	}

	short CountLetters()
	{
		return CountLetters(_Value);
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountLetterInString(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}

	short CountLetterInString(short Letter , bool MatchCase = true)
	{
		return CountLetterInString(_Value, Letter , MatchCase = true);
	}

	static bool IsVowelLetter(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
			
	}

	static short CountVowelLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowelLetter(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountVowelLetters()
	{
		return CountVowelLetters(_Value);
	}

    static void PrintVowelLetters(string S1)
	{
		cout << "\nVowels in string are: ";
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowelLetter(S1[i]))
				cout << S1[i] << " ";
		}
	}

	void PrintVowelLetters()
	{
		PrintVowelLetters(_Value);
	}

	static void PrintEachWordInString(string S1)
	{
		string delim = " "; 
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord; 
		 
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); 
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length()); 
		}
		if (S1 != "")
		{
			cout << S1 << endl; 
		}
	}
	 
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static vector<string> Split(string S1, string Delim)
	{
		vector<string> vString;
		short pos = 0;
		string sWord; 
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);  
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length());  
		}
		if (S1 != "")
		{
			vString.push_back(S1);  
		}
		return vString;
	}

	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}
	
	string TrimLeft()
	{
		return TrimLeft(_Value);
	}

    static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	string TrimRight()
	{
		return TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}

	string Trim()
	{
		return Trim(_Value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{
		string S1 = "";
		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";
		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWordsInString(string S1)
	{
		vector<string> vString;
		string S2 = "";
		vString = Split(S1, " ");
 		vector<string>::iterator iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1);  
		return S2;
	}

	string ReverseWordsInString()
	{
		return ReverseWordsInString(_Value);
	}

	static string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
			
			pos = S1.find(StringToReplace); 
		}
		return S1;
	}

	string ReplaceWordInString(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWordInString(_Value, StringToReplace, sRepalceTo);
	}

	static string RemovePunctuationsFromString(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}
		return S2;
	}

	string RemovePunctuationsFromString()
	{
		return RemovePunctuationsFromString(_Value);
	}


};
 