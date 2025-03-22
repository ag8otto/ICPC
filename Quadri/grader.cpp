#include <stdio.h>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdlib.h>
using namespace std;
static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int *V;
static int B;
using namespace std;
// Declaring functions
int quadri(int N, long long M, int *V)
{
	int i = 0, j = 0;
	int min = N;
	long long sum = 0;
	while (j < N)
	{
		if (sum > M)
		{
			sum -= V[i];
			i++;
			if (j - i < min)
			{
				min = j - i;
			}
		}
		else
		{
			sum += V[j];
			j++;
		}
	}
	return min;
}

int main()
{
	ifstream cin("input0.txt");
	//ofstream cout("output.txt");

	// Iterators used in for loops
	// Reading input
	cin >> N >> M;
	V = (int *)malloc(N * sizeof(int));
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> V[i];
	}
	cout << N << ' ' << M << endl;
	// Calling functions
	B = quadri(N, M, V);
	// Writing output
	fprintf(fw, "%d\n", B);

	fclose(fr);
	fclose(fw);
	return 0;
}
