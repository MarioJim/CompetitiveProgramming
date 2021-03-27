#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
using namespace std;

int numPeople;
double* memoization;
int sizeMemoArr;

class ID {
public:
    bool* _id;
    ID(): _id(new bool[numPeople]) {
        fill(_id, _id + numPeople, false);
    }
    explicit ID(int from): _id(new bool[numPeople]) {
        fill(_id, _id + numPeople, false);
        for (int i = 0; i < numPeople; ++i) {
            if (from & 1) turnBitOn(i);
            from /= 2;
        }
    }
    void turnBitOn(int bitPos) {
        _id[bitPos] = true;
    }
    int getIntRepresentation() {
        int result = 0;
        for (int i = 0; i < numPeople; i++) {
            result |= _id[i] << i;
        }
        return result;
    }
    static int getMaxIntRepresentation() {
        ID id;
        fill(id._id, id._id + numPeople, true);
        return id.getIntRepresentation() + 1;
    }
};

struct Point {
public:
    double x, y;
    Point(): x(0), y(0) {}
    Point(double x, double y): x(x), y(y) {}
    inline bool operator==(const Point &p) {
        return x == p.x && y == p.y;
    }
    inline Point operator-(const Point &p) {
        return { x - p.x, y - p.y };
    }
    friend ostream &operator<<(ostream &out, const Point &point) {
        out << "Point { x: " << point.x << ", y: " << point.y << " } ";
        return out;
    }
};

vector<Point> peopleCoords;

class Circle {
public:
    Point c;
    double r;
    Circle(): c(0,0), r(0) {}
    explicit Circle(int &p): c(peopleCoords[p]), r(0) {}
    Circle(int &p1, int &p2):
        c((peopleCoords[p1].x + peopleCoords[p2].x) / 2.0, (peopleCoords[p1].y + peopleCoords[p2].y) / 2.0) {
        r = hypot(peopleCoords[p1].x - c.x, peopleCoords[p1].y - c.y);
    }
    Circle(int &p1, int &p2, int &p3) {
        // https://en.wikipedia.org/wiki/Circumscribed_circle#Circumcenter_coordinates
        Point p2tr = peopleCoords[p2] - peopleCoords[p1], p3tr = peopleCoords[p3] - peopleCoords[p1];
        double dTrans = 2 * (p2tr.x * p3tr.y - p2tr.y * p3tr.x);
        double xTrans = (p3tr.y * (p2tr.x * p2tr.x + p2tr.y * p2tr.y)
                         - p2tr.y * (p3tr.x * p3tr.x + p3tr.y * p3tr.y)) / dTrans;
        double yTrans = (p2tr.x * (p3tr.x * p3tr.x + p3tr.y * p3tr.y)
                         - p3tr.x * (p2tr.x * p2tr.x + p2tr.y * p2tr.y)) / dTrans;
        r = hypot(xTrans, yTrans);
        c = Point(xTrans + peopleCoords[p1].x, yTrans + peopleCoords[p1].y);
    }
    static Circle fromPointsVector(vector<int> &points) {
        switch (points.size()) {
            case 1: return Circle(points[0]);
            case 2: return Circle(points[0], points[1]);
            case 3: return Circle(points[0], points[1], points[2]);
            default: return Circle();
        }
    }
    bool includes(int &point) {
        return hypot(peopleCoords[point].x - c.x, peopleCoords[point].y - c.y) <= r * (1 + 1e-14);
    }
    bool operator<(const Circle &circle) {
        return r < circle.r;
    }
    friend ostream &operator<<(ostream &out, const Circle &circle) {
        out << "Circle { x: " << circle.c.x << ", y: " << circle.c.y << ", r: " << circle.r << " } ";
        return out;
    }
};

// https://en.wikipedia.org/wiki/Smallest-circle_problem#Matou%C5%A1ek,_Sharir,_Welzl's_algorithm
void msw(const ID id) {
    vector<int> P;
    // Generate set of points from id
    for (int i = 0; i < numPeople; ++i)
        if (id._id[i]) P.push_back(i);
    int Psize = P.size();
    // R is the set of points that defines the circle
    vector<int> R, newR;
    Circle circleR;
    for (int i = 0; i < Psize; ++i) {
//        cout << circleR << endl;
        if (circleR.includes(P[i])) {
//            cout << "inside: P index: " << i << ", R size: " << R.size() << ", " << P[i] << endl;
            continue;
        }
        if (i == Psize) break;
//        cout << "P index: " << i << ", R size: " << R.size() << ", " << P[i] << endl;
        if (R.size() <= 1) {
            R.push_back(P[i]);
            circleR = Circle::fromPointsVector(R);
            continue;
        }
        auto minRadius = DBL_MAX;
        Circle c1p(R[0], P[i]);
        Circle c2p(R[1], P[i]);
        Circle c12p(R[0], R[1], P[i]);
        if (R.size() == 2) {
            if (c1p.includes(R[1]) && c1p.r < minRadius) { minRadius = c1p.r; newR = { R[0], P[i] }; }
            if (c2p.includes(R[0]) && c2p.r < minRadius) { minRadius = c2p.r; newR = { R[1], P[i] }; }
            if (c12p.r < minRadius) { newR = { R[0], R[1], P[i] }; }
            R = newR;
            circleR = Circle::fromPointsVector(R);
            continue;
        }
        Circle c3p(R[2], P[i]);
        Circle c23p(R[1], R[2], P[i]);
        Circle c13p(R[0], R[2], P[i]);
        if (c1p.includes(R[1]) && c1p.includes(R[2]) && c1p.r < minRadius) { minRadius = c1p.r; newR = { R[0], P[i] }; }
        if (c2p.includes(R[0]) && c2p.includes(R[2]) && c2p.r < minRadius) { minRadius = c2p.r; newR = { R[1], P[i] }; }
        if (c3p.includes(R[0]) && c3p.includes(R[1]) && c3p.r < minRadius) { minRadius = c3p.r; newR = { R[2], P[i] }; }
        if (c12p.includes(R[2]) && c12p.r < minRadius) { minRadius = c12p.r; newR = { R[0], R[1], P[i] }; }
        if (c13p.includes(R[1]) && c13p.r < minRadius) { minRadius = c13p.r; newR = { R[0], R[2], P[i] }; }
        if (c23p.includes(R[0]) && c23p.r < minRadius) { newR = { R[1], R[2], P[i] }; }
        R = newR;
        circleR = Circle::fromPointsVector(R);
    }
//    if (R.size() == 2) cout << R[0] << R[1] << endl;
//    else cout << R[0] << R[1] << R[2] << endl;
    double result = circleR.r;
    int Rsize = R.size();
    for (int i = 0; i < sizeMemoArr; ++i) {
        bool containsR = true;
        ID tempID = ID(i);
        for (int j = 0; j < Rsize; ++j)
            if (!tempID._id[R[j]])
                containsR = false;
        if (containsR)
            memoization[i] = max(memoization[i], result);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(9);

    int sizeX, sizeY;
    cin >> sizeX >> sizeY >> numPeople;
    sizeMemoArr = ID::getMaxIntRepresentation();
    // Make an array to store the results of every possible set of points
    memoization = new double[sizeMemoArr];
    // Pre-fill it with -1's
    fill(memoization, memoization + sizeMemoArr, -1);
    // Save points
    for (int i = 0; i < numPeople; ++i) {
        Point p;
        cin >> p.x >> p.y;
        peopleCoords.push_back(p);
    }
    // Pre-generate memoization array
    for (int i = sizeMemoArr; i > 0; --i)
        if (memoization[i] == -1)
            msw(ID(i));
    // Receive queries
    int numQueries;
    cin >> numQueries;
    for (int i = 0; i < numQueries; ++i) {
        int numPeopleInQuery;
        cin >> numPeopleInQuery;
        ID id;
        for (int j = 0; j < numPeopleInQuery; ++j) {
            int personIndex;
            cin >> personIndex;
            id.turnBitOn(personIndex - 1);
        }
        cout << fixed << memoization[id.getIntRepresentation()] << endl;
    }
    return 0;
}
