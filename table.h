#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

int indiceMaxInt(const int tab[], int tabLength);
int indiceMaxDouble(const double tab[], int tabLength);
int* pointMaxInt(const int tab[], int tabLength);
double* pointMaxDouble (const double tab[], int tabLength);

int indiceMinInt(const int tab[], int tabLength);
int indiceMinDouble(const double tab[], int tabLength);
int* pointMinInt(const int tab[], int tabLength);
double* pointMinDouble (const double tab[], int tabLength);

double moyInt(const int tab[], int tabLength);
double moyDouble(const double tab[], int tabLength);

double ecartTypeInt(const int tab[], int tabLength);
double ecartTypeDouble(const double tab[], int tabLength);
int* dispTabInt(int tab[], int tablength);
double* dispTabDouble (double tab[], int tablength);

void switchPointInt(int* point1, int* point2);
void switchPointDouble(double* point1, double* point2);

int* selectSortInt(int tab[],int tablength);
double* selectSortDouble(double tab[],int tablength);

int* bubbleSortInt(int tab[], int tablength);
double* bubbleSortDouble(double tab[], int tablength);

int* quickSortInt(int tab[], int tabLength, int first, int last);
double* quickSortDouble(double tab[], int tabLength, int first, int last);

#endif // TABLE_H_INCLUDED
