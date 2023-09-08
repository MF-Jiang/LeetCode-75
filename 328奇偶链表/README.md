# 328. 奇偶链表

给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。

请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

 

## 示例 1:

![1](https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg)

输入: head = [1,2,3,4,5]
输出: [1,3,5,2,4]
## 示例 2:

![2](https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg)

输入: head = [2,1,3,5,6,4,7]
输出: [2,3,6,7,1,5,4]
 

## 提示:

n ==  链表中的节点数
0 <= n <= 104
-106 <= Node.val <= 106

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};


## 做法：
![1](https://assets.leetcode-cn.com/solution-static/328/1.png)
## 时间复杂度：
O(n)，O(1)

