// FriendIsConnected.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <set>
class Friend
{
    std::string email;

public:
    Friend(const std::string& email)
        : email(email)
    {}

    void AddFriend(Friend* target)
    {
        friends.push_back(target);
        target->friends.push_back(this);
    }

    std::string Email() const
    {
        return email;
    }

    bool isConnected(Friend* target)
    {
        std::set<std::string> emails;
        emails.insert(email);
        return myFunc(target, emails);
    }

    bool myFunc(const Friend* target, const std::set<std::string>& nodes)
    {
        for (const auto& friendNode : friends)
        {
            std::cout << friendNode->Email() << std::endl;
            if (friendNode->Email() == target->Email())
            {
                return true;
            }
            if (nodes.end() != nodes.find(friendNode->Email()))
            {
                continue;
            }
            auto nodesPlus = nodes;
            nodesPlus.insert(friendNode->Email());
            if (friendNode->myFunc(target, nodesPlus))
            {
                return true;
            }
        }
        return false;
    }
    std::list<Friend*> friends;
};

int main()
{
    Friend A("a");
    Friend B("b");
    Friend C("c");
    Friend D("d");
    Friend E("e");
    A.AddFriend(&B);
    B.AddFriend(&C);
    C.AddFriend(&D);
    D.AddFriend(&B);
    D.AddFriend(&E);
    std::cout << A.isConnected(&E) << std::endl;
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
