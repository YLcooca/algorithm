#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

// 朴素并查集
class unionFind {
public:
  int Find(int i);
  int FindZip(int i);
  // 将a指向b的父节点
  void Union(int a, int b);

  explicit unionFind(uint64_t size_) {
    set = std::vector<int>(size_ + 1);
    std::iota(set.begin(), set.end(), 0);
  }

private:
  std::vector<int> set;
};

int unionFind::Find(int i) {
  if (i == set[i]) {
    return i;
  }
  return Find(i);
}

void unionFind::Union(int a, int b) {
  int parent_a = set[a];
  int parent_b = set[b];
  set[parent_a] = parent_b;
}

int unionFind::FindZip(int i) {
  if (i == set[i]) {
    return i;
  }
  set[i] = FindZip(set[i]);

  return set[i]; // 返回父节点
}

int main() {
  auto uf = unionFind(5);
  uf.Union(1, 2);
  uf.Union(2, 3);
  uf.Union(3, 4);
  uf.Union(4, 5);
  for (int i = 1; i <= 5; ++i) {
    std::cout << uf.FindZip(i) << " ";
  }
  std::cout << std::endl;

  return 0;
}