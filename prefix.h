
#include<cstring>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
//Node节点
class Node{
    public:
        string data;
        Node* next;
    public:
        Node(string data);
};
//栈对象
class Stack{
    public:
        //栈的头节点
        Node* head;
        //栈的长度
        int len;
    public:
        Stack();
        void push(string data);
        string top();
        string pop();

};

//prefix对象
class Prefix{
    public:
        Stack* stack;
        Stack* digits;
        int status;

    public:
        Prefix();
        string calculateData(string op, string left, string right);
        int isOp(string op);
        int isDigitStr(string op);
        int calculate(vector<string>* op);
};