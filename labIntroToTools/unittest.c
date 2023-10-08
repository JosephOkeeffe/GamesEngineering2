#include <stdio.h>
#include "stuff.c"
#include "minunit.h"

int tests_run = 0;
 
 int factorialNum = 3;
 int fibonacciNum = 4;
 
 static char * test_factroial() 
 {
     mu_assert("error, foo != 6", factorial(factorialNum) == 6);
     return 0;
 }
 
 static char * test_fibonacci() 
 {
     mu_assert("error, fibonacci != 7", fibonacci(fibonacciNum) == 7);
     return 0;
 }
 
 static char * all_tests() 
 {
     mu_run_test(test_factroial);
     mu_run_test(test_fibonacci);
     return 0;
 }
 
 int main(int argc, char **argv)
 {
     char *result = all_tests();
     if (result != 0) 
     {
         printf("%s\n", result);
     }
     else 
     {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
 }

