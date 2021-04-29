#include <Eigen/Dense>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<int> sort_indexes(const std::vector<float> &v)
{

  // initialize original index locations
  std::vector<int> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);

  std::stable_sort(idx.begin(), idx.end(),
                   [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });

  return idx;
}

int factorial(int n)
{

  return (n == 0) || (n == 1) ? 1 : n * factorial(n - 1);
}

float permutation_entropy(std::vector<float> trajectory, int n)
{

  std::cout << "Computing permutation entropy for embedding dimension " << n
            << "\n";

  int L = trajectory.size();

  Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> permMatrix = Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>,
                                                                               0, Eigen::OuterStride<>>(
      trajectory.data(), n, L - n + 1, Eigen::OuterStride<>(1));

  int permutations = factorial(n);

  std::vector<int> base;
  std::vector<int> perms[L - n + 1];

  for (int i = 0; i <= permutations; i++)
    base.push_back(i);

  int j = 0;
  do
  {
    perms[j] = base;
    j += 1;
  } while (std::next_permutation(base.begin(), base.end()));

  std::vector<size_t> idx(n);
  std::iota(idx.begin(), idx.end(), 0);

  std::vector<int> counts(n, 0);
  int iter = 0;

  for (auto col : permMatrix.colwise())
  {

    std::vector<float> thisCol(col.data(), col.data() + col.rows() * col.cols());

    for (auto i : sort_indexes(thisCol))
    {
      if (iter % 2 == 0)
      {
        if (i == 0)
        {
          counts[0] += 1;
        }
        else
        {
          counts[1] += 1;
        }
      }
      iter += 1;
    }
  }

  Eigen::Map<Eigen::VectorXi> permCounts(counts.data(), n);

  Eigen::VectorXf permCountsNorm = permCounts.cast<float>() / permCounts.sum();

  return -1.0 * (permCountsNorm.array().cwiseProduct(permCountsNorm.array().log() / std::log(2))).sum();
}

int main()
{
  std::vector<float> testArray = {4, 7, 9, 10, 6, 11, 3};
  float k;
  k = permutation_entropy(testArray, 2);
  std::cout << "Permutation entropy: " << k << "\n";
}
