/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 * Please complete each STUDENT TODO in this file.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

// (FIRST) STUDENT TODO: change how variables are passed into the functions you
// must complete

#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>

// STUDENT TODO: add paths
std::string COURSES_OFFERED_CSV_PATH = R"(/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/student_output/courses_offered.csv)";

std::string COURSES_NOT_OFFERED_CSV_PATH = R"(/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/student_output/courses_not_offered.csv)";

struct Course {
  /* STUDENT TODO: ADD TYPE */ std::string title; //课程名
  /* STUDENT TODO: ADD TYPE */ std::string number_of_units; //学分
  /* STUDENT TODO: ADD TYPE */ std::string quarter; //上课的学期(年份+季度)

  // ignore this!
  bool operator==(const Course &other) const {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

// forward declarations
//void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);

/*
 * This function should populate the vector_of_courses with structs of type
 * Class We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 */
void parse_csv(std::string filename, std::vector<Course>& vector_of_courses) {
  // STUDENT TODO: Implement this function
  std::ifstream file(filename);
  //成功打开文件
  if(file.is_open()){
    std::string line;
    while(getline(file,line)){
      std::vector<std::string> line_name = split(line,',');
      //用line_name存储切割为三部分的split;
      std::string title = line_name[0], number_of_units = line_name[1], quarter = line_name[2];
      Course new_course = {title,number_of_units,quarter};
      vector_of_courses.push_back(new_course);
    }
    file.close();
  }
};
//写完这里可以把其他地方全部注释掉然后检验一下子函数写的有没有问题;
// for(auto [a,b,c]:vector_of_courses){
//   std::cout << a << " " << b << " " << c << '\n';
// }

/*
 * This function has TWO requirements.
 * 1) Write the courses that are offered to the file courses_offered.csv inside
 * the student_output folder
 *
 * 2) Delete classes that are offered from vector_of_courses.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 */
void write_courses_offered(std::vector<Course>& vector_of_courses) {
  // STUDENT TODO: implement this function
  //1.COURSES_OFFERED_CSV_PATH
  std::ofstream infile1(COURSES_OFFERED_CSV_PATH);
  if(!infile1.is_open()){
    std::cout << "文件无法打开\n";
    return; 
  }
  std::vector<Course> tmp;
  int times = 0;
  for(const auto &[title,number_of_units,quarter]:vector_of_courses){
    if(times == 0){
      times ++;
      continue;
    }
    if(quarter != "null"){
      infile1 << title << ',' << number_of_units << ',' << quarter << std::endl;
    }
    else{
      tmp.push_back({title,number_of_units,quarter});
    }
  }
  vector_of_courses = tmp;
  infile1.close();
  // for(auto& it:tmp){
  //   delete_elem_from_vector(vector_of_courses,it);
  // }
}

/*
 * This function writes the courses NOT offered to the file
 * courses_not_offered.csv inside of the student_output folder
 *
 * This function is ALWAYS called after the write_courses_offered function.
 * vector_of_courses will trivially contain classes that are not offered
 * since you delete offered classes from vector_of_courses in the
 * 'write_courses_offered' function.
 *
 * HINT: This should be VERY similar to write_courses_offered
 */
void write_courses_not_offered(std::vector<Course>& vector_of_courses) {
  // STUDENT TODO: implement this function
  std::ofstream infile2(COURSES_NOT_OFFERED_CSV_PATH);
  std::vector<Course> tmp;
  for(const auto &[title,number_of_units,quarter]:vector_of_courses){
    infile2 << title << ',' << number_of_units << ',' << quarter << std::endl;
  }
  infile2.close();
}

/* ######## HEYA! DON'T MODIFY ANYTHING BEYOND THIS POINT THX ######## */

// TODO: ADD DOCUMENTATION COMMENTS
void print_vector(std::vector<Course> vector_of_courses) {
  for (int i = 1; i < vector_of_courses.size(); ++i) {
    std::cout << vector_of_courses[i].title << ","
              << vector_of_courses[i].number_of_units << ","
              << vector_of_courses[i].quarter << std::endl;
  }
}

// void delete_elem_from_vector(std::vector<Course> &v, Course &elem) {
//   auto it = std::find(v.begin(), v.end(), elem);
//   v.erase(it);
// }

std::vector<std::string> split(std::string s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  //用getline读入缓存区上面的内容，以'delim'为分割，因此实际上split实现了分割;
  //因此可以吧下面这里的','修改为delim
  while (getline(ss, token, delim)) {
    return_vec.push_back(token);
  }
  return return_vec;
}
