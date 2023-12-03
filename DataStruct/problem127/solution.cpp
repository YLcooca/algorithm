// link https://uoj.ac/problem/127

#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

class unionFind {
private:
  std::vector<int> set;

public:
  explicit unionFind() {
    set = std::vector<int>(200001);
    std::iota(set.begin(), set.end(), 0);
  }

  int Find(int i) {
    if (i != set[i]) {
      set[i] = Find(set[i]);
    }
    return set[i];
  }

  void Union(int a, int b) {
    int parent_a = Find(a);
    int parent_b = Find(b);
    set[parent_a] = parent_b;
  }
};

struct relation {
  int i;
  int j;
  int e = -1;
};

int main() {
  int t, n;
  int i, j, e;
  std::cin >> t;
  std::unordered_map<int, int> m; // {trueNumber, idx}
  while (t-- > 0) {
    auto uf = unionFind();
    std::string res = "YES";
    m.clear();
    int idx = 1;

    std::cin >> n;
    std::vector<relation> r(n);
    for (int x = 0; x < n; ++x) {
      std::cin >> i >> j >> e;
      // 对真实的i,j 进行预处理
      int idxi, idxj;
      if (m.count(i))
        idxi = m[i];
      else {
        idxi = idx++;
        m.insert({i, idxi});
      }
      if (m.count(j))
        idxj = m[j];
      else {
        idxj = idx++;
        m.insert({j, idxj});
      }
      r[x] = {idxi, idxj, e};
      if (e == 1) {
        uf.Union(idxi, idxj);
      }
    }
    for (int x = 0; x < n; ++x) {
      auto [i, j, e] = r[x];
      if (e == 0) {
        if (uf.Find(i) == uf.Find(j)) {
          res = "NO";
          break;
        }
      }
    }

    std::cout << res << std::endl;
  }
  return 0;
}
