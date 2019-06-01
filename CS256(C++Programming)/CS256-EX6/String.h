// Andrew Trang
// Exercise 6
// Completed 2/18/2016

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>

class StringTester;

class String
{
	friend class StringTester;

private:
	char* data;
	int size;
public:
	String();
	String(char input);
	String(const char* input);
	String(const String& input);
	~String();
	String& operator=(const String& input);
	int length();
	char charAt(int input);
	int indexOf(char input);
	char& operator[](const int input) const;
	String operator+(const String& input) const;
	String operator+(char input) const;
	bool operator==(const String& input) const;
	bool operator<(const String& input) const;
	bool operator<=(const String& input) const;
	bool operator>(const String& input) const;
	bool operator>=(const String& input) const;
	bool operator!=(const String& input) const;
	String substring(int start, int end) const;
	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
};
#endif