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

void dia_sum_Matrix(const vector<vector<int>> &A, int N) {
	int prime = 0, second = 0;
	
	for (int i = 0; i < N; i++) {
		prime += A[i][i];
		second += A[i][N-1-i];
	}
		
	cout << "Prime Diagonal: " << prime << endl;
	cout << "Second Diagonal: " << second << endl;
	cout << "Both Diagonals: " << prime + second << endl;
}

int main() {
	string filename;
	cout << "Enter input file: ";
	cin >> filename;
	
	vector<vector<int>> A;
	int N;
	
	readMatrices(filename, A, N);
	
	printMatrix(A, "Matrix");
	
	dia_sum_Matrix(A, N);
	
	return 0;

}
	
