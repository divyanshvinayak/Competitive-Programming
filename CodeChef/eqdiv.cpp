#include <bits/stdc++.h>
using namespace std;

int k, t, n, x;

void solve()
{
	cin >> n;
	x = n & 3;
    n >>= 2;
	if (x == 1)
		cout << "1\n1";
	else if (x == 2)
		cout << "1\n01";
	else if (x == 3)
		cout << "0\n001";
	else
		cout << "0\n";
	while (n--)
		cout << "1001";
	cout << '\n';
}

void solve2()
{
	cin >> n;
	x = n & 7;
	n >>= 3;
	if (x == 1)
		cout << "1\n1";
	else if (x == 2)
		if (n)
			cout << "1\n0100100101", --n;
		else
			cout << "3\n01";
	else if (x == 3)
		if (n)
			cout << "0\n10111000101", --n;
		else
			cout << "4\n001";
	else if (x == 4)
		if (n)
			cout << "0\n000000001101", --n;
		else
			cout << "2\n0001";
	else if (x == 5)
		if (n)
			cout << "1\n0001000010011", --n;
		else
			cout << "3\n01001";
	else if (x == 6)
		cout << "1\n101001";
	else if (x == 7)
		cout << "0\n1101001";
	else
		cout << "0\n";
	while (n--)
		cout << "01101001";
	cout << '\n';
}

void solve3()
{
	cin >> n;
	x = n & 15;
	n >>= 4;
	if (x == 1)
		cout << "1\n1";
	else if (x == 2)
		if (n)
			cout << "1\n010011010101011010", --n;
		else
			cout << "7\n01";
	else if (x == 3)
		if (n)
			cout << "0\n0011001001011000011", --n;
		else
			cout << "18\n001";
	else if (x == 4)
		if (n)
			cout << "0\n10100000001000000111", --n;
		else
			cout << "28\n0001";
	else if (x == 5)
		if (n)
			cout << "1\n011000000001010010011", --n;
		else
			cout << "25\n00001";
	else if (x == 6)
		if (n)
			cout << "1\n0000000000000001000111", --n;
		else
			cout << "7\n011110";
	else if (x == 7)
		if (n)
			cout << "0\n10001000000000101010011", --n;
		else
			cout << "26\n1110001";
	else if (x == 8)
		if (n)
			cout << "0\n010000000010000101001101", --n;
		else
			cout << "4\n11001001";
	else if (x == 9)
		if (n)
			cout << "1\n0000000001001000000100111", --n;
		else
			cout << "5\n100101001";
	else if (x == 10)
		cout << "1\n1000000101";
	else if (x == 11)
		if (n)
			cout << "0\n001000000000000001001111001", --n;
		else
			cout << "12\n00001101001";
	else if (x == 12)
		cout << "0\n110100011001";
	else if (x == 13)
		cout << "1\n0000010000011";
	else if (x == 14)
		cout << "1\n10100110010110";
	else if (x == 15)
		cout << "0\n110000101000011";
	else
		cout << "0\n";
	while (n--)
		cout << "0110100110010110";
	cout << '\n';
}

void solve4()
{
	cin >> n;
	x = n & 31;
	n >>= 5;
	if (x == 1)
		cout << "1\n1";
	else if (x == 2)
		if (n)
			cout << "1\n0100000100000000010101000000010111", --n;
		else
			cout << "15\n01";
	else if (x == 3)
		if (n)
			cout << "0\n10000100101000101000000000100010111", --n;
		else
			cout << "64\n001";
	else if (x == 4)
		if (n)
			cout << "0\n001010000011001000000000100010101011", --n;
		else
			cout << "158\n0001";
	else if (x == 5)
		if (n)
			cout << "1\n0000000101000100000001000000000111011", --n;
		else
			cout << "271\n00001";
	else if (x == 6)
		if (n)
			cout << "1\n10100010000000000010101000001000001111", --n;
		else
			cout << "317\n000001";
	else if (x == 7)
		if (n)
			cout << "0\n101000001000000000100000101010101100011", --n;
		else
			cout << "126\n0000001";
	else if (x == 8)
		if (n)
			cout << "0\n0000000010100001101000000000101010101110", --n;
		else
			cout << "34\n11010001";
	else if (x == 9)
		if (n)
			cout << "1\n10100010100000100000001000000000100111101", --n;
		else
			cout << "253\n111110001";
	else if (x == 10)
		if (n)
			cout << "1\n000000000000000000010010000000000110010111", --n;
		else
			cout << "13\n0101001001";
	else if (x == 11)
		if (n)
			cout << "0\n1111111111100010000001000000110001100101101", --n;
		else
			cout << "92\n00000101001";
	else if (x == 12)
		if (n)
			cout << "0\n11111111111101000011000000000000001110101101", --n;
		else
			cout << "30\n110010101001";
	else if (x == 13)
		if (n)
			cout << "1\n001000000000000000000000010001000000011100111", --n;
		else
			cout << "47\n0010110101001";
	else if (x == 14)
		if (n)
			cout << "1\n1111111111111101000000000000010010001001011011", --n;
		else
			cout << "31\n00000001111010";
	else if (x == 15)
		if (n)
			cout << "0\n11111111111111000000000010100001000001000110111", --n;
		else
			cout << "2\n100001110101001";
	else if (x == 16)
		cout << "0\n0000111000001110";
	else if (x == 17)
		cout << "1\n00000010110010110";
	else if (x == 18)
		if (n)
			cout << "1\n00000000000000000000000000000000010010101100011011", --n;
		else
			cout << "13\n000000110100001110";
	else if (x == 19)
		cout << "0\n1110011000000110110";
	else if (x == 20)
		cout << "0\n00110000001011011010";
	else if (x == 21)
		if (n)
			cout << "1\n00000000000010000000000001000000001000000001100011111", --n;
		else
			cout << "9\n000000000100100100011";
	else if (x == 22)
		cout << "1\n1010000011000000001011";
	else if (x == 23)
		cout << "0\n10111000000000100110110";
	else if (x == 24)
		cout << "0\n001010000000001100111010";
	else if (x == 25)
		cout << "1\n1010001010000001000000111";
	else if (x == 26)
		if (n)
			cout << "1\n0000000000000000000000001000000001000000000000101010011111", --n;
		else
			cout << "5\n00010100000100010000110101";
	else if (x == 27)
		cout << "0\n100010000100100010001001101";
	else if (x == 28)
		cout << "0\n0010001010100000000011100011";
	else if (x == 29)
		if (n)
			cout << "1\n1000000000000000000000000000000000000010000000100101100110111", --n;
		else
			cout << "5\n00010000000100110001000101110";
	else if (x == 30)
		cout << "1\n110000101000000001001010001011";
	else if (x == 31)
		cout << "0\n0000100000001010100000101010011";
	else
		cout << "0\n";
	while (n--)
		cout << "10010110011010010110100110010110";
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> t;
	if (k == 1)
		while (t--)
			solve();
	else if (k == 2)
		while (t--)
			solve2();
	else if (k == 3)
		while (t--)
			solve3();
	else
		while (t--)
			solve4();
    return 0;
}