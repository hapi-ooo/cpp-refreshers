#include <iostream>
#include <string>

int main() {
  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;

  const std::string greeting = "Hello, " + name + "!";

  const std::string greetingSpace(greeting.size(), ' ');
  const std::string spaces = "* " + greetingSpace + " *";
  const std::string border(spaces.size(), '*');

  std::cout << border << std::endl;
  std::cout << spaces << std::endl;
  std::cout << "* " << greeting << " *" << std::endl;
  std::cout << spaces << std::endl;
  std::cout << border << std::endl;

  return 0;
}
