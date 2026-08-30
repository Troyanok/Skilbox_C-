#pragma once

#include <string>
#include <vector>

/// @brief Класс ветви дерева (или самого дерева)
class Branch
{
public:
    /// @brief Конструктор ветви
    /// @param name Название ветви
    /// @param parent Указатель на родительскую ветвь (nullptr для корня)
    Branch(const std::string& name, Branch* parent = nullptr)
        : name_(name)
        , parent_(parent)
    {}

    /// @brief Деструктор Рекурсивно удаляет дочерние ветви
    ~Branch()
    {
        for (Branch* child : children_)
        {
            delete child;
        }
    }

    /// @brief Добавляет дочернюю ветвь
    /// @param child Указатель на дочернюю ветвь
    void AddChild(Branch* child)
    {
        children_.push_back(child);
    }

    /// @brief Возвращает указатель на родительскую ветвь
    /// @return Указатель на Branch или nullptr
    Branch* GetParent() const
    {
        return parent_;
    }

    /// @brief Возвращает вектор дочерних ветвей (неконстантная версия)
    /// @return Ссылка на вектор указателей
    std::vector<Branch*>& GetChildren()
    {
        return children_;
    }

    /// @brief Возвращает вектор дочерних ветвей (константная версия)
    /// @return Константная ссылка на вектор
    const std::vector<Branch*>& GetChildren() const
    {
        return children_;
    }

    /// @brief Возвращает название ветви
    /// @return Название
    std::string GetName() const
    {
        return name_;
    }

    /// @brief Возвращает имя эльфа
    /// @return Имя эльфа (пустая строка, если нет)
    std::string GetElfName() const
    {
        return elfName_;
    }

    /// @brief Устанавливает имя эльфа
    /// @param name Имя эльфа
    void SetElfName(const std::string& name)
    {
        elfName_ = name;
    }

    /// @brief Создаёт случайное дерево
    /// @param treeIndex Номер дерева
    /// @return Указатель на корневой Branch
    static Branch* CreateTree(int treeIndex);

    /// @brief Рекурсивно выводит дерево
    /// @param level Уровень вложенности
    void PrintTree(int level = 0) const;

    /// @brief Ищет эльфа по имени
    /// @param name Имя эльфа
    /// @return Указатель на ветвь или nullptr
    Branch* FindElf(const std::string& name);

    /// @brief Вычисляет количество соседей
    /// @return Количество соседей
    int GetNeighborsCount() const;

private:
    std::string name_;              ///< Название ветви
    std::string elfName_;           ///< Имя эльфа
    Branch* parent_;                ///< Родительская ветвь
    std::vector<Branch*> children_; ///< Дочерние ветви
};