#include <fstream>
#include <iostream>
#include <vector>

#include "common.hpp"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    return error("Error expect exactly one argument!");
  }

  std::string filename(argv[1]);

  std::ifstream input_file(filename, std::ios::in);

  std::vector<std::string> rows = read_file(filename);
  
  int final_value = 0;
  for (const auto &row : rows) {

    int row_value = get_row_value_advanced(row);

    final_value += row_value;
  }

  std::cout << "Final sum: " << std::to_string(final_value) << std::endl;

  return 0;
}
