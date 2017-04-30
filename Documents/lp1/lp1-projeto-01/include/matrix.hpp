#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

int **soma(int **A, int **B, int n);
void AgruparSubMatrize(int **C, int **C1, int **C2, int **C3, int C4, int n);
int **MultiplicaMatrizesRecursivo(int **A, int **B, int **C, int n);
int **malloc_matrix(int n);
template <typename T>
void print_matrix(T **C, int n){
	std::fstream out;
	std::string path, size = std::to_string(n);
	path = "../data/output/C"+size+"x"+size+".txt";
	out.open(path, std::fstream::out | std::fstream::app);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
				out<<C[i][j]<<" ";
		}
		out<<std::endl;
	}
}

template <typename T>
T **multiplicaI(T **A, T **B, int n){
	std::fstream outfile;
	std::string path, size = std::to_string(n);
	int soma;
	T **C;
	C = malloc_matrix(n);
	path = "../data/output/"+size+"iterative_timer.dat";
	outfile.open(path, std::fstream::out | std::fstream::app);
	std::cout<<std::chrono::high_resolution_clock::period::den<<std::endl;
	auto start_time = std::chrono::high_resolution_clock::now();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			soma = 0;
			for(int k=0;k<n;k++){
				soma = soma + (A[i][k] * B[k][j]);
			}
		C[i][j] = soma;
		}
	}
	auto end_time = std::chrono::high_resolution_clock::now();
	outfile<<std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count()<<std::endl;
return C;
}
template <typename T>
T **multiplicaR(T **A, T **B, int n){
	T **C;
	C = malloc_matrix(n);
	C = MultiplicaMatrizesRecursivo(A, B, C, n);

return C;	
}

#endif 
