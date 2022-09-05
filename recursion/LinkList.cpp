//
// Created by Yulong on 2022/9/5.
//

#include "LinkList.h"

void test_LinkList()
{

}

/*
 * 初始化一个链表(带头结点)，需要传引用
 */
bool InitList(LinkList &L)
{
    L= (LinkList) malloc(sizeof(LNode));
    if(L==NULL) return false;
    L->next= NULL;
    return true;
}

/*
 * 判断表是否为空(带头结点) 只有头结点代表为空
 */
bool Empty(LinkList L)
{
    if(L->next == NULL) return true;
    return false;
}

/**
 * 按位序插入(带头结点)
 * @param &L 传入链表的引用
 * @param i 插入位置
 * @param e 插入元素
 * @return bool
 */
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1) return false;
    LNode* p; //指针p指向当前扫描到的结点
    p=L;      //p指向头结点，头结点不存数据(为第0个结点 ， 从第一个结点开始存数据)
    int j=0;  //表示当前扫描到了第几个结点
    //循环找到第i-1个结点
    while(p!=NULL&&j<i-1)
    {
        p= p->next;
        j++;
    }
    if(p==NULL) return false;
    //新定义一个结点s(分配空间并存入数据) 插入进去
    LNode *s;
    s = (LNode*) malloc(sizeof(LNode));
    if(s==NULL) return false;       //位置不合法
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


/*
 * 指定结点的后插
 * 在p结点之后插入e元素
 */
bool InsertNextNode(LNode* p, ElemType e)
{
    if(p == NULL) return false;
    LNode* s;
    s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL) return false;//内存分配失败
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

/*
 * 指定结点的前插
 */
bool InsertPriorNode(LNode* p, ElemType e)
{//在p结点之前插入e元素    方法：将新结点插入到p后面，再将两结点元素交换
    if(p == NULL) return false;
    LNode* s;
    s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL) return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//在p结点之前插入s结点
bool InsertPriorNode(LNode* p, LNode* s)
{//在p结点之前插入s结点    方法：将新结点插入到p后面，再将两结点数据域交换
    if(p == NULL) return false;
    s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL) return false;
    s->next = p->next;
    p->next = s;
    ElemType temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}

