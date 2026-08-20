#include<stdio.h>
int validate_name(char *str)
{
    for(int i=0;str[i]!=0;i++)
    {
        if((str[i]<'a'||str[i]>'z') &&(str[i]<'A' || str[i]>'Z') &&(str[i]<'0' || str[i]>'9')&&(str[i]!=' '))
        return 0;
    } 
    return 1;
}
int validate_phone(char *str)
{
    for(int i=0;str[i]!=0;i++)
    {
        if(i>9)
        return 1;
        else if(i==0 && (str[i]-48)<=5)
        return 2;
        else if(!(str[i]>='0' && str[i]<='9'))
        return 3;
    }
    return 0;
}
int validate_email(char *str)
{
    int cont=0,len;
    for(len=0;str[len]!=0;len++);
    for(int i=0;str[i]!=0;i++)
    {
        if(str[i]=='@')
        cont++;
    }
    for(int i=0;str[i]!=0;i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        return 1;
        else if(str[i]==' ')
        return 2;
        else if(i==0 && str[i]=='@')
        return 3;
        else if(str[i]=='@' && str[i+1]=='.')
        return 4;
    }
    if(cont==0 || cont>1)
     return 5;
    else if(str[len-1]!='m' || str[len-2]!='o' || str[len-3]!='c' || str[len-4]!='.')
    return 6;

    else return 0;
}