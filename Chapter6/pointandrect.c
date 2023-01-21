#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

void printpoint(struct point p);
struct point makepoint(int x, int y);
struct point addpoints(struct point a, struct point b);
int isinrect(struct point p, struct rect r);
struct rect canonrect(struct rect r);

int main()
{
    struct point p = makepoint(10, 10);
    struct point p2 = makepoint(11, 12);
    struct point p3 = addpoints(p, p2);

    printpoint(p);
    printf(" + ");
    printpoint(p2);
    printf(" = ");
    printpoint(p3);
    printf("\n");

    struct point *ptr = &p;

    printf("(%d, %d)", ptr->x, ptr->y);

    return 0;
}

void printpoint(struct point p)
{
    printf("(%d, %d)", p.x, p.y);
}

struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoints(struct point a, struct point b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

int isinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);

    return temp;
}
