#include "matrix.hpp"
#include <iostream>
#include <fstream>  //to read from files
#include <string>

int main(int argc, char *argv[]) {
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename; //get the file name from the user

    std::ifstream file(filename); //open the file
    if (!file.is_open()) { //check if the file got open
        std::cerr << "Was not able to open the file\n"; //error if not
        return 1; //exit prog with error
    }

    int N;
    file >> N; //read the matrix size from the file

    //create two 2D vectors to store the martices
    std::vector<std::vector<int> > matrix1(N, std::vector<int>(N));
    std::vector<std::vector<int> > matrix2(N, std::vector<int>(N));

    //read matrix 1 vals 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix1[i][j]; //read each value into matrix1
        }
    }

    //read matrix 2 vales
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix2[i][j]; //read each value into matrix2
        }
    }

    file.close(); //close the file

    //create Matrix objects using the values 
    Matrix m1(matrix1);
    Matrix m2(matrix2);

    std::cout << "\nmatrix 1:\n";
    m1.print_matrix(); //print matrix1 using class

    std::cout << "\nmatrix 2:\n";
    m2.print_matrix(); //print matrix2 using class

    return 0; //end prog
}