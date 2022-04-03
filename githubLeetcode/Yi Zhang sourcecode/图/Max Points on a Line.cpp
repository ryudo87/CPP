Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.




// 取定一个点points[i], 遍历其他所有节点, 然后统计斜率相同的点数，并求取最大值即可

(1) The slop is computed using "/", if (x2-x1)==0, there will be an error, but in the 2D plane it is a valid line (vertical line). So, store the vertical line as a specific slope is needed.

(2) Remember to consider the input points have duplicates. In my code, I only consider the duplicates with the starting point in each loop, the slop is not computed then but the number of duplicates are stored instead. Also be careful with all the input points are the same case.




/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
  int maxPoints(vector<Point> &points) {
    
		unordered_map<float,int> mp;
		if (points.size() == 0) {
      return 0;
		}
		int maxNum = 1;
		for(int i = 0; i < points.size(); i++)
		{
			mp.clear();
      
			int duplicate = 1;
			for(int j = 0; j < points.size(); j++)
			{
				if(j == i) continue;
				if(points[i].x == points[j].x && points[i].y == points[j].y)
				{
					duplicate++;
					continue;
				}
				float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
				mp[k]++;
			}
			maxNum = max(duplicate, maxNum);
			for(unordered_map<float, int>::iterator it = mp.begin(); it != mp.end(); it++)
				if(it->second + duplicate > maxNum)
					maxNum = it->second + duplicate;
		}
		return maxNum;
  }
};







#include "all.h"
#include <unordered_map>
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};


//注意：
//0、points中重复出现的点。
//
//1、int maxNum = 0;
//
//初始化，以防points.size() ==0的情况。
//
//2、mp[INT_MIN] = 0;
//
//保证poins中只有一个结点，还有points中只有重复元素时，mp中没有元素。这两种极端情况。
//
//3、int duplicate = 1;
//
//duplicate记录重复点的数量，初始化为1，是因为要把当前的点points[i]加进去。

int maxPoints(vector<Point> &points) {
  
  unordered_map<float,int> mp;
  int maxNum = 0;
  for(int i = 0; i < points.size(); i++)
  {
    mp.clear();
    mp[INT_MIN] = 0;
    int duplicate = 1;
    for(int j = 0; j < points.size(); j++)
    {
      if(j == i) continue;
      if(points[i].x == points[j].x && points[i].y == points[j].y)
      {
        duplicate++;
        continue;
      }
      float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
      mp[k]++;
    }
    
    for(unordered_map<float, int>::iterator it = mp.begin(); it != mp.end(); it++)
      if(it->second + duplicate > maxNum)
        maxNum = it->second + duplicate;
  }
  return maxNum;
}

int main() {
  
  
}
