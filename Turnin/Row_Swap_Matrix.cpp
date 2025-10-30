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

void row_swap_Matrix(vector<vector<int>> &A, int N, int row1, int row2) {
	if (row1 < 0|| row1 >= N || row2 < 0 || row2 >= N) {
		cout << "Not valid indicies." << endl;
		return;
	}
	
	swap(A[row1], A[row2]);
}

int main() {
	string filename;
	cout << "Enter input file: ";
	cin >> filename;
	
	vector<vector<int>> A;
	int N;
	
	readMatrices(filename, A, N);
	
	printMatrix(A, "Matrix");
	cout << "Type row indicies to switch:\n";
	int row1;
	int row2;
	cout << "Row 1: ";
	cin >> row1;
	cout << "Row 2: ";
	cin >> row2;
	
	row_swap_Matrix(A, N, row1, row2);
	printMatrix(A, "Swapped Matrix");
	
	return 0;
}