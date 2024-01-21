#include <fstream>
#include <string>
#include <vector>

class Student {
 public:
  // ...

 private:
  std::string strId;
  std::string strName;
};

class UStudent : public Student {
 public:
  // ...

 private:
  double dCredits;
  bool bResult;
};

class GStudent : public UStudent {
 public:
  // ...

 private:
  double bTeaching;
  bool bResearch;
};

int main() {
  std::vector<Student*> s(4);
  s[0] = new UStudent(1001, "Donald", 156, 1);
  s[1] = new UStudent(1002, "Vivion", 142, 0);
  s[2] = new GStudent(2003, "Chris", 36, 1, 1, 1);
  s[3] = new GStudent(2004, "Cindy", 38, 1, 1, 1);

  // output the information of students in to "studentGraduate.data" file
  //according to the bResult data

  { /* fill the blanks here */ }

  for (int i = 0; i < s.size(); i++) {
    delete s[i];
  }
}