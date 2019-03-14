#include <vector>
#include <iostream>
#include <map>

using namespace std;

/*
 * Given a m x n grid filled with non-negative numbers, find a path from top 
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */

int minPathSum(vector<vector<int>> &grid)
{
  #define MAX_NUM   10000
  #define DBG       1

  int nrows = grid.size();
  int ncols = grid[0].size();
  int nways = nrows + ncols - 1;
  int res = 0;

  int oi[2] = {0, 0};
  int ri[2] = {nrows - 1, ncols - 1};

  //vector<int> way;
  //way.resize(nways);
  //way[0] = grid[oi[0]][oi[1]];
  //way[nways-1] = grid[ri[0]][ri[1]];

  int candidate1 = 0;
  int candidate2 = 0;

  int i = 1, j = nways - 1;
  int move_count = (int)(nways / 2);
  if (nways % 2 != 0)
    move_count++;

  int a = grid[oi[0]][oi[1]], b = grid[ri[0]][ri[1]];

  #ifdef DBG
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
  #endif
  
  while (i < nways)
  {
    // try to down...
    if (oi[0]+1 <= nrows-1)
      candidate1 = grid[oi[0]+1][oi[1]];
    else
      candidate1 = MAX_NUM;

    // try to right...
    if (oi[1]+1 <= ncols-1)
      candidate2 = grid[oi[0]][oi[1]+1];
    else
      candidate2 = MAX_NUM;

    if (candidate1 < candidate2)
    {
      //way[i] = candidate1;
      a += candidate1;
      oi[0]++;
    }
    else
    {
      //way[i] = candidate2;
      a += candidate2;
      oi[1]++;
    }
    #ifdef DBG
      cout << "a = " << a << endl;
    #endif
    //res += way[i];

    // -----------------------------------------

    // try to up...
    if (ri[0]-1 >= 0)
      candidate1 = grid[ri[0]-1][ri[1]];
    else
      candidate1 = MAX_NUM;

    // try to left...
    if (ri[1]-1 >= 0)
      candidate2 = grid[ri[0]][ri[1] - 1];
    else
      candidate2 = MAX_NUM;

    if (candidate1 < candidate2)
    {
      //way[j] = candidate1;
      b += candidate1;
      ri[0]--;
    }
    else
    {
      //way[j] = candidate2;
      b += candidate2;
      ri[1]--;
    }
    #ifdef DBG
      cout << "b = " << b << endl;
    #endif
    //res += way[j];

    i++;
    j--;
  }

  res = a < b ? a : b;
  return res;
}

int main(int argc, char *argv[])
{
  /*
  vector<vector<int>> input = {
      {1, 3, 1},
      {1, 5, 1},
      {4, 2, 1}};
*/

/*
  vector<vector<int>> input = {
      {1, 2},
      {5, 6},
      {1, 1}};
*/
  vector<vector<int>> input = {
      {7,4,8,7,9,3,7,5,0},
      {1,8,2,2,7,1,4,5,7},
      {4,6,4,7,7,4,8,2,1},
      {1,9,6,9,8,2,9,7,2},
      {5,5,7,5,8,7,9,1,4},
      {0,7,9,9,1,5,3,9,4}};
  
  int res = minPathSum(input);
  cout << res << endl;
  return 0;
}