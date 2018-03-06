#include<cstring>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include "prefix.h"

using namespace std;
//Node节点的构造函数
Node::Node(string data){this->data = data;};

//stack的构造函数
Stack::Stack(){head = NULL;len = 0;}
//stack的push函数，将data压到栈顶
void Stack::push(string data){
            Node* p;
            p = head;
            len ++;
            //如果栈空，那么头节点指向一个心创建的节点
            if(head == NULL){
                Node* temp = new Node(data);
                temp->next = NULL;
                head = temp;
                return ;
            }
            Node* temp = new Node(data);
            temp->next = p;
            head = temp;
        }
//获取到栈的栈顶元素的数据
string Stack::top(){
            return head->data;
        }
//抛出栈顶元素
string Stack::pop(){

    len --;
    Node* p;
    p = head;
            
    if(p == NULL){
        return "";
    }
           
    head = head->next;
    return p->data;
}


//窗前prefix对象，初始化 stack栈和digits栈
Prefix::Prefix(){stack = new Stack();digits = new Stack();status = 1;};
//根据操作符，和两个操作数计算数值
string Prefix::calculateData(string op, string left, string right){
            int lf;
            int rg;
            stringstream ss(left);
            ss >> lf;
            stringstream sr(right);
            sr >> rg;

            int res;

            //分四种操作服进行处理
            if(op.compare("+") == 0){
                res = lf + rg;

            }else if(op.compare("-") == 0){
                res = lf - rg;

            }else if(op.compare("*") == 0){
                res =  lf * rg;

            }else if(op.compare("/") == 0){
                if(rg == 0){
                    status = 0;
                    return "0";
                }
                res = lf / rg;

            }

            stringstream sres("");
            sres<< res;
            return sres.str();
        }

//是否是操作符，如果是，那么返回1 如果不是返回0
int Prefix::isOp(string op){
            if(op.compare("+") == 0 || op.compare("/") == 0 ||op.compare("*") == 0 ||op.compare("-") == 0 ){
                return 1;
            }
            return 0;
        }
//是否是数字，如果是那么返回1,如果不是那么返回0
int Prefix::isDigitStr(string op){
            for(int i=0;i<op.length();i++){
                if(!isdigit(op[i])){
                    return 0;
                }
            }
            return 1;
        }
//对所有前缀串的每个数据进行处理
int Prefix::calculate(vector<string>* op){
            int len = op->size()-1;
            while(len >= 0){
                //如果是操作符那么进行处理
                if(isOp(op->at(len))){
                    //从stack栈抛出两个操作数
                    string left = stack->pop();
                    string right = stack->pop();

                    if(left.compare("") == 0 || right.compare("") == 0){
                        
                        this->status = 0;
                        return -1;
                    }
                    //从digits栈中抛出两个字符串，进行前缀串转中缀串
                    string l = digits->pop();
                    string r = digits->pop();
                    //进行出栈 如栈处理
                    string str = op->at(len).compare("*") == 0 || op->at(len).compare("/") == 0 ? l + " "  + op->at(len) +  " " +r  : "(" + l + " "  + op->at(len) +  " " +r + ")" ;
                    digits->push(str);
                    stack->push(calculateData(op->at(len),left,right));
                    --len;
                //如果是数字的话，那么进行处理
                }else if(isDigitStr(op->at(len))){
                    //将当前数字压入digits 栈
                    digits->push(op->at(len));
                    --len;
                    //压人stack栈 用于计算前缀串的最终计算结果
                    stack->push(op->at(len+1));
                    
                }
            }
            //stack栈的栈顶就是最终的计算结果
            stringstream so(stack->top());
            int res;
            so >> res;
            //digits栈中的数据就是最终的中缀串
            int leng = digits->len;
            //cout << leng << "----------" << endl;
            if(leng != 1){
                status = 0;
            }
            

            if(status == 1){
                for(int i=0;i<leng;i++){
                    cout << digits->pop() ;
                }
            }
            
            
            return res;

};



