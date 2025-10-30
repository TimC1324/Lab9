#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

void readMatrices(const string &filename, vector<vector<int>> &A, vector<vector<int>> &B, int &N) {
	ifstream infile(filename);
	if (!infile) {
		cerr << "Error: Cannot open file " << filename << endl;
		exit(1);
	}
	
	infile >> N;
	A.assign(N, vector<int>(N));
	B.assign(N, vector<int>(N));
	
	//first matrix
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			infile >> A[i][j];
		
	//second matrix
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			infile >> B[i][j];
		
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

vector<vector<int>> multMatricies(const vector<vector<int>> &A, const vector<vector<int>> &B, int N) {
	vector<vector<int>> result(N, vector<int>(N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return result;
}

int main() {
	string filename;
	cout << "Enter input file: ";
	cin >> filename;
	
	vector<vector<int>> A, B, product;
	int N;
	
	readMatrices(filename, A, B, N);
	
	printMatrix(A, "Matrix A");
	printMatrix(B, "Matrix B");
	
	product = multMatricies(A, B, N);
	
	printMatrix(product, "A x B");
	
	return 0;
	
}
	