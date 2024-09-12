#include <iostream>

class Animal{
public:
    virtual void speak(){
        std::cout << "I am an animal!" << '\n';
    }
};  

class Dog: public Animal{
public:
    void speak(){
        std::cout << "I am a dog!" << '\n';
    }
};

void func(Animal* animal){
    animal->speak();
}

int main(){
    Animal* a = new Animal;
    Dog* b = new Dog;
    func(a);
    func(b);
}
