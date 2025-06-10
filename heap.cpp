#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
struct Nod {
  int val;
  Nod *next;
};
struct Elem {
  int v;
  int d;
};

void heapifyDown(Elem heap[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && heap[left].d > heap[largest].d)
    largest = left;
  else if (left < n && heap[left].d == heap[largest].d &&
           heap[left].v > heap[largest].v)
    largest = left;
  if (right <= n && heap[largest].d <= heap[right].d)
    largest = right;
  else if (right < n && heap[right].d == heap[largest].d &&
           heap[right].v > heap[largest].v)
    largest = right;
  if (largest != i) {
    swap(heap[i], heap[largest]);
    heapifyDown(heap, n, largest);
  }
}

void buildHeap(Elem heap[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapifyDown(heap, n, i);
}

void heapifyUp(Elem heap[], int i) {
  while (i) {
    int parent = (i - 1) / 2;
    if (heap[parent].d < heap[i].d) {
      swap(heap[parent], heap[i]);
      i = parent;
    } else
      break;
  }
}
void insert(Elem heap[], int &n, int val, int x) {
  heap[n].v = val;
  heap[n].d = abs(x - val);
  heapifyUp(heap, n);
  n++;
}
void heapSort(Elem heap[], int n) {
  buildHeap(heap, n);
  for (int i = n - 1; i > 0; i--) {
    swap(heap[i], heap[0]);
    heapifyDown(heap, i, 0);
  }
}
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  Elem v[100];
  for (int i = 0; i < n; i++) {
    cin >> v[i].v;
    v[i].d = abs(x - v[i].v);
  }
  heapSort(v, n);
  for (int i = 0; i < k; i++)
    cout << v[i].v << " ";
  cout << endl;
  return 0;
}