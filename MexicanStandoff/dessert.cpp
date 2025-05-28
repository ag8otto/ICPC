/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXN 1000000

// input data
int N, i, j;
int M[MAXN], L[MAXN], *F[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (i=0; i<N; i++) {
        assert(2 == scanf("%d %d", &M[i], &L[i]));
        F[i] = (int*)malloc(M[i]*sizeof(int));
        for (j=0; j<M[i]; ++j)
            assert(1 == scanf("%d", &F[i][j]));
    }

    // insert your code here
    
    printf("%d\n", 42); // print the result
    return 0;
}
