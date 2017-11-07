#include <iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class Bag
{
public:
    int value;
    int weight;

};
bool cmp(Bag obj1,Bag obj2)
{
    double r1=double(obj1.value/obj1.weight);
    double r2=double(obj2.value/obj2.weight);
    return r1>r2;
}
int nowweight=0;
double total=0;
int i=0;
double Knapsnack(Bag a[],int wt,int n)
{

    if(a[i].weight+nowweight<=wt)
    {
        nowweight+=a[i].weight;
        total+=a[i].value;
        i++;
        return Knapsnack(a,wt,n);
    }
    else
    {
        double remain=wt-nowweight;
        total+=a[i].value * (remain/a[i].weight);
        i++;
       return total;
    }
}

int main()
{
    ifstream in("z.txt");
    int wt;
    in>>wt;
    int i=0;
    Bag a[100];
    while(in>>a[i].value >> a[i].weight)
    {
        i++;
    }
    int n=i;
    sort(a,a+n,cmp);
    cout<< Knapsnack(a,wt,n);

}
