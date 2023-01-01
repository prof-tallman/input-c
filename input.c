#include <stdio.h>
#include <stdlib.h>
#include "console_util.h"


int main()
{
    int rc = EXIT_FAILURE;

    // Read user input into the buffer and trims the trailing newline
    // Uses an allocated buffer from the heap
    printf("What is your favorite ice cream? ");
    char* buffer1 = NULL;
    size_t size1 = 0;
    rc = get_line_dynamic(&buffer1, &size1);
    if (rc == EXIT_FAILURE)
    {
        debug("get_line() failed")
        return EXIT_FAILURE;
    }

    // Read user input into the buffer and trims the trailing newline
    // Uses a local stack variable and fails if the buffer is too small
    printf("What is your favorite decimal number? ");
    char buffer2[16];
    int size2 = sizeof(buffer2);
    rc = get_line_static(buffer2, size2);
    if (rc == EXIT_FAILURE)
    {
        debug("get_line() failed")
        return EXIT_FAILURE;
    }

    // Convert the user input to an integer
    float number = 0;
    rc = to_float(buffer2, &number);
    if (rc == EXIT_FAILURE)
    {
        debug("to_float() failed");
        return EXIT_FAILURE;
    }

    // Output the result
    if (number == 3)
    {
        printf("I like '%s' and %f too!\n", buffer1, number);
    }
    else
    {
        printf("Well, I suppose %.3f and '%s' are nice\n", number, buffer1);
    }

    // Remember to free the buffer allocated by get_line_dynamic()
    free(buffer1);

    return EXIT_SUCCESS;
}
