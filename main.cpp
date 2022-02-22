#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol265;

/*
Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5;
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
*/
tuple<vector<vector<int>>, int>
testFixture1()
{
  auto costs = vector<vector<int>>{
      {1, 5, 3}, {2, 9, 4}};

  return make_tuple(costs, 5);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::minCost(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  return 0;
}