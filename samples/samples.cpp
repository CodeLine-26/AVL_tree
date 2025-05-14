#include <iostream>
#include <limits>
#include "AVL_tree.h"
using namespace std;

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu()
{
    std::cout << "1. Добавить элементы" << endl;
    std::cout << "2. Удалить элементы" << endl;
    std::cout << "3. Показать дерево" << endl;
    std::cout << "4. Выход" << endl;
    std::cout << "Выберите действие: ";
}

void insertElements(AVL_tree& tree)
{
    std::cout << "\nВведите элементы для добавления (0 для завершения):" << endl;

    int value;
    while (true)
    {
        std::cout << "> ";

        if (!(cin >> value))
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число." << endl;
            clearInputBuffer();
            continue;
        }
        if (value == 0) break;

        try
        {
            tree.insert(value);
            std::cout << "Элемент " << value << " успешно добавлен." << endl;
        }
        catch (const logic_error& e)
        {
            std::cout << "Ошибка: " << e.what() << endl;
        }
    }
}

void removeElements(AVL_tree& tree)
{
    std::cout << "\nВведите элементы для удаления (0 для завершения):" << endl;

    int value;

    while (true)
    {
        std::cout << "> ";
        if (!(cin >> value))
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число." << endl;
            clearInputBuffer();
            continue;
        }
        if (value == 0) break;

        try {
            tree.erase(value);

            std::cout << "Элемент " << value << " успешно удален." << endl;
        }
        catch (const logic_error& e)
        {
            std::cout << "Ошибка: " << e.what() << endl;
        }
    }
}

void printTree(const AVL_tree& tree)
{
    std::cout << "\nТекущее состояние AVL-дерева:" << endl;
    std::cout << "-------------------------" << endl;
    tree.print();
    std::cout << "-------------------------" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    AVL_tree tree;
    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;

        clearInputBuffer();

        switch (choice)
        {
        case 1:
            insertElements(tree);
            break;
        case 2:
            removeElements(tree);
            break;
        case 3:
            printTree(tree);
            break;
        case 4:
            std::cout << "Выход из программы..." << endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, выберите от 1 до 4." << endl;
        }

    } while (choice != 4);

    return 0;
}