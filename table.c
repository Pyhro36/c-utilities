#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int indiceMaxInt(const int tab[], int tabLength)
{
    int indMax = 0;
    int valMax = tab[0];
    int i = 0;

    for (i=1 ; i<tabLength ; i++)
    {
        if(tab[i]>valMax)
        {
            valMax = tab[i];
            indMax = i;
        }
    }
    return indMax;
}

int indiceMaxDouble(const double tab[], int tabLength)
{
    int indMax = 0;
    double valMax = tab[0];
    int i = 0;

    for (i=1 ; i<tabLength ; i++)
    {
        if(tab[i]>valMax)
        {
            valMax = tab[i];
            indMax = i;
        }
    }
    return indMax;
}

int* pointMaxInt(const int tab[], int tabLength)
{
    return tab + indiceMaxInt(tab, tabLength);
}

double* pointMaxDouble (const double tab[], int tabLength)
{
    return tab + indiceMaxDouble(tab, tabLength);
}

int indiceMinInt(const int tab[], int tabLength)
{
    int indMin = 0;
    int valMin = tab[0];
    int i = 0;

    for (i=1 ; i<tabLength ; i++)
    {
        if(tab[i]<valMin)
        {
            valMin = tab[i];
            indMin = i;
        }
    }
    return indMin;
}

int indiceMinDouble(const double tab[], int tabLength)
{
    int indMin = 0;
    double valMin = tab[0];
    int i = 0;

    for (i=1 ; i<tabLength ; i++)
    {
        if(tab[i]<valMin)
        {
            valMin = tab[i];
            indMin = i;
        }
    }
    return indMin;
}

int* pointMinInt(const int tab[], int tabLength)
{
    return tab + indiceMinInt(tab, tabLength);
}

double* pointMinDouble (const double tab[], int tabLength)
{
    return tab + indiceMinDouble(tab, tabLength);
}

double moyInt(const int tab[], int tabLength)
{
    double moy = 0;
    int i = 0;
    double buffTab;
    double effect = tabLength;

    for(i=0; i<tabLength; i++)
    {
        buffTab = tab[i];
        moy += buffTab/effect;
    }

    return moy;
}

double moyDouble(const double tab[], int tabLength)
{
    double moy = 0;
    int i = 0;
    double effect = tabLength;

    for(i=0; i<tabLength; i++)
    {
        moy += tab[i]/effect;
    }

    return moy;
}

double ecartTypeInt(const int tab[], int tabLength)
{
    double moy = 0;
    double variance = 0;
    double effect = tabLength;
    double buffTab;
    int i = 0;

    for (i = 0; i<tabLength; i++)
    {
        buffTab = tab[i];
        moy += buffTab/effect;
        variance += buffTab*buffTab;
    }

    return sqrt(variance / effect - (moy*moy));
}

double ecartTypeDouble(const double tab[], int tabLength)
{
    double moy = 0;
    double variance = 0;
    double effect = tabLength;
    double buffTab;
    int i = 0;

    for (i = 0; i<tabLength; i++)
    {
        buffTab = tab[i];
        moy += buffTab/effect;
        variance += buffTab*buffTab;
    }

    return sqrt(variance / effect - (moy*moy));
}

int* dispTabInt(int tab[], int tablength)
{
    int i = 0;

    for (i = 0; i<tablength; i++)
    {
        printf(" %d", tab[i]);
    }

    printf("\n");

    return tab;
}

double* dispTabDouble (double tab[], int tablength)
{
    int i = 0;

    for (i = 0; i<tablength; i++)
    {
        printf(" %lf", tab[i]);
    }

    printf("\n");

    return tab;
}

void switchPointInt(int* point1, int* point2)
{
    int temp = *point1;
    *point1 = *point2;
    *point2 = temp;
}

void switchPointDouble(double* point1, double* point2)
{
    double temp = *point1;
    *point1 = *point2;
    *point2 = temp;
}

int* selectSortInt(int tab[],int tablength)
{
    int p;
    int* h;

    for(p = 0; p<tablength; p++)
    {
        h = pointMinInt((tab + p), (tablength - p));
        if(h != (tab + p))
            switchPointInt(h, (tab + p));
    }

    return tab;
}

double* selectSortDouble(double tab[],int tablength)
{
    int p;
    double* h;

    for(p = 0; p<tablength; p++)
    {
        h = pointMinDouble((tab + p), (tablength - p));
        if(h != (tab + p))
            switchPointDouble(h, (tab + p));
    }

    return tab;
}

int* bubbleSortInt(int tab[], int tablength)
{

    int i, d;

    for(i = 0; i<tablength; i++)
    {
        for(d = 0; d<(tablength-1-i); d++)
        {
            if (tab[d] > tab[d+1])

                switchPointInt((tab + d), (tab + d + 1));
        }
    }

   return tab;
}

double* bubbleSortDouble(double tab[], int tablength)
{

    int i, d;

    for(i = 0; i<tablength; i++)
    {
        for(d = 0; d<(tablength-1-i); d++)
        {
            if (tab[d] > tab[d+1])

                switchPointDouble((tab + d), (tab + d + 1));
        }
    }

    return tab;
}

static int partitionInt(int tab[], int first, int last)
{
    int pivot = tab[(last + first)/2];

    while (first <= last)
    {
        while (tab[first] < pivot)
        {
            first++;
        }
        while (tab[last] > pivot)
        {
            last--;
        }
        if (first <= last)
        {
            switchPointInt(tab + first, tab + last);
            first++;
            last--;
        }
    }

    return first;
}


static int partitionDouble(double tab[], int first, int last)
{
    double pivot = tab[(last + first)/2];

    while (first <= last)
    {
        while (tab[first] < pivot)
        {
            first++;
        }
        while (tab[last] > pivot)
        {
            last--;
        }
        if (first <= last)
        {
            switchPointDouble(tab + first, tab + last);
            first++;
            last--;
        }
    }

    return first;
}

int* quickSortInt(int tab[], int tabLength, int first, int last)
{

    if (first < last)
    {
        int pivot = partitionInt(tab, first, last);

        if (first < pivot - 1)
            quickSortInt(tab, tabLength, first, pivot - 1);

        if (pivot<last)
            quickSortInt(tab, tabLength, pivot, last);
    }

    return tab;
}

double* quickSortDouble(double tab[], int tabLength, int first, int last)
{

    if (first < last)
    {
        int pivot = partitionDouble(tab, first, last);

        if (first < pivot - 1)
            quickSortDouble(tab, tabLength, first, pivot - 1);

        if (pivot<last)
            quickSortDouble(tab, tabLength, pivot, last);
    }

    return tab;
}
