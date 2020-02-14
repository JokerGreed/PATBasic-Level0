#include<iostream>
#include<algorithm>
#include<map>

/*
1085 PAT单位排行
*/

using namespace std;
struct sch{
    string name;
    float score=0;
    int stu=0;
}arr[100005];//这个数组可以小点，学校怎么可能这么多
bool cmp(sch A,sch B){
    if((int)A.score!=(int)B.score) return (int)A.score>(int)B.score;//分数不同，谁大谁在前
    else if(A.stu!=B.stu) return A.stu<B.stu;       //分数相同，学生数不同，学生数小的在前
    else return A.name<B.name;          //否则只能用字典序了，谁小谁的字典序在前
}
int main(){
    int N;scanf("%d",&N);           //学生数的定义和输入
    int num=0;//学校数
    map<string,int> mp;                         //mp用来存放学校名字符串到结构体数组的映射
    for(int i=0;i<N;i++){
        string id,school;float score;
        cin>>id;scanf("%f",&score);cin>>school;
        for(int j=0;j<school.length();j++){         //名字变小写
            school[j]=tolower(school[j]);
        }
        if(id[0]=='B') score/=1.5;          //计算当前学生可以给学校带来多少分
        if(id[0]=='T') score*=1.5;
        if(mp.count(school)==0){            //如果此学校第一次出现
            mp[school]=num++;
            arr[num-1].name=school;
        }
        arr[mp[school]].score+=score;           //给这个学校加上这个学生的分
        arr[mp[school]].stu++;          //学校的学生数加加
    }
    sort(arr,arr+num,cmp);              //对结构体数组进行排序
    int mingci=1;
    printf("%d\n1 ",num);               //先输出了学校数和第一名的学校
    cout<<arr[0].name;
    printf(" %d %d",(int)arr[0].score,arr[0].stu);
    for(int i=1;i<num;i++){                     //从第二个学校开始的
        if((int)arr[i].score!=(int)arr[i-1].score)  //如果分数和前一个学校相同，当然mingci就行同了
            mingci=i+1;             //如果分数不同，那么名次正好等于i+1
        printf("\n%d ",mingci);             //输出当前学校的信息
        cout<<arr[i].name;
        printf(" %d %d",(int)arr[i].score,arr[i].stu);
    }
    return 0;
}
