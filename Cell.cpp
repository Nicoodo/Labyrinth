#include "Cell.h"

using namespace std;

Cell::Cell(int x, int y) : m_x(x), m_y(y)
{

}

Cell::~Cell()
{
  
}

void Cell::add_neighb(Cell *n1)
{
  for(int i = 0 ; i < m_nb_neighb ; i++)
    if(m_neighb[i] == n1)
      return;

  m_nb_neighb++;

  Cell **new_neighb = new Cell*[m_nb_neighb];
  for(int i = 0 ; i < m_nb_neighb - 1 ; i++)
    new_neighb[i] = m_neighb[i];

  new_neighb[m_nb_neighb - 1] = n1;
  delete[] m_neighb;
  m_neighb = new_neighb;

  n1->add_neighb(this);
}

void Cell::add_neighb(Cell *n1, Cell *n2)
{
  add_neighb(n1);
  add_neighb(n2);
}

void Cell::add_neighb(Cell *n1, Cell *n2, Cell *n3)
{
  add_neighb(n1);
  add_neighb(n2);
  add_neighb(n3);
}

ostream& operator<<(ostream& stream, const Cell& r) {
  stream << "("<< r.m_x << ","<<r.m_y<<")"<< r.m_nb_neighb;
  for (int i =0; i<r.m_nb_neighb ; i++)
    {
      stream << "("<< r.m_neighb[i]->m_x << ","<<r.m_neighb[i]->m_y<<")";
    }
  stream<<endl;
  cout << "("<< r.m_x << ","<<r.m_y<<")" << endl;
  return stream ;
}

istream& operator<<(istream& stream, Cell& r) {
    string ligne;
    const char lim=')';
    getline(stream,ligne,lim);
    Cell* new_r = new Cell(ligne[1],ligne[3]);
    cout <<ligne<<endl;
    // r = new_r // à faire marcher je veux que l'addresse de r devienne celle de new_r
  return stream ;
}
