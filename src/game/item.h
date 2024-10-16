#ifndef ITEM_H
#define ITEM_H

#pragma once
#include <string>

class Item {
    std::string name;
    char symbol;
    bool canInteract;

public:
    Item(const std::string& itemName, char itemSymbol, bool interactable);
    char getSymbol() const;
    bool isInteractable() const;
};


#endif //ITEM_H
