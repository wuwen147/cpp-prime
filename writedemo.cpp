#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int month =10 ;
    int day = 1;
    ofstream outfile;
    outfile.open("test.txt");
    outfile<<"国庆节："<<month<<"月"<<day<<"日"<<endl;
    outfile.close();
    return 0;
}