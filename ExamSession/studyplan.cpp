/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>

// constraints
#define MAXN 100000

// input data
int N, i, j;
int H[MAXN];

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(1 == scanf("%d", &N));
  for (i = 0; i < N; i++)
    assert(1 == scanf("%d", &H[i]));
  for (i = 0; i < N; i++) {
    int k;
    assert(1 == scanf("%d", &k));
    for (j = 0; j < k; j++) {
      int s;
      assert(1 == scanf("%d", &s));
      // TODO: process dependency s --> i
    }
  }

  // insert your code here

  printf("%d\n", 42); // print the result
  return 0;
}
