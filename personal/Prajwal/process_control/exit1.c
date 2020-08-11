#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void demo() {
    int exit_code = 10;
    printf("Hello...");
    _Exit(exit_code);
}
int
main()
{
    printf("Hello..");

    // int exit_code = 10;
    printf("Hello...");
    demo();
    // _Exit(exit_code);

    printf("Hello");

}
