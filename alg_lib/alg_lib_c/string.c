#include <stdio.h>
#include <string.h>

void naive_matcher(char* T, char* P);
void rk_matcher(char* T, char* P, int d, int q);
void kmp_matcher(char* T, char* P);
int* compute_prefix_function(char* P);

int main(int argc, char* argv[]) {
	char* T = "Hello\0";
	char* P = "ll\0";
	printf("Enter naive string matcher\n");
	naive_matcher(T, P);
	printf("Leaving naive string matcher\n");
	printf("Enter rk matcher\n");
	rk_matcher(T, P, 256, 101);
	printf("Leaving rk matcher\n");
	return 0;
}

void naive_matcher(char* T, char* P) {
	int n = strlen(T);
	int m = strlen(P);
	for (int s = 0; s < n - m; s++) {
		int t;
		for (t = 0; t < m; t++) {
			if (T[s+t] != P[t]) break;
		}
		if (t == m) printf("Pattern appears at shift %d\n", s);
	}
}

void rk_matcher(char* T, char* P, int d, int q) {
	int n = strlen(T);
	int m = strlen(P);
	int h = 1;
	for (int i = 0; i < m - 1; i++) h = (h * d) % q;
	int p = 0;
	int t = 0;
	for (int i = 0; i < m; i++) {
		p = (d*p + P[i]) % q;
		t = (d*t + T[i]) % q;
	}
	for (int s = 0; s < n - m + 1; s++) {
		if (p == t) {
			int u;
			for (u = 0; u < m; u++) {
				if (T[s+u] != P[u]) break;
			}
			if (u == m) printf("Pattern appears at shift %d\n", s);
		}
		if (s < n - m) {
			int partial = (d * (t - T[s] * h) + T[s + m]);
			// modulo is not defined for negative values in C :/ 
			if (partial < 0) {
				t = ((d * (t - T[s] * h) + T[s + m]) % q) + q;
			} else {
				t = (d * (t - T[s] * h) + T[s + m]) % q;
			}
		}
	}
}

