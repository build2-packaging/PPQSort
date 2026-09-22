#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

#include <ppqsort.h>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;

  // Sequential sort.
  //
  {
    vector<int> v {5, 3, 1, 4, 1, 5, 9, 2, 6};
    ppqsort::sort (ppqsort::execution::seq, v.begin (), v.end ());
    assert (is_sorted (v.begin (), v.end ()));
  }

  // Parallel sort of a larger, reverse-sorted range.
  //
  {
    vector<int> v (1 << 16);
    iota (v.rbegin (), v.rend (), 0);
    ppqsort::sort (ppqsort::execution::par, v.begin (), v.end ());
    assert (is_sorted (v.begin (), v.end ()));
    assert (v.front () == 0);
    assert (v.back () == static_cast<int> (v.size ()) - 1);
  }

  // Custom comparator with an explicit thread count.
  //
  {
    vector<int> v {5, 3, 1, 4, 1, 5, 9, 2, 6};
    ppqsort::sort (ppqsort::execution::par,
                   v.begin (), v.end (), greater<int> (), 2);
    assert (is_sorted (v.begin (), v.end (), greater<int> ()));
  }

  // Forced branchless partitioning.
  //
  {
    vector<int> v {5, 3, 1, 4, 1, 5, 9, 2, 6};
    ppqsort::sort (ppqsort::execution::seq_force_branchless,
                   v.begin (), v.end ());
    assert (is_sorted (v.begin (), v.end ()));
  }
}
