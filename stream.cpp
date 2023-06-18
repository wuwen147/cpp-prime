#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdio>
using namespace std;
int main()
{
    //首先进行文件的读取
    /*FILE* file = fopen("cmds.ini","r");
    if(file == NULL)
    {
        cout <<"open failed"<< endl;
        return -1;
    }
    char c = fgetc(file);//读取一个字符
    cout <<c<<endl;
    */
   ifstream ifs("cmds.ini");
   //使用wofstream读写中文字符
   ofstream out;
   out.open("result.txt");
   if(!ifs.is_open())
   {
    cout<<"open file failed:"<<"cmds.ini"<<endl;
    return -1;
   }
   //使用ofstream向一个给定文件写入数据
   if(!out.is_open())
   {
    cout<<"open file failed:"<<"result.txt"<<endl;
    return -1;
   }
   string line;
   //自动换行读取
   while(getline(ifs,line))
   {
    cout << line << endl;
    //使用ofstream向一个给定文件写入数据
    //转成UTF-8编码
    //string test = "哈哈";
    //wstring wContent1(test.length(),L' ');
    //wstring wContent(line.length(),L' ');
    //copy(test.begin(),test.end(),wContent1.begin());
    //copy(line.begin(),line.end(),wContent.begin());
    out<<line<<endl;
   }
   //关闭
   out.close();
   ifs.close();
    return 0;
}