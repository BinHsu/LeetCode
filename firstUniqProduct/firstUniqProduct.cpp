// firstUniqProduct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cassert>
std::string firstUniqProduct(std::vector<std::string>& products)
{
    if (products.empty())
    {
        return "";
    }
    //product, num, index
    std::map<std::string, std::pair<int, int> > productList;
    for (int i = 0; i < products.size(); ++i)
    {
        const auto& productName = products[i];
        auto it = productList.find(productName);
        if (productList.end() == it)
        { 
            productList[productName] = std::make_pair(1, i);
        }
        else
        {
            productList[productName].first++;
        }
    }
    for (auto it = productList.begin(); it != productList.end();)
    {
        if (1 != it->second.first)
        {
            it = productList.erase(it);
        }
        else
        {
            ++it;
        }
    }
    int minPos = products.size();
    for (const auto& product : productList)
    {
        if (product.second.second < minPos)
        {
            minPos = product.second.second;
        }
    }
    return products[minPos];
}

int main()
{
    std::vector<std::string> products{"apple", "banana", "apple", "mango"};
    const auto answer = firstUniqProduct(products);
    std::cout << answer << std::endl;
    assert(answer == "banana");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
