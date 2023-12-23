#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <stdexcept>

int error(const std::string &error_msg) {
  std::cerr << error_msg << std::endl;
  return 1;
}

std::vector<std::string> read_file(std::ifstream &input_file) {
  std::vector<std::string> rows;

  std::string line;
  while (std::getline(input_file, line)) {
    rows.push_back(line);
  }

  return rows;
}

int get_row_value(const std::string &row) {

  char first_digit;
  char last_digit;

  bool found_first = false;

  for (const auto &character : row) {
    if (character >= '0' && character <= '9') {
      if (!found_first) {
        first_digit = character - '0';
        found_first = true;
      }
      last_digit = character - '0';
    }
  }

  return first_digit * 10 + last_digit;
}

int get_row_value_advanced(const std::string &row) {
  const std::vector<std::string> DIGITS = std::vector<std::string>{
    "one", "1",
    "two", "2",
    "three", "3",
    "four", "4",
    "five", "5",
    "six", "6",
    "seven", "7",
    "eight", "8",
    "nine", "9"
  };

  char first_digit;
  char last_digit;

  bool found_first = false;

  std::map<std::size_t, int> position_value_map;
  
  for (std::size_t index = 0; index < DIGITS.size(); ++index) {
    const auto& digit = DIGITS.at(index);
    // hhvjkdnlffnineeighttwo18twonecs
    std::size_t position = row.find(digit);
    if (position != std::string::npos) {
      int value = int(index / 2) + 1;
      position_value_map.insert(std::make_pair(position, value));
      // std::cout << "Found value: " << digit << " at position " << std::to_string(position) <<  " value: " << std::to_string(value) << std::endl;
    }
  }

  first_digit = position_value_map.begin()->second;

  position_value_map = std::map<std::size_t, int>();

  std::string row_copy = std::string(row);
  std::reverse(row_copy.begin(), row_copy.end());
  
  for (std::size_t index = 0; index < DIGITS.size(); ++index) {
    std::string digit = std::string(DIGITS.at(index));
    std::reverse(digit.begin(), digit.end());
    // jvvslnkdk6qnfzjzvseight55eight
    std::size_t position = row_copy.find(digit);
    if (position != std::string::npos) {
      int value = int(index / 2) + 1;
      position_value_map.insert(std::make_pair(position, value));
      // std::cout << "Found value: " << digit << " at position " << std::to_string(position) <<  " value: " << std::to_string(value) << std::endl;
    }
  }

  last_digit = position_value_map.begin()->second;

  return first_digit * 10 + last_digit;
}

std::vector<std::string> read_file(const std::string& filename) {
  std::vector<std::string> rows;

  std::ifstream input_file(filename, std::ios::in);

  if (input_file.is_open()) {

    rows = read_file(input_file);

    input_file.close();
  } else {
    throw std::runtime_error("Couldn't open file!");
  }

  return rows;
}


