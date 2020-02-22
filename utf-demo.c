#include <stdio.h>
#include <stdint.h> // uint8_t

void print_spaced(char *s)
{
    int i=0;

    while(1)
    {
        // unsigned 8-bit values
        // to shift bytes
        uint8_t c=s[i];
        if(c==0)    // null terminator
        {
            break;
        }

        int len=1; // length of sequence (number of bytes)
        if (c >> 5 == 0b110){
            len=2;
        } 
        else if( c>>4 == 0b1110){
            len=3;
        }
        else if( c >>3 == 0b11110){
            len=4;
        }
        /* 110 is 2 bytes
           1110 is 3 bytes
           11110 is 4 bytes
           10 us multi byte sequence
        */

       // print UTF-8 encoded scalar value

       for(; len>0; len--)
       {
           printf("%c",s[i]);
           i++;
       }

    printf(" ");


    }
}

int main(int argc, char **argv)
{
    for(int i=1; i<argc ; i++)
    {
        print_spaced(argv[i]);
        printf("\n");
    }
}