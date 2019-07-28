#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "algebre.h"
#include "table.h"
#include "stringExtend.h"

// main de test des sources utilitaires

int main()
{
    int a = 9, b = 7;

    printf("%d %d \n", isPrime(a), areTwins(a,b));


    int tabInt[10] = {4, 0, 189, 1, -123, -6, 10, 0, 9, 123};
    double tabDble[10] = {12.12, 0, 0, 45, 378.03, -4.893, 0.1, 0, 9, 10};

    printf("%d %d %d %p %lf %d %lf %p \n", tabInt[indiceMaxInt(tabInt, 10)], indiceMaxInt(tabInt, 10), *pointMaxInt(tabInt, 10), pointMaxInt(tabInt, 10), tabDble[indiceMaxDouble(tabDble, 10)], indiceMaxDouble(tabDble, 10), *pointMaxDouble(tabDble, 10), pointMaxDouble(tabDble, 10));

    printf("moyennes : %lf %lf \n", moyInt(tabInt, 10), moyDouble(tabDble, 10));

    printf("ecart type %lf %lf \n", ecartTypeInt(tabInt, 10), ecartTypeDouble(tabDble, 10));

    dispTabInt(bubbleSortInt(tabInt, 10), 10);
    dispTabDouble(bubbleSortDouble(tabDble, 10), 10);
    dispTabInt(selectSortInt(tabInt, 10), 10);
    dispTabDouble(selectSortDouble(tabDble, 10), 10);
    dispTabInt(quickSortInt(tabInt, 10, 0, 0), 10);
    dispTabDouble(quickSortDouble(tabDble, 10, 0, 0), 10);


   char strTest[] = "ceci esta un test !";
   char anagramm[strlen(strTest)];

    int count = letterCountInString(strTest, 'e');

    printf("%d %s %d %s \n", wordCount(strTest), invertString(strTest), isPalindrome(strTest), getAnagramm(anagramm, strTest));

    char bin[] = "001101";

    printf("%d", binToDec(bin));

    return 0;
}
