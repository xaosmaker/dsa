

int sum(int n) {

  if (n <= 0) {
    return 0;
  }

  return sum(n - 1) + n;
}

int factorial(int n) {

  if (n <= 1) {
    return 1;
  }

  return n * factorial(n - 1);
}

int ex(int b, int e) {
  if (e == 0) {
    return 1;
  }

  if (e % 2 == 0) {
    return ex(b * b, e / 2);
  }

  return ex(b, e - 1) * b;
}

#include <stdio.h>
int main(void) {
  printf("Hello from rec\n");
  int n = 5;

  printf("sum(%d) = %d\n", n, sum(n));
  printf("form n*(n+1) /2 = %d\n", n * (n + 1) / 2);
  printf("factorial(%d) = %d\n", n, factorial(n));
  printf("ex(%d) = %d\n", n, ex(2, 16));
  return 0;
}
