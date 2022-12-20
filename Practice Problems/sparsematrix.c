/*
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 21/11/2022 Thursday
	Exp No : 11
	Aim : Implementing Sparse Matrix Representation
*/


#include<stdio.h>

int main()
{
	int r,c;
	printf("Enter the rows and coloumns of Matrix:\n");
	scanf("%d%d",&r,&c);
	int sparseMatrixA[r][c];
	int sparseMatrixB[r][c];
	printf("Enter Sparse Matrix A:\n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			scanf("%d",&sparseMatrixA[i][j]);
		}
		
	printf("Sparse Matrix A:\n");		//Printing the sparse Matrix
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			printf("%d\t",sparseMatrixA[i][j]);
		printf("\n");
		}

	int sizeofA = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){		//getting non zero elements count
			if (sparseMatrixA[i][j] != 0)	
				sizeofA++;
			}
		}

	int sparserepA[sizeofA+1][3];
	sparserepA[0][0] = r;   		//explicitly setting values to representation matrix
	sparserepA[0][1] = c;
	sparserepA[0][2] = sizeofA;

	// Assigning values to matrix
	for (int i = 0; i < r; i++){
		int k=0;
		for (int j = 0; j < c; j++){
			if (sparseMatrixA[i][j] != 0)
			{
				sparserepA[k][0] = i;
				sparserepA[k][1] = j;
				sparserepA[k][2] = sparseMatrixA[i][j];
				k++;
			}
		}
	}
	
	printf("Sparse Matrix Representation of A:\n");
	printf("Rows\t Coloumn\t Values\t\n");
	for (int i=0; i<=sizeofA; i++)
	{
		for (int j=0; j<3; j++)
			printf("%d\t ", sparserepA[i][j]);
		printf("\n");
	}
	
	printf("Transpose of A:\n");
	printf("Rows\t Coloumn\t Values\t\n");
	for (int i=0; i<sizeofA; i++)
	{
		for (int j=0; j<3; j++)
			printf("%d\t ", sparserepA[j][i]);
		printf("\n");
	}
	
	
	// Second Sparse Matrix 
	
	printf("Enter  Sparse Matrix B:\n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			scanf("%d",&sparseMatrixB[i][j]);
		}
		
	printf("Sparse Matrix B:\n");		//Printing the sparse Matrix
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			printf("%d\t",sparseMatrixB[i][j]);
		printf("\n");
		}

	int sizeofB = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){		//getting non zero elements count
			if (sparseMatrixB[i][j] != 0)	
				sizeofB++;
			}
		}

	int sparserepB[sizeofB+1][3];
	sparserepA[0][0] = r;   		//explicitly setting values to representation matrix
	sparserepA[0][1] = c;
	sparserepA[0][2] = sizeofB;

	// Assigning values to matrix
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (sparseMatrixB[i][j] != 0)
			{
				sparserepB[i+1][0] = i;
				sparserepB[i+1][1] = j;
				sparserepB[i+1][2] = sparseMatrixB[i][j];
			}
		}
	}
	
	printf("Sparse Matrix Representation of B:\n");
	printf("Rows\t Coloumn\t Values\t\n");
	for (int i=0; i<=sizeofB; i++)
	{
		for (int j=0; j<3; j++)
			printf("%d\t ", sparserepB[i][j]);
		printf("\n");
	}
	
	printf("Transpose of B:\n");	//Transpose of B
	printf("Rows\t Coloumn\t Values\t\n");
	for (int i=0; i<sizeofB; i++)
	{
		for (int j=0; j<3; j++)
			printf("%d\t ", sparserepB[j][1]);
		printf("\n");
	}
	
	
	return 0;
}
