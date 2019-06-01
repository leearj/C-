// Andrew Trang
// Exercise 6
// Completed 2/18/2016

#include "String.h"

String::String():data(new char[10]), size(0){}
String::String(char input) : data(new char[10]), size(1){
	data[0] = input;
}
String::String(const char* input):data(new char[strlen(input)]), size(strlen(input)){
	for (int i = 0; i < strlen(input); ++i)
		data[i] = input[i];
}
String::String(const String& other):data(new char[other.size]), size(other.size){
	for (int i = 0; i < size; ++i)
		data[i] = other.data[i];
}
String::~String(){
	delete[] data;
}
String& String::operator=(const String& input){
	if (this == &input)
		return *this; 
	size = input.size;
	delete[] data;
	data = new char[size];
	for(int i = 0; i < size; ++i)
		data[i] = input.data[i];
	return *this;
}
int String::length(){
	return size;
}
char String::charAt(int input){
	return data[input];
}
int String::indexOf(char input){
	for (int i = 0; i < size; ++i)
		if (data[i] == input)
			return i;
	return -1;
}
char& String::operator[](const int input) const{
	return data[input];
}
String String::operator+(const String& input) const{
	int index = 0;
	String temp;
	delete[] temp.data;
	temp.data = new char[size + input.size];
	temp.size = size + input.size;
	for (int i = 0; i < size; ++i, ++index)
		temp.data[index] = data[i];
	for (int i = 0; i < input.size; ++i, ++index)
		temp.data[index] = input.data[i];
	return temp;
}
String String::operator+(char input) const{
	return *this + String(input);
}
bool String::operator==(const String& input) const{
	if (size != input.size)
		return 0;
	for (int i = 0; i < size; ++i)
		if (data[i] != input.data[i])
			return 0;
	return 1;
}
bool String::operator<(const String& input) const{
	for (int i = 0; i < (size < input.size ? size : input.size); ++i)
		if (data[i] < input.data[i])
			return 1;
	return 0;
}
bool String::operator<=(const String& input) const{
	if (*this == input || *this < input)
		return 1;
	return 0;
}
bool String::operator>(const String& input) const{
	if (*this <= input)
		return 0;
	return 1;
}
bool String::operator>=(const String& input) const{
	if (*this < input)
		return 0;
	return 1;
}
bool String::operator!=(const String& input) const{
	if (*this == input)
		return 0;
	return 1;
}
String String::substring(int start, int end) const{	if (start < 0 || start >= size || end <= start){		std::cout << String().size;		return String();	}	else{		int index = 0;		String temp;		delete[] temp.data;		temp.data = new char[end-start];		while (start < end && start < size){			temp.data[index++] = data[start++];			++temp.size;		}		return temp;	}}std::ostream& operator<<(std::ostream& os, const String& s){
	for (int i = 0; i < s.size; ++i)
		os << s.data[i];
	return os;
}
std::istream& operator>>(std::istream& is, String& s){
	std::string temp;
	is >> temp;
	delete[] s.data;
	s.data = new char[temp.length()];
	s.size = temp.length();
	for (int i = 0; i < temp.length(); ++i)
		s.data[i] = temp[i];
	return is;}