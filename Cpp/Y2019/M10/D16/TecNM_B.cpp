#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cfloat>
using namespace std;

typedef pair<int, int> pii;

class Circle {
public:
    double x, y, r;
    Circle() : x(0), y(0), r(0) {}
    Circle(pii p) : x(p.first), y(p.second), r(0) {}
    Circle(pii p1, pii p2) :
        x((p1.first + p2.first) / 2.0), y((p1.second + p2.second) / 2.0) {
        r = hypot(p1.first - x, p1.second - y);
    }
    Circle(pii p1, pii p2, pii p3) {
        // https://en.wikipedia.org/wiki/Circumscribed_circle#Circumcenter_coordinates
        pii p2trans = {p2.first - p1.first, p2.second - p1.second};
        pii p3trans = {p3.first - p1.first, p3.second - p1.second};
        double dTrans = 2 * (p2trans.first * p3trans.second - p2trans.second * p3trans.first);
        double xTrans = (p3trans.second * (p2trans.first * p2trans.first + p2trans.second * p2trans.second)
                - p2trans.second * (p3trans.first * p3trans.first + p3trans.second * p3trans.second)) / dTrans;
        double yTrans = (p2trans.first * (p3trans.first * p3trans.first + p3trans.second * p3trans.second)
                - p3trans.first * (p2trans.first * p2trans.first + p2trans.second * p2trans.second)) / dTrans;
        r = hypot(xTrans, yTrans);
        x = xTrans + p1.first;
        y = yTrans + p1.second;
    }
    static Circle fromPointsVector(vector<pii> &points) {
        switch (points.size()) {
            case 1: return Circle(points[0]);
            case 2: return Circle(points[0], points[1]);
            case 3: return Circle(points[0], points[1], points[2]);
            default: return Circle();
        }
    }
    bool includes(const pii &point) {
        if (point.first == x && point.second == y) return true;
        return hypot(point.first - x, point.second - y) <= r * (1 + 1e-14);
    }
    friend ostream &operator<<(ostream &out, const Circle &c) {
        out << "Circle { x: " << c.x << ", y: " << c.y << ", r: " << c.r << " } ";
        return out;
    }
};
// https://en.wikipedia.org/wiki/Smallest-circle_problem#Matou%C5%A1ek,_Sharir,_Welzl's_algorithm
Circle msw(vector<pii> P, vector<pii> R) {
    if (P.empty())
        return Circle::fromPointsVector(R);
    pii p = P.back();
    P.pop_back();
    if (Circle::fromPointsVector(R).includes(p))
        return msw(P, R);
    if (R.size() <= 1) {
        R.push_back(p);
        return msw(P, R);
    }
    vector<pii> newR = R;
    double minRadius = DBL_MAX;
    Circle c1p(R[0], p);
    Circle c2p(R[1], p);
    Circle c12p(R[0], R[1], p);
    if (R.size() == 2) {
        if (c1p.includes(R[1]) && c1p.r < minRadius) {
            minRadius = c1p.r;
            newR = { R[0], p };
        }
        if (c2p.includes(R[0]) && c2p.r < minRadius) {
            minRadius = c2p.r;
            newR = { R[1], p };
        }
        if (c12p.r < minRadius) {
            newR = { R[0], R[1], p };
        }
    } else {
        if (c1p.includes(R[1]) && c1p.includes(R[2]) && c1p.r < minRadius) {
            minRadius = c1p.r;
            newR = { R[0], p };
        }
        if (c2p.includes(R[0]) && c2p.includes(R[2]) && c2p.r < minRadius) {
            minRadius = c2p.r;
            newR = { R[1], p };
        }
        Circle c3p(R[2], p);
        if (c3p.includes(R[0]) && c3p.includes(R[1]) && c3p.r < minRadius) {
            minRadius = c3p.r;
            newR = { R[2], p };
        }
        if (c12p.includes(R[2]) && c12p.r < minRadius) {
            minRadius = c12p.r;
            newR = { R[0], R[1], p };
        }
        Circle c23p(R[1], R[2], p);
        if (c23p.includes(R[3]) && c23p.r < minRadius) {
            minRadius = c23p.r;
            newR = { R[1], R[2], p };
        }
        Circle c13p(R[0], R[2], p);
        if (c13p.includes(R[1]) && c23p.r < minRadius) {
            newR = { R[0], R[2], p };
        }
    }
    return msw(P, newR);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int sizeX, sizeY, people;
    cin >> sizeX >> sizeY >> people;
    vector<pii> peopleCoords;
    for (int i = 0; i < people; ++i) {
        int coordX, coordY;
        cin >> coordX >> coordY;
        peopleCoords.emplace_back(coordX, coordY);
    }
    int numQueries;
    cin >> numQueries;
    for (int i = 0; i < numQueries; ++i) {
        int numPeople;
        cin >> numPeople;
        vector<pii> peopleInQuery;
        for (int j = 0; j < numPeople; ++j) {
            int personIndex;
            cin >> personIndex;
            peopleInQuery.push_back(peopleCoords[personIndex - 1]);
        }
        cout << fixed << msw(peopleInQuery, {}).r << endl;
    }
    return 0;
}
