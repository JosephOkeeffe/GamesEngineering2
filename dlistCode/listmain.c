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

/*******************************************************************************
 * @param N Creating a DLList
 * @return returns the list               
 ******************************************************************************/
DLList* createDLList()
{
  DLList* list = (DLList*)malloc(sizeof(DLList));
  list->first = NULL;
  list->current = NULL;
  list->size = 0;
  return list;
}

/*******************************************************************************
 * @param N Creating a function that checks the size of the list
 * @return returns the size of the list             
 ******************************************************************************/
int size(DLList *theList)
{
  int size = theList->size;

  return size;
}

/*******************************************************************************
 * @param N Creating a function that pushes a new item to the front of the list
 * @return returns the size of the list               
 ******************************************************************************/
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

/*******************************************************************************
 * @param N Creating a function that removes the first item in the list
 * @return returns the data of the list               
 ******************************************************************************/
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

/*******************************************************************************
 * @param N Creating a function that returns the current item in the list
 * @return returns the data from the list             
 ******************************************************************************/
int getCurrent(DLList* theList)
{
  // check if theres nothing in the list then return -1
    if (theList->size == 0){return -1;}
    int data = theList->current->data;
    return data;
}
/*******************************************************************************
 * @param N Creating a function that changes the current to the first item in the list
 * @return returns nothing              
 ******************************************************************************/
void first(DLList* theList) 
{
    theList->current = theList->first;
}

/*******************************************************************************
 * @param N Creating a function that changes the current to the next item in the list
 * @return returns nothing              
 ******************************************************************************/
void next(DLList *theList) 
{
    if (theList->current->next != NULL)
    {
        theList->current = theList->current->next;
    }
}

/*******************************************************************************
 * @param N Creating a function that checks to see if you are at the end of the list
 * @return returns true or false              
 ******************************************************************************/
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

/*******************************************************************************
 * @param N Creating a function that deletes the current item in the list
 * @return returns size of the list              
 ******************************************************************************/
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

/*******************************************************************************
 * @param N Creating a function that inserts an item after the current item in the list
 * @return returns nothing             
 ******************************************************************************/
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

/*******************************************************************************
 * @param N Creating a function that inserts an item before the current item in the list
 * @return returns nothing             
 ******************************************************************************/
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

/*******************************************************************************
 * @param N Creating a function that displays all the items in the list
 * @return returns nothing             
 ******************************************************************************/
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
