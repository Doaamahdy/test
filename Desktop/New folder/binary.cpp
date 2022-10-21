// FCAI � Programming 2 � 2022 - Assignment 1
// Program Name: Task5.cpp ---->sheet1
// Program Description: for connecting the dominos in a rigth way
// Last Modification Date:9/10/2022
// Author and ID and Group: Doaa Mahdy Mohamed - 20210128 - Group:A
// Teaching Assistant:

#include<bits/stdc++.h>
using namespace std;
int siz;

class binary{
public:
    static void binaryPrint(int n);
    static void members(string prefix , int k);
};
//----------
void binary::binaryPrint(int n){

    if(n <= 1){
        cout << n;
        return ;
    }
    binary::binaryPrint(n/2);
    cout << n % 2;
}
///--------
void binary::members(string prefix , int k){
    if(prefix.size() == siz+k) {
        cout << prefix << endl;
        return;
    }
     binary::members(prefix+'0',k);
     binary::members(prefix+'1',k);

}
//------------
int main(){
    cout << "Hi ya user! Enter a number to be converted into binary: ";
    int num; cin >> num;
    binary::binaryPrint(num);
    cout <<endl;string prefix;
    cout << "Enter a preifix: ";
    cin >> prefix;
    siz = prefix.size();
    int n;
    cout <<"Enter the number of bits you wana add: ";
    cin >> n;
    cout << "the prefixes are: " << endl;
    binary::members(prefix,n);
    return 0;

}