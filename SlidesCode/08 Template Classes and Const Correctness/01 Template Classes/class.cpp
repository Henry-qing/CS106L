template<typename T>
class Circle {
private:
    T r;
public:
    Circle(T r);
    ~Circle();
    T get_area();
};

template<typename T>
Circle<T>::Circle(T r): r(r) {}

template<typename T>
Circle<T>::~Circle(){}

template<typename T>
T Circle<T>::get_area(){
    T res = this->r * this->r * 3.14;
    return res;
}

