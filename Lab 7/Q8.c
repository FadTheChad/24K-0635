#include <stdio.h>

int main()
{
    char eq[50];
    printf("Enter eq: ");
    scanf("%s", eq);

    int i = 0;
    int sum = 0;
    int temp = 0;
    char last_opp = '+';

    while (eq[i] != '\0')
    {
        if ((eq[i] >= '0') && (eq[i] <= '9'))
        {
            temp = (temp * 10) + (eq[i] - '0');
        }
        else if (eq[i] == '+')
        {
            if (last_opp == '+')
            {
                sum += temp;
            }
            else if (last_opp == '-')
            {
                sum -= temp;
            }
            last_opp = '+';
            temp = 0;
        }
        else if (eq[i] == '-')
        {
            if (last_opp == '+')
            {
                sum += temp;
            }
            else if (last_opp == '-')
            {
                sum -= temp;
            }
            last_opp = '-';
            temp = 0;
        }
        else
        {
            printf("Invalid operator '%c'\n", eq[i]);
            return 1;
        }

        i++;
    }

    if (last_opp == '+')
    {
        sum += temp;
    }
    else if (last_opp == '-')
    {
        sum -= temp;
    }

    printf("RESULT: %d\n", sum);
    return 0;
}
