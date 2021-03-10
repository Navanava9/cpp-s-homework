#include <iostream>
#include <iomanip>
using namespace std;

struct twodim
{
    int r;
    int c;
    float *a;
};

void get_twodim(twodim &s, int row, int col)
{
    twodim **x = new twodim[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            twodim *x = new twodim;
            x->a = 0;
            x->r = i;
            x->c = j;
        }
}

float &val(twodim &s, int i, int j)
{
}

void free_twodim(twodim &s)
{
}

void main(void)
{
    struct twodim s;
    int i, j;
    get_twodim(s, 3, 4);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            val(s, i, j);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            cout << setw(5) << val(s, i, j);
        cout << endl;
    }
    free_twodim(s);
}