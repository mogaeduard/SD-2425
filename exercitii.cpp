#include <iostream>
#include <string>
using namespace std;

struct Nod {
  int valoare;
  Nod *next;
};
// ex1
struct Stiva {
  Nod *top;
};

void Init(Stiva &s) { s.top = nullptr; }

void push(Stiva &s, int x) {
  Nod *nou = new Nod{x, s.top};
  s.top = nou;
}

void afisare(Stiva &s) {
  Nod *b = s.top;
  while (b) {
    cout << b->valoare << " ";
    b = b->next;
  }
  cout << endl;
}
void pop(Stiva &s) {
  Nod *temn = s.top;
  s.top = s.top->next;
  delete temn;
}
void top(Stiva &s) { cout << s.top->valoare << endl; }
void max(Stiva &s) {
  Nod *cop = s.top;
  int maxi = 0;
  while (cop) {
    if (cop->valoare > maxi)
      maxi = cop->valoare;
    cop = cop->next;
  }
  cout << maxi << endl;
}
// ex2

struct Queue {
  Nod *inceput;
  Nod *final;
};
void InitQ(Queue &q) { q.inceput = q.final = nullptr; }
void enqueue(Queue &q, int x) {
  Nod *nou = new Nod{x, nullptr};
  if (q.final == nullptr)
    q.final = q.inceput = nou;
  else {
    q.final->next = nou;
    q.final = nou;
  }
}

void dequeue(Queue &q) {
  if (q.inceput == nullptr)
    return;
  Nod *temp = q.inceput;
  q.inceput = q.inceput->next;
  if (q.inceput == nullptr)
    q.final = nullptr;
  delete temp;
}
void peek(Queue &q) {
  if (q.inceput)
    cout << q.inceput->valoare << " ";
  else
    cout << " Coada este goala." << endl;
}
void afisareQ(Queue &q) {
  Queue cop = q;
  while (cop.inceput) {
    peek(cop);
    dequeue(cop);
  }
  cout << endl;
}
void reverseQ(Queue &q) {
  Stiva s;
  Init(s);
  while (q.inceput) {
    push(s, q.inceput->valoare);
    dequeue(q);
  }

  while (s.top) {
    enqueue(q, s.top->valoare);
    s.top = s.top->next;
  }
}

// ex 3

void heapifyDown(int heap[], int n, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && heap[left] > heap[smallest])
    smallest = left;
  if (right < n && heap[right] > heap[smallest])
    smallest = right;
  if (smallest != i) {
    swap(heap[i], heap[smallest]);
    heapifyDown(heap, n, smallest);
  }
}

void heapifyUp(int heap[], int i) {
  while (i) {
    int parent = (i - 1) / 2;
    if (heap[parent] < heap[i]) {
      swap(heap[parent], heap[i]);
      i = parent;
    } else
      break;
  }
}

void insert(int heap[], int &n, int val) {
  heap[n] = val;
  heapifyUp(heap, n);
  n++;
}

void extract(int heap[], int &n) {
  if (n == 0)
    return;
  int root = heap[0];
  heap[0] = heap[n - 1];
  n--;
  heapifyDown(heap, n, 0);
  cout << root << '\n';
}

void buildHeap(int heap[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapifyDown(heap, n, i);
  }
}

void heapSort(int heap[], int n) {
  buildHeap(heap, n);
  for (int i = n - 1; i > 0; i--) {
    swap(heap[0], heap[i]);
    heapifyDown(heap, i, 0);
  }
}
int main() {
  /* ex 1&2
  Queue q;
  InitQ(q);

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);

  cout << "Inainte de inversare: ";
  afisareQ(q);

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);

  reverseQ(q);

  cout << "Dupa inversare: ";
  afisareQ(q);
  */

  // ex3
  int n, heap[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> heap[i];
  buildHeap(heap, n);
  for (int i = 0; i < n; i++)
    cout << heap[i] << " ";
  cout << '\n';
  insert(heap, n, 6);
  insert(heap, n, 8);
  for (int i = 0; i < n; i++)
    cout << heap[i] << " ";
  cout << '\n';
  extract(heap, n);
  for (int i = 0; i < n; i++)
    cout << heap[i] << " ";
  cout << '\n';
  heapSort(heap, n);
  for (int i = 0; i < n; i++)
    cout << heap[i] << " ";
  cout << '\n';
  return 0;
}