************************************************************************************************************************
正常题: 抛出时栈回溯 (stack unwinding)
************************************************************************************************************************

抛出异常时, 控制流沿着栈进行回溯, 直到找到一个能 **匹配** 到的 :cpp:`try-catch` 块, 如果没能找到, 则调用 :cpp:`std::terminate`.

在栈回溯的过程中离开某个函数的栈时, 该函数所有具有自动存储期的已构造但尚未销毁的对象, 以它们的构造函数完成的逆序调用析构函数.
当从 :cpp:`return` 语句所使用的局部变量或临时量的构造函数中抛出异常时, 从函数返回的对象的析构函数也会被调用.

========================================================================================================================
题 1
========================================================================================================================

.. code-block:: cpp
  :linenos:

  void function1() {
    Printer c1{Info{.ctor = "O", .dtor = "F"}};
    throw 1.0;
  }

  void function2() {
    Printer* c1 = new Printer{Info{.ctor = "E", .dtor = "I"}};
    function1();
    Printer c2{Info{.ctor = "H", .dtor = "L"}};
  }

  auto main() -> int {
    try {
      function2();
    } catch (double) {
    }
  }

.. admonition:: 点击查看提示
  :class: dropdown

  3 个字符, 输入流读取到流结束时产生的标志.

.. admonition:: 点击查看答案
  :class: dropdown, solution

  :godbolt:`6nvf1bj5j`, 答案: :code:`EOF`.

========================================================================================================================
题 2
========================================================================================================================

.. code-block:: cpp
  :linenos:

  void function1() {
    try {
      Printer c1{Info{.ctor = "i", .dtor = "n"}};
      throw 1;
    } catch (double) {
    }
  }

  void function2() {
    Printer* c1 = new Printer{Info{.ctor = "c", .dtor = "u"}};
    function1();
    Printer c2{Info{.ctor = "o", .dtor = "t"}};
  }

  auto main() -> int {
    try {
      function2();
    } catch (int) {
    }
  }

.. admonition:: 点击查看提示
  :class: dropdown

  3 个字符, 标准输入流.

  catch 判断是否匹配时, 与判断函数是否匹配的方式不同, 不正式地说, 它不会进行大部分隐式类型转换.

.. admonition:: 点击查看答案
  :class: dropdown, solution

  :godbolt:`7TEqd7arP`, 答案: :code:`cin`.

========================================================================================================================
题 3
========================================================================================================================

.. code-block:: cpp
  :linenos:

  class Base {};

  class Derived : public Base {};

  void function1() {
    try {
      Printer c1{Info{.ctor = "r", .dtor = "o"}};
      throw Derived{};
    } catch (Base&) {
    }
  }

  void function2() {
    Printer* c1 = new Printer( Info{.ctor = "f", .dtor = "z"} );
    function1();
    Printer c2(Info{.ctor = "n", .dtor = "t"});
  }

  auto main() -> int {
    try {
      function2();
    } catch (Derived&) {
    }
  }

.. admonition:: 点击查看提示
  :class: dropdown

  catch 判断是否匹配时, 异常对象可以与其 **公有基类** 匹配.

  5 个字符, 如何获取 vector 的首元素？

.. admonition:: 点击查看答案
  :class: dropdown, solution

  :godbolt:`7nzo55zPv`, 答案: :code:`front`.