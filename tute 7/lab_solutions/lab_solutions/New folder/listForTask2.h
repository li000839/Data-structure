/* * * * * * *
 * Module for creating and manipulating singly-linked lists of integers
 *
 * created for COMP20007 Design of Algorithms 2017
 * by Matt Farrugia <matt.farrugia@unimelb.edu.au>
 *
 * list_contains(), ListIterator created for COMP20007 2019 Workshop 4
 * by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

// 'include guards': these lines (and #endif at the bottom) prevent this file
// from being included multiple times. multiple inclusion can cause errors on
// some compilers, especially if the included file contains struct definitions
// how it works: https://en.wikipedia.org/wiki/Include_guard
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct listForTask2 ListForTask2;

typedef struct list_iterator ListIterator;

// create a new list and return its pointer
ListForTask2 *new_list();

// destroy a list and free its memory
void free_list(ListForTask2 *list);

// add an element to the front of a list
// this operation is O(1)
void list_add_start(ListForTask2 *list, int data);

// add an element to the back of a list
// this operation is O(1)
void list_add_end(ListForTask2 *list, int data);

// remove and return the front data element from a list
// this operation is O(1)
// error if the list is empty (so first ensure list_size() > 0)
int list_remove_start(ListForTask2 *list);

// remove and return the final data element in a list
// this operation is O(n), where n is the number of elements in the list
// error if the list is empty (so first ensure list_size() > 0)
int list_remove_end(ListForTask2 *list);

// return the number of elements contained in a list
int list_size(ListForTask2 *list);

// returns whether the list contains no elements (true) or some elements (false)
bool list_is_empty(ListForTask2 *list);

// returns whether the list contains the specified element.
// this operation is O(n)
bool list_contains(ListForTask2 *list, int element);

// returns a new iterator
ListIterator *new_list_iterator(ListForTask2 *list);

// frees the list iterator
void free_list_iterator(ListIterator *iterator);

// whether or not there are elements remaining to be iterated through
bool list_iterator_has_next(ListIterator *iterator);

// get's the next element in the list
int list_iterator_next(ListIterator *iterator);

#endif
