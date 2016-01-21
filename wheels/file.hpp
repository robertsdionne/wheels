#ifndef WHEELS_FILE_HPP_
#define WHEELS_FILE_HPP_

#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <streambuf>
#include <string>

namespace wheels {

using std::string;

string ReadFile(const string &filename) {
  using std::ifstream;
  using std::ios;
  using std::istreambuf_iterator;

  auto file = ifstream(filename);
  assert(file.good());

  string content;

  file.seekg(0, ios::end);
  content.reserve(file.tellg());
  file.seekg(0, ios::beg);

  content.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
  return content;
}

}  // namespace wheels

#endif  // WHEELS_FILE_HPP_
