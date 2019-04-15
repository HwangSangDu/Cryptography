#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

int determinantOfMatrix(int mat[N][N], int n);
void display(int mat[N][N], int row, int col);

int main(void)
{
	int matrix[N][N] =
	{
		{6, 1, 1},
		{4, -2, 5},
		{2, 8, 7}
	};

	display(matrix, N, N);

    int determinant = determinantOfMatrix(matrix, N);

	printf("Determinant of the matrix is: %d\n", determinant);

	return 0;
}

int determinantOfMatrix(int mat[N][N], int n)
{
    int det=0, p, h, k, i, j, temp[N][N];

    if (n == 1)
    {
    	return mat[0][0];
    }
    else if (n == 2) 
    {
        det = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);

        return det;
    }
	else {
		for (p = 0; p < n; p++) {
			h = 0;
			k = 0;
			
			for (i = 1; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (j==p) {
						continue;
					}
					
					temp[h][k] = mat[i][j];
					k++;
					
					if (k == n-1) {
						h++;
						k = 0;
					}
				}
			}
			
			det = det + mat[0][p] * pow(-1, p) * determinantOfMatrix(temp, n-1);
		}
		
		return det;
	}
}

void display(int mat[N][N], int row, int col)
{
    int i;
    int j;
		
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
        	printf("%d\t", mat[i][j]);
        }

        printf("\n");
    }
}