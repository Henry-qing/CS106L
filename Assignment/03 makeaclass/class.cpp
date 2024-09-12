// Blank cpp file
#include "class.h"

Lesson::Lesson(string name, string teacher, int score, int credit_hours): name(name),teacher(teacher),score(score),credit_hours(credit_hours){}
Lesson::~Lesson(){}
std::string Lesson::get_name() {return this->name;};
std::string Lesson::get_teacher() const {return this->teacher;};
int Lesson::get_credit_hours() const {return this->credit_hours;};
int Lesson::get_score() const {return this->score;};
void Lesson::set_name(std::string name){
    this->name = name;
}
void Lesson::set_teacher(std::string teacher){
    this->teacher = teacher;
}
void Lesson::set_credit_hours(int credit_hours){
    this->credit_hours = credit_hours;
}
void Lesson::set_score(int score){
    this->score = score;
}