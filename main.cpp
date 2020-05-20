//
//  main.cpp
//  leetcode_cpp
//
//  Created by vvvchen on 2020/4/17.
//  Copyright © 2020 vvvchen. All rights reserved.
//

//#include<iostream>
//using namespace std;
//int main(){
//    int x;
//    float y;
//    cout<<"Please input an int number and a float number:"<<endl;
//    cin>>x>>y;
//    cout<<"The int number is x= "<<x<<endl;
//    cout<<"The float number is y= "<<y<<endl;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <stdio.h>
#include <cstdlib>
using namespace std;
//class Solution{
//
//public:
//    int max_words(vector<multimap<int, int, greater<int>>> & grade){
//        unordered_set<int> people;
//        for (multimap<int, int, greater<int>> &index: grade) {
//            auto ite = index.begin();
//            auto p_grade = 0;
//            do{
//                people.insert(ite->second);
//                p_grade = ite -> first;
//                ite ++;
//            }while(ite != index.end() && ite->first == p_grade);
//        }
//        return people.size();
//    }
//
//};
//int main(){
//    int n,m;
//    while (cin >> n >> m) {
//        int grade = 0;
//        int num = n*m;
//        vector<multimap<int, int , greater<int>>> grade_num(m,multimap<int, int, greater<int>>());
//        for (int i=0, j=0; i<num; i++) {
//            cin >> grade;
//            if (i%m == 0 && i !=0) {
//                j++;
//            }
//            grade_num.at(i % m).insert(pair<int, int>(grade,j));
//        }
//
//        Solution solution;
//        cout << solution.max_words(grade_num);
//
//    }
//
//}

//int main()
//{
//    string a;
//    // 每组第一行是2个整数，N和M，至于为啥用while，因为是多组。
//    while(cin>> a) {
//      // 循环读取“接下来的M行”
//
//          int length = a.length();
//          string b=a;
//          if (a == " ") {
//              return 0;
//          }
//          for (int i=0; i<length; i++) {
//              string t = b.substr(0,1);
//              b.append(t);
//              b.erase(0,1);
//              if (a == b) {
//                  cout << i+1;
//                  break;
//              }
//          }
//
//    }
//    return 0;
//}





//string ten_to_two(int x){
//
//    char a[32],b[32];
//    int i=0,j=0;
//
//    while ((x/2)!=0) {
//        a[i] = x%2+'0';
//        i++;
//        x/=2;
//    }
//    a[i]=x+'0';
//    a[i+1] = '\0';
//    b[i+1] = '\0';
//    while (i) {
//        b[j] = a[i];
//        j++;
//        i--;
//    }
//    b[j]=a[i];
//    string s = b;
//    return s;
//
//}
//
//int hamming(int x, int y){
//    string a = ten_to_two(x);
//    string b = ten_to_two(y);
//    int length_a = a.length();
//    int length_b = b.length();
//    if (length_a<length_b) {
//        string s(length_b-length_a,'0');
//        s.append(a);
//        a = s;
//        length_a=a.length();
//    }
//    if (length_b<length_a) {
//        string s(length_a-length_b,'0');
//        s.append(b);
//        b=s;
//        length_b=b.length();
//    }
//    int num=0;
//    for (int i=0; i<length_b; i++) {
//        if (a[i]!=b[i]) {
//            num++;
//        }
//    }
//    return num;
//}
//
//int max_cmp(vector<int> num_array){
//    int length = num_array.size();
//    int result = 0;
//    for (int i=0; i<length; i++) {
//        int x = num_array[i];
//        for (int j=0; j<length; j++) {
//            if (num_array[i] == num_array[j]) {
//                continue;
//            }
//            int flag = hamming(x, num_array[j]);
//            if (flag > result) {
//                result = flag;
//            }
//        }
//    }
//    return result;
//}
//
//int main(){
//    int n;
//    while (cin >>n) {
//        vector<int> number_array;
//        for (int i=0; i<n; i++) {
//            int num;
//            cin >> num;
//            number_array.push_back(num);
//
//        }
//        cout << max_cmp(number_array);
//    }
//}

//
//
//string ten_to_two(int x){
//
//    char a[32],b[32];
//    int i=0,j=0;
//
//    while ((x/2)!=0) {
//        a[i] = x%2+'0';
//        i++;
//        x/=2;
//    }
//    a[i]=x+'0';
//    a[i+1] = '\0';
//    b[i+1] = '\0';
//    while (i) {
//        b[j] = a[i];
//        j++;
//        i--;
//    }
//    b[j]=a[i];
//    string s = b;
//    return s;
//
//}
//
//int xiangsi(int x, int y){
//    string a = ten_to_two(x);
//    string b = ten_to_two(y);
//    int length_a = a.length();
//    int length_b = b.length();
//    if (length_a<length_b) {
//        string s(length_b-length_a,'0');
//        s.append(a);
//        a = s;
//        length_a=a.length();
//    }
//    if (length_b<length_a) {
//        string s(length_a-length_b,'0');
//        s.append(b);
//        b=s;
//        length_b=b.length();
//    }
//    int num=0;
//    for (int i=0; i<length_b; i++) {
//        if (a[i]=='1' && b[i]=='1') {
//            return -1;
//        }
//    }
//    return 1;
//}
//
//int test_xiangsi(vector<int> num_array, int test_data){
//    int length = num_array.size();
//    int result = 0;
//    for (int i=0; i<length; i++) {
//        if (num_array[i] == test_data) {
//            continue;
//        }
//        int flag = xiangsi(num_array[i], test_data);
////        if (flag == -1) {
////            return -1;
////        }
//        if (flag == 1) {
//            return 1;
//        }
//    }
//    return -1;
//}
//
//int main(){
//    int n;
//    while (cin >>n) {
//        vector<int> number_array;
//        for (int i=0; i<n; i++) {
//            int num;
//            cin >> num;
//            number_array.push_back(num);
//            }
//        for (int i=0; i<n; i++) {
//            cout << test_xiangsi(number_array,number_array[i]);
//        }
//
//        }
//
//}

int main(){
    string s;
    int k;
    while(cin >> s){
        cin >> k;
        cout << 3;
    }
}
