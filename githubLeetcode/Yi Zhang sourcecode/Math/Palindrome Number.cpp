class Solution {
public:
  
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int div = 1;
    while (x / div >= 10) {
      div *= 10;
    }
    while (x != 0) {
      int l = x / div;
      int r = x % 10;
      if (l != r) return false;
      x = (x % div) / 10;
      div /= 100;
    }
    return true;
  }
};





Solution:
First, the problem statement did not specify if negative integers qualify as palindromes. Does negative integer such as -1 qualify as a palindrome? Finding out the full requirements of a problem before coding is what every programmer must do. For the purpose of discussion here, we define negative integers as non-palindromes.

The most intuitive approach is to first represent the integer as a string, since it is more convenient to manipulate. Although this certainly does work, it violates the restriction of not using extra space. (ie, you have to allocate n characters to store the reversed integer as string, where n is the maximum number of digits). I know, this sound like an unreasonable requirement (since it uses so little space), but don’t most interview problems have such requirements?

Another approach is to first reverse the number. If the number is the same as its reversed, then it must be a palindrome.



This seemed to work too, but did you consider the possibility that the reversed number might overflow? If it overflows, the behavior is language specific (For Java the number wraps around on overflow, but in C/C++ its behavior is undefined). Yuck.

Of course, we could avoid overflow by storing and returning a type that has larger size than int (ie, long long). However, do note that this is language specific, and the larger type might not always be available on all languages.

We could construct a better and more generic solution. One pointer is that, we must start comparing the digits somewhere. And you know there could only be two ways, either expand from the middle or compare from the two ends.

It turns out that comparing from the two ends is easier. First, compare the first and last digit. If they are not the same, it must not be a palindrome. If they are the same, chop off one digit from both ends and continue until you have no digits left, which you conclude that it must be a palindrome.

Now, getting and chopping the last digit is easy. However, getting and chopping the first digit in a generic way requires some thought. I will leave this to you as an exercise. Please think your solution out before you peek on the solution below.