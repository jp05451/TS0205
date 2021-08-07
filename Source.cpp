#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct BigInt {
				string num;
};
int max(int a, int b) {
				if (a >= b)
								return a;
				else
								return b;
}
// If test file has character
bool NoChar(const BigInt& num) {
				for (int i = 0; i < num.num.size(); i++) {
								if (!(num.num[i] > 47 && num.num[i] <= 57))
												return false;
				}
				return true;
}
BigInt Add(const BigInt& num1, const BigInt& num2) {
				int carry = 0;
				BigInt sum;
				int numarray1[10000] = { 0 };
				int numarray2[10000] = { 0 };
				int sumarray[10000] = { 0 };
				for (int i = num1.num.size() - 1; i >= 0; i--)
								numarray1[num1.num.size() - 1 - i] = num1.num[i] - '0';
				for (int i = num2.num.size() - 1; i >= 0; i--)
								numarray2[num2.num.size() - 1 - i] = num2.num[i] - '0';
				for (int i = 0; i < max(num1.num.size(), num2.num.size()) || carry != 0; i++) {
								sumarray[i] = numarray1[i] + numarray2[i] + carry;
								carry = sumarray[i] / 10;
								sumarray[i] %= 10;
								sum.num = (char)(sumarray[i] + '0') + sum.num;
				}
				return sum;
}
int main() {
				int time = 0;
				BigInt number1[200];
				BigInt number2[200];
				BigInt result[200];
				while (cin >> time) {
								for (int i = 0; i < time; i++) {
												cin >> number1[i].num;
												cin >> number2[i].num;
								}
								for (int i = 0; i < time; i++) {
												if (NoChar(number1[i]) && NoChar(number2[i])) {
																result[i] = Add(number1[i], number2[i]);
																cout << result[i].num;
												}
												else
																cout << "Not a valid number, please try again.";
												//if (i != time - 1)
																cout << '\n';
								}
								for (int i = 0; i < time; i++) {
												number1[i].num = "\0";
												number2[i].num = "\0";
												result[i].num = "\0";
								}
				}
}