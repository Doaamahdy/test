
#include<bits/stdc++.h>
using namespace std;


class bigInteger{

    string s;
    vector<int> v;
    bool signd;
    int siz;

public:
    bigInteger();
    bigInteger(int n);
    bigInteger(string str);
    bool operator==(bigInteger obj);
    int size();
    int sign();
    bool operator> (bigInteger obj);
    bool operator< (bigInteger obj);
    bigInteger operator =(bigInteger obj);
    bigInteger operator +(bigInteger d );
    bigInteger operator -(bigInteger d);
    friend istream&  operator >> (istream&input , bigInteger& d);
    friend ostream& operator << (ostream& output , bigInteger d);
};