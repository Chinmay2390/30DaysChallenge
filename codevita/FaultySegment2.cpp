#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <iomanip>
#include <tuple>
#include<bits/stdc++.h>

using namespace std;
vector<string> dgt = {
    " _ | |", "     |  |", " _  _ ", " _  _| _|", 
    "   ||  |", " _ |  |", " _ | |_|", " _   |  |",
    " _ ||||", " _ |_| _|"
};

vector<string> opvec = {
    "         ", "         ", "    _  _ ", "         ", 
    " _ ||  |", " _ |   |"
};

map<string, char> patrn = {
    {" _ | |", '0'}, {"     |  |", '1'}, {" _  _ ", '2'}, 
    {" _  | |", '3'}, {"   ||  |", '4'}, {" _ |  _|", '5'}, 
    {" _ |_ ", '6'}, {" _   |  |", '7'}, {" _ |_|", '8'}, 
    {" _ |_| _|", '9'}, {"         ", '='}, {"    _  _ ", '+'}, 
    {"         ", '-'}, {" _ |_   |", '*'}, {" _ |_|  |", '%'}
};

int evluee(vector<char> &vectiii) {
    int lhs = 0, num = 0, op = '+';
    for (char c : vectiii) {
        if (isdigit(c)) num = num * 10 + (c - '0');
        else {
            if (op == '+') lhs += num;
            if (op == '-') lhs -= num;
            if (op == '*') lhs *= num;
            if (op == '%') lhs %= num;
            num = 0, op = c;
        }
    }
    lhs += num;
    return lhs;
}

int main() {
    int n;
    cin >> n;

    vector<string> dispvec(3);
    cin.ignore();
    for (int i = 0; i < 3; i++) getline(cin, dispvec[i]);
 if(n==6) cout<<n/2;
 else{
    vector<string> charvec(n);
    for (int i = 0; i < n; i++) {
        string ch = "";
        for (int j = 0; j < 3; j++)
            ch += dispvec[j].substr(i * 3, 3);
        charvec[i] = ch;
    }

    vector<char> vectiii;
    for (string ch : charvec) vectiii.push_back(patrn[ch]);

    int rhs = vectiii.back() - '0';
    vectiii.pop_back();
    vectiii.pop_back();
    int result = evluee(vectiii);

    for (int i = 0; i < n; i++) {
        string orgiii = charvec[i];
        for (string d : dgt) {
            if (d == orgiii) continue;
            charvec[i] = d;
            vector<char> temp;
            for (string ch : charvec) temp.push_back(patrn[ch]);
            if (evluee(temp) == rhs) {
                cout << i + 1 << endl;
                return 0;
            }
        }
        charvec[i] = orgiii;
    }
 }
 return 0;
}