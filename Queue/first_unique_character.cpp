#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    int firstUniqChar(string s){
        unordered_map<char, int> m;
        queue<int> q;

        for(int i=0; i<s.size(); i++){
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }

            m[s[i]]++;

            while(q.size()>0 && m[s[q.front()]]>1){
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();

    }
};

int main(){
    Solution obj;

    string s = "level";
    int result = obj.firstUniqChar(s);

    if(result == -1){
        cout << "No unique character found" << endl;
    } else {
        cout << "First unique character index: " << result << endl;
        cout << "Character: " << s[result] << endl;
    }

    return 0;
}