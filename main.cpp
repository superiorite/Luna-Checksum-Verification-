#include <iostream>

using namespace std;

// Checking if a double number is greater than 10? 
int doubleDigitValue(int digit)
{
	int doubledDigit = digit * 2;
	int sum;
	if (doubledDigit >= 10) sum = 1 + doubledDigit % 10;
	else sum = doubledDigit;
	return sum;
}

int main()
{
	char digit;
	int oddLengthChecksum = 0;
	int evenLengthChecksum = 0;
	int position = 1;
	cout << "Enter a number: " << endl;
	digit = cin.get();  // Reading each digit separately
	while (digit != 10) 	  // We know we've reached the end of the number 
	{
		if (position % 2 == 0)
		{
			oddLengthChecksum += doubleDigitValue(digit - '0'); // We do not know which numbers to multiply by 2, 
			evenLengthChecksum += digit - '0';		// but we calculate two options: for an even 
		}							 // number of numbers and an odd 
		else 
		{
			oddLengthChecksum += digit - '0';
			evenLengthChecksum += doubleDigitValue(digit - '0');
		}
		digit = cin.get(); // Reading each digit separately 
		position++;
	}
	int checksum;
	if ((position - 1) % 2 == 0) checksum = evenLengthChecksum;
	else checksum = oddLengthChecksum;
	cout << "Checksum is " << checksum << ". \n";
	if (checksum % 10 == 0) cout << "Checksum is divisible by 10. Valid. \n";
	else cout << "Checksum is not divisible by 10. Invalid. \n";
}
