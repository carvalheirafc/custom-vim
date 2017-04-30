#include <iostream>
#include "matrix.hpp"

int **malloc_matrix(int n){
	int **A = new int *[n];
	for(int i=0;i<n;i++){
		A[i] = new int[n];
	}
return A;
}

int **soma(int **A, int **B, int n){
	int **C;
	C = malloc_matrix(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
return C;
}

void AgruparSubMatrizes(int **C, int **C1, int **C2, int **C3, int **C4, int n){
	int aux = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i][j] = C1[i][j];	
		}
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i][n+aux] = C2[i][j];
			aux++;
		}
	aux = 0;
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i+n][j] = C3[i][j];
		}
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		
			C[i+n][n+aux] = C4[i][j];
			aux++;
		}
	aux = 0;
	}
}

int **MultiplicaMatrizesRecursivo(int **A, int **B, int **C, int n){
	if(n == 1){
		C[0][0] = A[0][0] * B[0][0];
		std::cout<<C[0][0]<<" ";
		return C; 
	}else{
		int **A11, **A12, **A21, **A22;
		int **B11, **B12, **B21, **B22;
		int **C11, **C12, **C21, **C22;
		int **P1, **P2, **P3, **P4;
		int **P5, **P6, **P7, **P8;
	
		A11 = malloc_matrix(n/2);
		A12 = malloc_matrix(n/2);
		A21 = malloc_matrix(n/2);
		A22 = malloc_matrix(n/2);		
		AgruparSubMatrizes(A, A11, A12, A21, A22, n/2);
		print_matrix(A, n);
		B11 = malloc_matrix(n/2);
		B12 = malloc_matrix(n/2);
		B21 = malloc_matrix(n/2);
		B22 = malloc_matrix(n/2);
		AgruparSubMatrizes(B, B11, B12, B21, B22, n/2);
		print_matrix(B, n);
		C11 = malloc_matrix(n/2);
		C12 = malloc_matrix(n/2);
		C21 = malloc_matrix(n/2);
		C22 = malloc_matrix(n/2);
		P1 = malloc_matrix(n/2);
		P2 = malloc_matrix(n/2);
		P3 = malloc_matrix(n/2);
		P4 = malloc_matrix(n/2);
		P5 = malloc_matrix(n/2);
		P6 = malloc_matrix(n/2);
		P7 = malloc_matrix(n/2);
		P8 = malloc_matrix(n/2);
		
		MultiplicaMatrizesRecursivo(A11, B11, P1, n/2);
		MultiplicaMatrizesRecursivo(A12, B21, P2, n/2);
		MultiplicaMatrizesRecursivo(A11, B12, P3, n/2);
		MultiplicaMatrizesRecursivo(A12, B22, P4, n/2);
		MultiplicaMatrizesRecursivo(A21, B11, P5, n/2);
		MultiplicaMatrizesRecursivo(A22, B21, P6, n/2);
		MultiplicaMatrizesRecursivo(A21, B12, P7, n/2);
		MultiplicaMatrizesRecursivo(A22, B22, P8, n/2);
	
		C11 = soma(P1, P2, n/2);
		C12 = soma(P1, P2, n/2);
		C21 = soma(P1, P2, n/2);
		C22 = soma(P1, P2, n/2);
		std::cout<<C11<<C12<<C21<<C22<<" ";		
		AgruparSubMatrizes(C, C11, C12, C21, C22, n/2);
		return C;
	}
}
