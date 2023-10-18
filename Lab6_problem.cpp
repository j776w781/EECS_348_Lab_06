/*
This file contains all of the code for Lab 06. It was created by Josh Welicky on 10/18/2023.
This program opens an input file named matrix_input.txt and reads in a set of integers. The first
integer read in will determine the dimension, N, of two N * N matrices. The remaining integers are
then used to create the two N*N matrices. These matricies, A and B, are then printed to the screen.
The results of A + B, A * B, and A - B are determined and printed to the screen. These tasks are
accomplished by the defined functions read(), which opens and reads from the input file; matrix_print(), 
which prints a matrix to the screen; add(), which adds two matrices; multiply, which multiplies two 
matrices; and subtract(), which subtracts two matrices.
*/


#include <iostream>
#include <fstream>
using namespace std;

static const int max_size = 100; //Sets the maximum size of a matrix to 100.
int A[max_size][max_size];                              //Globally declared two dimensional array, which represents the matrix A.
int B[max_size][max_size];                              //Globally declared two dimensional array, which represents the matrix B.
                                                        //These variables are globally declared so that they can be altered by read() and accessed by main().
/*
This section contains the prototypes of all the functions used in this program. These are read(), 
matrix_print(), add(), multiply(), and subtract(). Most take in an integer N. This N represents the 
dimension of a considered matrix and is used as the stopping point for iteration. Each function 
takes in atleast one 2-dimensional array, which represent matrices. read() takes in no parameters. 
All but read() return nothing.*/

int read();

void matrix_print(int N, int matrix[max_size][max_size]);

void add(int N, int A[max_size][max_size], int B[max_size][max_size]);

void multiply(int N, int A[max_size][max_size], int B[max_size][max_size]);

void subtract(int N, int A[max_size][max_size], int B[max_size][max_size]);


int main()
{
	cout << "Josh Welicky\nLab #6: Matrix Manipulation\n\n";
	static const int N = read();
	/*Calls read(), which opens up the given input file and stores the matrix data
	 into the proper globally declared arrays. Returns an integer, N, which is stored
	 as a static constant. This was done to satisfy the relevant constraint.*/


	cout << "Matrix A:\n";
	matrix_print(N, A);
	
	cout << "\nMatrix B: \n";
	matrix_print(N, B);
	/*This block prints matrices A and B to the screen.*/

	cout << "\nMatrix Sum (A+B):\n";
	add(N, A, B);
	
	cout << "\nMatrix Product (A * B):\n";
	multiply(N, A, B);

	cout << "\nMatrix Difference (A - B): \n";
	subtract(N, A, B);

	cout << "\n";
	return 0;

	/*The remaining code in this function follows a simple formula. First, a message is printed
	 announcing what matrix operation will be displayed. Then, the subsequent matrix operation
	 function is called, passing in N, A, and B as parameters.*/
}


int read() {							//This function reads in all data in an input file. It stores matrix data into globally declared arrays.
	ifstream input_file("matrix_input.txt", ios::in);	//Opens the file matrix_input.txt.
	int N;							//Creates a variable N, which represents the dimension of an N*N matrix.

        input_file >> N;					//Reads in the first integer and assigns it as the N value.

	for(int i = 0; i < N; i++) {				
              for(int j = 0; j < N; j++)
                      input_file >> A[i][j];
        }
	/*This block populates the first N*N matrix A by reading the next N integers in the file,
	 assigning them to their proper place in a matrix. For loops are used to file the proper
	 row and columns for these matrix values.*/

	for(int i = 0; i < N; i++) {
              for(int j = 0; j < N; j++)
                      input_file >> B[i][j];
        }
	/*Builds the B matrix in the exact same way as above.*/
	input_file.close();
	return N;						//Returns N, which will be assigned to a static constant in main().
}


void matrix_print(int N, int matrix[max_size][max_size]) {   //This takes in an N value, used as a ending point for iteration, and a matrix. It will print it to the screen.
	for(int i = 0; i < N; i++) {		  //This function will print a matrix row by row. Since the matrix could be 2*2 or 99*99, N is used to stop iteration when the last row has been fully printed.
		for(int j = 0; j < N; j++)	  //When printing rows, each entry is printed, separated by tabs. Therefore, this nested loop iterates through each value in a "row".	
			cout << matrix[i][j] << "\t"; 
		cout << "\n";				//A new line is printed so that the next row can begin on its own line.

	}
}


void add(int N, int A[max_size][max_size], int B[max_size][max_size]) {  //Used to add two matrices together, store the results in a new matrix, and print it to the screen.
	int result[max_size][max_size];				//Creates our result matrix, which will be the sum of A and B.
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			result[i][j] = A[i][j] + B[i][j];
	}

	/*Uses nested loops to iterate through every entry in our N by N matrix. The entry in result at row i
	 and column j is set equal to the sum of the entries in A and B at row i and column j. The result is then
	 given to matrix_print() to display.*/
	matrix_print(N, result);
}


void multiply(int N, int A[max_size][max_size], int B[max_size][max_size]) { //Used to multiply two matrices together, store the results in a new matrix, and print it to the screen.
	int result[max_size][max_size];				//Creates our result matrix, which will store the product of A and B.
	
	for(int i = 0; i < N; i++) { 			//This loop will iterate N times (N defines the dimension of our matrix) and gives us a current row number i. This is just for result and A.
		for(int j = 0; j < N; j++) {		//This loop will iterate N times as well. It gives us a current column number j. This is the current column of result and B.
			result[i][j] = 0;		//This sets our entry in result at row i and column j to 0 initially. This gives us something to build on.
			for(int k = 0; k<N; k++)	//This loop gives us the current column number of A and the current row number of B.
				result[i][j] += A[i][k] * B[k][j]; //Calculates the product of the entry in A at row i, column k  and the entry in A at row k, column j. Adds this to the current entry in result.
								   //Complete iteration of the innermost loop will determine the correct value for result at row i and column j.
		}
	}

	matrix_print(N, result); //This will display the result matrix to the screen.
}


void subtract(int N, int A[max_size][max_size], int B[max_size][max_size]) { //Used to subtract two matrices, store the results in a new matrix, and print it to the screen.
	int result[max_size][max_size];				//Creates our result matrix, which will be the difference of A and B.
	for(int i = 0; i < N; i++) {			
		for(int j = 0; j < N; j++)
			result[i][j] = A[i][j] - B[i][j];
	}
	matrix_print(N, result);
	/*Uses nested loops to iterate through every entry in our N by N matrix. The entry in result at row i and column
	 j is set equal to the difference between the entries in A and B at row i and column j. The result is the given
	 to matrix_print() to be displayed.*/
}
