/* ******************************************************************

Class: GrayCUtils
Provide general methods for system calls and file manupulations

Methods:


******************************************************************/

#ifndef GRAYC_UTILS_H
#define GRAYC_UTILS_H

#include <string>

using namespace std;

class GrayCUtils {
public:
  // System calls -  Unix commands
  static bool delete_mutator_file(std::string const &file_name);
  static bool remake_folder(std::string const &folder_name);
  static int unprotected_system_call(std::string const &data);
  static int protected_system_call(std::string const &data);

  // General checks before mutating
  static bool is_bad_line(std::string const &line);
  static bool is_bad_char(const unsigned char &c);
  static int getAssignmentNos(std::string s);
};
#endif // End of GRAYC_UTILS_H
