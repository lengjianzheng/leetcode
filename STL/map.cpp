#include <iostream>
#include <map>
#include <string>

using namespace std;

// 简单的增删改查，遍历
// 1, 获得值的时候  std::cout << myMap["haha"]; 会在map里插入一个键值对("haha", 0)
int main() {
    map<string, int> myMap; // 初始化
    myMap["abc"] = 123; // 插入
    myMap.insert(std::make_pair<string, int>("def", 456)); // 插入
    myMap.erase("abc"); // 删除
    std::cout << myMap["def"] << ", " << myMap["haha"] << endl; // 获取值
    myMap["def"] = 777;
    // 遍历
    for (auto it = myMap.begin(); it != myMap.end(); it++) {
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
    // C++ 11遍历, 用const引用
    for (const auto& p : myMap) {
        cout << "key:" << p.first << ", value:" << p.second << endl;
    }
    return 0;
}