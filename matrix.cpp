#include "matrix.hpp"
#include <iostream>
#include <iomanip> //to format matrix output

//implementation of functions declared in matrix.hpp goes here
//function definitions for a class have their names prefixed with
//the class name and "::"


Matrix::Matrix(size_t N) { //start an empty NxN matrix with all zeros
    matrix.resize(N, std::vector<int>(N, 0)); //create NxN matrix filled with zeros
}

//start a matrix from an existing 2D vector
Matrix::Matrix(std::vector<std::vector<int> > nums) {
    matrix = nums; //copy the 2D vector to the class 
}


Matrix Matrix::operator+(const Matrix &rhs) const {//add two matrices and return the result
    size_t N = matrix.size(); //get the size of the matrix
    Matrix result(N); //create result matrix of same size

    
    for (size_t i = 0; i < N; ++i) { //go through every element to addtheir values
        for (size_t j = 0; j < N; ++j) {
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j]; //addition of matrixes
        }
    }

    return result; //return the sum matrix
}

Matrix Matrix::operator*(const Matrix &rhs) const { //matrixes multiplication
    size_t N = matrix.size(); //get the size of the matrix
    Matrix result(N); //create result matrix of same size

    for (size_t i = 0; i < N; ++i) { //do matrix multiplication using the formula
        for (size_t j = 0; j < N; ++j) {
            for (size_t k = 0; k < N; ++k) {
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j]; //multiply and add
            }
        }
    }

    return result; //return the product matrix
}

void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= matrix.size() || j >= matrix[i].size()) {
        //check that index are in bound otherwise let them know there are out of bounds thorwing error
        throw std::out_of_range("Index out of range");
    }
    matrix[i][j] = n; //set the value at row i, column j to n
}

int Matrix::get_value(std::size_t i, std::size_t j) const { //get the value from pos
    if (i >= matrix.size() || j >= matrix[i].size()) {
        //check that index are in valid bounds, otherwise throw error
        throw std::out_of_range("Index out of range");
    }
    return matrix[i][j]; //return the value at that position
}

int Matrix::get_size() const {  //get the size of matrix
    return matrix.size(); //return how many rows 
}

int Matrix::sum_diagonal_major() const { //sum all elements from the main diagonal from the top left to the bottom right
    int sum = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        sum += matrix[i][i]; //add each element on diagonal
    }
    return sum; //return total
}

int Matrix::sum_diagonal_minor() const { //sum all elements from the other diagonal, so other way arounf, top right to bbottom left
    int sum = 0;
    size_t N = matrix.size();
    for (size_t i = 0; i < N; ++i) {
        sum += matrix[i][N - 1 - i]; //add each element on the secondary diagonal
    }
    return sum; //return the total
}

void Matrix::swap_rows(std::size_t r1, std::size_t r2) { //swap two rows if indx are valid
    std::swap(matrix[r1], matrix[r2]); //swap the entire row vectors
}

//swap columns if index are valid
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        std::swap(matrix[i][c1], matrix[i][c2]); //swap each element in column 
    }
}

void Matrix::print_matrix() const { //print the matrix with nince formatting
    for (const auto& row : matrix) { //go through each row
        for (const auto& value : row) { //go through each column in the row
            std::cout << std::setw(4) << value; //print each value with 4 char spacing
        }
        std::cout << '\n'; //move to next line after each row
    }
}