#include <assert.h>
#include <stdio.h>

int sum(int a, int b) { return a + b; }

int test() {
  assert(sum(5, 5) == 10);
  printf("\nAll tests passed.\n");
  return 0;
}
