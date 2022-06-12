/**
 * @file stackC.h
 * @author Hidekela (rhidekela@gmail.com)
 * @brief Stack manager library in C
 * 
 *                                      MIT LICENSE
 *
 *      Permission is hereby granted, free of charge, to any person obtaining a copy
 *      of this software and associated documentation files (the "Software"), to deal
 *      in the Software without restriction, including without limitation the rights
 *      to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *      copies of the Software, and to permit persons to whom the Software is
 *      furnished to do so, subject to the following conditions:
 * 
 *      The above copyright notice and this permission notice shall be included in
 *      all copies or substantial portions of the Software.
 * 
 *      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *      IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *      FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *      AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *      LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *      OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *      THE SOFTWARE.
 * 
 * 
 * @version 1.0
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdbool.h>

typedef struct _Cell Cell;
struct _Cell
{
    void *data;
    Cell *next;
};

typedef struct _Stack Stack;
struct _Stack
{
    Cell *current;
    bool isDynamicallyAllocated;
    bool dataManagement; // True if this lib should manage the allocation of the data
    /* Add another properties: length, etc... */
};

/**
 * @brief Check the existence of a stack
 * 
 * @param stack the stack
 * @return true if exist
 * @return false 
 */
bool stack_exist(Stack *stack);

/**
 * @brief Init the stack
 * 
 * @param stack the stack
 * @return Stack* a pointer to the stack (needed if you want to allocate the stack dynamically,
 *  and if it is, then you must quit the stack by stack_quit() in order to free it in the end)
 */
Stack* stack_init(Stack *stack);

/**
 * @brief Check if the stack doesn't contain anything
 * 
 * @param stack the stack
 * @return true if the stack is empty
 * @return false 
 */
bool stack_isEmpty(Stack *stack);

/**
 * @brief Destroy the stack
 * 
 * @param stack the stack
 * @return Stack* NULL (needed if you allocated dynamically the stack and want
 *  to secure the pointer to the stack)
 */
Stack* stack_quit(Stack *stack);

/**
 * @brief Delete the first element of the stack. Warning! If you have used stack_createData() and 
 *  the type of your data structure contain dynamically allocated variables, free those variables
 *  before using this function
 * 
 * @param stack the stack
 */
void stack_pop(Stack *stack);

/**
 * @brief Add an element in the first of the stack. The data of element must be already
 *  dynamically allocated (by stack_createData() or malloc()) and filled by yourself.
 *  Note that if you don't manage yourself the data allocation and freeing, you must use
 *  stack_createData() in order to tell the library to manage it (allocation and freeing).
 *  You can create a new function of push costumized in your need for creation of data
 *  (allocation), add of the data items (fill properties) and call stack_pushData() in the end.
 * 
 *  For example: 
 *      bool stack_push(Stack *stack, int age, const char *name) 
 *  where data is an instance of a structure containing 'age' and 'name': 
 *      struct{int age, char name[20]}
 * 
 * @param stack the stack
 * @param data the data of the new element
 * @return true if the operation succeed
 * @return false 
 */
bool stack_pushData(Stack *stack, void *data);

/**
 * @brief Allocate (dynamically) memory spaces for a new data. Warning! If you manage yourself the allocation
 *   and freeing of the data, so never use this function for the concerned stack.
 * 
 * @param stack the stack
 * @param sizeofDataType the size of the data type
 * @param numberofData the number of data (length of the array if it is an array, 1 otherwise)
 * @return void* pointer of the new data
 */
void* stack_createData(Stack *stack, size_t sizeofDataType, unsigned int numberofData);

/**
 * @brief Return the first element of the stack
 * 
 * @param stack the stack
 * @return void* the pointer to the first data
 */
void* stack_getFirst(Stack *stack);

#endif // STACK_H_INCLUDED
