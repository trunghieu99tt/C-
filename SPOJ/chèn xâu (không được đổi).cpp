#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];	// input
    char b[30];		// temporary
    char c[30],d[30];		// result
    int j = 0, maxlength = 0,minlength=10000;

    gets(a); // input

    for(int i = 0; i <= strlen(a); i++)
    {
        if(a[i] != 32 && a[i] != '\0') b[j++] = a[i];
        else
        {
            b[j] = '\0';
            if(strlen(b) > maxlength)
                {
                    strcpy(c, b);		// b -> c
                    maxlength = strlen(b);	// update maxLength
                } 
            if(strlen(b)<minlength)
            {
                strcpy(d,b);
                minlength=strlen(b);
            }
            j = 0;
        }
    }
    printf("%s %s", c,d);
    return 0;
}