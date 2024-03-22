#ifndef IP_HPP
#define IP_HPP

#include <iomanip>
#include <istream>
#include <ostream>
#include <stdexcept>

namespace detail {
auto is_valid_ip_section(int ip_section) -> bool {
  int const kLowerBound{0};
  int const kUpperBound{255};

  return kLowerBound <= ip_section && ip_section <= kUpperBound;
}
}  // namespace detail

class Ip {
 public:
  Ip() : first_(), second_(), third_(), fourth_() {}
  Ip(int first, int second, int third, int fourth)
      : first_(first), second_(second), third_(third), fourth_(fourth) {
    throw_if_invalid_ip();
  }

  auto first() const -> int {
    return first_;
  }
  auto second() const -> int {
    return second_;
  }
  auto third() const -> int {
    return third_;
  }
  auto fourth() const -> int {
    return fourth_;
  }

  void set_first(int first) {
    first_ = first;
    throw_if_invalid_ip();
  }
  void set_second(int second) {
    second_ = second;
    throw_if_invalid_ip();
  }
  void set_third(int third) {
    third_ = third;
    throw_if_invalid_ip();
  }
  void set_fourth(int fourth) {
    fourth_ = fourth;
    throw_if_invalid_ip();
  }

  friend auto operator<<(std::ostream& ostream, Ip const& ip) -> std::ostream& {
    ostream << std::setfill('0');

    ostream << std::setw(3) << ip.first_;
    ostream << '.' << std::setw(3) << ip.second_;
    ostream << '.' << std::setw(3) << ip.third_;
    ostream << '.' << std::setw(3) << ip.fourth_;
    return ostream;
  }

  friend auto operator>>(std::istream& istream, Ip& ip) -> std::istream& {
    // 这里输入也应该检测 IP 是不是在范围内, 这是 Ip 类的不变式
    // - 一种方式是输入数据成员, 然后利用现有的构造函数 (其中会判定 IP 是不是在范围内) 和拷贝赋值函数进行
    // - 另一种是把判定不变式抽象为一个函数, 在输入完成后调用

    bool is_good = false;

    int first  = 0;
    int second = 0;
    int third  = 0;
    int fourth = 0;
    if (istream >> first
        && istream.get() == '.'
        && istream >> second
        && istream.get() == '.'
        && istream >> third
        && istream.get() == '.'
        && istream >> fourth) {
      is_good = true;  // 格式正确
    }

    if (is_good) {
      ip = Ip(first, second, third, fourth);
    }

    return istream;
  }

 private:
  void throw_if_invalid_ip() const {
    if (detail::is_valid_ip_section(first_)
        && detail::is_valid_ip_section(second_)
        && detail::is_valid_ip_section(third_)
        && detail::is_valid_ip_section(fourth_)) {
      return;
    }
    throw std::invalid_argument("Invalid IPv4");
  }

  int first_;
  int second_;
  int third_;
  int fourth_;
};

#endif