#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top=-1;
int isfull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int data)
{
    if(isfull)
    {
        printf("\n stack overflow");
        exit(1);
    }
    top=top++;
    stack_arr[top]=data;
}
void pop()
{
    int val;
    if(isempty())
    {
        printf("\n overflow!");
        exit(1);
    }
    val=stack_arr[top];
    top--;
    return val;
}
void dec2bin(int n)
{
    while(n!=0)
    {
        push(n%2);
        n=n/2;
    }
}
void print()
{
    if(isempty())
    {
        printf("\n overflow!");
        exit(1);
    }
    while(!isempty()){
    printf("%d",pop());

    }
}
int main()
{
    int dec;
    printf("\n enter the decimal no. :");
    scanf("%d",&dec);
    dec2bin(dec);
    print();
    return 0;
}
