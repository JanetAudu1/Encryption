#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
bool isNumber(char number[]);

int main(int argc, string argv[])
{

    int n, c, key, encrpyt;
    char encipered_text[100], myCharKey;

    //convert arg string to int
    key = atoi(argv[1]);

    //convert arg(first and only arg) to char
    myCharKey = argv[1][0];


    //validate lack of arg[1] and non numeric key
    for (int i = 0; i < argc; i++)
    {
        char myCharKey1 = argv[1][i];

        if ((isdigit(myCharKey1) == 0) && (myCharKey1 != '\0'))
        {
            printf("Usage: ./caesar key shoukld not be alphanumeric\n");
            return 1;
        }

    }



    //validate key is positive and non-zero
    if ((key < 1) || (isalpha(key)) || !isdigit(myCharKey) || argc != 2)
    {
        printf("Key Must be non-zero/non-alpha, rerun command\n");
        return 1;
    }

    string plaintext = get_string("plaintext:");
    int s = strlen(plaintext);

    for (int i = 0; i < s ; i++)
    {

        //TODO: preserve case
        //preserve non alphanumeric chars in their original state
        if (!((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z') || plaintext[i] == '\0'))
        {
            encipered_text[i] = plaintext[i];
            continue;
        }

        //shift by key to encrypt.Encipher
        encrpyt = plaintext[i] + key;

        //wrap around and start from 'a' if encrpyt value is 25 or greater
        if (encrpyt > 'z')
        {
            encrpyt = 0;
            c = ((plaintext[i] + key) % 122) + 96;
            encrpyt = c;
        }

        //TODO: Chcek this may be buggy
        encipered_text[i] = encrpyt;

    }

    printf("ciphertext: %s", encipered_text);
    printf("\n");

    exit(0);


}

