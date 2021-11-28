#ifndef QUESTION6_H
#define QUESTION6_H
#include<iostream>
#include<stack>
using namespace std;
struct listnode
{
    int m_nvalue;
    listnode* next;
};

void AddToTail(listnode** pHead, int value)
{
    listnode* pNew = new listnode();
    pNew->m_nvalue = value;
    pNew->next = nullptr;

    if(pHead == nullptr)
    {
        *pHead = pNew;
    }
    else {
        listnode* pNode = *pHead;

        while (pNode->next != nullptr) {
            pNode = pNode->next;
        }

        pNode->next = pNew;
    }
}

void RemoveNode(listnode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
    {
        return;
    }

    listnode* pToDeleteNode = nullptr;
    if(pToDeleteNode->m_nvalue == value)
    {
        pToDeleteNode = *pHead;
        *pHead = (*pHead)->next;
    }
    else {
        listnode* pNode = *pHead;

        while (pNode->next != nullptr && pNode->next->m_nvalue != value) {
            pNode = pNode->next;
        }

        if(pNode->next != nullptr && pNode->next->m_nvalue == value)
        {
            pToDeleteNode = *pHead;
            *pHead = (*pHead)->next;
        }

    }
    if(pToDeleteNode != nullptr)
    {
        delete pToDeleteNode;
        pToDeleteNode = nullptr;
    }
}

void PrintReversingly_recursively(listnode* pHead)
{
    if(pHead != nullptr)
    {
        if(pHead->next != nullptr)
        {
            PrintReversingly_recursively(pHead->next);
        }

        cout << pHead->m_nvalue << endl;
    }
}

void PrintReversingly_recursively1(listnode* pHead)
{
    std::stack<listnode*> nodes;

    listnode* pNode = pHead;
    while (pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->next;
    }

    while (!nodes.empty()) {
        pNode = nodes.top();
        cout << pNode->m_nvalue << endl;
        nodes.pop();
    }
}

#endif // QUESTION6_H
