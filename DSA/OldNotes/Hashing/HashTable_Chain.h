#include <cstddef>
#include <iostream>
typedef int ElemType;

struct ChainNode
{
    ElemType key;
    ChainNode *next;
    ChainNode() { key = 0, next = NULL; }
    ChainNode(ElemType _key, ChainNode *_next) { key = _key, next = _next;}
};

struct HashTableNode
{
    ChainNode *ChainHead;
    HashTableNode() { ChainHead = new ChainNode; }
};

class Hash
{
    private:
        HashTableNode *HashTable;
        int size;
        int p;
        int getP(int _size);
        bool isPrime(int n);

    public:
        Hash(int _size);
        ~Hash();

        void Insert(ElemType _key);
        bool Delete(ElemType _key);
        bool Search(ElemType _key);

        void display();
};




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
    int HashAddress = _key % p;
    ChainNode *head = HashTable[HashAddress].ChainHead;

    if(head->next == NULL)
    {
        head->next = new ChainNode(_key, NULL);
    }
    else
    {
        ChainNode *tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new ChainNode(_key, NULL);
    }
}


bool Hash::Delete(ElemType _key)
{
    int i;
    for(i = 0; i < size; i++)
    {
        ChainNode *head = HashTable[i].ChainHead;
        if(head->next != NULL)
        {
            ChainNode *prev = head;
            ChainNode *curr = head->next;

            while(curr != NULL)
            {
                if(curr->key == _key)
                {
                    prev->next = curr->next;
                    delete curr;
                    curr = NULL;
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
        std::cout << "HashLine " << i << ":";
        ChainNode *head = HashTable[i].ChainHead;

        if(head->next != NULL)
        {
            ChainNode *curr = head->next;
            while(curr != NULL)
            {
                std::cout << curr->key << " ";
                curr = curr->next;
            }
        }

        std::cout << std::endl;
    }
}