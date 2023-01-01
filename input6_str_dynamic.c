#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console_util.h"

int main()
{
    printf("Please type a line of input: ");

    // We could create a variable or use a #define to set the maximum size
    int buffer_size = 128;

    // Allocate a buffer to store the user input
    char* buffer = malloc(buffer_size);
    if (buffer == NULL)
    {
        printf("Error: cannot allocate buffer %s:%d", __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    // Zero out the buffer to remove any stale data
    memset(buffer, 0, buffer_size);

    // Get the user input
    if (get_line_static(buffer, buffer_size) != EXIT_SUCCESS)
    {
        printf("Error: cannot read from stdin %s:%d\n", __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    printf("You entered '%s'\n", buffer);

    // Remember to free the allocateed buffer
    free(buffer);

    return EXIT_SUCCESS;
}
