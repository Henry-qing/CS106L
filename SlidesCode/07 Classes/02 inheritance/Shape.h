class Shape{
private:
    virtual double area() const = 0;
public:
};

class Circle : public Shape{
public:
    Circle(double r);
    ~Circle();
    double area() const;
private:
    double r;
};  

class Rectangle : public Shape{
public:
    Rectangle(double a, double b);
    ~Rectangle();
    double area() const;
private:
    double length,width;
};
