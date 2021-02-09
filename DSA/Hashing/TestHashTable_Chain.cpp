#include <iostream>
#include "HashTable_Chain.h"
#define JUST_CHECK
using namespace std;

int main()
{
    int size;
    cout << "Please enter the number of keys:" << endl;
    cin >> size;
    cout << "Please enter the keys:" << endl;
    int a[size];
    for(int i = 0 ; i < size; i++)
        cin >> a[i]; 

    cout << "Please enter the size of hash table:" << endl;
    int HTsize;
    cin >> HTsize;
    Hash HT(HTsize);
    for(int i = 0; i < size; i++)
        HT.Insert(a[i]);

    #ifdef JUST_CHECK
        HT.display();
    #endif
    
    int mode;
    while(true)
    {
        cout << "Please enter mode:" << endl;
        cin >> mode;
        if(mode == 1)
        {
            int k;
            cout << "Please enter the key to be inserted:" << endl;
            cin >> k;
            HT.Insert(k);
            #ifdef JUST_CHECK
                HT.display();
            #endif
        } 
        else if(mode == 2)
        {
            int k;
            cout << "Please enter the key to be deleted:" << endl;
            cin >> k;
            if(HT.Delete(k))
            {
                cout << "The key has been successfully deleted!" << endl;
            }
            else
            {
                cout << "The key doesn't exsit!" << endl;
            }
            #ifdef JUST_CHECK
                HT.display();
            #endif
        }
        else if(mode == 3)
        {
            int k;
            cout << "Please enter the key to be searching:" << endl;
            cin >> k;
            if(HT.Search(k))
            {
                cout << "The key exsits!" << endl;
            }
            else
            {
                cout << "The key doesn't exsit!" << endl;
            } 
        }
        else 
        {
            cout << "Invalid Input, please try again!" << endl;
        }
    }

    return 0;
}