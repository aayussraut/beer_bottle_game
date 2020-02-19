#include<iostream>
#include<stdlib.h>

using namespace std;

int Randoms(int lower,int upper,int count)
{
    int i,num;
    for (i = 0; i < count; i++) {
        num = (rand()%(upper - lower + 1)) + lower;
    }
    return num;
}

int main()
{
    int t=21,b,p,option,cases=0;
    cout<<"Total no of bottles: 21\nWhoever chooses the bottle at last loses i.e. player to pick the last bottle loses\nChoose between (1-4) bottles at a time";
    cout<<"\nChoose who goes first (1 for player and 2 for bot): ";
    cin>>option;
    switch(option)
    {
    case 1:
        while(t>1)
        {
            top:
            cout<<"Player's turn: ";
            cin>>p;
            if(p<1 || p>4){
                cout<<"Enter again betwenn (1-4)";
                goto top;
            }
            t-=p;
            cout<<"Bottle left: "<<t<<endl;
            cout<<"Bot's turn: ";
            b=5-p;
            cout<<b<<endl;
            t-=b;
            cout<<"Bottle left: "<<t<<endl<<endl;
        }
        cout<<"Only one bottle left, so you lose by default!"<<endl;
        break;



    case 2:
        cout<<"\n\nBot's turn: ";
        b=Randoms(1,4,10);
        cout<<b<<endl;
        t-=b;
        cout<<"Bottle left: "<<t<<endl;
        while(t>1)
        {
            inp:
            cout<<"Player's turn: ";
            cin>>p;
            if(p<1 || p>4){
                cout<<"Enter again betwenn (1-4)";
                goto inp;
            }
            t-=p;
            cout<<"Bottle left: "<<t<<endl<<endl;
            if(cases == 2)
            {
                b=5-p;
                cout<<"Bot's turn: ";
                cout<<b<<endl;
                t-=b;
                cout<<"Bottle left: "<<t<<endl;
            }
            else if((5-b-p)>0)
            {
                b=5-b-p;
                cout<<"Bot's turn: ";
                cout<<b<<endl;
                t-=b;
                cout<<"Bottle left: "<<t<<endl;
                cases=2;
            }
            else if((5-b-p)<0)
            {
                if(t>11)
                    b=t-11;
                else if(t>6)
                    b=t-6;
                cout<<"Bot's turn: ";
                cout<<b<<endl;
                t-=b;
                cout<<"Bottle left: "<<t<<endl;
                cases=2;
            }
            else if((5-b-p)==0)
            {
                cout<<"Bot's turn: ";
                b=Randoms(1,4,10);
                cout<<b<<endl;
                t-=b;
                cout<<"Bottle left: "<<t<<endl;
                cases=0;
            }
        }
        if(b<=1){
            cout<<"You win!!!"<<endl<<endl;
            break;
        }
        cout<<"Only one bottle left, so you lose by default!"<<endl<<endl;
        break;
    default:
        cout<<"Wrong choice!!";
        break;
    }
    return 0;
}
