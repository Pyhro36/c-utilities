#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int p)
{
    if(p==1)
        return 0;

    int i;

    for(i=2;i<=(sqrt(p)+1);i++)
    {
        if(!(p%i))
            return 0;
    }
    return 1;
}

int areTwins(int p, int q)
{
    if(isPrime(p)&&isPrime(q)&&((q==p+2)||(p==q+2)))
       return 1;

    else
        return 0;

}
