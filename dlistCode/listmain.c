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

int main(void)
{
  DLList* myList;
  return 0;
}

int size(DLList *theList)
{
  int size = theList->size;

  return size;
}

//
int push(DLList * theList, int newData)
{
  struct node_t *newNode = (struct node_t *)malloc(sizeof(struct node_t));

// Make a new node that stores the data
// If you are pushing into an empty list, store the data into the *first node
// If there is only one element in the list, set the first->next to the current node
// Store new data in the new node
// Update the list's previous
// New list
// null <- 1 -> null - size = 1
// 1 <- 3 -> null - size = 2
// 3 <- 5 -> null - size = 3

  if (newNode == 0)
  {
    return 0;
  }

  // If the size is 0, initialise the data to the first
  if(theList->first == 0)
  {
    // setting both first and current to the same values
    theList->first->data = newData;
    theList->first->previous = 0;
    theList->first->next = 0;
  }

      // null <- 3 -> null
    newNode->data = newData;
      //1 <- 3 -> 
    newNode->previous = theList->current;
      //1 <- 3 -> null
    newNode->next = 0;

  // if its 1, set the firsts next to the new node
  if(theList->size == 1)
  {
     theList->first->next = newNode->data;
  }

    theList->current = newNode; // setting the current list to the new node
    // This includes previous, next and data (i think thats how it works)

    theList->size++; // increasing the size

}
int pop(DLList* theList)
{

}
int getCurrent(DLList* theList)
{
  
}
void first(DLList* theList)
{
  
}
void next(DLList *theList)
{
  
}
bool atEnd(DLList *theList)
{
  
}
int deleteCurrent(DLList* theList)
{
  
}
void insertAfter(DLList* theList, int newData)
{
  
}
void insertBefore(DLList* theList, int newData)
{

}

void printList(DLList* theList)
{
  
}

/* listmain.c ends here */
