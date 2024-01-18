
#include <iostream>
#include <windows.h>
using std::cout;
using std::string;

class Figure {
protected:
   string name = "Фигура";
   short a, b, c, d, A, B, C, D;
   short num_part;
   string W_or_R;
public:

   virtual void print_info() {
      cout << name << "\n" << W_or_R << "\n" << "Количество сторон: " << num_part << "\n\n";
   }

   virtual bool check() {
      short sum = A + B + C + D;
      if (sum == 0) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }

   Figure(short a, short b, short c, short A, short B, short C, short num_part) {}
   Figure() {}
};

class Triangle : public  Figure {

protected:
   bool check() override {
      short sum = A + B + C;
      if (sum == 180 && num_part == 3) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }
   void print_info() override {
      cout << name << "\n" << W_or_R << "\n" << "Количество сторон: " << num_part << "\n";
      cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << "\n";
      cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << "\n\n";
   }
public:
   Triangle(short a, short b, short c, short A, short B, short C, short num_part) {
      this->a = a;  this->b = b;  this->c = c;  this->A = A;  this->B = B;  this->C = C;
      this->num_part = num_part;
   }
};

class Right_Triangle : public  Triangle {
protected:
   bool check() override {
      if (C == 90 && Triangle::check()) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }
public:
   Right_Triangle(short a, short b, short c, short A, short B, short C, short num_part) : Triangle(a, b, c, A, B, C, num_part) {
      name = "Прямоугольный треугольник: ";

   }
};

class Isosceles_Triangle : public  Triangle {
protected:
   bool check() override {
      if ((C == A && a == c) && Triangle::check()) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }
public:
   Isosceles_Triangle(short a, short b, short c, short A, short B, short C, short num_part) : Triangle(a, b, c, A, B, C, num_part) {
      name = "Равнобедренный треугольник: ";

   }
};

class Equilateral_Triangle : public Isosceles_Triangle {
protected:
   bool check() override {
      if ((C == B && c == b) && Isosceles_Triangle::check()) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }
public:
   Equilateral_Triangle(short a, short b, short c, short A, short B, short C, short num_part) : Isosceles_Triangle(a, b, c, A, B, C, num_part) {
      name = "Равносторонний треугольник: ";
   }
};

class Quadrilateral : public Figure {
protected:
   bool check() override {
      if (num_part == 4 && (A + B + C + D) == 360) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }

public:
   Quadrilateral(short a, short b, short c, short d, short A, short B, short C, short D, short num_part) {
      name = "Четырёхугольник: ";
      this->a = a;  this->b = b;  this->c = c; this->d = d; this->A = A;  this->B = B;  this->C = C; this->D = D;
      this->num_part = num_part;
   }

   void print_info() override {
      cout << name << "\n" << W_or_R << "\n" << "Количество сторон: " << num_part << "\n";
      cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
      cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
   }
};

class Rectangle_User : public Quadrilateral {
protected:
   bool check() override {
      if (a == c && b == d && A == 90 && B == A && C == A && D == A) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }
public:
   Rectangle_User(short a, short b, short c, short d, short A, short B, short C, short D, short num_part) : Quadrilateral(a, b, c, d, A, B, C, D, num_part) {
      name = "Прямоугольник:";
   }
};

class Square : public Rectangle_User {
protected:
   bool check() override {
      if (a == b && Rectangle_User::check()) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }
public:
   Square(short a, short b, short c, short d, short A, short B, short C, short D, short num_part) : Rectangle_User(a, b, c, d, A, B, C, D, num_part) {
      name = "Квадрат:";
   }
};

class Parallelogram : public Quadrilateral {
protected:
   bool check() override {
      if (a == c && b == d && A == C && B == D && Quadrilateral::check()) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }

public:
   Parallelogram(short a, short b, short c, short d, short A, short B, short C, short D, short num_part) : Quadrilateral(a, b, c, d, A, B, C, D, num_part) {
      name = "Параллелограм:";
   }
};

class Rhomb : public Parallelogram {
protected:
   bool check() override {
      if (a == b && Parallelogram::check() && Quadrilateral::check()) {
         W_or_R = "Правильная";
         return 1;
      }
      else {
         W_or_R = "Неправильная";
         return 0;
      }
   }

public:
   Rhomb(short a, short b, short c, short d, short A, short B, short C, short D, short num_part) : Parallelogram(a, b, c, d, A, B, C, D, num_part) {
      name = "Ромб:";
   }

};
int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   Figure f_f(0, 0, 0, 0, 0, 0, 0);
   f_f.check();
   f_f.print_info();

   Triangle some(10, 20, 30, 50, 60, 70, 3);
   Figure* p_s = &some;
   p_s->check();
   p_s->print_info();

   Right_Triangle right_t(10, 20, 30, 50, 60, 90, 3);
   Figure* p_right_t = &right_t;
   p_right_t->check();
   p_right_t->print_info();

   Right_Triangle new_right_t(10, 20, 30, 50, 40, 90, 3);
   Figure* new_p_right_t = &new_right_t;
   new_p_right_t->check();
   new_p_right_t->print_info();

   Isosceles_Triangle Iso_t(30, 20, 30, 50, 80, 50, 3);
   Figure* p_Iso_t = &Iso_t;
   p_Iso_t->check();
   p_Iso_t->print_info();

   Equilateral_Triangle eq_t(30, 30, 30, 60, 60, 60, 3);
   Figure* p_eq_t = &eq_t;
   p_eq_t->check();
   p_eq_t->print_info();

   Quadrilateral quad_t(10, 20, 30, 40, 90, 90, 90, 90, 4);
   Figure* p_quad_t = &quad_t;
   p_quad_t->check();
   p_quad_t->print_info();

   Rectangle_User user_rec(10, 20, 10, 20, 90, 90, 90, 90, 4);
   Figure* p_user_rec = &user_rec;
   p_user_rec->check();
   p_user_rec->print_info();

   Parallelogram paral(20, 30, 20, 30, 30, 40, 30, 40, 4);
   Figure* p_paral = &paral;
   p_paral->check();;
   p_paral->print_info();

   Square square(20, 20, 20, 20, 90, 90, 90, 90, 4);
   Figure* p_square = &square;
   p_square->check();
   p_square->print_info();

   Rhomb rhomb(30, 30, 30, 30, 30, 150, 30, 150, 4);
   Figure* p_rhomb = &rhomb;
   p_rhomb->check();
   p_rhomb->print_info();
}

