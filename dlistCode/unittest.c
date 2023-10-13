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

    mu_assert("Size not initialised properly in test_Create()", 0 == size(myList));
    mu_assert("Pointers is initialised to NULL on creation in test_Create()", !atEnd(myList));
    free(myList);
    return 0;
 }
 
 static char * test_size() 
 {
    DLList * myList = createDLList();
    push(myList, 1);
    mu_assert("Incorrect size after push", 1 == size(myList));

    insertAfter(myList, 2);
    mu_assert("Incorrect size after insert after", 2 == size(myList));

    insertBefore(myList, 3);
    mu_assert("Incorrect size after insert before", 3 == size(myList));

    push(myList, 5);
    mu_assert("Incorrect size after push", 4 == size(myList));

    pop(myList);
    mu_assert("Incorrect size after pop", 3 == size(myList));

    //deleteCurrent(myList);
    //mu_assert("Incorrect size after delete current", 2 == size(myList));

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
    mu_assert("Pop does not remove the correct element in the list", 5 == pop(myList));
    free(myList);
    return 0;
}

static char * test_getCurrent() 
{
    DLList * myList = createDLList();
    push(myList, 1);
    push(myList, 2);
    push(myList, 3);

    mu_assert("Get current does not change the current pointer", 3 == getCurrent(myList));
    free(myList);
    return 0;
}

static char * test_first() 
{
    DLList * myList = createDLList();
    push(myList, 1);
    push(myList, 2);
    //int sizeBefore = size(myList);
    first(myList);

   // mu_assert("First does not change the current pointer to the first element in the list (test_first)", 1 == getCurrent(myList));
   // mu_assert("First changes the size of the list (test_first)", sizeBefore ==  size(myList));
    free(myList);
    return 0;
}
static char * test_next() 
{
    DLList * myList = createDLList();
    push(myList, 5);
    push(myList, 6);
    push(myList, 7);
    first(myList);
    next(myList);

    mu_assert("Next does not change the current pointer to the next element in the list", 6 == getCurrent(myList));
    free(myList);

    push(myList, 3);
    next(myList);

    mu_assert("Next in a list with one element should not work but its giving some value", 0  == getCurrent(myList));
    free(myList);
    return 0; 
}

static char * test_atEnd() 
{
    DLList * myList = createDLList();
    push(myList, 5);

    mu_assert("Current element is at the end, it should return true", true == atEnd(myList));
    free(myList);

    push(myList, 1);
    push(myList, 2);
    first(myList);
    mu_assert("Current element is NOT at the end, it should return true", false == atEnd(myList));
    free(myList);
    return 0; 
}

static char * test_deleteCurrent() 
{
    DLList * myList = createDLList();
    push(myList, 1);
    push(myList, 2);
    push(myList, 3);
    deleteCurrent(myList);

    mu_assert("Delete Current did not work. Element has not been deleted", 2 == getCurrent(myList));
    free(myList);
    return 0; 
}

static char * test_insertAfter() 
{
    DLList * myList = createDLList();
    push(myList, 5);
    insertAfter(myList, 8);
    next(myList);

    mu_assert("Insert After did not insert after the current element ", 8 == getCurrent(myList));
    free(myList);
    return 0; 
}

static char * test_insertBefore() 
{
    DLList * myList = createDLList();
    push(myList, 3);
    insertBefore(myList, 1);

    mu_assert("Insert Before did not insert before the current element ", 1 == getCurrent(myList));
    free(myList);
    return 0; 
}
 
 
static char * all_tests() 
{
    mu_run_test(test_create);
    mu_run_test(test_size);
    mu_run_test(test_push);
    mu_run_test(test_pop);
    mu_run_test(test_getCurrent);
    mu_run_test(test_first);
    mu_run_test(test_next);
    mu_run_test(test_atEnd);
    mu_run_test(test_deleteCurrent);
    mu_run_test(test_insertAfter);
    mu_run_test(test_insertBefore);

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
