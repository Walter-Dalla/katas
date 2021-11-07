#include <stdio.h>
#include <stdlib.h>

char numberInRoman[10];

int charIndex = 0;
int input = 448;

int romanDecNumber[] = {1, 5, 10, 50, 100, 500, 1000};
char romanCharNumber[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int parseIndex = 3;

int parser(int romanIndex){
    int parsed = 1;
    int number = romanDecNumber[romanIndex];
    char romanNumber = romanCharNumber[romanIndex];

    while (parsed == 1)
    {
        if(input /(double) number >= 1)
        {
            input -= number;
            numberInRoman[charIndex++] = romanNumber;
        }
        else
        {
            for (int i = parseIndex; i >= 0; i--)
            {
                if((number - romanDecNumber[i] == input))
                {
                    input -= number - romanDecNumber[i];
                    numberInRoman[charIndex++] = romanCharNumber[i];
                    numberInRoman[charIndex++] = romanNumber;
                }

                if(input == 0) break;
            }
            
            parsed = 0;
        }
    }
     

    return parsed;
}


int main() {

    for (int i = 0; i < 10; i++)
    {
        numberInRoman[i] = ' ';
    }

    for (int i = 6; i >= 0; i--)
    {
        printf("%c _ %i\n", romanCharNumber[i], input);
        parser(i);
    }
    

    printf("%s\n", numberInRoman);
    printf("CDXLVIII \n");
    printf("%lf\n", input);
}



