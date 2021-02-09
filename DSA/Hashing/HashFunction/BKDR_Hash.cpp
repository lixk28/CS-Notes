/*
 * @Author: Xuekun Li
 * @Date: 2020-11-11 17:25:57
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-11 17:29:19
 * @Description: Try to code your bug.
 */

#include <iostream>
#include <string>
using namespace std;

unsigned int BKDR_Hash(string str, unsigned int HashTableSize)
{
	unsigned int HashAddress = 0;
    unsigned int seed = 131;  
    //Remember the SEED!!!

    for (unsigned int i = 0; i < str.length(); i++)
		HashAddress = (HashAddress * seed) + str[i];

	return HashAddress % HashTableSize;
}

int main()
{
    cout << "HAO YE!" << endl;

    return 0;
}
