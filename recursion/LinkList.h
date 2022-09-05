//
// Created by Yulong on 2022/9/5.
//

#ifndef RECURSION_LINKLIST_H
#define RECURSION_LINKLIST_H

#include <iostream>
using namespace std;
typedef int ElemType;

/*
 * ������ṹ��Ķ���
 * ʵ�����ͺ�ָ�����Ͷ�����һ��
 * LNode�����Ϊʵ�����ͣ�LinkList�����Ϊָ������
 * ����nextָ��Ĵ��ڣ��ҵ���ͷ�����൱��������������
 * ���� LNode*��LinkList ����һ����ͬ������ǿ���㲻ͬ
 * ǿ������һ�������� --��LinkList
 * ǿ������һ����� --��LNode*
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
