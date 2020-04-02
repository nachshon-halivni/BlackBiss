#include <stdio.h>

//declarations
int fibonacci(int n);

//main
int main() {
    int n = 0;
    scanf("%d", &n);
    int fib = fibonacci(n);
    printf("The %dth Fibonacci number is: %d", n, fib);
    return (0);
}

//definitions
int fibonacci(int n) {
    if (n == 0 || n == 1)
        return (n);
    return (fibonacci(n - 1) + fibonacci(n - 2));
}