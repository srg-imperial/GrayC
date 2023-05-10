#include "GrayCUtils.h"
#include <algorithm>
#include <future>
#include <stdio.h>
#include <thread>

int GrayCUtils::getAssignmentNos(std::string s) {
  if (s.empty())
    return 0;

  int occurs = 0;
  std::string::size_type pos = 0;
  std::string target = " =";
  while ((pos = s.find(target, pos)) != std::string::npos) {
    ++occurs;
    pos += target.length();
  }
  return occurs;
}

bool GrayCUtils::is_bad_line(std::string const &line) {
  if (line.empty())
    return true;

  // Check if too large
  if (line.size() > 12000)
    return true;

  // Check for bad chars
  return std::find_if(line.begin(), line.end(), GrayCUtils::is_bad_char) !=
         line.end();
}

bool GrayCUtils::is_bad_char(const unsigned char &c) {
  static const std::string bad_list = ":[]#";
  return bad_list.find(c) != std::string::npos;
}

bool GrayCUtils::delete_mutator_file(std::string const &file_name) {
  // If string is empty return false
  if (file_name.size() == 0)
    return false;

  // Try to remove the file
  return (remove(file_name.c_str()) == 0);
}

// Delete and mkdir call
bool GrayCUtils::remake_folder(std::string const &folder_name) {
  // If string is empty return false
  if (folder_name.size() == 0)
    return false;

  // Try to remove the folder
  std::string command =
      "(rm -rf " + folder_name + "; mkdir " + folder_name + ")";
  return GrayCUtils::protected_system_call(command);
}

int GrayCUtils::unprotected_system_call(std::string const &data) {
  if (data.size() == 0)
    return -99;
  return std::system(data.c_str());
}

int GrayCUtils::protected_system_call(std::string const &data) {
  auto future = std::async(GrayCUtils::unprotected_system_call, data);
  int ret_value = future.get();

  return ret_value;
}
