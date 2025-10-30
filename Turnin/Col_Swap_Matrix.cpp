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

void col_swap_Matrix(vector<vector<int>> &A, int N, int col1, int col2) {
	if (col1 < 0|| col1 >= N || col2 < 0 || col2 >= N) {
		cout << "Not valid indicies." << endl;
		return;
	}
	for (int i = 0; i < N; i++)
		swap(A[i][col1], A[i][col2]);
}

int main() {
	string filename;
	cout << "Enter input file: ";
	cin >> filename;
	
	vector<vector<int>> A;
	int N;
	
	readMatrices(filename, A, N);
	
	printMatrix(A, "Matrix");
	cout << "Type Column indicies to switch:\n";
	int col1;
	int col2;
	cout << "Column 1: ";
	cin >> col1;
	cout << "Column 2: ";
	cin >> col2;
	
	col_swap_Matrix(A, N, col1, col2);
	printMatrix(A, "Swapped Matrix");
	
	return 0;
}