************************************************************************************************************************
3.
************************************************************************************************************************

.. admonition:: 点击查看考点
  :class: dropdown, keyword

  C 风格数组, C 风格字符串, 指针

.. code-block:: cpp
  :linenos:

  #include <iostream>

  void function(char* what, char* ever) {
    int n = 0;
    int m = 0;
    for (; *what != '\0' && *ever != 0; ++what, ++ever) {
      if (*what != *ever) {
        // 永远不用 std::swap(*what, *ever) 的读程序题
        char temp = *what;
        *what     = *ever;
        *ever     = temp;
        ++n;
      } else {
        ++m;
      }
    }

    std::cout << n << ' ' << m << '\n';
    std::cout << what << ' ' << ever << '\n';
  }

  auto main() -> int {
    char what[] = "killermequeen";
    char ever[] = "thirdbmeomb";

    function(what, ever);

    std::cout << what << ' ' << ever << '\n';
  }


.. admonition:: 点击查看答案
  :class: dropdown, solution

  :godbolt:`rMWzThTPP`

  :cpp:`function` 是将两个字符数组的不同内容交换 (直到某字符数组达到终止字符), 并在 :cpp:`n` 和 :cpp:`m` 中分别记录交换次数和同位置相同字符个数, 并进行一些输出操作.

  .. code-block:: text
    :linenos:

    9 2
    en 
    thirdbmeomben killermeque