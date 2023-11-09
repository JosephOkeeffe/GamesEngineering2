/* listmain.c --- 
 * 
 * Filename: listmain.c
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Wed Oct  4 20:32:33 2023 (+0100)
 * Last-Updated: Wed Oct  4 20:40:43 2023 (+0100)
 *           By: Joseph
 *     Update #: 4
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
#include "DLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

DLList* createDLList()
{
  DLList* list = (DLList*)malloc(sizeof(DLList));
  list->first = NULL;
  list->current = NULL;
  list->size = 0;
  return list;
}

int size(DLList *theList)
{
  int size = theList->size;

  return size;
}

//
// int push(DLList * theList, int newData)
// {
//   struct node_t *newNode = (struct node_t *)malloc(sizeof(struct node_t));

// // Make a new node that stores the data
// // If you are pushing into an empty list, store the data into the *first node
// // If there is only one element in the list, set the first->next to the current node
// // Store new data in the new node
// // Update the list's previous
// // New list
// // null <- 1 -> null - size = 1
// // 1 <- 3 -> null - size = 2
// // 3 <- 5 -> null - size = 3

//   if (newNode == 0)
//   {
//     return -1;
//   }

//   // If the size is 0, initialise the data to the first
//   if(theList->first == 0)
//   {
//     // setting both first and current to the same values
//     theList->first->data = newData;
//     theList->first->previous = 0;
//     theList->first->next = 0;
//   }

//       // null <- 3 -> null
//     newNode->data = newData;
//       //1 <- 3 -> 
//     newNode->previous = theList->current;
//       //1 <- 3 -> null
//     newNode->next = 0;

//   // if its 1, set the firsts next to the new node
//   if(theList->size == 1)
//   {
//      theList->first->next = newNode;
//   }

//     theList->current = newNode; // setting the current list to the new node
//     // This includes previous, next and data (i think thats how it works)

//       theList->size++; // increasing the size
//     return theList->size;

// }
int push(DLList * theList, int newData) 
{
    struct node_t* newNode = (struct node_t*) malloc(sizeof(struct node_t));
    newNode->data = newData;
    newNode->next = theList->first;
    newNode->previous = NULL;

    if (theList->first != NULL) 
    {
        theList->first->previous = newNode;
    }

    theList->first = newNode;
    theList->current = newNode;
    theList->size += 1;

    return theList->size;
}

int pop(DLList* theList)
{
    if (theList->size == 0) 
    {
        return -1;
    }
    
    // Current points to the last node.
    struct node_t* firstNode = theList->first; 

    theList->first = theList->first->next;
    theList->current = theList->first;
    
    int data = firstNode->data;
    free(firstNode); // Free the memory of the popped node.
    theList->size--;

    return data; // Return the data from the popped node.
}

int getCurrent(DLList* theList)
{
  // check if theres nothing in the list then return -1
    if (theList->size == 0){return -1;}
    int data = theList->current->data;
    return data;
}
void first(DLList* theList) 
{
    theList->current = theList->first;
}

void next(DLList *theList) 
{
    if (theList->current->next != NULL)
    {
        theList->current = theList->current->next;
    }
}

bool atEnd(DLList *theList)
{
  if(theList->current != NULL)
  {
    return (NULL == theList->current->next);
  }
  else
  {
    return false;
  }
}

int deleteCurrent(DLList* theList) 
{
    if (theList->current == NULL)
    {
        return theList->size;
    }

    if (theList->current->previous != NULL) 
    {
        theList->current->previous->next = theList->current->next;
    }
    else 
    {
        theList->first = theList->current->next;
    }

    if (theList->current->next != NULL) 
    {
        theList->current->next->previous = theList->current->previous;
    }

    struct node_t* temp = theList->current;
    theList->current = theList->current->next;
    free(temp);
    theList->size--;

    return theList->size;
}

void insertAfter(DLList* theList, int newData)
{
   // Create a new node with the given data.
    struct node_t* newNode = (struct node_t*)malloc(sizeof(struct node_t));
    if (newNode == 0) 
    {
        return;
    }
    newNode->data = newData;

    if (theList->size == 0 || theList->current == 0)
     {
        // If the list is empty or there's no current element, insert the new node as the first element.
        newNode->next = theList->first;
        newNode->previous = 0;
        theList->first = newNode;
    }
    else 
    {
        // Update pointers to insert the new node after the current element.
        newNode->next = theList->current->next;
        newNode->previous = theList->current;
        theList->current->next = newNode;
        if (newNode->next != 0) 
        {
            newNode->next->previous = newNode;
        }
    }

    // Update the current pointer to point to the newly inserted node.
    theList->current = newNode;
    theList->size++;
}

void insertBefore(DLList* theList, int newData)
{
// Create a new node with the given data.
    struct node_t* newNode = (struct node_t*)malloc(sizeof(struct node_t));

    if (newNode == 0) 
    {
        return;
    }
    newNode->data = newData;

    if (theList->size == 0 || theList->current == 0) 
    {
        // If the list is empty or there's no current element, insert the new node as the first element.
        newNode->next = 0;
        newNode->previous = 0;
        theList->first = newNode;
        theList->current = newNode;
    } 
    else 
    {
        // 1 - 2 - 3
        // 2 is current
        // 1 - new - 2 - 3
        newNode->previous = theList->current->previous; 
        theList->current->previous = newNode;
        newNode->next = theList->current;

        if (newNode->previous != 0) 
        {
            newNode->previous->next = newNode;
        } 
        else 
        {
            // If the current element is at the beginning, update the 'first' pointer.
            theList->first = newNode;
        }
    }

    theList->size++;
}

void printList(DLList* theList)
{
   struct node_t* current = theList->first;

    while (current != 0) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

/* listmain.c ends here */
