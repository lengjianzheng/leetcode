/*
sort, to_string
*/
#include <string>

using namespace std;

int main() {
    string s;
    sort(s.begin(), s.end());
    string s1 = to_string(123);
    reverse(s.begin(), s.end());
    return 0;
}