// Blank header file
#include <iostream>
#include <string>
class Lesson{
public:
    using string = std::string;
    Lesson(string name, string teacher, int score, int credit_hours);
    ~Lesson();
    string get_name();
    string get_name() const{
        return const_cast<Lesson&>(*this).get_name();
    };
    string get_teacher() const;
    int get_score() const;
    int get_credit_hours() const;
    void set_name(string name);
    void set_teacher(string teacher);
    void set_credit_hours(int credit_hours);
    void set_score(int score);
private:
    string name;
    string teacher;
    int score;
    int credit_hours;
};