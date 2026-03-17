#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
	string _string;

public:
	clsString() {
		_string = "";
	}
	clsString(string value) {
		_string = value;
	}
	void SetString(string s) {
		_string = s;
	}
	string GetString() {
		return _string;
	}
	static size_t Length(const string& str) {
		size_t count = 0;
		for (char _ : str) {
			count++;
		}
		return count;
	}
	size_t Length() {
		return Length(_string);
	}
	static bool Contains(string base, const string& str) {
		if (Length(str) > Length(base)) {
			return false;
		}
		if (str.empty()) {
			return true;
		}
		size_t pos = base.find(str[0]);
		size_t count = 0;
		while (pos != string::npos) {
			base = base.substr(pos);
			for (size_t i = 0; i < Length(str); i++) {
				if (base[i] != str[i]) {
					break;
				}
				if (i == Length(str) - 1) {
					if (base[i] == str[i]) {
						return true;
					}
				}

			}
			base = base.substr(1);
			pos = base.find(str[0]);
		}
		return false;
	}
	bool Contains(const string& str) {
		return Contains(_string, str);
	}
	static bool StartsWith(string base, const string& str) {
		if (Length(str) > Length(base)) {
			return false;
		}
		for (size_t i = 0; i < Length(str); i++) {
			if (base[i] != str[i]) {
				return false;
			}
		}
		return true;
	}
	bool StartsWith(const string& str) {
		return StartsWith(_string, str);
	}
	static bool EndsWith(string base, const string& str) {
		if (Length(str) > Length(base)) {
			return false;
		}
		size_t difference = Length(base) - Length(str);
		for (int i = Length(str) - 1; i >= 0; i--) {
			if (base[difference + i] != str[i]) {
				return false;
			}
		}
		return true;
	}
	bool EndsWith(const string& str) {
		return EndsWith(_string, str);
	}
	static bool IsPalindrome(const string& str) {
		for (size_t i = 0; i < Length(str) / 2; i++) {
			if (str[i] != str[Length(str) - 1 - i]) {
				return false;
			}
		}
		return true;
	}
	bool IsPalindrome() {
		return IsPalindrome(_string);
	}
	static bool IsNumeric(const string& str) {
		if (str == "") {
			return false;
		}
		if (str.empty() || str == "-" || str == ".") {
			return false;
		}
		size_t countdots = 0;
		for (size_t i = 0; i < Length(str); i++) {
			if (countdots >= 2) {
				return false;
			}
			if (!isdigit(str[i])) {
				if (i == 0 && str[i] == '-') {
					continue;
				}
				if (str[i] == '.') {
					countdots++;
					continue;
				}
				return false;
			}
		}
		return true;
	}
	bool IsNumeric() {
		return IsNumeric(_string);
	}
	static bool IsEmpty(const string& str) {
		if (str == "") {
			return true;
		}
		for (size_t i = 0; i < Length(str); i++) {
			if (str[i] != ' ') {
				return false;
			}
		}
		return true;
	}
	bool IsEmpty() {
		return IsEmpty(_string);
	}
	static string Reverse(const string& str) {
		string result;
		if (str == "") {
			return "";
		}
		for (int i = Length(str) - 1; i >= 0; i--) {
			result += str[i];
		}
		return result;
	}
	string Reverse() {
		return Reverse(_string);
	}
	static string Repeat(const string& str, size_t num) {
		string result;
		for (size_t i = 1; i <= num; i++) {
			result += str;
		}
		return result;
	}
	string Repeat(size_t num) {
		return Repeat(_string, num);
	}
	static string PadLeft(const string& str, size_t totalWidth, char padChar) {
		string result = str;
		if (Length(str) < totalWidth) {
			result.insert(0, totalWidth - Length(str), padChar);
		}
		return result;
	}
	string PadLeft(size_t totalWidth, char padChar) {
		return PadLeft(_string, totalWidth, padChar);
	}
	static string PadRight(const string& str, size_t totalWidth, char padChar) {
		string result = str;
		if (Length(str) < totalWidth) {
			result.insert(Length(result), totalWidth - Length(str), padChar);
		}
		return result;
	}
	string PadRight(size_t totalWidth, char padChar) {
		return PadRight(_string, totalWidth, padChar);
	}
	static string RemoveSpaces(const string& str) {
		string result = str;
		size_t pos = result.find(" ");
		while (pos != string::npos) {
			result.erase(pos, 1);
			pos = result.find(" ");
		}
		return result;
	}
	string RemoveSpaces() {
		return RemoveSpaces(_string);
	}
	static string RemoveDuplicates(const string& str) {
		string result;
		for (size_t i = 0; i < Length(str); i++) {
			if (result.find(str[i]) == string::npos) {
				result += str[i];
			}
		}
		return result;
	}
	string RemoveDuplicates() {
		return RemoveDuplicates(_string);
	}
	static string Replace(const string& str, char oldChar, char newChar) {
		string result;
		for (size_t i = 0; i < Length(str); i++) {
			if (str[i] == oldChar) {
				result += newChar;
			}
			else {
				result += str[i];
			}
		}
		return result;
	}
	string Replace(char oldChar, char newChar) {
		return Replace(_string, oldChar, newChar);
	}
	static string SubString(const string& str, size_t start, size_t length) {
		string result;
		for (size_t i = 0; i < Length(str); i++) {
			if (i >= start && i < start + length) {
				result += str[i];
			}
		}
		return result;
	}
	string SubString(size_t start, size_t length) {
		return SubString(_string, start, length);
	}
	static size_t IndexOf(const string& str, string SubStr) {
		if (!Contains(str, SubStr)) {
			return -1;
		}
		for (size_t i = 0; i < Length(str); i++) {
			if (str[i] == SubStr[0]) {
				for (size_t x = 0; x < Length(SubStr); x++) {
					if (str[x + i] != SubStr[x]) {
						break;
					}
					if (x == Length(SubStr) - 1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	size_t IndexOf(string SubStr) {
		return IndexOf(_string, SubStr);
	}
	static string Left(const string& str, size_t num) {
		if (num > Length(str)) {
			return str;
		}
		string result;
		for (size_t i = 0; i < num; i++) {
			result += str[i];
		}
		return result;
	}
	string Left(size_t num) {
		return Left(_string, num);
	}
	static string Right(const string& str, size_t num) {
		if (num > Length(str)) {
			return str;
		}
		size_t index = Length(str);
		string result;
		for (size_t i = 0; i < num; i++) {
			result += str[index - num + i];
		}
		return result;
	}
	string Right(size_t num) {
		return Right(_string, num);
	}
	static long long ToInt(const string& str) {
		bool isnegative = false;
		if (!IsNumeric(str)) {
			return 0;
		}
		long long result = 0;
		for (size_t i = 0; i < Length(str); i++) {
			if (str[i] == '-') {
				isnegative = true;
				continue;
			}
			if (str[i] == '.') {
				break;
			}
			result = (result * 10) + (str[i] - '0');
		}
		if (isnegative) {
			result *= -1;
		}
		return result;
	}
	long long ToInt() {
		return ToInt(_string);
	}
	static double ToDouble(const string& str) {
		double beforedot = 0;
		double afterdot = 0;
		bool isnegative = false;
		double iteration = 10;
		if (!IsNumeric(str)) {
			return 0;
		}
		for (size_t i = 0; i < Length(str); i++) {
			if (str[i] == '-') {
				isnegative = true;
				continue;
			}
			if (str[i] == '.') {
				break;
			}
			beforedot = (beforedot * 10) + (str[i] - '0');
		}
		if (str.find('.') != string::npos) {
			string strafterdot = str.substr(str.find('.') + 1);
			for (size_t i = 0; i < Length(strafterdot); i++) {
				afterdot += (strafterdot[i] - '0') / iteration;
				iteration = iteration * 10;
			}
		}
		if (isnegative) {
			beforedot *= -1;
		}
		return beforedot + afterdot;
	}
	double ToDouble() {
		return ToDouble(_string);
	}
	static string ToString(long long num) {
		string result;
		bool isnegative = false;
		if (num == 0) {
			return "0";
		}
		if (num < 0) {
			num *= -1;
			isnegative = true;
		}
		while (num > 0) {
			result.insert(0, 1, num % 10 + '0');
			num /= 10;
		}
		if (isnegative) {
			result.insert(0, 1, '-');
		}
		return result;
	}
	static size_t  CountSpecificLetter(const string& str, char ch , bool Matchcase = true) {
		size_t  count = 0;		 
		for (char c : str) {
			if (!Matchcase) {
				if (tolower(c) == ch) {
					count++;
				}
			}
			else {
				if (c == ch) {
					count++;
				}
			}
		}
		return count;
	}
	size_t  CountSpecificLetter(char ch, bool Matchcase = true) {
		return CountSpecificLetter(_string, ch , Matchcase);
	}
	static size_t CountSmallLetters(const string& str) {
		size_t count = 0;
		for (char c : str) {
			if (c >= 'a' && c <= 'z') {
				count++;
			}
		}
		return count;
	}
	size_t CountSmallLetters() {
		return CountSmallLetters(_string);
	}
	static size_t CountCapitalLetters(const string& str) {
		size_t count = 0;
		for (char c : str) {
			if (c >= 'A' && c <= 'Z') {
				count++;
			}
		}
		return count;
	}
	size_t CountCapitalLetters() {
		return CountCapitalLetters(_string);
	}
	static size_t CountLetters(const string& str) {
		size_t count = 0;
		for (char c : str) {
			if (isalpha(c)) {
				count++;
			}
		}
		return count;
	}
	size_t CountLetters() {
		return CountLetters(_string);
	}
	static bool IsVowel(const char ch, const string& vowels = "aeuoiAEUIO") {
		return vowels.find(ch) != string::npos;
	}
	static size_t CountVowels(const string& str, const string& vowels = "aeuoiAEUIO") {
		size_t count = 0;
		for (char c : str) {
			if (vowels.find(c) != string::npos) {
				count++;
			}
		}
		return count;
	}
	size_t CountVowels() {
		return CountVowels(_string);
	}
	static char InvertLetterCase(const char ch) {
		if (isupper(ch)) {
			return tolower(ch);
		}
		return toupper(ch);
	}
	static string InvertAllLettersCase(const string& str) {
		string result;
		for (char ch : str) {
			result += InvertLetterCase(ch);
		}
		return result;
	}
	string InvertAllLettersCase() {
		return InvertAllLettersCase(_string);
	}
	static string UpperAllString(const string& str) {
		string result = str;
		for (char& c : result) c = toupper(c);
		return result;
	}
	string UpperAllString() {
		return UpperAllString(_string);
	}
	static string LowerAllString(const string& str) {
		string result = str;
		for (char& c : result) c = tolower(c);
		return result;
	}
	string LowerAllString() {
		return LowerAllString(_string);
	}
	static string UpperFirstLetterOfEachWord(const string& str) {
		string result = str;
		bool isFirst = true;
		for (char& c : result) {
			if (c != ' ' && isFirst) {
				c = toupper(c);
			}
			isFirst = (c == ' ');
		}
		return result;
	}
	string UpperFirstLetterOfEachWord() {
		return UpperFirstLetterOfEachWord(_string);
	}
	static string LowerFirstLetterOfEachWord(const string& str) {
		string result = str;
		bool isFirst = true;
		for (char& c : result) {
			if (c != ' ' && isFirst ) {
				c = tolower(c);
			}
			isFirst = (c == ' ');
		}
		return result;	
	}
	string LowerFirstLetterOfEachWord() {
		return LowerFirstLetterOfEachWord(_string);
	}
	static string RemovePunctuations(const string& str) {
		string result;
		for (char ch : str) {
			if (!ispunct(ch)) {
				result += ch;
			}
		}
		return result;
	}
	static size_t CountWords(const string& s) {
		return Split(s).size();
	}
	size_t CountWords() {
		return CountWords(_string);
	}
	string RemovePunctuations() {
		return RemovePunctuations(_string);
	}
	static string TrimLeft (const string& str) {
		string temp = str;
		size_t pos = str.find_first_not_of(' ');
		if ( pos == string::npos) {
			return "";
		}
		return temp.substr(pos);
	}
	string TrimLeft() {
		return TrimLeft(_string);
	}
	static string TrimRight(const string& str) {
		string temp = str;
		return Reverse(TrimLeft(Reverse(temp)));
	}
	string TrimRight() {
		return TrimRight(_string);
	}
	static string Trim(const string& str) {
		string temp = str;
		return TrimRight(TrimLeft(str));
	}	
	string Trim() {
		return Trim(_string);
	}
	static vector <string> Split(const string& str, const string& delimter = " ") {
		vector <string> vWords;
		string temp = str;
		size_t pos = temp.find(delimter);
		if (pos == string::npos) {
			vWords.push_back(temp);
			return vWords;
		}
		while(pos != string::npos) {
			vWords.push_back(temp.substr(0 , pos));
			temp = temp.substr(pos + Length(delimter));
			pos = temp.find(delimter);
		}
		if (!temp.empty()) {
			vWords.push_back(temp);
		}
		return vWords;
	}
	static string ReplaceWord(const string& str, const string& oldword, const string& newword, const string& delimter = " ") {
		vector <string> vWords = Split(str , delimter);
		string result;
		for (size_t i = 0; i < vWords.size(); i++) {
			if (vWords.at(i) == oldword) {
				result += newword;
			}
			else {
				result += vWords.at(i);
			}
			if (i != vWords.size() - 1) {
				result += delimter;
			}
		}
		return result;
	} 
	string ReplaceWord(const string& oldword, const string& newword) {
		return ReplaceWord(_string, oldword, newword);
	}
	static string ReverseWordsInString(const string& str , const string& delimter = " ") {
		vector <string> vWords = Split(str, delimter);
		string result;
		for (int i = vWords.size() - 1; i >= 0 ; i--) {
			result += vWords.at(i);
			if (i != 0) {
				result += delimter;
			}
		}
		return result;
	}
	string ReverseWordsInString() {
		return ReverseWordsInString(_string);
	}
	static string JoinString(const string str[], size_t size , const string& separator = " ") {
		string result;
		for (size_t i = 0; i < size; i++) {
			result += str[i];
			if (i != size - 1) {
				result += separator;
			}
		}
		return result;
	}
	static string JoinString(const vector<string>& vWords, const string& separator = " ") {
		string result;
		for (size_t i = 0; i < vWords.size(); i++) {
			result += vWords[i];
			if (i != vWords.size() - 1) result += separator;
		}
		return result;
	}
	__declspec(property(get = GetString, put = SetString)) string String;
};

