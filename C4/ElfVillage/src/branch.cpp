#include <include/branch.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

Branch* Branch::CreateTree(int treeIndex)
{
    Branch* root = new Branch("Tree " + std::to_string(treeIndex));
    int bigBranchesCount = 3 + std::rand() % 3; // 3..5
    for (int i = 0; i < bigBranchesCount; ++i)
    {
        Branch* big = new Branch("Big " + std::to_string(treeIndex) + "." + std::to_string(i + 1), root);
        root->AddChild(big);
        int middleBranchesCount = 2 + std::rand() % 2; // 2..3
        for (int j = 0; j < middleBranchesCount; ++j)
        {
            Branch* middle = new Branch("Middle " + std::to_string(treeIndex) + "." + std::to_string(i + 1) + "." + std::to_string(j + 1), big);
            big->AddChild(middle);
        }
    }
    return root;
}

void Branch::PrintTree(int level) const
{
    for (int i = 0; i < level; ++i)
    {
        std::cout << "    ";
    }
    std::cout << name_;
    if (!elfName_.empty())
    {
        std::cout << " - " << elfName_;
    }
    std::cout << std::endl;
    for (const Branch* child : children_)
    {
        child->PrintTree(level + 1);
    }
}

Branch* Branch::FindElf(const std::string& name)
{
    if (elfName_ == name)
    {
        return this;
    }
    for (Branch* child : children_)
    {
        Branch* result = child->FindElf(name);
        if (result != nullptr)
        {
            return result;
        }
    }
    return nullptr;
}

int Branch::GetNeighborsCount() const
{
    const Branch* bigBranch = this;
    while (bigBranch->parent_ != nullptr && bigBranch->parent_->parent_ != nullptr)
    {
        bigBranch = bigBranch->parent_;
    }
    if (bigBranch->parent_ == nullptr)
    {
        return 0;
    }

    int count = 0;
    std::vector<const Branch*> stack;
    stack.push_back(bigBranch);
    while (!stack.empty())
    {
        const Branch* node = stack.back();
        stack.pop_back();
        if (!node->elfName_.empty())
        {
            ++count;
        }
        for (const Branch* child : node->children_)
        {
            stack.push_back(child);
        }
    }
    if (!elfName_.empty())
    {
        --count;
    }
    return count;
}
