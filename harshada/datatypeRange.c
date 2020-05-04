#include<stdio.h>
#include<limits.h>
#include<float.h>
int main() {
  printf("Range of unsigned charter:0 to %d\n", UCHAR_MAX );
  printf("Range of signed charter:%d to %d\n\n", SCHAR_MIN, SCHAR_MAX );

  printf("Range of unsigned short integer:0 to %d\n", USHRT_MAX );
  printf("Range of signed short integer:%d to %d\n\n", SHRT_MIN, SHRT_MAX );

  printf("Range of unsigned integer:0 to %lu\n", UINT_MAX );
  printf("Range of signed integer:%d to %d\n\n", INT_MIN, INT_MAX );

  printf("Range of unsigned long integer:0 to %lu\n", ULONG_MAX );
  printf("Range of signed long integer:%ld to %ld\n\n", LONG_MIN, LONG_MAX );

  printf("Range of float:%e to %e\n", FLT_MIN, FLT_MAX );
  printf("Range of double:%e to %e\n\n", DBL_MIN, DBL_MAX );

  printf("Pricision of float:%i\n", FLT_DIG);
  printf("Pricision of double:%i\n", DBL_DIG);
  printf("Pricision of long double:%i\n", LDBL_DIG);

  return 0;
}
