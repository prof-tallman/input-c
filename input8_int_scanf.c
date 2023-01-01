#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("What is your favorite number? ");

    // Read user input into the buffer
    int number;
    if (scanf("%d", &number) != 1)
    {
        printf("Error: cannot read from stdin %s:%d\n", __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

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
