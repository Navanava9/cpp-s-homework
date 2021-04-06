#include <iostream>
using namespace std;

typedef struct card
{
    int Ctype;
    int Cpoint;
    int ID;
} card;

class Poker
{
private:
    card *c;

public:
    Poker();
    ~Poker();
    void display();
    void shuffle();

    string change(int);
};

Poker::Poker()
{
    c = new card[54];
    c[52].Cpoint = -1;
    c[52].Ctype = -1;
    c[53].Cpoint = -2;
    c[53].Ctype = -1;
    for (int i = 1; i <= 52; i++)
    {
        c[i - 1].ID = i;
        if (i == 13 || i == 26 || i == 39 || i == 52)
            c[i - 1].Cpoint = 13;
        else
            c[i - 1].Cpoint = i % 13;
        c[i - 1].Ctype = (int)((i - 1) / 13);
    }
}

Poker::~Poker()
{
    delete[] c;
}

void Poker::display()
{
    for (int i = 0; i < 54; i++)
        cout << change(c[i].Ctype) << ' ' << c[i].Cpoint << endl;
}

void Poker::shuffle()
{
    card temp;
    for (int i = 0; i < 500; i++)
    {
        int r1 = rand() % 54;
        int r2 = rand() % 54;
        temp = c[r1];
        c[r1] = c[r2];
        c[r2] = temp;
    }
}

string Poker::change(int a)
{
    if (a == 0)
        return "diamond";
    if (a == 1)
        return "club   ";
    if (a == 2)
        return "heart  ";
    if (a == 3)
        return "spade  ";
    if (a != 0 || a != 1 || a != 2 || a != 3)
        return "       ";
    return "error";
}

int main(void)
{
    Poker p;
    p.shuffle();
    p.display();
    return 0;
}