#include <iostream>
#include <map>
#include <string>

using namespace std;

// 简单的增删改查，遍历
// 注意: 
// 1, 获得值的时候  std::cout << myMap["haha"]; 会在map里插入一个键值对("haha", 0)
int main() {
    // 1, 初始化
    map<string, int> myMap;
    // 2, 插入
    myMap["abc"] = 123; 
    myMap.insert(std::make_pair<string, int>("def", 456));
    // 3, 删除
    myMap.erase("abc");
    // 4, 查找, 获得值的时候  std::cout << myMap["haha"]; 会在map里插入一个键值对("haha", 0)
    std::cout << myMap["def"] << ", " << myMap["haha"] << endl;
    myMap["def"] = 777;
    // 5, 遍历
    for (auto it = myMap.begin(); it != myMap.end(); it++) {
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
    // C++ 11遍历, 用const引用
    for (const auto& p : myMap) {
        cout << "key:" << p.first << ", value:" << p.second << endl;
    }
    return 0;
}