#include <iostream>
#include <string>
#include <fstream>

#include "matrix.hpp"
#include "filestream.hpp"


void input_files(int argc, char **argv){
	int i, lines, run = 0;
	int **A, **B, **C;
	std::ifstream inputA;/** @param inputA usado como operador de arquivos das matrizes A */
	std::ifstream inputB;/** @param inputB usado como operador de arquivos das matrizes B */
	std::string bufferA;/** @param bufferA usado para ler os arquivos das matrizes A */
	std::string bufferB;/** @param bufferB usado para ler os arquivos das matrizes B */
	std::string matrixA;/** @param matrixA usado para armazenar o caminho dos arquivos de matrizes A */
	std::string matrixB;/** @param matrixB usado para armazenar o caminho dos arquivos de matrizes B */
	while(run < 100){	
		if(argc > 1){
			for(i=1;i<argc;i++){
				std::string arg = argv[i];
				matrixA = "../data/input/A" + arg + "x" + arg + ".txt"; /** @brief Gold Line */
				std::cout<<matrixA<<std::endl;
				matrixB = "../data/input/B" + arg + "x" + arg + ".txt"; /** @brief Gold Line */
				std::cout<<matrixB<<std::endl;
										/** @param lines usado para delimitar o tamanho das matrizes */
				lines = std::atoi(argv[i]);/** @param argv[i] convertido para o @param lines*/
			
				A = malloc_matrix(lines);
				B = malloc_matrix(lines);

				inputA.open(matrixA);
				inputB.open(matrixB);

				std::getline(inputA, bufferA, '\n'); /** Used for jump the first line of file*/
				std::getline(inputB, bufferB, '\n'); /** Used for jump the first line of file*/
				for(int l=0;l<lines;l++){  
					for(int c=0;c<lines;c++){
						inputA>>bufferA; /** @brief passagem do ponteiro da leitura dos arquivos para o string */
						inputB>>bufferB; 
						A[l][c] = std::atoi(bufferA.c_str()); /** @brief conversao do tipo string para inteiro e */
						B[l][c] = std::atoi(bufferB.c_str()); /** passagem para o elemento da matriz */
					}
				}
			
			C = multiplicaI(A, B, lines);
			//C = multiplicaR(A, B, lines);
			print_matrix(C, lines);
			for(int l=0;l<lines;l++){
				delete[] A[l];
				delete[] B[l];
				delete[] C[l];
			}
			delete[] A; 
			delete[] B; 
			delete[] C;
			inputA.close(), inputB.close();
			}
		}	
	std::cout<<run<<std::endl;
	run++;
	}
}
