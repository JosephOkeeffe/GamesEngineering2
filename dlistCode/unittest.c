#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "DLinkedList.h"

int tests_run = 0;
 
 int factorialNum = 3;
 int fibonacciNum = 4;
 
 static char * test_create() 
 {
    DLList * myList = createDLList();

    mu_assert("Size not initialised properly", 0 == size(myList));
    mu_assert("Pointers not initialised to NULL on creation", true == atEnd(myList));
    free(myList);
    return 0;
 }
 
 static char * test_size() 
 {
    DLList * myList = createDLList();
    push(myList);
    mu_assert("Incorrect size after push", 1 == size(myList));

    insertAfter(myList, 2);
    mu_assert("Incorrect size after insert after", 2 == size(myList));

    insertBefore(myList, 3);
    mu_assert("Incorrect size after insert before", 3 == size(myList));

    push(myList, 5);
    mu_assert("Incorrect size after push", 4 == size(myList));

    pop(myList);
    mu_assert("Incorrect size after pop", 3 == size(myList));

    deleteCurrent(myList);
    mu_assert("Incorrect size after delete current", 2 == size(myList));

    free(myList);

    return 0;
 }

 static char * test_push() 
 {
    DLList * myList = createDLList();

    push(myList, 3);
    mu_assert("Push does not return the desired value", 3 == pop(myList));
    free(myList);
    return 0;
 }

  static char * test_pop() 
 {
    DLList * myList = createDLList();

    push(myList, 5);
    mu_assert("Pop does not return the desired value", 5 == pop(myList));
     return 0;
 }
 
 static char * all_tests() 
 {
     mu_run_test(test_create());
     mu_run_test(test_size());
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

