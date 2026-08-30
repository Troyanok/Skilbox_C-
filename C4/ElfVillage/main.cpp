#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <include/branch.h>

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    const int treeCount = 5;
    std::vector<Branch*> trees;

    for (int i = 0; i < treeCount; ++i)
    {
        Branch* tree = Branch::CreateTree(i + 1);
        trees.push_back(tree);
    }

    std::cout << "Generated forest:" << std::endl;
    for (const Branch* tree : trees)
    {
        tree->PrintTree();
        std::cout << std::endl;
    }

    std::cout << "Populate elves. Enter name for each house (or 'None' to skip):" << std::endl;
    for (Branch* tree : trees)
    {
        std::vector<Branch*> stack;
        for (Branch* child : tree->GetChildren())
        {
            stack.push_back(child);
        }
        while (!stack.empty())
        {
            Branch* node = stack.back();
            stack.pop_back();
            std::string input;
            std::cout << "Elf for " << node->GetName() << ": ";
            std::cin >> input;
            if (input != "None")
            {
                node->SetElfName(input);
            }
            for (Branch* child : node->GetChildren())
            {
                stack.push_back(child);
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Forest after population: " << std::endl;
    for (const Branch* tree : trees)
    {
        tree->PrintTree();
        std::cout << std::endl;
    }

    std::string searchName;
    std::cout << "Enter elf name to search: ";
    std::cin >> searchName;

    Branch* found = nullptr;
    for (Branch* tree : trees)
    {
        found = tree->FindElf(searchName);
        if (found != nullptr)
        {
            break;
        }
    }

    if (found != nullptr)
    {
        int neighbors = found->GetNeighborsCount();
        std::cout << "Elf " << searchName << " has " << neighbors << " neighbors." << std::endl;
    }
    else
    {
        std::cout << "Elf not found." << std::endl;
    }

    for (Branch* tree : trees)
    {
        delete tree;
    }

    return 0;
}