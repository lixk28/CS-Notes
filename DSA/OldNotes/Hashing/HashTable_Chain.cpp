#include "HashTable_Chain.h"

bool Hash::isPrime(int n)
{
    if(n < 2)
        return false;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int Hash::getP(int _size)
{
    for(int i = _size; i >= 2; i--)
    {
        if(isPrime(i))
            return i;
    }
    return 2;
}

Hash::Hash(int _size)
{
    HashTable = new HashTableNode[_size];
    size = _size;
    p = getP(_size);
}

Hash::~Hash()
{
    for(int i = 0; i < size; i++)
    {
        ChainNode *head = HashTable[i].ChainHead;
        while(head != NULL)
        {
            ChainNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
    delete[] HashTable;
}

void Hash::Insert(ElemType _key)
{
    int HashAddress = _key % size;
    ChainNode *tail = HashTable[HashAddress].ChainHead;
    ChainNode *newNode = new ChainNode(_key, NULL);

    if(tail == NULL)
        tail = new ChainNode(0, newNode);

    if(tail != NULL)
    {
        while(tail->next != NULL)
            tail = tail->next;
        tail->next = newNode;
    }
}


bool Hash::Delete(ElemType _key)
{
    int i;
    for(i = 0; i < size; i++)
    {
        ChainNode *head = HashTable[i].ChainHead;
        if(head == NULL)
            continue;
        if(head != NULL)
        {
            ChainNode *prev = head;
            ChainNode *curr = head->next;
            while(curr != NULL)
            {
                if(curr->key == _key)
                {
                    prev->next = curr->next;
                    delete curr;
                }
                else
                {
                    prev = prev->next;
                    curr = curr->next;
                }
            }
        }
    }

    if(i == size)
        return false;
    else
        return true;
}

bool Hash::Search(ElemType _key)
{
    for(int i = 0; i < size; i++)
    {
        ChainNode *curr = HashTable[i].ChainHead;
        if(curr == NULL)
            continue;
        if(curr != NULL)
        {
            curr = curr->next;
            while(curr != NULL)
            {
                if(curr->key == _key)
                    return true;
                curr = curr->next;
            }
        }
    }
    return false;
}

void Hash::display()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << "Line " << i + 1 << ":";
        ChainNode *head = HashTable[i].ChainHead;

        if(head != NULL)
        {
            ChainNode *curr = head->next;
            while(curr != NULL)
                std::cout << curr->key << " ";
        }

        std::cout << std::endl;
    }
}