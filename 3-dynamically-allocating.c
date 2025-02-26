// In this example, when the user runs the program they have to specify how big they want the allocation to be.
// The allocation is going to store integers
// So you'd run it like this:
//   ./program-name 5
// Thusly it allocates space for 5 integers: 32-bits/4-bytes each.

#include <stdio.h>
#include <stdlib.h>

// Define a struct to manage dynamic memory
struct list {
    int *data;    // Pointer to dynamically allocated memory
    int numItems; // Number of items stored
    int size;     // Current allocated capacity
};

// Function to add an item to the list, resizing if necessary
void addToList(struct list *myList, int item) {
    if (myList->numItems == myList->size) {
        myList->size *= 2; // Double the capacity
        myList->data = (int *)realloc(myList->data, myList->size * sizeof(int));

        if (myList->data == NULL) {
            printf("Memory reallocation failed\n");
            exit(1);
        }
    }

    myList->data[myList->numItems] = item;
    myList->numItems++;
}

//"plumbing" is added to our main function so we can get a parameter passed from the command line
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number_of_elements>\n", argv[0]);
        return 1;
    }

    // based on how many elements the user wants, we set up the memory allocation
    // even though this isn't a C array - it is being used like one, so we call it "array"
    struct list myList;

    myList.numItems = 0;
    myList.size = atoi(argv[1]);
    myList.data = (int *)malloc(myList.size * sizeof(int));

    if (myList.data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Keep entering numbers enter -1 to stop:\n");

    // Now the user enters the data, type in a number, hit return/enter, enter another until done.
    while (1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == -1)
            break;

        addToList(&myList, num); // Stores the number in the array
    }

    // Then print out what was entered.
    printf("Numbers in the array:\n");
    for (int i = 0; i < myList.numItems; i++) {
        printf("%d ", myList.data[i]);
    }
    printf("\n");

    // Free up memory at the end. Allocated memory isn't automatically freed up by the OS like a C array.
    free(myList.data);
    return 0;
}

/* 

WHAT TO DO:

MODIFY THIS CODE

Continue to prompt the user for the number of elements.  This will be the "starting size" of the allocated memory

Replace the FOR loop for entering numbers into the array with a never ending WHILE loop.

Continuously prompt the user to enter more numbers. 

Continuously check to see how big the array is getting.

For example, the user specified to start with 5 items in the allocated memory.

They've now entered 5 items and want to add a 6th.

We now need to resize and move the array.   

What do we need to do?

Research and come up with a solution.

Use the guide and examples at W3SCHOOLS. It has a good example of using reallocate.

Another good example is in file 7-managing-allocation-with-struct.case

You don't need to write code like that example, but look at how they do it in the "addToList" function.

Indeed you can see what CoPilot says (I would prefer you use CoPilot) to.

But you must understand why the solution works. Don't copy/paste.

Write a short paragraph about your approach and why is solves the problem.

Modify the code with your approach/code and make it work.

*/