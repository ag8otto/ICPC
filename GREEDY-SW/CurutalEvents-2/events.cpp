/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 50000

// input data
int N, V, i;
int prices[MAXN], vouchers[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &V));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &prices[i]));
    for(i=0; i<V; i++)
        assert(1 == scanf("%d", &vouchers[i]));

    // insert your code here
    
    printf("%d\n", 42); // print the result
    return 0;
}
