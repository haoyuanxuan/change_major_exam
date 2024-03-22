************************************************************************************************************************
正常题: 抛出时栈回溯 (stack unwinding)
************************************************************************************************************************

抛出异常时, 控制流沿着栈 **向上** 进行回溯, 直到找到一个能 **匹配** 到的 :cpp:`try-catch` 块, 如果没能找到, 则调用 :cpp:`std::terminate` 终止程序.

自动存储期对象是分配在栈上, 因此在栈回溯的过程中会依次析构 *已构造但尚未销毁的自动存储期对象*, 以它们的构造函数完成的逆序调用析构函数;
而 **向上** 意味着从抛出异常 :cpp:`throw` 语句起, 之上的内容都会被析构, 直到找到匹配的 :cpp:`try-catch` 块.

.. hint::

  如果不理解什么是栈, 请进行 :ref:`断点调试 <question_board:debugger>`, 其中:

  - 调用堆栈显示的就是栈的内容, 各行是对应函数调用的记录 (如局部变量等), 称为栈帧. 如果对递归函数进行断点调试就会发现, 每次调用都创建了新的栈帧, 即可以理解为单纯就是调用了新的函数, 所以递归函数的调用与普通函数的调用是完全一致的.
  - 局部变量窗口显示的就是栈帧中的局部变量内容, 所以栈回溯过程自然会析构掉其中 *已构造但尚未销毁的自动存储期对象*.

========================================================================================================================
题 1
========================================================================================================================

.. code-block:: cpp
  :linenos:

  void function() {
    try {
      Printer c1{Info{.ctor = "c", .dtor = "i"}};
      throw 1;
    } catch (int) {
      std::cout << "n";
    }
  }

  auto main() -> int {
    function();
  }

.. admonition:: 点击查看提示
  :class: dropdown

  3 个字符, C++ 标准输入流.

.. admonition:: 点击查看答案
  :class: dropdown, solution

  :godbolt:`7noc3ernc`, 答案: :code:`cin`.

========================================================================================================================
题 2
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
题 3
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
题 4
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

  catch 判断是否匹配时, 异常对象可以与其 **公用基类** 匹配.

  5 个字符, 如何获取 vector 的首元素？

.. admonition:: 点击查看答案
  :class: dropdown, solution

  :godbolt:`7nzo55zPv`, 答案: :code:`front`.
