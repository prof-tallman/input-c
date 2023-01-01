#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("What is your favorite ice cream? ");

    // Read user input into the buffer
    char buffer[16];
    if (scanf("%s", buffer) != 1)
    {
        printf("Error: cannot read from stdin %s:%d\n", __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    // Output the result (oops--a long input crashes the program)
    printf("I like '%s' too!\n", buffer);

    return EXIT_SUCCESS;
}
