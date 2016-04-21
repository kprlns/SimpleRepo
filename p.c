#include "nomer6.h"
#include <stdio.h>


char Check(char* path,int i)
{
    char c;
    if(i==1)
    {
        printf("Enter file path:\n");
        scanf("%s",path);
    }
    if(i==2)
    {
        printf("Use pervious filename?[Y/n]\n");
        scanf("%c",&c);
        while(1)
        {
            scanf("%c",&c);
            if(c=='N' || c=='n' || c=='Y' || c=='y') break;
            printf("Error, enter [Y/n]\n");
        }

    }

}


int main()
{
    int action;
    char path [200];
    int i=1;
    while(i)
    {
        menu();
        printf("Choose option\n");
        scanf("%d",&action);

        if(action>8 || action<1)
        {
            while(1)
            {
                printf("Error, option must be a number [1..8]\n");
                scanf("%d",&action);
                if(action>=1 || action<=9) break;
            }

        }
        if(action==1)
        {
            Check(path,i);
            base_create(path);
        }

        if(action==2)
        {
            Check(path,i);
            base_print(path);
        }

        if(action==3)
        {
            Check(path,i);
            manual_add(path);
        }

        i=2;
    }
}
