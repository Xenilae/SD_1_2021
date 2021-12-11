#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j, n, m, ok, k, x, y, s, e, v[20], w[20], b[20], a[20][20];
    struct putere

    {
        int p, v;
    } c[20], aux;
    system("cls");
    cout <<"Program realizat de Costiuc Igor\n";
    cout <<"Numar de varfuri =";
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    cout <<"Numar de arce =";
    cin >> m;
    for (k = 1; k <= m; k++)
    {
        cout <<"Extremitati arc "<< k <<" ";
        cin >> x >> y;
        a[x][y] = 1;
    }
    k = 1;
    int ok1 = 1;
    while ((k <= n) && (ok1 == 1))
    {
        for (i = 1; i <= n; i++)
            w[i] = a[k][i];
        for (j = 1; j <= n; j++)
            if (j != k)
                if (a[k][j] == 1)
                {
                    for (i = 1; i <= n; i++)
                        v[i] = a[j][i];
                    for (i = 1; i <= n; i++)
                        if (v[i] > w[i])
                            b[i] = v[i];
                        else
                            b[i] = w[i];
                    for (i = 1; i <= n; i++)
                        w[i] = b[i];
                };
        ok1 = 0;
        for (i = 1; i <= n; i++)
            if (w[i] != a[k][i])
                ok1 = 1;
        if (ok1 == 1)
        {
            for (i = 1; i <= n; i++)
                a[k][i] = w[i];
            k = k;
        }
        else
        {
            for (i = 1; i <= n; i++)
                a[k][i] = w[i];
            k++;
            ok1 = 1;
        }
    }
    e = 0;
    for (i = 1; i <= n; i++)
        if (a[i][i] == 1)
            e = 1;
    if (e == 1)
        cout <<"Graful nu are circuite"<< endl;
    else
        cout <<"Graful are circuite"<< endl;
    for (i = 1; i <= n; i++)
    {
        c[i].p = 0;
        c[i].v = i;
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1)
                c[i].p++;
    }
    s = 0;
    for (i = 1; i <= n; i++)
        s = s + c[i].p;
    if (s == (n * (n - 1)) / 2)
    {
        for (i = 1; i < n; i++)
            for (j = i + 1; j <= n; j++)
                if (c[i].p < c[j].p)
                {
                    aux = c[i];
                    c[i] = c[j];
                    c[j] = aux;
                }
        cout <<"Drumul hamiltonian este :";
    }
}