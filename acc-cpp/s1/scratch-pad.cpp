#include <iostream>
#include <string>

int main() {
  // std::string test = "hi" + "hapi-ooo"; // compiler error
  std::string test = "hir";
  // std::string test2 = "hello" + ", world" + test; // compiler error
  std::string test2 = "hello" + test + ", world";

  std::cout << test2 << std::endl;
  return 0;
}
