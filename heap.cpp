#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
ifstream in("heap_sort.in");
ofstream out("heap_sort.out");
const int MAXDIM = 100005;
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }
void downKey(int h[], int dim_h, int i) {
  while (left(i) < dim_h) {
    int smallest = left(i);
    int r = right(i);
    if (r < dim_h && h[r] < h[smallest])
      smallest = r;
    if (h[i] > h[smallest]) {
      swap(h[i], h[smallest]);
      i = smallest;
    } else
      break;
  }
}
void upKey(int h[], int dim_h, int i) {
  while (i > 0 && h[parent(i)] > h[i]) {
    swap(h[i], h[parent(i)]);
    i = parent(i);
  }
}
void buildHeap(int h[], int dim_heap) {
  for (int i = parent(dim_heap - 1); i >= 0; i--) {
    downKey(h, dim_heap, i);
  }
}
void heapSort(int h[], int dim_heap) {
  buildHeap(h, dim_heap);
  for (int i = dim_heap - 1; i >= 1; i--) {
    swap(h[0], h[i]);
    downKey(h, i, 0);
  }
}
void insert(int h[], int &dim_heap, int x) {
  h[dim_heap++] = x;
  upKey(h, dim_heap, dim_heap - 1);
}
void print(int h[], int d) {
  for (int i = 0; i < d; i++)
    cout << h[i] << " ";

  cout << '\n';
}
int main() {
  int n;
  int v[100000];
  in >> n;
  for (int i = 0; i < n; i++) {
    in >> v[i];
  }
  heapSort(v, n);
  reverse(v, v + n);
  for (int i = 0; i < n; i++)
    out << v[i] << " ";

  return 0;
}