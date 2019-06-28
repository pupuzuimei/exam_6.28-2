#include <iostream>
#include<fstream>
#include <algorithm>
#include<string>
using namespace std;
struct student{
    string number;//学号
    string name;//姓名
    string sex;//性别
    int age;//年龄
    double score[7];//成绩
    double ave;//平均分
}a[5];
struct people{
    string referee;//裁判
    string people;
    double score[10];
};
bool cmp(student s1,student s2)
{
    return s1.ave>s2.ave;
}
int main() {
    student t[10];
    people k[10];
    int i,j;
    ofstream inf("/Users/s20181106278/Desktop/myinf.txt");
    ifstream onf("/Users/s20181106278/Desktop/onf.txt");
    ifstream enf("/Users/s20181106278/Desktop/enf.txt");
    if(onf.is_open())
    {
        for(i=0;i<5;++i)
        {
            onf>>a[i].number>>a[i].name>>a[i].sex>>a[i].age;
        }
        onf.close();
    }
    if(enf.is_open())
    {
        for(j=0;j<7;j++)
        {
            enf>>k[j].people;
        }
        for(j=0;j<5;++j)
        {
            for(i=0;i<7;++i)
            {
                enf>>k[j].score[i];
            }
        }
        enf.close();
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<7;j++)
        {
            t[i].score[j]=k[i].score[j];
        }
    }
    for(i=0;i<5;i++)
        sort(t[i].score,t[i].score+7);
    for(j=0;j<5;++j)
    {
        for(i=1;i<6;++i)
        {
            t[j].ave+=t[j].score[i];
        }
        t[j].ave/=5;
    }
    for(i=0;i<5;i++)
    {
        a[i].ave=t[i].ave;
    }
    sort(a,a+5,cmp);
    
    if(inf.is_open())
    {
        for(int i=0;i<5;i++)
        {
            inf<<a[i].number<<" "<<a[i].name<<" "<<a[i].sex<<" "<<a[i].age<<" "<<a[i].ave<<" "<<endl;
        }
        inf.close();
    }
    return 0;
}
