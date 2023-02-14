#include <iostream>
#include <fstream>

bool getFileContent(std::string &content, const char *filename) {
  std::ifstream in(filename, std::ifstream::in);

  if (!in.is_open())
    return false;

  std::string buffer;
  while (1) {
    getline(in, buffer);
    if (!in)
      break;
    content += buffer;
    content += '\n';
  }
  return true;
}

void replaceContent(std::string &content, std::string s1, std::string s2) {
  while (true) {
    std::string::size_type location = content.find(s1);
    if (location == std::string::npos)
      break ;
    content.erase(location, s1.size());
    content.insert(location, s2);
  }
}

bool createReplaceFile(std::string &content, std::string filename) {
  filename += ".replace";
  std::ofstream out(filename.c_str());

  if (!out.is_open())
    return false;
  out << content;
  return true;
}

int main(int argc, char **argv) {
  if (argc != 4)
    return 1;

  std::string content;
  if (getFileContent(content, argv[1]) == false)
    return 1;
  replaceContent(content, argv[2], argv[3]);
  if (createReplaceFile(content, argv[1]) == false)
    return 1;
}