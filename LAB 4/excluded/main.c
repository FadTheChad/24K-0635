#include <stdio.h>

int main()
{
    char m;
    int n;
    int status = 1;

    printf("Enter char and int: ");
    scanf("%c%d", &m, &n);

    if (m == 'J' || m == 'j')
    {
        if (n == 0) printf("JAN");
        else if (n == 1) printf("JUN");
        else if (n == 2) printf("JUL");
        else status = 0;
    } else if (m == 'F' || m == 'f')
    {
        if (n == 0) printf("FEB");
        else status = 0;
    } else if (m == 'M' || m == 'm')
    {
        if (n == 0) printf("MAR");
        else if (n == 1) printf("MAY");
        else status = 0;
    } else if (m == 'A' || m == 'a')
    {
        if (n == 0) printf("APR");
        else if (n == 1) printf("AUG");
        else status = 0;
    } else if (m == 'S' || m == 's')
    {
        if (n == 0) printf("SEP");
        else status = 0;
    } else if (m == 'O' || m == 'o')
    {
        if (n == 0) printf("OCT");
        else status = 0;
    } else if (m == 'N' || m == 'n')
    {
        if (n == 0) printf("NOV");
        else status = 0;
    } else if (m == 'D' || m == 'd')
    {
        if (n == 0) printf("DEC");
        else status = 0;
    } else 
    {
        status = 0;
    }
    
    if (status == 0) printf("INVALID INPUT");

    return 0;
}