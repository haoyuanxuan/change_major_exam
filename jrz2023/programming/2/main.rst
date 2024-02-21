************************************************************************************************************************
2.
************************************************************************************************************************

.. hint::

  与 :doc:`/jrz2020/index` 第 4 题极为相似. 但注意这题没有提到 :cpp:`set`, 所以我们可以直接用 :cpp:`set` 实现; 而 :doc:`/jrz2020/index` 直接说了是要实现 :cpp:`set`, 直接用 :cpp:`set` 很可能不给分.

.. warning::

  以下内容考试中是用英文写在纸上, 也就是代码需要自己抄一遍到电脑里, 所以 **要学会正确使用键盘, 加快打字速度!**

给的回忆我认为有一定问题, 以下为进行修正的版本, 不太了解原题中的 :cpp:`String` 是怎么回事, 用 :cpp:`std::string` 代替.

请设计一个类 :cpp:`MyList`, 它可以存储任意数量的 :cpp:`std::string` 对象, 且满足以下不变式:

- :cpp:`std::string* data_`

  - 保存存储的 :cpp:`std::string` 对象; 当不存储有 :cpp:`std::string` 对象时, :cpp:`data_` 为空指针.

- :cpp:`int size_`

  - 表示存储的 :cpp:`std::string` 数量; 当不存储有 :cpp:`std::string` 对象时, :cpp:`size_ == 0`.

- 元素唯一性

  - 对于 :cpp:`data_` 中存储的 :cpp:`std::string` 对象, 不存在两个对象 :cpp:`string1` 和 :cpp:`string2`, 使得 :cpp:`string1 == string2` (称为相等) 成立.

  - 也就是说, 当插入新对象时, 若 :cpp:`data_` 中已存在相等的对象时, 则不进行插入.

为其实现:

- 构造函数 :cpp:`MyList(std::string* data, int size)`

  - 将 :cpp:`[data, data + size)` 中的元素加入 :cpp:`data_` 中.

- 拷贝构造函数

- 拷贝赋值函数

- :cpp:`auto operator+=(MyList const& other) -> MyList&`

  - 将 :cpp:`other` 中的元素加入 :cpp:`*this` 中.

- :cpp:`friend auto operator+(MyList const& lhs, MyList const& rhs) -> MyList`

  - 合并两个 :cpp:`MyList` 为一个新的 :cpp:`MyList`.

- :cpp:`friend auto operator<<(std::ostream& ostream, MyList const& my_list) -> std::ostream&`

  - 按 :cpp:`[元素1, 元素2, ..., 元素n]` 的格式输出存储的 :cpp:`std::string` 对象.

:cpp:`MyList` 的部分定义和 :cpp:`main()` 函数均已给出, 请在不修改 :cpp:`MyList` 数据成员的情况下完善程序, 注意接口与实现相分离.

.. literalinclude:: main.cpp
  :language: cpp
  :linenos:
  :caption: main.cpp

.. literalinclude:: my_list.hpp
  :language: cpp
  :linenos:
  :caption: my_list.hpp

.. admonition:: 点击查看解答参考
  :class: dropdown

  :godbolt:`GecrPoqYT`

  题目代码虽然给出了指针, 暗示需要 :cpp:`new` 一个动态数组, 但其实可以在实现时用 :cpp:`std::set` 取巧简化. 简化后最复杂的代码反而是笔者无聊加上的输出格式要求.

  不使用 :cpp:`std::set` 地, 你可以用 :cpp:`std::vector` 和 STL 算法 :cpp:`std::sort`、:cpp:`std::unique` 简单实现: :godbolt:`njE6qdfKM`.
