//c program to pointer operations

#include <stdio.h>
int 
main()
{    
    double x = 0.0;
    double *dblPtr;    //pointer to double 
    int i = 1;
    int *intPtr;       //pointer to int 
    int **intPtrPtr;   //pointer to pointer to int --- intPtrPtr hold the memory address of another pointer 
    
    dblPtr = &x;
    intPtr = &i;
    intPtrPtr = &intPtr;
    //values
    printf("\n\n-------- values");
    printf("\nvalue of double x = %lf", x);
    printf("\nvalue of double dblptr = %lf", *dblPtr);
    printf("\nvalue of int i = %d", i);
    printf("\nvalue of int intPtr = %d", *intPtr);
    printf("\nvalue of int intPtrPtr = %d", **intPtrPtr);
    //address
    printf("\n\n-------- Addresses");
    printf("\naddress of double x = %d", &x);
    printf("\naddress of double dblptr = %d", &dblPtr);
    printf("\naddress of int i = %d", &i);
    printf("\naddress of int intPtr = %d", &intPtr);
    printf("\naddress of int intPtrPtr = %d", &intPtrPtr);
    //sizeof
    printf("\n\n-------- Sizeof");
    printf("\nvalue of double x = %d", sizeof(x));
    printf("\nvalue of double dblptr = %d", sizeof(*dblPtr));
    printf("\nvalue of int i = %d", sizeof(i));
    printf("\nvalue of int intPtr = %d", sizeof(*intPtr));
    printf("\nvalue of int intPtrPtr = %d", sizeof(**intPtrPtr));
    printf("\n\n----------------------------");

    int offset;
    int *base;
    int A[8] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0 };

    offset = 0;
    base = &A[0];

    printf("\n\n<Variable>: <Value> @ <Address> : <Sizeof> \n\n");
    printf("offset: %d @ %d : %d\n", offset, &offset, sizeof(offset));
    printf("base: %d @ %d : %d\n", base, &base, sizeof(base));

    for (offset = 0; offset < 8; offset++) {
      printf("A[%d]: %d @ %d : %d\n", offset, *(base + offset), 
             base + offset, sizeof(*(base + offset)));
    }
    return 0;
}
