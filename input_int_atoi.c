#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define debug(msg) fprintf(stderr, "INFO %s:%d: %s\n", __FILE__, __LINE__, msg);

int main(int argc, char* argv[])
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
    int number = atoi(buffer);

    // Output the result (oops--if the number is large or a non-number!)
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
