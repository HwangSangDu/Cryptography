#include<iostream>
#include <cstring>
using namespace std;




#define N 5

char keySpace[N][N] = {
	'K','A','N','G','M',
	'U','I','U','E','R',
	'S','T','Y','B','C',
	'D','F','H','O','P',
	'Q','V','W','X','Z'
};


char convert[N] = {'A','D','F','G','X'};

char key[N][N] = {
	'G','S','I','E','B',
	'K','N','V','Y','T',
	'C','R','D','M','H',
	'G','O','W','Z','P',
	'A','U','F','X','L'
};
char keyword[] = "ROSE";


//1. ROW Return Func
char rowReturn(char chr)
{
	// cout << chr << endl;
	for (int i = 0; i < N; ++i)		
		for (int j = 0; j < N; ++j)
			if(chr==key[i][j]){
				// cout << convert[chr / N] << endl;
				return convert[i];
			}
}
//2. COL Return Func
char colReturn(char chr)
{
	// cout << chr << endl;
	for (int i = 0; i < N; ++i)		
		for (int j = 0; j < N; ++j)
			if(chr==key[i][j]){
				// cout << convert[chr % N] << endl;
				return convert[j];
			}
	// return convert[chr % N];
}
//3. 문자열을 순서대로 만드는 함수 --> 정렬
void swap(char* s1, char* s2)
{
	char temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}
void sort(char *keyword)
{
	int len = strlen(keyword);
	for (int i = 0; i < len; ++i){
		for (int j = i; j < len; ++j)
		{	
			if(keyword[i] < keyword[j])
				swap(&keyword[i], &keyword[j]);
		}
	}
}



char firstReturn(char chr1, char chr2)
{
	// cout << chr << endl;
	int row1,col1,row2,col2;
	for (int i = 0; i < N; ++i)		
		for (int j = 0; j < N; ++j)
			if(chr1==keySpace[i][j]){
				row1 = i;
				col1 = j;
			}
	for (int i = 0; i < N; ++i)		
		for (int j = 0; j < N; ++j)
			if(chr2==keySpace[i][j]){
				row2 = i;
				col2 = j;
			}

	if(col1 == col2){
		return keySpace[(row1-1)%5][col1];
	}
	else if(row1 == row2){
		return keySpace[row1][(col1-1)%N];
	}
	else{
		return keySpace[row1][col2];	
	}

	// return convert[chr % N];
}

char secondReturn(char chr1, char chr2)
{
	// cout << chr << endl;
	int row1,col1,row2,col2;
	for (int i = 0; i < N; ++i)		
		for (int j = 0; j < N; ++j)
			if(chr1==keySpace[i][j]){
				row1 = i;
				col1 = j;
			}
	for (int i = 0; i < N; ++i)		
		for (int j = 0; j < N; ++j)
			if(chr2==keySpace[i][j]){
				row2 = i;
				col2 = j;
			}

	if(col1 == col2){
		// return keySpace[row2][(col2-1)%N];
		return keySpace[(row2-1)%N][col2];
	}
	else if(row1 == row2){
		
		return keySpace[row2][(col2-1)%N];
	}
	else{
		return keySpace[row2][col1];	
	}

	// return convert[chr % N];
}


int main()
{

	char str[] = "BFFKTUTYERDQNT";
	int len = strlen(str);
	char plainText[100];
	for (int i = 0; i < len / 2; ++i)
	{
		plainText[2*i] = firstReturn(str[2*i],str[2*i + 1]);
		plainText[2*i + 1] = secondReturn(str[2*i],str[2*i + 1]);
		cout << plainText << endl;	
	}
	cout << plainText << endl;

	// cout << "ADFGX START" << endl;
	// char plainText[] = "TODAYISTUESDAY";
	// int plainTextLen = strlen(plainText);
	// char cipherText[100];
	// cout << plainTextLen << endl;
	// for (int i = 0; i < plainTextLen; ++i)
	// {
	// 	if(plainText[i] == ' ')
	// 		continue;
	// 	cipherText[2*i] = rowReturn(plainText[i]);
	// 	cipherText[2*i+1] = colReturn(plainText[i]);	
	// }
	// cout << cipherText << endl;




	return 0;
}














