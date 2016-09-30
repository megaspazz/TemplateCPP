/*
 * Example program to compute the sum of two input numbers. The sum of the
 * two numbers must be within the range of signed 32-bit integers.
 */

#include<iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int A, B;
	cin >> A;
	cin >> B;
	cout << A + B << endl;

	return 0;
}
