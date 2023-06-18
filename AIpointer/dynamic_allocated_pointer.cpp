#include <iostream>
#include <vector>

using Ptr = std::vector<int> *;
//动态分配
//如果改成make_shared,就不用new
auto make_dynamically()
{
    return new std::vector<int> {};
}
//往对应的容器中插入数据
auto populate(Ptr vec)
{
    for(int i;std::cout<<"Pls Enter:\n",std::cin>>i;vec->push_back(i));
    return vec;
}
auto print(Ptr vec)->std::ostream&
{
    for(int i:*vec)
    {
        std::cout<<i<<"";
        
    }
    return std::cout;
}
int main()
{
    auto vec = populate(make_dynamically());
    print(vec)<<std::endl;
    delete vec;
    return 0;
}