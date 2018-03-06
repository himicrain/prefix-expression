 
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include "prefix.h"
 
 //- * / 15 - 7 + 1 1 3 + 2 + 1 1
int main()
{   //创建一个Prefix对象
    Prefix* pre = new Prefix();
    //创建一个buffer 存储接收到的数据
    char buf[256] ;
    cin.getline(buf,256);
    char* p;
    //存放每个字符串
    vector<string>* buff = new vector<string>();

    //按照空格分割接收到的前缀字符串
    p = strtok(buf," ");
    while(p){
        buff->push_back(p);
        p = strtok(NULL," ");
    }
    //对数据进行处理
   int res = pre->calculate(buff);
   if(pre->status == 1){
        cout << " = " << res << endl;
   }else{
       cout << "Error" << endl;
   }

   

   return 0;
}