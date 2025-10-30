#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

void readMatrices(const string &filename, vector<vector<int>> &A, int &N) {
	ifstream infile(filename);
	if (!infile) {
		cerr << "Error: Cannot open file " << filename << endl;
		exit(1);
	}
	
	infile >> N;
	A.assign(N, vector<int>(N));
	
	//first matrix
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			infile >> A[i][j];

	infile.close();
}

void printMatrix(const vector<vector<int>> &M, const string &name) {
	cout << name << ":\n";
	for (const auto &row : M) {
		for (int val : row)
			cout << setw(5) << val;
		cout << "\n";
	}
	cout << "\n";
}

void update_Matrix(vector<vector<int>> &A,int N, int row, int col, int new_value) {
	if (row < 0|| row >= N || col < 0 || col >= N) {
		cout << "Not valid indicies." << endl;
		return;
	}
	
	A[row][col] = new_value;
}

int main() {
	string filename;
	cout << "Enter input file: ";
	cin >> filename;
	
	vector<vector<int>> A;
	int N;
	
	readMatrices(filename, A, N);
	
	printMatrix(A, "Matrix");
	cout << "Type the row and column indicies you want to update:\n";
	int row;
	int col;
	int new_value;
	cout << "Row: ";
	cin >> row;
	cout << "Column: ";
	cin >> col;
	cout << "Enter the updated value: ";
	cin >> new_value;
	
	
	update_Matrix(A, N, row, col, new_value);
	printMatrix(A, "Updated Matrix");
	
	return 0;
}
	