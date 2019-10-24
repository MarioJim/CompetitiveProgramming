#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdbool.h>

int numPeople;
int sizeMemoArr;

struct R { int p1, p2, p3; };

struct R* R_new() {
    struct R* r = malloc(sizeof(struct R));
    r->p1 = -1; r->p2 = -1; r->p3 = -1;
    return r;
}

struct R* R_newInts(int p1, int p2, int p3) {
    struct R* r = malloc(sizeof(struct R));
    r->p1 = p1; r->p2 = p2; r->p3 = p3;
    return r;
}

int R_size(const struct R* r) {
    if (r->p1 == -1) return 0;
    if (r->p2 == -1) return 1;
    if (r->p3 == -1) return 2;
    return 3;
}

void R_push(struct R* r, int num) {
    if (r->p1 == -1) { r->p1 = num; return; }
    if (r->p2 == -1) { r->p2 = num; return; }
    r->p3 = num;
}

struct ID { bool* _id; };

struct ID* ID_new() {
    struct ID* id = malloc(sizeof(struct ID));
    id->_id = malloc(numPeople * sizeof(bool));
    for (int i = 0; i < numPeople; ++i) id->_id[i] = false;
    return id;
}

struct ID* ID_newInt(int num) {
    struct ID* id = malloc(sizeof(struct ID));
    id->_id = malloc(numPeople * sizeof(bool));
    for (int i = 0; i < numPeople; ++i) {
        id->_id[i] = num & 1;
        num /= 2;
    }
    return id;
}

void ID_turnBitOn(struct ID* id, int bitPos) {
    id->_id[bitPos] = true;
}

bool ID_bitIsOn(struct ID* id, int bitPos) {
    return id->_id[bitPos];
}

int ID_getIntRepresentation(struct ID* id) {
    int result = 0;
    for (int i = 0; i < numPeople; i++) {
        result |= id->_id[i] << i;
    }
    return result;
}

struct ID* ID_getMaxIntRepresentation() {
    struct ID* id = ID_new();
    for (int i = 0; i < numPeople; ++i) id->_id[i] = true;
    return id;
}

void ID_print(struct ID* id) {
    printf("%d %d %d %d\n", id->_id[0], id->_id[1], id->_id[2], id->_id[3]);
}

struct Point { double x, y; };

struct Point* Point_new() {
    struct Point* p = malloc(sizeof(struct Point));
    p->x = 0; p->y = 0;
    return p;
}

struct Point* Point_new2Doubles(double x, double y) {
    struct Point* p = malloc(sizeof(struct Point));
    p->x = x; p->y = y;
    return p;
}

struct Point* Point_substract(struct Point* p1, struct Point* p2) {
    struct Point* p = malloc(sizeof(struct Point));
    p->x = p1->x - p2->x; p->y = p1->y - p2->y;
    return p;
}

struct Point* peopleCoords;

struct Circle { struct Point* c; double r; };

struct Circle* Circle_new() {
    struct Circle* c = malloc(sizeof(struct Circle));
    c->c = Point_new(); c->r = 0;
    return c;
}

struct Circle* Circle_new1Int(int p) {
    struct Circle* c = malloc(sizeof(struct Circle));
    c->c = Point_new2Doubles(peopleCoords[p].x, peopleCoords[p].y);
    c->r = 0;
    return c;
}

struct Circle* Circle_new2Int(int p1, int p2) {
    struct Circle* c = malloc(sizeof(struct Circle));
    c->c = Point_new2Doubles(
            (peopleCoords[p1].x + peopleCoords[p2].x) / 2.0,
            (peopleCoords[p1].y + peopleCoords[p2].y) / 2.0);
    c->r = hypot(peopleCoords[p1].x - c->c->x, peopleCoords[p1].y - c->c->y);
    return c;
}

struct Circle* Circle_new3Int(int p1, int p2, int p3) {
    struct Circle* c = malloc(sizeof(struct Circle));
    // https://en.wikipedia.org/wiki/Circumscribed_circle#Circumcenter_coordinates
    struct Point* p2tr = Point_substract(peopleCoords + p2, peopleCoords + p1);
    struct Point* p3tr = Point_substract(peopleCoords + p3, peopleCoords + p1);
    double dTrans = 2 * (p2tr->x * p3tr->y - p2tr->y * p3tr->x);
    double xTrans = (p3tr->y * (p2tr->x * p2tr->x + p2tr->y * p2tr->y)
            - p2tr->y * (p3tr->x * p3tr->x + p3tr->y * p3tr->y)) / dTrans;
    double yTrans = (p2tr->x * (p3tr->x * p3tr->x + p3tr->y * p3tr->y)
            - p3tr->x * (p2tr->x * p2tr->x + p2tr->y * p2tr->y)) / dTrans;
    c->c = Point_new2Doubles(xTrans + peopleCoords[p1].x, yTrans + peopleCoords[p1].y);
    c->r = hypot(xTrans, yTrans);
    free(p2tr); free(p3tr);
    return c;
}

struct Circle* Circle_newInts(struct R* R) {
    switch (R_size(R)) {
        case 1: return Circle_new1Int(R->p1);
        case 2: return Circle_new2Int(R->p1, R->p2);
        case 3: return Circle_new3Int(R->p1, R->p2, R->p3);
        default: return Circle_new();
    }
}

bool Circle_includes(struct Circle* c, int point) {
    if (peopleCoords[point].x == c->c->x && peopleCoords[point].y == c->c->y) return true;
    return hypot(peopleCoords[point].x - c->c->x, peopleCoords[point].y - c->c->y) <= c->r * (1 + 1e-14);
}

// https://en.wikipedia.org/wiki/Smallest-circle_problem#Matou%C5%A1ek,_Sharir,_Welzl's_algorithm
struct Circle* msw(struct ID* id) {
//    printf("Entered msw with id: ");
//    ID_print(id);
    // R is the set of points that defines the circle
    struct R *R = R_new(), *newR;
    struct Circle* circleR = Circle_new();
    for (int i = 0; i < numPeople; ++i) {
        if (!ID_bitIsOn(id, i)) continue;
        if (Circle_includes(circleR, i)) continue;
        if (R_size(R) <= 1) {
            R_push(R, i);
            free(circleR); circleR = Circle_newInts(R);
            continue;
        }
        newR = R_new();
        double minRadius = DBL_MAX;
        struct Circle* c1p = Circle_new2Int(R->p1, i);
        struct Circle* c2p = Circle_new2Int(R->p2, i);
        struct Circle* c12p = Circle_new3Int(R->p1, R->p2, i);
        if (R_size(R) == 2) {
            if (Circle_includes(c1p, R->p2) && c1p->r < minRadius) { minRadius = c1p->r; free(newR); newR = R_newInts(R->p1, i, -1); }
            if (Circle_includes(c2p, R->p1) && c2p->r < minRadius) { minRadius = c2p->r; free(newR); newR = R_newInts(R->p2, i, -1); }
            if (c12p->r < minRadius) { free(newR); newR = R_newInts(R->p1, R->p2, i); }
            free(c1p); free(c2p); free(c12p);
            free(R); R = newR;
            free(circleR); circleR = Circle_newInts(R);
            continue;
        }
        struct Circle* c3p = Circle_new2Int(R->p3, i);
        struct Circle* c23p = Circle_new3Int(R->p2, R->p3, i);
        struct Circle* c13p = Circle_new3Int(R->p1, R->p3, i);
        if (Circle_includes(c1p, R->p2) && Circle_includes(c1p, R->p3) && c1p->r < minRadius) { minRadius = c1p->r; free(newR); newR = R_newInts(R->p1, i, -1); }
        if (Circle_includes(c2p, R->p1) && Circle_includes(c2p, R->p3) && c2p->r < minRadius) { minRadius = c2p->r; free(newR); newR = R_newInts(R->p2, i, -1); }
        if (Circle_includes(c3p, R->p1) && Circle_includes(c3p, R->p2) && c3p->r < minRadius) { minRadius = c3p->r; free(newR); newR = R_newInts(R->p3, i, -1); }
        if (Circle_includes(c12p, R->p3) && c12p->r < minRadius) { minRadius = c12p->r; free(newR); newR = R_newInts(R->p1, R->p2, i); }
        if (Circle_includes(c13p, R->p2) && c13p->r < minRadius) { minRadius = c13p->r; free(newR); newR = R_newInts(R->p1, R->p3, i); }
        if (Circle_includes(c23p, R->p1) && c23p->r < minRadius) { free(newR); newR = R_newInts(R->p2, R->p3, i); }
        free(c1p); free(c2p); free(c3p); free(c12p); free(c13p); free(c23p);
        free(R); R = newR;
        free(circleR); circleR = Circle_newInts(R);
    }
    free(R); // Also frees newR because both point to the same address
    return circleR;
}

int main() {
    int sizeX, sizeY;
    scanf("%d %d %d", &sizeX, &sizeY, &numPeople);
    // Save points
    peopleCoords = malloc(numPeople * sizeof(struct Point));
    for (int i = 0; i < numPeople; ++i) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        peopleCoords[i] = *Point_new2Doubles(x, y);
    }
    struct Circle* maxCircle = msw(ID_getMaxIntRepresentation());
    int* orderByDistToCenter = malloc(numPeople * sizeof(int));
    for (int i = 0; i < numPeople - 1; ++i)
        for (int j = 0; j < numPeople - i - 1; ++j)
            if (orderByDistToCenter[j] > orderByDistToCenter[j+1]) {
                int temp = orderByDistToCenter[j];
                orderByDistToCenter[j] = orderByDistToCenter[j+1];
                orderByDistToCenter[j+1] = temp;
            }
    free(maxCircle);
    // Receive queries
    int numQueries;
    scanf("%d", &numQueries);
    for (int i = 0; i < numQueries; ++i) {
        int numPeopleInQuery;
        scanf("%d", &numPeopleInQuery);
        struct ID* id = ID_new();
        for (int j = 0; j < numPeopleInQuery; ++j) {
            int personIndex;
            scanf("%d", &personIndex);
            ID_turnBitOn(id, personIndex - 1);
        }
        struct Circle* circle = msw(id);
        free(id);
        printf("%.9f\n", circle->r);
        free(circle);
    }
    free(peopleCoords);
    return 0;
}
