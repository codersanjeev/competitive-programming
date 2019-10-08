//
//  main.cpp
//  Hello-World
//
//  Created by ingenuo-yag on 09/07/19.
//  Copyright © 2019 ingenuo-yag. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

int main()
{
    //cout<<"This is the test file\n";
    //int a = 5;//copy initialisation
    //int b(6);//direct initialisation
    //int c{5};//uniform initialisation(preferred)
    //int n;
    //Initialization gives a variable a value at the point when it is created. Assignment gives a variable a value at some point after it is created.
    //cout<<a<<b<<c<<endl;
    //cout<<n<<endl;
    //'/n' is preferred over endl
    string a = "abc";
    int n = (int)a.size();
    cout<<n<<endl;
    return 0;
}
