#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int e;
    struct node *next;
}Node,*NodePtr;

void traverseList(Node *head);
Node* createList();
void insertList(Node *head, int e);
int lenList(Node *head);
Node* searchList(Node *head, int e);
void deleteNodeOfList(Node *head, Node *pFind);
void sortList(Node *head);
void reverseList(Node *head);
void destoryList(Node *head);

int main()
{
    Node *head = createList();
    for (int i = 0;i < 10; i++) {
        insertList(head, i);
    }
    int len = lenList(head);
    printf("len = %d\n", len);
    traverseList(head);
    Node *pFind = searchList(head, 0);
    if (NULL == pFind) {
        printf("find none\n");
    } else {
        printf("find value = %d\n", pFind->e);
//        deleteNodeOfList(head, pFind);
    }

    printf("after sort\n");
    sortList(head);
    traverseList(head);

    printf("after reverse\n");
    reverseList(head);
    traverseList(head);

    destoryList(head);
    return 0;
}

// 创建虚拟头节点
Node* createList()
{
    Node *head = (Node*)malloc(sizeof (Node));
    if (NULL == head)
        exit(-1);

    head->next = NULL;
    return head;
    //    Node *tail = head, *cur;
    //    Node *cur;

    //    int e;
    //    scanf("%d", &e);
    //    while (e) {
    //        cur = (Node*)malloc(sizeof (Node));
    //        if (NULL == cur)
    //            exit(-1);
    // 尾部插入(当前尾部节点的下一个节点指向新的节点，再将尾部节点位置移动新的节点)
    //        cur->e = e;
    //        tail->next = cur;
    //        tail = cur;
    //
    // 头部插入(新的节点的下一个节点指向头部节点的下一个节点，头部节点的下一个节点指向新的节点)
    //        cur->e = e;
    //        cur->next = head->next;
    //        head->next = cur;
    //        scanf("%d", &e);
    //    }
    //    tail->next = NULL;
}

// 头部插入(让新来的节点先有指向，避免打断原来的指向关系)
void insertList(Node *head, int e)
{
    Node *cur = (Node*)malloc(sizeof (Node));
    if (NULL == cur)
        exit(-1);
    cur->e = e;
    cur->next = head->next;
    head->next = cur;
}

// 链表长度
int lenList(Node *head)
{
    int len = 0;
    head = head->next; // 过滤虚拟头节点
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// 查找元素所在节点
Node* searchList(Node *head, int e)
{
    Node *cur = head->next;
    while (cur) {
        if (cur->e == e)
            break;
        cur = cur->next;
    }
    return cur;
}

// 删除节点
void deleteNodeOfList(Node *head, Node *pFind)
{
    // 删除的节点为最后一个元素
    if (NULL == pFind->next) {
        Node *cur = head;
        while (cur->next != pFind) {
            cur = cur->next;
        }
        cur->next = pFind->next;
        free(pFind);
    } else {
        Node *tmp = pFind->next;
        pFind->e = tmp->e;
        pFind->next = tmp->next;
        free(tmp);
    }
}

// 链表排序
//void sortList(Node *head)
//{
//    int len = lenList(head);
//    head = head->next;
//    Node *p, *q;
//    for (int i = 0; i < len - 1; i++) {
//        p = head; // 每次循环重头开始
//        q = p->next; // q 始终指向 p 的下一个节点
//        for (int j = 0; j < len - i - 1; j++) {
//            // 换值冒泡排序
//            if (p->e > q->e) {
//                p->e ^= q->e;
//                q->e ^= p->e;
//                p->e ^= q->e;
//            }
//            p = p->next;
//            q = p->next;
//        }
//    }
//}

void sortList(Node *head)
{
    int len = lenList(head);
    Node *prev, *p, *q, *tmp;
    for (int i = 0; i < len - 1; i++) {
        prev = head; // 每次指向虚拟头节点
        p = head->next;
        q = p->next;
        for (int j = 0; j < len - 1 - i; j++) {
            if (p->e > q->e) {
                // 交换 p，q 的指向
                prev->next = q; // 上一节点指向q
                p->next = q->next; // p 的下一节点指向 q 的下一节点
                q->next = p; // q 的下一节点指向 p
                // 重置 p，q 的位置
                tmp = p;
                p = q;
                q = tmp;
            }
            prev = prev->next;
            p = p->next;
            q = p->next;
        }
    }
}

// 逆置链表
void reverseList(Node *head)
{
    // 分割成两个链表，一个只留虚拟头节点，一个保留剩余部分
    // 运用前插法逆置链表
    Node *cur = head->next, *tmp;
    head->next = NULL;

    while (cur) {
        tmp = cur->next;
        // 先让新来的节点有所指向
        cur->next = head->next;
        head->next = cur;
        cur = tmp;
    }
}

// 销毁链表
void destoryList(Node *head)
{
    Node *tmp;
    while (head) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

// 遍历输出
void traverseList(Node *head)
{
    head = head->next;
    while (head) {
        printf("%d\t", head->e);
        head = head->next;
    }
    puts("");
}
