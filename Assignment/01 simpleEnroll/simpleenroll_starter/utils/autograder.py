'''
Hey friend! Glad you're curious about this, but please don't touch this file :>)
'''

from csv_utils import *
import os

def main():
  # fstream writing tests!
  binary_to_csv(R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/courses_not_offered.bin", 
                R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/courses_not_offered.csv")
  binary_to_csv(R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/courses_offered.bin", 
                R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/courses_offered.csv")
  assert files_are_equal(R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/courses_offered.csv", 
                         R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/student_output/courses_offered.csv"), "write_courses_offered test failed 😞"
  assert files_are_equal(R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/courses_not_offered.csv", 
                         R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/student_output/courses_not_offered.csv"), "write_courses_not_offered test failed 😞"
  os.remove(R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/courses_not_offered.csv")
  os.remove(R"/mnt/d/code/code_vscode/cpp/CS106L/Assignment/1simpleEnroll/simpleenroll_starter/utils/courses_offered.csv")
  print("Congratulations, your code passes all the autograder tests! ✅")

main()