#include <iostream>
#include <string>

int main() {
  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;

  const std::string greeting = "Hello, " + name + "!";

  const std::string::size_type pad = 0;
  const std::string::size_type rows = pad * 2 + 3;
  const std::string::size_type columns = greeting.size() + pad * 2 + 2;

  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      // first or last row
      if (row == 0 || row == rows - 1) {
        std::cout << std::string(columns, '*') << std::endl;
        break;
      }
      // middle row
      if (row == pad + 1) {
        std::cout << '*' << std::string(pad, ' ') << greeting
                  << std::string(pad, ' ') << '*' << std::endl;
        break;
      }
      // not middle, first, or last
      if (column == 0) {
        std::cout << '*';
        continue;
      }
      if (column == columns - 1) {
        std::cout << '*' << std::endl;
        continue;
      }
      std::cout << ' ';
    }
  }

  return 0;
}
