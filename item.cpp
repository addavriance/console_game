#include "item.h"

Item::Item(const std::string& itemName, char itemSymbol, bool interactable)
    : name(itemName), symbol(itemSymbol), canInteract(interactable) {}

char Item::getSymbol() const {
    return symbol;
}

bool Item::isInteractable() const {
    return canInteract;
}
