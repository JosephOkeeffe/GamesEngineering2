/* stuff.c --- 
 * 
 * Filename: stuff.c
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Wed Sep 20 11:38:45 2023 (+0100)
 * Last-Updated: Wed Sep 20 11:46:34 2023 (+0100)
 *           By: Joseph
 *     Update #: 2
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */

/**
 * A brief history of JavaDoc-style (C-style) comments.A javadoc style comment for Doxygen
 *
 * This is the typical JavaDoc-style C-style comment. It starts with two
 * asterisks. This is a longer comment detailing algorithm (as required)
 *
 * @param N Integer input to function
 * @return the factorial of N 
 *               
 */

 #include "minunit.h"
 #include <stdio.h>

int factorial(int N)
{
  int result = N;

  while(N > 1)
  {
    result *= (N - 1);
    N--;
  }
  
  return result;
}


/*******************************************************************************
 * A brief history of JavaDoc-style (C-style) banner comments.
 *
 * This is the typical JavaDoc-style C-style "banner" comment. It starts with
 * a forward slash followed by some number, n, of asterisks, where n > 2. It's
 * written this way to be more "visible" to developers who are reading the
 * source code.
 *
 * Often, developers are unaware that this is not (by default) a valid Doxygen
 * comment block!
 *
 * However, as long as JAVADOC_BLOCK = YES is added to the Doxyfile, it will
 * work as expected.
 *
 * This style of commenting behaves well with clang-format.
 *
 * @param N Integer input to function
 * @return the fibonacci of N 
 *               
 *
 ******************************************************************************/
int fibonacci(int N)
{
  int temp = 0;

  int current = 1;
  int previous = 1;
  int sum = 2;

  while(N > 2)
  {
    temp = current + previous; // 2 = 1 + 1 // 3 = 2 + 1
    previous = current; // 1 = 1 // 1 = 2
    current = temp; // 2 = 2 // 3 = 3
    
    sum += current;
    N--;
  }

  return sum;
}



int tests_run = 0;
 
 int factorialNum = 3;
 int fibonacciNum = 4;


 
 static char * test_factroial() 
 {
     mu_assert("error, factorial != 6", factorial(factorialNum) == 6);
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
 

  


/* stuff.c ends here */
