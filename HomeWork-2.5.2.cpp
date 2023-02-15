#include <iostream>
#include <string>

class Figure {
public:
    int get_sides_count() { return sides_count_; }
    std::string get_name() { return name_; }
    Figure() : Figure(0, "Фигура") {};
    virtual void print_sides_() = 0;
    virtual void print_angles_() = 0;
protected:
    Figure( const int &s_c, const std::string &n) : sides_count_(s_c), name_(n) {};
private:
    int sides_count_;
    std::string name_;
};

class Triangle : public Figure {
public:
    Triangle(const int& a, const int& b, const int& c, const int& A, const int& B, const int& C) :
        Triangle(a, b, c, A, B, C, 3, "Треугольник") {};
    int get_side_a() { return side_a_; }
    int get_side_b() { return side_b_; }
    int get_side_c() { return side_c_; }
    int get_angle_a() { return angle_a_; }
    int get_angle_b() { return angle_b_; }
    int get_angle_c() { return angle_c_; }
    void print_sides_() override;
    void print_angles_() override;
protected:
    Triangle(const int& a, const int& b, const int& c, const int& A, const int& B, const int& C, const int& s_c, const std::string& n) 
        : Figure(s_c, n), side_a_(a), side_b_(b), side_c_(c), angle_a_(A), angle_b_(B), angle_c_(C) {};
private:
    int side_a_;
    int side_b_;
    int side_c_;
    int angle_a_;
    int angle_b_;
    int angle_c_;
};

void Triangle::print_sides_() {
    std::cout << " a=" << get_side_a();
    std::cout << " b=" << get_side_b();
    std::cout << " c=" << get_side_c();
}

void Triangle::print_angles_() {
    std::cout << "\t  A=" << get_angle_a();
    std::cout << " B=" << get_angle_b();
    std::cout << " C=" << get_angle_c();
}

class Right_triangle : public Triangle {
public:
    Right_triangle(const int& a, const int& b, const int& c, const int& A, const int& B) 
        :Triangle (a, b, c, A, B, 90, 3, "Прямоугольный треугольник") {};
};
class Isosceles_triangle : public Triangle {
public :
    Isosceles_triangle(const int& a, const int& b, const int& A, const int& B)
        :Triangle(a, b, a, A, B, A, 3, "Равнобедренный треугольник") {};
};

class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle (const int& a)
        : Triangle(a, a, a, 60, 60, 60, 3, "Равносторонний треугольник") {};
};

class Quadrangle : public Triangle {
public:
    Quadrangle(const int& a, const int& b, const int& c, const int& d, const int& A, const int& B, const int& C, const int &D) 
        : Quadrangle(a, b, c, d, A, B, C, D, 4, "Четырёхугольник") {};
    int get_side_d() { return side_d_; }
    int get_angle_d() { return angle_d_; }
    void print_sides_() override;
    void print_angles_() override;
protected:
    Quadrangle(const int& a, const int& b, const int& c, const int& d,
        const int& A, const int& B, const int& C, const int& D, const int& s_c, const std::string& n)
        :Triangle(a, b, c, A, B, C, 4, n), side_d_(d), angle_d_(D) {};
private:
    int side_d_;
    int angle_d_;
};

void Quadrangle::print_sides_() {
    Triangle::print_sides_();
    std::cout << " d=" << get_side_d();
}

void Quadrangle::print_angles_() {
    Triangle::print_angles_();
    std::cout << " D=" << get_angle_d();
}

class Parallelogram : public Quadrangle {
public:
    Parallelogram(const int& a, const int& b, const int& A, const int& B)
        :Quadrangle(a, b, a, b, A, B, A, B, 4, "Параллелограмм") {};
protected:
    Parallelogram(const int& a, const int& b, const int& A, const int& B, const std::string& n)
        :Quadrangle(a, b, a, b, A, B, A, B, 4, n) {};
};

class Rectangle : public Parallelogram {
public:
    Rectangle(const int& a, const int& b)
        :Parallelogram(a, b, 90, 90, "Прямоугольник") {};
protected:
    Rectangle(const int& a, const int& b, const std::string& n)
        :Parallelogram(a, b, 90, 90, n) {};
};

class Square : public Rectangle {
public:
    Square(const int& a)
        :Rectangle(a, a, "Квадрат") {};
};

class Rhombus : public Parallelogram {
public:
    Rhombus(const int& a, const int& A, const int& B)
        :Parallelogram(a, a, A, B, "Ромб") {};
};

void print_info(Figure& f) {
    std::cout << f.get_name() << ":" << std::endl;
    std::cout << "Стороны :";
    f.print_sides_();
    std::cout << std::endl << "Углы:";
    f.print_angles_();
    std::cout << std::endl;
}

int main()
{
    Triangle t(10, 20, 30, 50, 60, 70);
    Right_triangle rt(10, 20, 30, 50, 60);
    Isosceles_triangle it(10, 20, 50, 60);
    Equilateral_triangle et(30);
    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle r(10, 20);
    Square sq(20);
    Parallelogram p(20, 30, 30, 40);
    Rhombus rh(30, 30, 40);

    setlocale(LC_ALL, "Russian");
    print_info(t);
    print_info(rt);
    print_info(it);
    print_info(et);
    print_info(q);
    print_info(r);
    print_info(sq);
    print_info(p);
    print_info(rh);
}