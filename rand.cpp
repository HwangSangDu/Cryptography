#include <iostream>
#include <cstdio>
#include <list>
using namespace std;
int main()
{
	// list<int> v;
	int i = 1;
	int num = 2;
	int pq = 63;
	// v.push_back(num);

	// 반복횟수
	do{
		num = num % pq;
		cout << i  << ": "<< num << endl;
		num *= num;
	}while(num != 2 && i++ != pq);
	cout << endl;


	// 원시근
	int temp = 2;
	num = 2;
	for(i = 1 ; i <= pq/2 ; i++)
	{	
		cout << i << ": " << temp % pq << endl;
		if((temp % pq) == 1)
			break;
		temp *= num;
	}
	
	// 2로 계속 나누기!
	while((i % 2) == 0){
		i /= 2;
	}

	return 0;
}