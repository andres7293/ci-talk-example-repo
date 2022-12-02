#include <iostream>
#include "LinkedList.H"
using namespace std;

class Point {
    public:
        Point(float x, float y): x(x), y(y) {};
        float getX() { return this->x; }
        float getY() { return this->y; }
    private:
        float x, y;
};

int main(void) { 
    LinkedList<Point> point_list;
    for (int i = 0; i < 1000; i++) {
        float coordinate = static_cast<float>(i);
        auto point = Point{coordinate, coordinate};
        point_list.add(point);
    }

    auto print_points = [](Point p) {
        std::cout << "Point{"
            << "x=" << p.getX()
            << ","
            << "y=" << p.getY()
            << "}"
            << std::endl;
    };

    point_list.iterate(print_points);
}
