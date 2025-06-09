#include <iostream>
using namespace std;
struct Nod {
  int valoare;
  Nod *next;
};
void adaugaSfarsit(Nod *&head, int val) {
  Nod *nou = new Nod{val, nullptr};
  if (!head) {
    head = nou;
    return;
  }
  Nod *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = nou;
}
void adaugaInceput(Nod *&head, int val) {
  Nod *nou = new Nod{val, head};
  head = nou;
}

void afisare(Nod *head) {
  while (head) {
    cout << head->valoare << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}
int main() {
  Nod *lista = nullptr;
  adaugaInceput(lista, 5);
  adaugaSfarsit(lista, 7);
  adaugaInceput(lista, 8);
  afisare(lista);
}