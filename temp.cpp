#include <iostream>

using namespace std;

int main(){
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    sort(str.begin(),str.end());
    for(int i =0; i< str.size(); i++){
        cout<<str[i]<<" ";
    }
    return 0;
}