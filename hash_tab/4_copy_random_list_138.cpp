/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。
返回复制链表的头节点。

用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。
*/

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
解题思路: 难点是为random字段赋值
1, 记录每个原节点指针对应的copy节点指针。可以通过回溯法或者遍历两遍。通过hash表来存储。给random赋值时，通过查找hash表
2, 生成copy节点 + 拆分。random字段可以直接通过原节点的random字段找到。
*/
class Solution {
public:
    unordered_map<Node*, Node*> hash; // 全局的
    Node* copyRandomList1(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (hash.find(head) == hash.end()) {
            Node* newHeader = new Node(head->val);
            hash[head] = newHeader; // 要把newHeader先添加hash表
            newHeader->next = copyRandomList(head->next);
            newHeader->random = copyRandomList(head->random);
            // hash[head] = newHeader; 如果写在这里，head->next 和 head->random都是null才会走到这里。否则会一直循环，走不到这里。
        }
        return hash[head];
    }
    Node* copyRandomList2(Node* head) {
        if (nullptr == head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> hash;
        Node* copyHeader  = new Node(head->val);
        Node* res = copyHeader;
        hash[head] = copyHeader;
        // 生成copy list，只copy value和next，并记录原Node的指针对应的copy Node的指针，为random字段赋值准备。
        for(Node* tmp = head->next; tmp != nullptr; tmp = tmp->next) {
            copyHeader->next = new Node(tmp->val);
            copyHeader = copyHeader->next;
            hash[tmp] = copyHeader;
        }
        // 为random字段赋值
        for (Node *tmp1 = head, *tmp2 = res; tmp1 != nullptr; tmp1 = tmp1->next, tmp2 = tmp2->next) {
            tmp2->random = tmp1->random == nullptr ? nullptr : hash[tmp1->random];
        }
        return res;
    }

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        // 1, 生成copy节点
        for (Node* tmp = head; tmp != nullptr; tmp = tmp->next->next) {
            Node* newNode = new Node(tmp->val);
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        Node *res = head->next;
        // 2, 为copy节点的random字段赋值
        for (Node *oldNode = head, *newNode = head->next; newNode != nullptr;) {
            newNode->random = oldNode->random == nullptr ? nullptr : oldNode->random->next;
            oldNode = newNode->next;
            newNode = newNode->next == nullptr ? nullptr : newNode->next->next;
        }
        // 3, 拆分原节点和copy节点
        for (Node *oldNode = head, *newNode = head->next; newNode != nullptr; oldNode = oldNode->next, newNode = newNode->next) {
            oldNode->next = newNode->next;
            newNode->next = newNode->next == nullptr ? nullptr : newNode->next->next;
        }
        return res;
    }
};