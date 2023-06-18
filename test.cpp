#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    wofstream file;
    file.open("test.txt", ios_base::out);
    if (file.is_open()) {
        //写入中文需要使用UTF-8编码
        string content = "测试中文utf-8编码";
        //将string类型转换为wstring类型
        wstring wContent(content.length(), L' ');
        copy(content.begin(), content.end(), wContent.begin());
        //输出到文件中
        file << wContent;
        file.close();
    }
    else {
        cout << "打开文件失败！" << endl;
    }
    return 0;
}