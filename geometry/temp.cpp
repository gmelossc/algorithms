#include <array>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>

#define T int
struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(const T&x, const T&y) : x(x), y(y) {} 

    void swap(Point& o) { std::swap(x, o.x); std::swap(y, o.y); }
    Point& operator = (const Point& other) { x = other.x; y = other.y; return *this; }    
    Point operator - (const Point& other) { x -= other.x; y -= other.y; return Point(x, y); }
    Point operator + (const Point& other) { x += other.x; y += other.y; return Point(x, y); }
    // Point operator > (const Point& a, Point& b) {}
};

Point build(const T& x, const T& y) { return Point(x, y); }
Point add(Point a, Point b) { return build(a.x+b.x, a.y+a.y); }
Point sub(Point a, Point b) { return build(a.x-b.x, a.y-b.y); }
Point mult(Point a, T s) { return build(a.x*s, a.y*s); }
Point div(Point a, T s) { return build(a.x/s, a.y/s); }
T dot(Point a, Point b) { return a.x*b.x  + a.y*b.y; }

// if positive, b points to opposite of vector direction a
// if negative, b points to vector direction a
// if equals 0, b is collinear with a
// cross is anti-symmetric so, a^b = -b^a
T cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
double anglePoint(Point a) { return atan2(a.y, a.x); }
double angleBetweenPoints(Point a, Point b) { return atan2(cross(a, b), dot(a, b)); }
double angleBetweenPointsToOrigin(Point a, Point b, Point org) {
    return angleBetweenPoints(a-org, b-org);
}

// counterclockwise rotation
Point rotate(Point p, double anglesin, double anglecos) {
    return build(anglecos*p.x - anglesin*p.y,
    anglesin*p.x + anglecos*p.y);
}
Point rotate(Point p, double angle) {
    return rotate(p, sin(angle), cos(angle));
}
T norm(Point a) {
    return sqrt(dot(a, a));
}
T dist(Point a, Point b) {
    return norm(a-b);
}