# 206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

## 示例 1：
![1](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
## 示例 2：
![2](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

输入：head = [1,2]
输出：[2,1]
## 示例 3：

输入：head = []
输出：[]

## 提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000

## 代码：
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};


## 做法：
迭代完成。
## 时间复杂度：
O(n),O(1)


