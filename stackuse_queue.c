#include<iostream>
using namespace std;
#define MAX 5
int main()
{
    int Q1[MAX],Q2[MAX],r1,f1,r2,f2,i;
    int ch, val;
    r1=-1,r2=-1,f1=0,f2=0;
    do
    {
        cout<<"\n1. push\n2.pop\n3.display"<<endl;
        cout<<"\n\tEnter choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1://push
            if(r1==MAX-1)
            {
                cout<<"\n\t\t\t stack is full";
            }
            else
            {
                cout<<"\n\t\tEnter the value: ";
                cin>>val;
                r1++;
                Q1[r1]=val;
                cout<<"\n\t\t" <<val<< " is pushed";
            }
            break;
            case 2://pop
            f1=0, r2=-1,f2=0;
            if(r1==-1 && r1==f1-1)
                cout<<"Stack is empty";
            else
            {
                while(f1<r1)
                {
                    Q2[++r2] = Q1[f1];
                    f1++;
                }
                cout<<"\n\t"<< Q1[f1]<<" is poped ";
                r1=-1;
                while(f2<=r2)
                {
                    Q1[++r1] = Q2[f2];
                    f2++;

                }
            }
            cout<<"\n\t\t r1 in pop = "<<r1;
            break;
            case 3://display
            i=r1;
            cout<<"\n\t\t r1 in display = "<<r1;
            while(i>=0)
            {
                    cout<<"\n"<<Q1[i];
                    i--;
            }

            break;
        }
        /* code */
    } while (ch<=3);

}
