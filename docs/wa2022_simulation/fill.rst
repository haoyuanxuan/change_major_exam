************************************************************************************************************************
2. 补全程序题
************************************************************************************************************************

请补全以下递归函数, 它将一个字符串前 9 个非空格字符逆序输出, 不足 9 个则遇到空白符停止.

.. code-block:: cpp
  :linenos:

  #include <iostream>
 
  void function(/*(1)*/) {
    if (count == 0 || *string == '\0') {
      return;
    }
 
    function(string + 1, /*(2)*/);
    std::cout << /*(3)*/;
  }
 
  auto main() -> int {
    function("hello", /*(4)*/);      // 输出 "olleh"
    function("helloworld", 9);       // 输出 "lrowolleh"
    function("colourful", /*(5)*/);  // 输出 "lufruoloc"
  }

.. admonition:: 点击查看解答参考
  :class: dropdown

  :godbolt:`Tn3sq7P4z`

  1. :cpp:`char const* string, int count`

  2. :cpp:`--count`

  3. :cpp:`*string`

  4. :cpp:`9`

  5. :cpp:`9`