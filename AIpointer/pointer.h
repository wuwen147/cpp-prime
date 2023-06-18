#include<string>
#include<vector>
#include<initializer_list>
#include<memory>
#include<exception>
using namespace std;
class StrBlob
{
public:
    using size_type = vector<string>::size_type;
    StrBlob():data(std::make_shared<vector<string>>()){}
    StrBlob(std::initializer_list<string> i1):data(std::make_shared<vector<string>>(i1)){}

    size_type size() const{return data->size();}
    bool empty() const{return data->empty();}

    void push_back(const string &t) {data->push_back(t);}
    void pop_back()
    {
        //检查是否为空
        check(0,"pop_back on empty StrBlob");
        data->pop_back();
    }
    std::string& front()
    {
        check(0,"front on empty StrBlob");
        return data->front();
    }
    std::string& back()
    {
        check(0,"back on empty StrBlob");
        return data->back();
    }
    const std::string& front() const
    {
        check(0,"front on empty StrBlob");
        return data->front();
    }
    const std::string& back() const
    {
        check(0,"back on empty StrBlob");
        return data->back();
    }
private:
    void check(size_type i, const string &msg) const
    {
        if(i >= data->size())
        {
            throw std::out_of_range(msg);
        }
    }
    //定义一个变量
    //在这里使用智能指针
    std::shared_ptr<vector<string>> data;
}