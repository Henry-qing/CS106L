/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 */

#include "utils.cpp"
#include <exception>
#include <iostream>
#include <system_error>
#include <vector>
#include <cstdio>

std::string COURSES_PATH = R"(/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/courses.csv)";

bool structTest() {
  Course c{"Standard C++ Programming", "1", "2023-2024 Winter"};
  return true;
}

int main() {
  std::vector<Course> vector_of_courses;

  if (!structTest()) {
    std::cerr << "structTest Failed 😞";
  } else {
    std::cout << "structTest Passed! ✅" << '\n';
  }

  parse_csv(COURSES_PATH, vector_of_courses);

  write_courses_offered(vector_of_courses);

  write_courses_not_offered(vector_of_courses);

  FILE *pipe = _popen(
    R"(python3 /mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/autograder.py)", "r");
  if (!pipe)
    return -1;

  char buffer[128];
  while (!feof(pipe)) {
    if (fgets(buffer, 128, pipe) != NULL)
      std::cout << buffer;
  }
  _pclose(pipe);

  // uncomment this line to debug
  // print_vector(vector_of_courses);
  return 0;
}
