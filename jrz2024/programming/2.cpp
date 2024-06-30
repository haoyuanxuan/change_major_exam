#include <cmath>
#include <iostream>
#include <string>

class Employer {
 public:
  Employer(std::string const& name, double wage) : name_(name), wage_(wage) {}

  auto calc_wage(int year) const -> double {
    return wage_ * std::pow(1.05, year);
  }

  auto get_name() const -> std::string const& {
    return name_;
  }
  void set_name(std::string const& name) {
    name_ = name;
  }

  auto get_wage() const -> double {
    return wage_;
  }
  void set_wage(double wage) {
    wage_ = wage;
  }

 private:
  std::string name_;
  double wage_;
};

auto main() -> int {
  Employer employers[3]
      = {Employer{"A", 1}, Employer{"B", 2}, Employer{"C", 3}};
  for (auto const& employer : employers) {
    std::cout << employer.get_name() << '\t' << employer.get_wage() << '\t'
              << employer.calc_wage(5) << '\n';
  }
}