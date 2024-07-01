#include <iostream>

using namespace std;

class Guest {
 public:
  Guest(char const* Name = "NoName") {
    pName = Name;
    cout << "Construct Guest of " << pName << endl;
  }
  ~Guest() {
    cout << "Destruct Guest of " << pName << endl;
  }

 private:
  char const* pName;
};

class Host {
 public:
  Host(Guest const& gs) : hs(gs) {
    cout << "Construct...\n";
  }

 private:
  Guest hs;
};

Guest g1("g1");
Host h1(g1);

int main() {
  cout << "in the main function\n";
  {
    cout << "in the block\n";
    static Host h2(h1);
  }
  cout << "end the main function" << endl;
}