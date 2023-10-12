#include <iostream>
#include <string>
#include "LinkedList.cpp"

int main()
{
    LinkedList<int> LLInt;
    LLInt.add(100);
    LLInt.add(200);
    LLInt.add(300);
    LLInt.add(400);

    std::cout << "Size is: " << LLInt.getSize() << std::endl; //my line
    for (int i = 0; i < LLInt.getSize(); ++i)
    {
        std::cout << LLInt.getByIndex(i) << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Calling deleteByIndex( 1 ):  " <<  std::endl; //my line
    LLInt.deleteByIndex(1);
    std::cout << "Size is: " << LLInt.getSize() << std::endl; //my line
    for (int i = 0; i < LLInt.getSize(); ++i)
    {
        std::cout << LLInt.getByIndex(i) << std::endl;
    }

    std::cout << "Calling deleteByValue( \"Three Hundred\" ):  " <<  std::endl; //my line
    std::cout << std::endl;
    LLInt.deleteByValue(300);
    std::cout << "Size is: " << LLInt.getSize() << std::endl; //my line
    for (int i = 0; i < LLInt.getSize(); ++i)
    {
        std::cout << LLInt.getByIndex(i) << std::endl;
    }

    std::cout << std::endl;

    LinkedList<std::string> LLString;
    LLString.add("One Hundred");
    LLString.add("Two Hundred");
    LLString.add("Three Hundred");
    LLString.add("Four Hundred");

    for (int i = 0; i < 4; ++i)
    {
        std::cout << LLString.getByIndex(i) << std::endl;
    }
}