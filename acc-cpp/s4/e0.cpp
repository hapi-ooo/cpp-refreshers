#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>
#include <vector>

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(std::vector<double> vec) {
  typedef std::vector<double>::size_type vec_sz;
  const vec_sz size = vec.size();
  if (size == 0)
    throw std::domain_error("median of an empty vector");

  std::sort(vec.begin(), vec.end());

  const vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// compute a student's overall grade from midterm and final exam grades and
// vector of homework grades
double grade(double midterm, double final, const std::vector<double> &hw) {
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  return 0.2 * midterm + 0.4 * final + 0.4 * median(hw);
}

// read homework from input stream
std::istream &read_homework(std::istream &in, std::vector<double> &hw) {
  if (in) {
    // clear homework
    hw.clear();
    // read in homework
    double x;
    while (in >> x)
      hw.push_back(x);
    // clear stream for future use
    in.clear();
  }
  return in;
}

int main() {
  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << "!" << std::endl;

  std::cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  std::cin >> midterm >> final;

  std::cout << "Enter all your homework grades, "
               "followed by end-of-file: ";

  std::vector<double> homework;
  read_homework(std::cin, homework);

  try {
    const double final_grade = grade(midterm, final, homework);
    std::streamsize prec = std::cout.precision();
    std::cout << "Your median homework grade is " << std::setprecision(3)
              << median(homework) << std::setprecision(prec) << std::endl;
    std::cout << "Your final grade is " << std::setprecision(3) << final_grade
              << std::setprecision(prec) << std::endl;
  } catch (std::domain_error) {
    std::cout << "You must enter your grades. "
                 "Please try again."
              << std::endl;
  }

  return 0;
}
