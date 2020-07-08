#include <stdio.h>

//method 1
// struct point {
// 		int x;
// 		int y;
// };
//
// struct point p1;
// struct point p2;


// struct point {
// 		int x;
// 		int y;
// } p1, p2;
//
// struct {
// 		int x;
// 		int y;
// } p1, p2;
//
//

typedef struct point {
		int x;
		int y;
} point_t;

point_t p1, p2;

typedef struct rect {
		point_t p1;
		point_t p2;
} rect_t;

void
print_rec(rect_t *recp)
{
		//rect_t *recp = &rec;
		printf("recp %p p1 (%d, %d), p2 (%d, %d)\n",
						recp, recp->p1.x, recp->p1.y, recp->p2.x, recp->p2.y);
		printf("sizeof recp %ld size of *recp %ld\n", sizeof recp, sizeof(*recp));
}

void
main(int argc, char *argv[])
{

	rect_t rec1 = {{10, 20}, {200, 100}};
	// rect_t *rec2;
	//
	// rec2 = &rec1;

	rect_t rec2;

	rec2 = rec1;



	rec1.p1.x = 500;
	rec1.p1.y = 2000;


	print_rec(&rec1);
	print_rec(rec2);


	//rec1.p1.x, rec1,p2.y


}
