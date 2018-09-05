#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> splitString(string s, string split) {
    long long sSize = s.size();
    string newS = "";
    vector<string> result;
    for (long long i = 0; i < sSize; i++) {
        if (s[i] == split[0]) {
            if (newS != "")
                result.push_back(newS);
            newS = "";
        } else {
            newS += s[i];
        }
    }
    if (newS != "") {
        result.push_back(newS);
    }
    return result;
}

bool isNumber(string s) {
    auto length = s.size();
    for (long long i = 0; i < length; i++) {
        if ('0' > s[i] || s[i] > '9')
            return false;
    }
    return true;
}

void urlProcess(string *sStatic_1, string *sStatic_2, string *sTarget, int n, int m) {
    vector<vector<string>> staticsList;
    vector<string> sList, sTemp;
    int length = 0;

    for (int i = 0; i < n; i++) {
        sList.push_back(sStatic_2[i]);
        sTemp = splitString(sStatic_1[i], "/");
        length = sTemp.size();
        for (int j = 0; j < length; j++) {
            sList.push_back(sTemp[j]);
        }
        staticsList.push_back(sList);
        sList = vector<string>();
    }
    cout << length;
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    string sStatic_1[n], sStatic_2[n], sTarget[m];
    for (int i = 0; i < n; i++) {
        cin >> sStatic_1[i] >> sStatic_2[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> sTarget[i];
    }
    urlProcess(sStatic_1, sStatic_2, sTarget, n, m);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}