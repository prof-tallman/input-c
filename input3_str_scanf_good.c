#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("What is your favorite ice cream? ");

    // Read user input into the buffer
    char buffer[16];
    if (scanf("%15s", buffer) != 1)
    {
        printf("Error: cannot read from stdin %s:%d\n", __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    // Output the result (this works, but be careful with more complex formats)
    printf("I like '%s' too!\n", buffer);

    return EXIT_SUCCESS;
}
