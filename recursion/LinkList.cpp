//
// Created by Yulong on 2022/9/5.
//

#include "LinkList.h"

void test_LinkList()
{

}

/*
 * ��ʼ��һ������(��ͷ���)����Ҫ������
 */
bool InitList(LinkList &L)
{
    L= (LinkList) malloc(sizeof(LNode));
    if(L==NULL) return false;
    L->next= NULL;
    return true;
}

/*
 * �жϱ��Ƿ�Ϊ��(��ͷ���) ֻ��ͷ������Ϊ��
 */
bool Empty(LinkList L)
{
    if(L->next == NULL) return true;
    return false;
}

/**
 * ��λ�����(��ͷ���)
 * @param &L �������������
 * @param i ����λ��
 * @param e ����Ԫ��
 * @return bool
 */
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1) return false;
    LNode* p; //ָ��pָ��ǰɨ�赽�Ľ��
    p=L;      //pָ��ͷ��㣬ͷ��㲻������(Ϊ��0����� �� �ӵ�һ����㿪ʼ������)
    int j=0;  //��ʾ��ǰɨ�赽�˵ڼ������
    //ѭ���ҵ���i-1�����
    while(p!=NULL&&j<i-1)
    {
        p= p->next;
        j++;
    }
    if(p==NULL) return false;
    //�¶���һ�����s(����ռ䲢��������) �����ȥ
    LNode *s;
    s = (LNode*) malloc(sizeof(LNode));
    if(s==NULL) return false;       //λ�ò��Ϸ�
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


/*
 * ָ�����ĺ��
 * ��p���֮�����eԪ��
 */
bool InsertNextNode(LNode* p, ElemType e)
{
    if(p == NULL) return false;
    LNode* s;
    s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL) return false;//�ڴ����ʧ��
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

/*
 * ָ������ǰ��
 */
bool InsertPriorNode(LNode* p, ElemType e)
{//��p���֮ǰ����eԪ��    ���������½����뵽p���棬�ٽ������Ԫ�ؽ���
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

//��p���֮ǰ����s���
bool InsertPriorNode(LNode* p, LNode* s)
{//��p���֮ǰ����s���    ���������½����뵽p���棬�ٽ�����������򽻻�
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

