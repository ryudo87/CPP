Sort a linked list in O(n log n) time using constant space complexity.



// http://fisherlei.blogspot.com/2013/12/leetcode-sort-list-solution.html

[Thoughts]
O(nlgn)的排序算法没几个，无非就是quick sort， heap sort和merge sort. 对于链表排序来说，难点之一就是如何O(1)定位节点。如果是数组，那么可以通过下标直接找到节点，但是对于链表，很明显没有下标这个东西可以用，如果需要定位到第k个元素，只能从节点头部顺序的访问K次，但是，如果排序中每一个定位操作都要这样做的话，就太慢了。
所以，问题其实就是，如何能够节省链表节点的定位时间。如果采用merge sort的话，就可以通过递归的特性来避免这个时间损耗。具体看代码





// http://www.cnblogs.com/TenosDoIt/p/3434550.html