Surrounded Regions
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region .
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X


Analysis:

Search is a good way to solve this problem!
First and easy thought might, scan all the element, if meets 'O', looking for a path to the boundary, if not exist, put it to 'X'. To look for the path, if all the four directions all have no way out, this element has no way out. The DFS can be used.  See code(small case) below. Actually, it only cannot pass the last big test case (where 250x250 matrix is provided).

However, it will not pass the big test, because the complexity is too high. One common thought is to use BFS instead of DFS, which use more space, but less time.

So how BFS is conducted, we can think from out to inside. Because the boundary 'O' are definitely "live" (have a path out) element, so, we BFS from each 'O' in the boundary, mark all its four directions (where is also 'O') as "live". If you think here, you almost done, the standard BFS using a queue (here I use vector for simplicity) can solve the problem. Last step is to flip "O" to "X" because there is no way out, and flip "P"(live) to "O", because it has a path out. See code (big case) for details. All the test cases are passed.

既然已经知道连通区域必须至少一个元素是在四边，那么一开始直接从四边开始扫描就好了，所以无法connect到得元素都是应该被清除的。所以，算法如下：
1. 从四条边上的O元素开始BFS，所有相连的O都赋个新值，比如‘Y’
2. 扫描整个数组，所有现存的O元素全部置为X，所有Y元素置为O


#include "all.h"
class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int row = board.size();  //get row number
    if (row==0){return;}
    int col = board[0].size(); // get column number
    
    vector<vector<bool> > bb(row, vector<bool>(col)); //result vector
    
    queue<pair<int,int> > q; // queue for BFS
    
    //search "O" from 1st row
    for (int i=0;i<col;i++){
      if (board[0][i]=='O'){
        q.push(make_pair(0,i));
        bb[0][i]=true;
      }
    }
    
    //search "O" from 1st column
    for (int i=0;i<row;i++){
      if (board[i][0]=='O'){
        q.push(make_pair(i,0));
        bb[i][0]=true;
      }
    }
    
    //search "O" from last row
    for (int i=0;i<col;i++){
      if (board[row-1][i]=='O'){
        q.push(make_pair(row-1,i));
        bb[row-1][i]=true;
      }
    }
    
    //search "O" from last column
    for (int i=0;i<row;i++){
      if (board[i][col-1]=='O'){
        q.push(make_pair(i,col-1));
        bb[i][col-1]=true;
      }
    }
    
    //BFS
    int i,j; // current position
    while (!q.empty()){
      //get current live "O"
      i = q.front().first;
      j = q.front().second;
      
      //pop up queue
      q.pop();
      
      //search four directions
      if (i-1>0 && board[i-1][j]=='O' && bb[i-1][j]==false){bb[i-1][j]=true; q.push(make_pair(i-1,j));} //top
      if (i+1<row-1 && board[i+1][j]=='O'&& bb[i+1][j]==false){bb[i+1][j]=true; q.push(make_pair(i+1,j));} // bottom
      if (j-1>0 && board[i][j-1]=='O'&& bb[i][j-1]==false){bb[i][j-1]=true; q.push(make_pair(i,j-1));} // left
      if (j+1<col-1 && board[i][j+1]=='O'&& bb[i][j+1]==false){bb[i][j+1]=true; q.push(make_pair(i,j+1));} // right
    }
    
    //Get result
    for (int i=0;i<row;i++){
      for (int j=0;j<col;j++){
        if (board[i][j]=='O'&&bb[i][j]==false){
          board[i][j]='X';
        }
      }
    }
    
    return;
    
  }
};