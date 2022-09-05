//
// Created by Yulong on 2022/9/5.
//

#ifndef RECURSION_LINKLIST_H
#define RECURSION_LINKLIST_H

#include <iostream>
using namespace std;
typedef int ElemType;

/*
 * 单链表结构体的定义
 * 实体类型和指针类型定义在一起
 * LNode定义的为实体类型，LinkList定义的为指针类型
 * 由于next指针的存在，找到了头结点就相当于有了整个链表
 * 所以 LNode*和LinkList 含义一般相同，但是强调点不同
 * 强调这是一个单链表 --用LinkList
 * 强调这是一个结点 --用LNode*
 */
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


void test_LinkList();

bool InitList(LinkList &L);

bool Empty(LinkList L);

bool ListInsert(LinkList &L, int i, ElemType e);

bool InsertNextNode(LNode* p, ElemType e);

bool InsertPriorNode(LNode* p, ElemType e);

bool InsertPriorNode(LNode* p, LNode* s);

bool ListDelete(LinkList &L, int i);

bool DeleteNode(LNode* p);

void showAll(LinkList L);

LNode* GetElem(LinkList L, int i);

LNode* LocateElem(LinkList L, ElemType e);

int Length(LinkList L);

LinkList TailInsert(LinkList &L);

LinkList HeadInsert(LinkList &L);


#endif //RECURSION_LINKLIST_H
