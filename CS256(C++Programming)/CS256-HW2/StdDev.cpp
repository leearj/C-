// Jaeseung Lee
// Homework 2
// Completed 1/24/2016

#include <iostream>
using namespace std;
double sum(double values[], int size);
double mean(double values[], int size);
double stdDev(double values[], int size);

int main() {
	double arr[10];
	for (int i = 0; i < 10; i++) {
		cout << "Please assign the value for the array [" << i << "]" << ": " << endl;
		cin >> arr[i];
	}
	sum(arr, 10);
	mean(arr, 10);
	stdDev(arr, 10);
	cout << "The stdDev of array: " << stdDev(arr, 10) << endl;
	cin.get();
	cin.get();
}
double sum(double values[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) 
		sum += values[i];
	return sum;
};
double mean(double values[], int size) {
	return sum(values,size) / size;
};
double stdDev(double values[], int size) {
	int m = mean(values, size);
	for (int i = 0; i < size; i++) values[i] = (values[i] - m)*(values[i] - m);
	return sqrt(sum(values, size));	
};