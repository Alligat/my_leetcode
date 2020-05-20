//
//  daily_leetcode.cpp
//  leetcode_cpp
//
//  Created by vvvchen on 2020/4/20.
//  Copyright © 2020 vvvchen. All rights reserved.
//

#include "daily_leetcode.hpp"

// 孤岛问题 ———— 广度优先遍历

//
//class Solution {
//public:
//    /*广度搜索*/
//    int numIslands(vector<vector<char>>& grid) {
//        int n = grid.size();
//        if (n ==0) {
//            return 0;
//        }
//        int m = grid[0].size();
//
//        int num_island = 0;
//        for (int i=0; i<n; i++) {   //注意这里是要逐一搜索
//            for (int j=0; j<m; j++) {
//
//                if (grid[i][j] == '1') {
//                    grid[i][j] = '0';
//                    num_island++;
//                    queue<pair<int, int>> neighbors;
//                    neighbors.push({i,j});
//                    while (!neighbors.empty()) {
//                        auto rc = neighbors.front(); //注意这里 广度搜索的核心
//                        int ni = rc.first, nj = rc.second;
//                        neighbors.pop(); //注意：这里要弹出 —— 先加入，后弹出
//
//                        if (ni+1<n && grid[ni+1][nj] == '1') {
//                            neighbors.push({ni+1,nj});
//                            grid[ni+1][nj] = '0' ; //注意：必须要归0
//                        }
//                        if (ni-1>=0 && grid[ni-1][nj] == '1') {
//                            neighbors.push({ni-1,nj});
//                            grid[ni-1][nj] = '0' ;
//                        }
//                        if (nj+1 < m && grid[ni][nj+1] == '1') {
//                            neighbors.push({ni,nj+1});
//                            grid[ni][nj+1] = '0' ;
//                        }
//                        if (nj-1 >=0 && grid[ni][nj-1] == '1') {
//                            neighbors.push({ni,nj-1});
//                            grid[ni][nj-1] = '0' ;
//                        }
//                    }
//
//                }
//            }
//
//        }
//        return num_island;
//    }
//
//
//    int numIslands_deep(vector<vector<char>>& grid) {
//        cout << 3 << '\n';
//        return 0;
//    }
//
//};
//
//
//
//
//int main()
//{
//    Solution test;
//    int num_island;
//    vector<vector<char>> v = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
//    num_island = test.numIslands_deep(v);
//    cout << num_island << '\n';
//    return 0;
//}


// 全排列，树的广度优先搜索
//
//class Solution {
//public:
//    vector<vector<int>> res;
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<int> begin;
//        next(begin,nums);
//        return res;
//    }
//    void next(vector<int>& nums,vector<int>& left){
//        int n = nums.size(); // 计算 nums 的大小
//        int m = left.size(); // 计算 left 的大小
//        if(m==1){
//            nums.push_back(left[0]);    //如果等于1，说明只剩下一个元素了，可以到达结束条件
//            res.push_back(nums);        // 将 num 放到 res中，作为一次的结果
//            return;
//        }
//
//        for(int i = 0;i<m-1;i++){
//            vector<int> nv(nums);     //保存结果的vector
//            vector<int> nl(left);     //保存剩余的 vector
//            nv.push_back(nl[i]);
//            nl.erase(nl.begin()+i);   //每次A增加，B减少后，再次导入 --> 一直是A增加，B减少，直到A结束
//            next(nv,nl);
//        }
//
//        nums.push_back(left[m-1]);    // 已经使用完了这个数，？
//        left.pop_back();              //
//        next(nums,left);
//
//    }
//};

class Solution{
public:
    vector<vector<int>> res;
    vector<vector<int>>permute(vector<int>& nums) {
        vector<int> begin;
        next(begin, nums);
        return res;
    }
    void next(vector<int> &nums, vector<int> &left){
        int n = nums.size();
        int m = left.size();
        if (m == 1) {
            nums.push_back(left[0]);
            res.push_back(nums);
            return;
        }

        for (int i=0; i<m-1; i++) {    //此处的循环，代表对于第一个数字的变化
            vector<int> nv(nums);
            vector<int> nl(left);
            nv.push_back(nl[i]);
            nl.erase(nl.begin()+i);   // 读取的一种方式
            next(nv, nl);
        }

        nums.push_back(left[m-1]);
        left.pop_back();
        next(nums, left);

    }
};

/** 全排列的广度优先遍历的基本思路
 广度优先不会，第一次队列中只有起点这个第一步的所有可能，然后让起点出队，将第二步的 所有可能也就是（1，2），（2，1）入队，然后将第二步的所有可能出队，让第三步的所有可能入队，直到队列为空则说明结束，这里我们不说明队列的实现原理，有兴趣的同学可以上网搜索队列的实现，有很多大佬都深入浅出的讲解过。这里我们用c++stl中实现好的队列queue
 
 1. 判断结束的条件，left的数组为0，说明已经遍历到了尽头
 
 2. 对当前的可能进行遍历
 
 3. 当前可能结束，将
 
 
 */

//int main()
//{
//    Solution test;
//    vector<vector<int>> result;
//    vector<int> u = {1,2,3,4};
//    result= test.permute(u);
//    for(int i=0; i<result.size();i++)
//    {
//        for(int j=0; j<result[0].size();j++)
//        {
//                cout << result[i][j] << '\t';
//        }
//        cout << '\n';
//    }
//    return 0;
//}
