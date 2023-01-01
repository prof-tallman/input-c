#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("What is your favorite ice cream? ");

    // Read user input into the buffer
    char buffer[16];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        printf("Error: cannot read from stdin %s:%d\n", __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    // Remove the trailing newline character by replacing it with NULL
    // Thanks to Tim Cas for highlighting the strcspn function
    // https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
    int index = strcspn(buffer, "\n");
    buffer[index] = '\0';

    // Output the result
    printf("I like '%s' too!\n", buffer);

    return EXIT_SUCCESS;
}
