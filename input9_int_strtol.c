#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


// macro to print the filename and line number for each error message
#define debug(msg) fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, msg);


int main()
{
    printf("What is your favorite number? ");

    // Read user input into the buffer and trim the trailing newline
    char buffer[16];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        debug("Cannot read from stdin");
        return EXIT_FAILURE;
    }
    int index = strcspn(buffer, "\n");
    buffer[index] = '\0';

    // Convert the input buffer to a number
    char* nextPtr = NULL;
    long lnumber = strtol(buffer, &nextPtr, 10);
    if (buffer[0] == '\0' || // input was empty
        nextPtr == buffer || // invalid number
        nextPtr[0] != '\0')  // contained more than a number
    {
        debug("Input was not a number");
        return EXIT_FAILURE;
    }
    else if (lnumber > INT_MAX || lnumber < INT_MIN)
    {
        debug("Input was too large to store as an integer");
        return EXIT_FAILURE;
    }
    int number = (int)lnumber;

    // Output the result
    if (number == 3)
    {
        printf("I like %d too!\n", number);
    }
    else
    {
        printf("Well, I suppose %d is a reasonable choice\n", number);
    }

    return EXIT_SUCCESS;
}
