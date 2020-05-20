//
//  may_daily_leetcode.cpp
//  leetcode_cpp
//
//  Created by vvvchen on 2020/5/1.
//  Copyright © 2020 vvvchen. All rights reserved.
//

#include "daily_leetcode.hpp"

/*    // 5月1日， 顺序链表排序
 
 //  存在问题：如何递归求解

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}  //构造函数，实现初始化，如果这里有构造函数，则可以直接用ListNode list(10) 的方式，对node的value进行初始化
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode * head= new ListNode(-1);
        ListNode * flag= head;
        l1 = l1->next;
        l2 = l2->next;
        flag->next = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                flag->next = l1;
                l1 = l1->next;
                flag = flag->next;
                flag->next = nullptr;
            }
            else{
                flag->next = l2;
                l2 = l2->next;
                flag = flag->next;
                flag->next = nullptr;
            }
        }
        if (l1 == nullptr) {
            flag->next = l2;
        }
        else{
            flag->next = l1;
        }
        return head;
    }
    void show_link(ListNode * head){
        if (head->val == -1) {
           head = head->next;
        }

        while (head!= nullptr) {
            printf("%d\t",head->val);
            head = head->next;
            
        }
    }
   ListNode * link_input(ListNode * head){
        
        head = new ListNode(-1);
        ListNode *flag = head;
       int num=0;
       cout << "请输入链表的长度:";
       cin >> num;
       
        for (int i=0; i<num; i++) {
            ListNode *s = new ListNode(-1);
            cin >> s->val;
            flag->next = s;
            flag = flag->next;
        }
       flag ->next = nullptr;
       return head;
    }
};
int main(){
    
    Solution solution;
    ListNode *l1 = nullptr, *l2=nullptr, *result = nullptr;
    l1 = solution.link_input(l1);
    l2 = solution.link_input(l2);
    solution.show_link(l1);
    solution.show_link(l2);
    
    result = solution.mergeTwoLists(l1, l2);
    cout << "here is the result\n";
    
    solution.show_link(result);
}
 */


/*
// 5月3日 最大子序和

class Solution {
public:
    
    // 分治思想
//    struct Status {
//            int lSum, rSum, mSum, iSum;
//        };
    

//        Status pushUp(Status l, Status r) {
//            int iSum = l.iSum + r.iSum;
//            int lSum = max(l.lSum, l.iSum + r.lSum);    //这里有些无法理解
//            int rSum = max(r.rSum, r.iSum + l.rSum);
//            int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
//            return (Status) {lSum, rSum, mSum, iSum};
//        };
//
//        Status get(vector<int> &a, int l, int r) {
//            if (l == r) return (Status) {a[l], a[l], a[l], a[l]};
//            int m = (l + r) >> 1;  //相当于除以2
//            Status lSub = get(a, l, m);
//            Status rSub = get(a, m + 1, r);
//            return pushUp(lSub, rSub);
//        }
//
//        int maxSubArray(vector<int>& nums) {
//            return get(nums, 0, nums.size() - 1).mSum;
//        }

    
    
    
    
    int maxSubArray_dp(vector<int>& nums) {
        int length = nums.size();
        int result = 0;
        vector<int> dp_array;
        dp_array.push_back(nums[0]);
        for (int i=1; i<length; i++) {
            if (dp_array[i-1]<0) {
                dp_array.push_back(nums[i]);
                if (nums[i]>result) {
                    result = nums[i];
                }
            }
            else{
                int tmp = dp_array[i-1]+nums[i];
                dp_array.push_back(tmp);
                if (tmp>result) {
                    result = tmp;
                }
                
            }
        }
        return result;
    }
    

};

int main(){
    Solution solution;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5};
    cout << solution.maxSubArray(nums);
}

*/

// 补充 5.2 ：无重复字符的最长子串
/*
 思路1： 动态规划
 
 状态转移：字符串从a转移到ab，从ab转移到abc
 
 转移条件，没有接触 -- 和5.3的比较类似
 
 思路：一个存储最优的字符子串的情况，然后另一个进行遍历，如果增加的字符和前面的不重复，则加入。如果重复，则重新开始存储
 */

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//
//        int length = s.size();
//
//        string tmp,res;
//        int flag = 0;
//
//        for (int i=0; i<length; i++) {
//            int sub_length = tmp.size();
//            for (int j=0; j<sub_length; j++) {
//                if (s[i] == tmp[j]) {
//                    i=i-j-1;
//                    flag = 1;
//                    break;
//                }
//            }
//
//            if (flag == 1) { //说明已经生成一个子串了: 存在问题 判断子串的条件是 -- 重复 = 子串
//                if (tmp.size()>res.size()) {
//                    res = tmp;
//                }
//                tmp.clear();
//                flag = 0;
//            }
//            tmp.push_back(s[i]);
//        }
//        if (tmp.size() > res.size()) {
//            res = tmp;
//        }
//
//        cout << res;
//        return res.length();
//
//    }
//
//    int lengthOfLongestSubstring_standard(string s) {
//           //s[start,end) 前面包含 后面不包含
//           int start(0), end(0), length(0), result(0);
//           int sSize = int(s.size());
//           while (end < sSize)
//           {
//               char tmpChar = s[end];
//               for (int index = start; index < end; index++)
//               {
//                   if (tmpChar == s[index])
//                   {
//                       start = index + 1;
//                       length = end - start;
//                       break;
//                   }
//               }
//
//               end++;
//               length++;
//               result = max(result, length);
//           }
//           return result;
//       }
//};
//
//
//
//int main(){
//    Solution solution;
//    string s = "abcabcbb";
//    cout << solution.lengthOfLongestSubstring_standard(s);
//}

/*
 5.5日 验证二叉搜索树
 */

//
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//public:
////    bool isValidBST(TreeNode* root) {
////
////    }
//    //树的初始化
//    TreeNode * intialization_tree(){
//        int root_val = 0;
//        cin >> root_val;
//        TreeNode * root = new TreeNode(root_val);
//        tree_input(root);
//        return root;
//    }
//    void tree_input(TreeNode *node){
//        int left_val=0, right_val=0;
//        cin >> left_val;
//        cin >> right_val;
//        if (left_val == -1 ) {
//            node->left = nullptr;
//        }
//        else{
//            TreeNode * left = new TreeNode(left_val);
//            node->left = left;
//            tree_input(left);
//
//        }
//        if (right_val == -1) {
//            node->right = nullptr;
//        }
//        else{
//            TreeNode * right = new TreeNode(right_val);
//            node->right = right;
//            tree_input(right);
//        }
//    }
//
//    //树的遍历——前序
//    void tree_output(TreeNode *root){
//        cout << root->val;
//        if (root->left != nullptr) {
//            tree_output(root->left);
//        }
//        if (root->right != nullptr) {
//            tree_output(root->right);
//        }
//    }
//    //中根遍历
//    void tree_output_mid(TreeNode *root){
//        if (root->left != nullptr) {
//            tree_output(root->left);
//        }
//        cout << root->val;
//        if (root->right != nullptr) {
//            tree_output(root->right);
//        }
//    }
//    // 二叉树的遍历还蛮简单的 —— 错误原因：审题不清楚，问题是所有节点，而不是单一节点，所以要传输上下限

//    判断是否是二叉搜索树
//    bool tree_check(TreeNode *root){
//        if (root == nullptr) {
//            return true;
//        }
//        if(root->left == nullptr && root->right == nullptr){
//            return true;
//        }
//        bool result=true, result_left=true, result_right=true;
//
//
//        if (root->left != nullptr && root->right != nullptr) {   //如果左右节点都非空
//            if (root->left->val < root->val && root->right->val > root->val) {   //判断结果
//                result_left = tree_check(root->left);
//                result_right = tree_check(root->right);
//            }else{
//                result=false;
//            }
//        }
//        else if (root->left == nullptr && root->right != nullptr && (root->right)->val > root->val) {
//            result_right = tree_check(root->right);
//        }
//        else if (root->right == nullptr && root->left != nullptr && (root->left)->val < root->val) {
//            result_left = tree_check(root->left);
//        }
//        else if(root->left == nullptr && root->right == nullptr){
//            return true;
//        }
//        else{
//            return false;
//        }
//
//
//        if (result == false || result_right == false || result_left == false) {
//            return false;
//        }else{
//            return true;
//        }
//
//    }
//    bool helper(TreeNode *root, long long lower, long long upper){
//        if (root == nullptr) {
//            return true;
//        }
//        if (root->val <= lower || root->val >=upper) {
//            return false;
//        }
//        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
//    }
//
//    bool tree_check_2(TreeNode *root){
//        return helper(root,LONG_MIN,LONG_MAX);
//    }
//
////5.7 简单思路：两个函数，一个用来遍历，令一个用来判断是不是子树
//
//    bool check(TreeNode *s, TreeNode *t){
//        if (t==nullptr && s==nullptr) {
//            return true;
//        }
//        if(t!= nullptr && s!= nullptr && s->val == t->val){
//            return check(s->left, t->left) && check(s->right, t->right);
//        }else{
//            return false;
//        }
//    }
//    bool dfs(TreeNode *s, TreeNode *t){
//        if (s == nullptr) {
//            return false;
//        }
//        if (check(s, t)) {
//            return true;
//        }
//        return dfs(s->left, t) || dfs(s->right, t);
//    }
//    bool isSubtree(TreeNode *s, TreeNode *t) {
//        return dfs(s, t);
//    }
//
//    //另一个思路：利用遍历的特性
//    void tree_dfs(TreeNode *root,vector<int> &p){
//        p.push_back(root->val);
//        if (root->left != nullptr) {
//            tree_dfs(root->left,p);
//        }else{
//            p.push_back(-1);
//        }
//        if (root->right != nullptr) {
//            tree_dfs(root->right,p);
//        }else{
//            p.push_back(-1);
//        }
//    }
//    bool isSubtree_v2(TreeNode *s, TreeNode *t){
//        vector<int> s_tree, t_tree;
//        tree_dfs(s, s_tree);
//        tree_dfs(t, t_tree);
//    }
    
//    // 5月10日 二叉树的最近公共祖先
//    /*
//     特点：公共祖先如何判断： 两个值，一个在左子树中，另一个在右子树中  或者  其中一个就是公共祖先
//
//     理解 后序遍历
//     */
//    TreeNode * ans;
//    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q){
//
//        if (root == nullptr) {
//            return false;
//        }
//        bool lson = dfs(root->left, p, q);
//        bool rson = dfs(root->right, p, q);
//        if ((lson && rson) || ((root->val == p->val || root->val == q->val) &&(lson || rson))) {
//            ans = root;
//        }
//        return lson || rson || (root->val == p->val || root->val == q->val);    //如何理解这里：前边的条件：正常的dfs的判断条件，后边的条件，当搜索到达p,q的值的情况下
//    }
//
//
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//
//
//
//    }
//};

//int main(){
//    Solution solution;
//    /*
//     5.5日
//     */
////    TreeNode * root = solution.intialization_tree();
////    solution.tree_output_mid(root);
////    cout << "\n" << solution.tree_check_2(root);
//    /*
//     5月7日
//     */
//    TreeNode *s = solution.intialization_tree();
//    vector<int> s_tree;
//    solution.tree_dfs(s, s_tree);
//    for(int element: s_tree){
//        cout << element;
//    }
//    TreeNode *t = solution.intialization_tree();
//    cout << solution.check(s, t);
    
//}


// 5月4日 跳跃游戏ii

//思路：动态规划，从后到前
// 遗憾：动态规划会超时，但是思路是类似贪心的，但为什么超时了？
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int length = nums.size();
//        vector<int> dp_array;   //从后往前构建 动态规划数组
//        dp_array.push_back(0);
//
//        for (int i=length-2; i>=0; i--) {
//            if (nums[i]>=dp_array.size()) {
//                dp_array.push_back(1);
//                continue;
//            }
//            if (nums[i] == 0) {
//                dp_array.push_back(999);
//                continue;
//            }
//            int min_step = *min_element(dp_array.end()-nums[i], dp_array.end()); //这里可以优化？
//            dp_array.push_back(min_step+1);
//        }
//        cout << dp_array[0];
//        return dp_array[length-1];
//
//    }
////反向思维：贪心算法的遍历
//
//
//};
//
//int main(){
//
//    vector<int>nums={2,3,0,1,4,3,5,1,3,4,5,2,1,2};
//    Solution solution;
//    solution.jump(nums);
////    int max_val = *max_element(nums.begin(), nums.end()-3);
////    cout << max_val;
//}


// 5月5日
/*
 通行证只有：1，7，30
 价格给定
 使用的日期给定
 如果使用动态规划：
 */
//class Solution {
//public:
//    int mincostTickets(vector<int>& days, vector<int>& costs) {
//        int dayOfPass[] = {1, 7, 30};
//        int totalCost[366] = {0};
//        int i = 1;
//        int start;
//        for(int date: days)
//        {
//            while(i < date) //不出门的时候
//            {
//                totalCost[i] = totalCost[i - 1];
//                i++;
//            }
//
//            totalCost[i] = INT_MAX;  //此时i == date，需要出门
//            for(int ticket = 0; ticket < 3; ticket++)
//            {
//                start = i - dayOfPass[ticket];
//                if(start < 0)  start = 0;
//                totalCost[i] = min(totalCost[i], totalCost[start] + costs[ticket]);  //借助贪心的思路，在最前一天买票
//            }
//            i++;
//        }
//        return totalCost[days.back()];
//    }
//
//    //借鉴思路后 自己重新写一次
//
//    //内存可以减免：最终按理可以只存30天的
//    int mincostTickets_new(vector<int>& days, vector<int>& costs) {
//        vector<int> dayOfPass ={1,7,30};
//        int dayMax = days[days.size()-1];
//        int i=1;
//        vector<int>total_cost(dayMax+1, 0);   //第0天是0
//        for (int data: days) {
//            while (i<data) {   //不在的日子里
//                total_cost[i] = total_cost[i-1];
//                i++;
//            }
//
//            total_cost[i]= INT_MAX; // 标记一下，用最大值
//            for (int ticket=0; ticket<dayOfPass.size(); ticket++) {
//                int start = i - dayOfPass[ticket];  //找到当天，对于该方法的初始位置
//                if (start<0) {
//                    start = 0;   //如果初始位置为负数，则说明第0天就可以到达当天
//                }
//                total_cost[i] = min(total_cost[i],total_cost[start]+costs[ticket]);
//            }
//            i++;
//
//        }
//
//        return total_cost[dayMax];
//    }
//
//};

//
//int main(){
//    Solution solution;
//    vector<int> days = {1,4,6,7,8,20};
//    vector<int> costs = {2,7,15};
//    cout << solution.mincostTickets_new(days, costs);
//}

///* 机器人的运动范围 —— 搜索问题（广度&深度）*/
//class Solution {
//public:
//    bool map[100][100];
//    int movingCount(int m, int n, int k) {
//        for(int i=0; i<m;i++){
//            for (int j=0; j<n; j++) {
//                map[i][j]=0;
//            }
//        }
//        return dfs(0, 0, m, n, k);
//    }
//
//    int dfs(int x, int y, int m, int n, int k){
//
//        if (map[x][y] == 1 || x<0 || y<0 || x>=m || y<=n || (x/10 + x%10 + y/10 + y%10)>k) {
//            return 0;
//        }//判断条件
//
//        map[x][y]=1;
//
//        return dfs(x+1, y, m, n, k) + dfs(x, y+1, m, n, k) + 1; //巧妙的在这个return上，能够直接累计
//    }
//
//    int movingCount_bfs(int m, int n, int k){
//
//
//
//    }
//
//};

// 5月8日 最大正方形
//class Solution {
//public:
//    int check(int m,int n,int i, int j, vector<vector<char>> &matrix){
//        int rec_size;
//        int result=0;
//        if (i==1 && j==2) {
//            cout << "here";
//        }
//        for(rec_size=0;rec_size<m;rec_size++){
//            if (i+rec_size>=m || j+rec_size>=n ) {
//                break;
//            }
//            if ( matrix[i+rec_size][j+rec_size]=='0') {
//                break;
//            }
//            string rec_area;
//
//            for (int count=0; count<=rec_size; count ++) {
//                rec_area = rec_area + accumulate(matrix[i+count].begin()+j, matrix[i+count].begin()+j+rec_size,string(" "));
//            }
//            int rec_are = rec_area.length();
//            if (result<rec_are && rec_are == (rec_size+1)*(rec_size+1)) {
//                result = rec_are;
//            }
//        }
//
//        return result;
//
//    }
//
//    int maximalSquare(vector<vector<char>>& matrix) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        int result=0;
//
//
//        for (int i=0; i<m; i++) {
//            for (int j=0; j<n; j++) {
//                if (matrix[i][j]=='0') {
//                    continue;
//                }
//                int flag = check(m,n,i,j,matrix);
//                if (flag > result) {
//                    result = flag;
//                }
//            }
//        }
//        return result;
//    }
//};

//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        if (matrix.size() == 0 || matrix[0].size() == 0) {
//            return 0;
//        }
//        int maxSide = 0;
//        int rows = matrix.size(), columns = matrix[0].size();
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < columns; j++) {
//                if (matrix[i][j] == '1') {
//                    // 遇到一个 1 作为正方形的左上角
//                    maxSide = max(maxSide, 1);
//                    // 计算可能的最大正方形边长
//                    int currentMaxSide = min(rows - i, columns - j);
//                    for (int k = 1; k < currentMaxSide; k++) {
//                        // 判断新增的一行一列是否均为 1
//                        bool flag = true;
//                        if (matrix[i + k][j + k] == '0') {
//                            break;
//                        }
//                        for (int m = 0; m < k; m++) {
//                            if (matrix[i + k][j + m] == '0' || matrix[i + m][j + k] == '0') {
//                                flag = false;
//                                break;
//                            }
//                        }
//                        if (flag) {
//                            maxSide = max(maxSide, k + 1);
//                        } else {
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//        int maxSquare = maxSide * maxSide;
//        return maxSquare;
//    }
//};


//int main(){
//
//    Solution solution;
//    vector<vector<char>> matrix ={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
//    cout << solution.maximalSquare(matrix);
//
////    {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
//}



/* 最大正方形 需要复习 搜索方法*/


//5月9日 x的平方根
//class Solution {
//public:
//    int mySqrt(int x) {
//
//        if (x==1 || x==0) {
//            return x;
//        }
//        int a=0, b=x,t=0;
//        while (a<b) {
//
//            t = (a+b)/2;
//            if (x/t == t || (x/t>t && x/(t+1)<(t+1)) ) {
//                return t;
//            }
//            if (t*t<=x) {
//                a=t;
//            }
//            if (t*t>x) {
//                b=t;
//            }
//        }
//        return -1;
//    }
//};
//
//int main(){
//    Solution solution;
//    cout << solution.mySqrt(9);
//}


//5月10日

//5月11日

//class Solution {
//public:
//
//    // 暴力解法：存在问题 超时/越界
//    double myPow(double x, int n) {
//        double result = x;
//        if(n==0){
//            return 1;
//        }
//        if(n==1){
//            return result;
//        }
//        if(x==1 || x==0){
//            return x;
//        }
//        if(n<0){
//            result = 1/result;
//            x = 1/x;
//            n = -n;
//        }
//        for(int i=1; i<n; i++){
//            result = result*x;
//        }
//        return result;
//    }
//
//};

//5.17 课程表II  ———— 拓扑排序，图论中的学习
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        
        
    }
};
