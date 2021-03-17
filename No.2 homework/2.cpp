#include <iostream>
#include <iomanip>
using namespace std;

struct twodim
{
    int level;
    int r;
    int c;
    float *a;
};

void get_twodim(twodim &s, int le, int row, int col)
{
    s.level = le;
    s.c = col;
    s.r = row;
    s.a = new float[row * col * le];
}

float &val(twodim &s, int k, int i, int j)
{
    return *(s.a + k * s.c * s.r + i * s.c + j);
}

void free_twodim(twodim &s)
{
    delete[] s.a;
}

int main(void)
{
    struct twodim s;
    int i, j, k;
    get_twodim(s, 3, 3, 4);

    for (k = 0; k < 3; k++)
        for (i = 0; i < 3; i++)
            for (j = 0; j < 4; j++)
                val(s, k, i, j) = 5;

    for (k = 0; k < 3; k++)
    {
        cout << k + 1 << "level" << endl;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 4; j++)
                cout << setw(5) << val(s, k, i, j);
            cout << endl;
        }
    }
    free_twodim(s);
}
