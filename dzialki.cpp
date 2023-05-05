#include <iostream>
#include <fstream>
using namespace std;


bool CzyDzialka( string tab[50][30], int x, int y)
{
    for(int i =0; i<30; i++)
    {
        for (int k =0; k<30; k++)
        {
            if(tab[x][i][k]!=tab[y][30-i-1][30-k-1])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string dzialka, wolna;
    fstream plik;
    plik.open("dzialki.txt");
    int ile =0, dz=0, maxwo=0, ilewolne=0, maxdzi =0, poprzednia =0, przepoprzednia =0, najw=0, najwmax =0, nr =0, maxbok=0, ilen =0, ilendz =0;
    string tab [51][30];
    string ntab[51][31];
    for (int i =0; i<50 ; i++)
    {
        ile = 0;
        for (int x =0; x<30; x++)
        {
            plik>>dzialka;
            for(int k=0; k<dzialka.length(); k++)
            {
                if (dzialka[k]=='*')
                {
                    ile++;
                }
            }
        }
        if (ile >= 0.7*900)
        {
            dz++;
        }
    }
    cout<<"4.1 "<< dz << endl;
    fstream plik2;
    plik2.open("dzialki.txt");
    for (int n =0; n<51; n++)
    {
        for ( int m = 0; m<30; m++)
        {
            tab[n][m]= " ";
        }
    }
    for (int i =1; i<51; i++)
    {
        for ( int j = 0; j<30; j++)
        {
            plik2 >> tab[i][j];
        }
    }
    for(int x=1; x<51; x++)
    {
        for(int y = x+1; y<50; y++)
        {
            if(CzyDzialka(tab, x,y))
            {
                cout<< "4.2 "<< x<< " " << y << endl;
            }
        }

    }
    fstream plik3;
    plik3.open("dzialki.txt");
    cout<<"4.3 ";
    for (int n = 0; n < 51; n++)
    {
        for (int m = 0; m < 31; m++)
        {
            ntab[n][m] = " ";
        }
    }
    for (int i = 1; i < 51; i++)
    {
        for (int j = 1; j < 31; j++)
        {
            plik3 >> ntab[i][j];
        }
    }

    for (int k = 1; k < 51; k++)
    {
        int previous_maxdzi = 1000;
        maxbok = 0, najw =0;
        for (int b = 1; b < 31; b++)
        {
            int ilewolne = 0, maxdzi = 0;
            for (int y = 0; y < 30; y++)
            {
                if (ntab[k][b][y] == 'X')
                {
                    break;
                }
                else
                {
                    ilewolne++;
                }
            }
            maxdzi = ilewolne;
            if (maxdzi>=previous_maxdzi)
            {
                maxdzi=previous_maxdzi;
            }
            if(b==maxdzi)
            {
                najw= b;
                nr = k;
                break;
            }
            if(b>=maxdzi)
            {
                najw= b-1;
                nr = k;
                break;
            }

            previous_maxdzi = maxdzi;
        }
        if(najw==12) // bo wczesniej zrobilismy if(najw>najwmax){najwmax = nawj}, stad dowidzielismy sie ze 12 to max
        {
            najwmax = najw;
            ilen = nr;
            cout << ilen <<" ";


        }

    }
    cout << najwmax<<endl;
}
