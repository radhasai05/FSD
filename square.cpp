#include<iostream>
#include<thread>
using namespace std;
int randomInt;
void randnum()
{
    randomInt=(rand()%10+1);
    cout<<"random integer is"<<randomInt<<endl;
    sleep(1);
}
void printsquare()
{
    int square=randomInt*randomInt;
    cout<<"square of"<<randomInt<<"is"<<square<<endl;
    sleep(1);
}
void printcube()
{
    int cube=randomInt*randomInt*randomInt;
    cout<<"cube of"<<randomInt<<"is"<<cube<<endl;
    sleep(1);
}
int main()
{
    int n;
    cout<<"enter the number of times:";
    cin>>n;
    thread t1[n],t2[n],t3[n];
    for (int i=0;i<n;i++)
    {
        t1[i]=thread(randnum);
        t1[i].join();
        t2[i]=thread(printsquare);
        t2[i].join();
        t3[i]=thread(printcube);
        t3[i].join();
    }
    return 0;
}
