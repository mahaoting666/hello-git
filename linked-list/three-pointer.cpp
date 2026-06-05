#include <iostream>
#include <cstddef>
using namespace std;

/*
// 链表里三大指针 head cur prev
head 链表的起点 保存链表的头地址 永远指向第一个节点
cur（current） 当前操作的节点 遍历链表或操作时的移动指针
prev（previous） 上一个节点 删除和反转链表时使用，记录cur的前驱节点

注 没有head 找不到链表 
   没有cur 无法遍历
   没有prev 删除与反转会很麻烦
*/

/*
// 删除节点
struct Node
{
    int val;
    Node* next;

    Node(int x)
    : val(x),next(nullptr){}
    
};
int mian()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    Node* cur = head;
    Node* prev = nullptr;

    while(cur!=nullptr)
    {
        if(cur->val == 20)
        {
            if(prev == nullptr)
            {   
                head = cur->next;
            }
            else{
                prev->next = cur->next;
            }
            delete(cur);
            break;
        }
        prev = cur;
        cur = cur->next;
    }
}
// 分两种情况 一种是要删除的是头节点 则就用不到prev 但判断条件是prev == nullptr
// 另一种不在头节点 需要同prev去覆盖cur 即要删除的元素
// 不管什么情况cur一定是要删除的元素 cur就是一个代替元素的变量

*/


// 反转链表  会用到prev
struct Node
{
    int val;
    Node* next;

    Node(int x)
    : val(x),next(nullptr){}
    
};
int main()
{
Node* head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);
 Node* prev = nullptr;
 Node* cur = head;


 while(cur != nullptr)
 {
    Node* nextnode = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nextnode;
 }
head = prev;
while(head != nullptr)
{
    cout << head->val <<endl;
    head = head->next;
}
}