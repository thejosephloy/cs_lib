#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <random>
#include <algorithm>
#include <ctime>
#include <x86intrin.h>

#define UNROLL (4)
#define BLOCKSIZE 32
#define N 3
using namespace std;
/*
void nmm(int n, double A[N][N], double B[N][N], double C[N][N]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}


}

void dgemm(int n, double* A, double* B, double* C) {
	for (int i = 0; i < n; i += UNROLL * 4) {
		for (int j = 0; j < n; j++) {
			__m256d c[4];
			for (int x = 0; x < UNROLL; x++) {
				c[x] = _mm256_load_pd(C + i + x * 4 + j * n);
			}

			for (int k = 0; k < n; k++) {
				__m256d b = _mm256_broadcast_sd(B + k + j * n);
				for (int x = 0; x < UNROLL; x++) {
					c[x] = _mm256_add_pd(c[x], _mm256_mul_pd(_mm256_load_pd(A + n * k + x * 4 + i), b));
				}
			}

			for (int x = 0; x < UNROLL; x++) {
				_mm256_store_pd(C + i + x * 4 + j * n, c[x]);
			}
		}
	}
}

void do_block(int n, int si, int sj, int sk, double* A, double* B, double* C) {
	for (int i = si; i < si + BLOCKSIZE; i += UNROLL * 4) {
		for (int j = sj; j < sj + BLOCKSIZE; j++) {
			__m256d c[4];
			for (int x = 0; x < UNROLL; x++) {
				c[x] = _mm256_load_pd(C + i + x * 4 + j * n);
			}

			for (int k = sk; k < sk + BLOCKSIZE; k++) {
				__m256d b = _mm256_broadcast_sd(B + k + j * n);
				for (int x = 0; x < UNROLL; x++) {
					c[x] = _mm256_add_pd(c[x], _mm256_mul_pd(_mm256_load_pd(A + n * k + x * 4 + i), b));
				}
			}

			for (int x = 0; x < UNROLL; x++) {
				_mm256_store_pd(C + i + x * 4 + j * n, c[x]);
			}
		}
	}
}

void dgemm_cache_blocking(int n, double* A, double* B, double* C) {
	for (int sj = 0; sj < n; sj += BLOCKSIZE) {
		for (int si = 0; si < n; si += BLOCKSIZE) {
			for (int sk = 0; sk < n; sk += BLOCKSIZE) {
				do_block(n, si, sj, sk, A, B, C);
			}
		}
	}
}
*/
vector<int> merge(vector<int>& A, int p, int q, int r) {
	// merge
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1 + 1, 0);
	vector<int> R(n2 + 1, 0);

	for (int i = 1; i < n1 + 1; i++) {
		L[i - 1] = A[p + i - 1];
	}

	for (int j = 1; j < n2 + 1; j++) {
		R[j - 1] = A[q + j];
	}
	
	L[n1] = numeric_limits<int>::max();
	R[n2] = numeric_limits<int>::max();

	int i = 0;
	int j = 0;
		
	for (int k = p; k < r + 1; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
	}
	
	return A;
}

vector<int> mergesort(vector<int>& A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		vector<int> L = mergesort(A, p, q);
		vector<int> R = mergesort(A, q + 1, r);
		A = merge(A, p, q, r);
	}
	return A;
}

int partition(vector<int>& A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r-1; j++) {
		if (A[j] <= x) {
			i += 1;
			// Swap A[i] and A[j]
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	// Swap A[i + 1] with A[r]
	int temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
}

void quicksort(vector<int>& A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
	
}

int main(int argc, char** argv) {
	cout << "Main program is running" << endl;
	
	int size = 100;
	vector<int> v(size, 0);
	random_device rd; // obtain a random number from hardware
    	mt19937 gen(rd()); // seed the generator
    	uniform_int_distribution<> distr(-1000, 1000); // define the range
	cout << "List is :" << endl;
    	for(int i = 0; i < size; i++) {
		v[i] = distr(gen);
		cout << v[i] << endl;
	}

	int p = 0;
	int r = size - 1;
	quicksort(v, p, r);

	cout << "Sorted list is :" <<  endl;

	for (int i = 0; i < size; i++) {
                cout << v[i] << endl;
        }

	int n = 3;
	double A[N][N] = {1, 0, 0, 0, 2, 0, 0, 0, 3};
	double B[N][N] = {1, 0, 0, 0, 2, 0, 0, 0, 3};
	double C[N][N] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	/*
	//m(n, A, B, C);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << C[i][j] << endl;
		}
	}
	*/
	

	return 0;
}
