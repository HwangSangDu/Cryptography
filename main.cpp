#include <iostream>
using namespace std;
int gcd (int n1, int n2);
int main(int argc, char const *argv[])
{
	int num1, num2;

	cout << "정수 2개 입력 : ";
	cin >> num1 >> num2;
	cout << gcd(num1, num2) << endl;
	return 0;
}


//  유클리드 호제법
int gcd (int n1, int n2){
	int temp;
	if(!n2)
		return n1;
	if (n1 < n2)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	return gcd(n2, n1 % n2);
}