#include<iostream>
#include<cmath>
#include<iomanip>

static const double eps = 1e-9;

class Point{
    private:
        double x, y;
    public:
        Point() : x(0.0), y(0.0){};
        Point(double x_val, double y_val) : x(x_val), y(y_val){};

        ~Point(){};
        double getX()  const {return x;}
        double getY()  const {return y;}
    
        Point operator-(const Point &other) const{
            return Point(x - other.getX(), y - other.getY());
        }

        Point operator+(const Point &other) const{
            return Point(x + other.getX(), y + other.getY());
        }
        Point operator*(double t) const{
            return Point(x*t, y*t);
        }
};

double cross(const Point& a, Point& b){
    return a.getX()*b.getY() - a.getY() * b.getX();
}

class Line{
    private:
        Point p1, p2;
    public:
        Line(){};
        Line(const Point& A, const Point& B): p1(A), p2(B) {};
        ~Line(){};
        int intersect(const Line& other, Point& res) const {
            Point v1 = p1 - p2;
            Point v2 = other.p2 - other.p1;
            double demo = cross(v1, v2);
            if (std::fabs(demo) < eps){
                Point diff = other.p1 - p1;
                if (std::fabs(cross(diff, v2)) < eps){
                    return 1;
                } else {
                    return 0;
                } 
            }
            Point diff = other.p1 - p1;
            double t = cross(diff, v2)/demo;
            res = p1 + (v1 * t);
            return 2;
        }
        

};

int main() {
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    freopen("test.txt", "r", stdin);
    std::cin >> Ax >> Ay;
    std::cin >> Bx >> By;
    std::cin >> Cx >> Cy;
    std::cin >> Dx >> Dy;

    Point A(Ax, Ay), B(Bx, By), C(Cx, Cy), D(Dx, Dy);

    Line AB(A, B);
    Line CD(C, D);

    Point intersectPt;
    int code = AB.intersect(CD, intersectPt);

    if (code == 0) {
        std::cout << "NO" << std::endl;
    } else if (code == 1) {
        std::cout << "MANY" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(6)
                  << intersectPt.getX() << " "
                  << intersectPt.getY() << std::endl;
    }

    return 0;
}