#include <iostream>
#include <string>

using namespace std;

struct ListNode {
  string valoare;
  ListNode *next;
};
struct stiva {
  ListNode *top;
};

void Init(stiva &s) { s.top = nullptr; }
void push(stiva &s, string sir) {
  ListNode *nou = new ListNode{sir, s.top};
  s.top = nou;
}
void pop(stiva &s) {
  if (s.top == nullptr)
    return;
  ListNode *tmp = s.top;
  s.top = s.top->next;
  delete tmp;
}

int main() {
  string comanda, sir;
  int n;
  stiva s;
  Init(s);
  push(s, "/");
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> comanda;
    if (comanda == "cd") {
      cin >> sir;
      if (sir != "..")
        push(s, sir);
      else if (sir == ".." && s.top->valoare != "/")
        pop(s);
    } else if (comanda == "pwd" && s.top)
      cout << s.top->valoare << '\n';
  }
  return 0;
}