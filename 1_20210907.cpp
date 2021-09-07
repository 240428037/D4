//一维数组
int nums[]={1,2,3,4};
sizeof(nums)=16//sizeof(数组名)-数组的大小
sizeof(*&nums)=16
sizeof(*nums)=4//nums是首元素的地址-int*
sizeof(nums+1)=4//nums是首元素的地址-nums+1-2的地址
sizeof(&nums)=4//数组的地址-数组指针
sizeof(&a[0])=4//1的地址

//字符数组
char nums[]={'a','b','c','d','e','f'};//nums是一个6个字符的数组
sizeof(nums)=6
sizeof(&nums)=4//&nums-指针
strlen(nums)=不确定

char nums[]="abcdef";//nums是一个7个字符的数组
sizeof(nums)=7
sizeof(&nums)=4//&nums-指针
strlen(nums)=6
strlen(&arr[0]+1)=5//&arr[0]=a的地址-+1从b开始往后算长度

char*p="abcdef";





// struct ListNode{
//     int val;
//     struct ListNode*next;
//     ListNode(x):val(x),next(nullptr){}
// };
//慢指针入环后一圈之内就会被快指针追上
//此时快指针走过的路程是慢指针的2倍
//head-entry:L
//entry-meet:X
//环周长C
//meet-entry:C-X
//2(L+X)=L+X+NC
//L+X=NC
//L=NC-X
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode*head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode*meet=fast;
                while(head!=meet){
                    head=head->next;
                    meet=meet->next;
                }
                return meet;
            }
        }
        return nullptr;
    }
};




// struct ListNode{
//     int val;
//     struct ListNode*next;
//     ListNode(int x):val(x),next(nullptr){}
// }
//链表判环
//必须是慢指针一次走一步-快指针一次走两步
//如果有环
//快指针先入环-慢指针后入环
//慢指针入环后和快指针距离为N
//两个指针每走一步
//距离减小1
//N
//N-1
//...
//0
//如果有环则一定相遇
//但是如果快指针一次不是走两步而是其他步数
//则极端情况下有可能永远不会相遇
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
//环的入口点
//head entry meet
//环周长-C
//head->entry-L
//entry-meet-X
//meet-entry-C-X
//慢指针入环后一圈之内就会被快指针追上
//相遇时-快指针走过的路程是慢指针的2倍
//2(L+X)=L+X+NC
//L+X=NC
//L=NC-X
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode*meet=fast;
                while(head!=meet){
                    head=head->next;
                    meet=meet->next;
                }
                return meet;
            }
        }
        return nullptr;
    }
};



/**
* struct ListNode {
*    int val;
*    struct ListNode *next;
*    ListNode(int x) : val(x), next(nullptr) {}
* };
*/
//解题思路
//快慢指针
//需要注意k大于链表长度的情况-放在while(k--)中处理
//-if(fast==nullptr)return nullptr;
class Solution {
public:
    ListNode* FindKthToTail(ListNode*head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(k--){
            if(fast==nullptr){
                return nullptr;
            }
            fast=fast->next;
        }
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};


/**
* struct ListNode {
*    int val;
*    struct ListNode *next;
* };
*/
//测试用例
//12345,n=2
//1235
//解题思路
//快慢指针先找到倒数第n个节点-链表的倒数第k个节点
//快指针先走k步-然后快慢指针一起走-快指针为空-慢指针指向节点即为倒数第k个
//将slow的前一个节点保存下来prev
//链接prev->next=slow->next;
//特殊情况!!!
//要删除的节点就是头节点
//if(fast==nullptr)return head->next;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head;
        ListNode*fast=head;
        //12,2
        while(n--){
            fast=fast->next;
        }
        //12,2-要删除的节点就是头节点-返回头节点的下一个节点
        if(fast==nullptr){
            return head->next;
        }
        ListNode*prev=nullptr;
        while(fast){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        return head;
    }
};
