#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>

using namespace sol265;
using namespace std;

/*takeaways
  - to achieve O(nk) we need to remember cost info
    from the previous house
  - when painting a house with a color, its total
    cost is
    - (costs[i][j] + min) if the color is different
      from the color that produces the min cost
      for the previous house
    - (costs[i][j] + min2) if the color is same
      as the color that produces the min cost
      for the previous house. We chose the min2
      to maintain the min cost and the color
      being different from the previous house

*/
int Solution::minCost(vector<vector<int>> &costs)
{
  const auto n = (int)costs.size();
  const auto c = (int)costs[0].size();
  /*
    - minimum accumulated costs by house and colors
    - add one more dimension to simplify
      coding. we don't really care for what's
      in h[0]
  */
  auto h = vector<vector<int>>(n, vector<int>(c, 0));

  /*record the cost info from the previous house
    - min
      - the lowest cost among the colors
    - min2
      - the second lowest cost among the colors
      - we will pick this for the current house
        if the color we want to paint is the
        same as the previous one as we can't
        paint the same color for adjacent houses
    - indx
      - the index of the color that has the lowest cost
  */
  auto pmin = 0, pmin2 = 0, pindx = -1;
  for (int i = 0; i < n; i++)
  {
    /*
      - the total minimum cost to paint the nth house
        with color 0 is the cost of painting it with
        color 0 plus the minimum total cost of painting
        the previous house with different colors
    */
    auto cmin = INT_MAX, cmin2 = INT_MAX, cindx = -1;

    for (auto j = 0; j < c; j++)
    {
      /*
        - different color pick pmin; same color pmin2
      */
      /*C++ notes
        - don't forget to put j != pindx ? pmin : pmin2
          in a pair of parenthesis
      */
      h[i][j] = costs[i][j] + (j != pindx ? pmin : pmin2);
      if (h[i][j] < cmin)
        /* record cmin2 first before updating cmin! */
        cmin2 = cmin, cmin = h[i][j], cindx = j;
      else if (h[i][j] < cmin2)
        cmin2 = h[i][j];
    }

    /* prepare the cost info for the next house */
    pmin = cmin, pmin2 = cmin2, pindx = cindx;
  }

  return pmin;
}
