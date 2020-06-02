int main(void)
{
    int a;
	float b;
	char c;

	printf("Address of a: %p\n", &a);
	printf("Address of b: %p\n", &b);
	printf("Address of c: %p\n", &c);

	printf("Enter the first value:");
    scanf("%d", &a);
    printf("Enter the second value:");
    scanf("%d", &b);
    c = a + b;
    printf("%d + %d = %d\n", a, b, c);

    printf("\nsize of char pointer: %d"     ,sizeof(char*));
    printf("\nsize of int pointer: %d"      ,sizeof(int*));
    printf("\nsize of float pointer: %d"    ,sizeof(float*));
    printf("\nsize of long int pointer: %d" ,sizeof(long int*));
    printf("\nsize of double pointer: %d\n" ,sizeof(double*));
    return 0;
}
