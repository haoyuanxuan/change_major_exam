************************************************************************************************************************
5.
************************************************************************************************************************

.. admonition:: 点击查看考点
  :class: dropdown, keyword

  递归函数, 插入排序

.. code-block:: cpp
  :linenos:

  #include <iostream>

  void function(char* string, int index) {
    if (string[index] == '\0') {
      return;
    }

    char current = string[index];

    int i = 0;
    for (i = index - 1; i >= 0 && *(string + i) > current; --i) {
      string[i + 1] = string[i];
    }
    string[i + 1] = current;

    function(string, index + 1);
  }

  auto main() -> int {
    char string[] = "HelloWorld";
    function(string, 0);
    std::cout << string;
  }

.. admonition:: 点击查看答案
  :class: dropdown, solution

  :godbolt:`dTPsYn65z`

  递归版本插入排序, 输出 :cpp:`HWdellloor`.