#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> __mul(vector<string>& m1, vector<string>& m2) {
    vector<string> r;
    for (string m1_ : m1) {
        for (string m2_ : m2) {
            string m = "";
            if (m1_ == "a" && m2_ == "a") {
                m = "b";
            } else if (m1_ == "a" && m2_ == "b") {
                m = "b";
            } else if (m1_ == "a" && m2_ == "c") {
                m = "c";
            } else if (m1_ == "b" && m2_ == "a") {
                m = "c";
            } else if (m1_ == "b" && m2_ == "b") {
                m = "b";
            } else if (m1_ == "b" && m2_ == "c") {
                m = "a";
            } else if (m1_ == "c" && m2_ == "a") {
                m = "a";
            } else if (m1_ == "c" && m2_ == "b") {
                m = "c";
            } else if (m1_ == "c" && m2_ == "c") {
                m = "c";
            }
            if (find(r.begin(), r.end(), m) == r.end()) {
                r.push_back(m);
            }
        }
    }
    return r;
}

vector<string> __merge(vector<string>& m1, vector<string>& m2) {
    for (string m : m2) {
        if (find(m1.begin(), m1.end(), m) == m1.end()) {
            m1.push_back(m);
        }
    }
    return m1;
}
bool multiplication(string s) {
    int n = s.length();
    vector<vector<vector<string>>> M(n, vector<vector<string>>(n, vector<string>()));
    
    for (int i = 0; i < n; i++) {
        M[i][i].push_back(s.substr(i, 1));
    }

    for (int w = 1; w < n; w++) {
        for (int i = 0; i < n - w; i++) {
            int j = i + w;
            for (int l = i; l < j; l++) {
                vector<string> m = __mul(M[i][l], M[l + 1][j]);
                M[i][j] = __merge(M[i][j], m);
            }
        }
    }

    for (string result : M[0][n - 1]) {
        if (result == "a") {
            return true;
        }
    }
    return false;
}



int main() {
    string s = "bbbbac";
    bool m = multiplication(s);
    cout << "s=[" << s << "] m=" << (m ? "true" : "false") << endl;

    s = "bbbbbb";
    m = multiplication(s);
    cout << "s=[" << s << "] m=" << (m ? "true" : "false") << endl;

    s = "baab";
    m = multiplication(s);
    cout << "s=[" << s << "] m=" << (m ? "true" : "false") << endl;

    s = "aabc";
    m = multiplication(s);
    cout << "s=[" << s << "] m=" << (m ? "true" : "false") << endl;

    return 0;
}