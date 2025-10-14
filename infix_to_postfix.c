#include<stdio.h>
#include<conio.h>
#define MAX 20

int isopd(char c)
{
    if(c>='a' && c<='z')
        return 1;
    else
        return 0;
}
int isopr(char c)
{
    if(c == '+'|| c=='-'|| c =='*'|| c=='/'|| c=='^')
        return 1;
    else
        return 0;
}
int priority(char ch)
{
    if(ch == '^')
        return 3;
    if(ch =='*' || ch == '/')
        return 2;
    else
        return 1;
}
int main()
{
char infix[15], stk[MAX], opd[15];
int i=0,j=0, top=-1;
char ch;
printf("\nEnter the infix expression: ");
scanf("%s",infix);
while(infix[i]!='\0')
{
    ch = infix[i];
    printf("\n char at position %d is %c", i,ch);
    if(ch == '(')
    {
        top++;
        stk[top]=ch;
        printf("\n\t\t stk[top] = %c", stk[top]);
    }
    else if(isopd(ch))
    {
        opd[j] = ch;
        printf("\n\t\t\t opd[j] = %c", opd[j]);
        j++;

    }
    else if(isopr(ch))
    {
        if(stk[top] =='(' || priority(ch)>priority(stk[top]))
        {

            top++;
            stk[top]= ch;
            printf("\n\t\t stk[top] = %c", stk[top]);
        }
        else
        {
            while(isopr(stk[top])&& priority(stk[top])>=priority(ch))
            {
                opd[j] = stk[top];
                top--;
                 printf("\n\t\t\t opd[j] = %c", opd[j]);
                j++;
            }
            top++;
            stk[top] = ch;
        }

    }
    else if(ch =='(')
    {
        top++;
        stk[top] = ch;
         printf("\n\t\t stk[top] = %c", stk[top]);
    }
    else
    {

        while(stk[top]!= '(')
        {
             opd[j] = stk[top];
               printf("\n\t\t\t opd[j] = %c", opd[j]);
             j++;
             top--;}
                          top--;
}
i++;

}
opd[j] = '\0';
printf("\n\t\t Postfix expression is %s", opd);

}
