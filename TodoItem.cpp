//
// Created by nick on 7/10/23.
//

#include "TodoItem.h"
#include "Date.h"

TodoItem::TodoItem()
        : completed(false), DueDate(2020, 12, 12, 12, 12), description("") {}

TodoItem::TodoItem(bool completed, Date date,
                   const std::string_view &new_description)
        : completed(completed), DueDate(date), description(new_description) {}
// TodoItem::~TodoItem() = default;

std::string TodoItem::getDescription() const { return description; }

bool TodoItem::isCompleted() const { return completed; }

std::string TodoItem::getDueDate() const {
    std::string date = std::to_string(DueDate.getYear()) + "/" +
                       std::to_string(DueDate.getMonth()) + "/" +
                       std::to_string(DueDate.getDay()) + "/" +
                       std::to_string(DueDate.getHours()) + ":" +
                       std::to_string(DueDate.getMinutes());
    return date;
}

void TodoItem::serialize(std::ofstream &ofs) const {
    ofs.write(reinterpret_cast<const char *>(&completed), sizeof(completed));
    DueDate.serialize(ofs);
    size_t descriptionSize = description.size();
    ofs.write(reinterpret_cast<const char *>(&descriptionSize),
              sizeof(descriptionSize));
    ofs.write(description.c_str(), descriptionSize);
}

void TodoItem::deserialize(std::ifstream &ifs) {
    ifs.read(reinterpret_cast<char *>(&completed), sizeof(completed));
    DueDate.deserialize(ifs);
    size_t descriptionSize;
    ifs.read(reinterpret_cast<char *>(&descriptionSize), sizeof(descriptionSize));
    char buffer[1024]; // Assuming a maximum description length of 1023 characters
    ifs.read(buffer, descriptionSize);
    buffer[descriptionSize] = '\0';
    description = buffer;
}

void TodoItem::setCompleted(bool val) { completed = val; }

void TodoItem::editDate(int index, int value) {
    switch (index) {
        case 1:
            DueDate.setYear(value, true);
            break;
        case 2:
            DueDate.setMonth(value, true);
            break;
        case 3:
            DueDate.setDay(value);
            break;
        case 4:
            DueDate.setHours(value);
            break;
        case 5:
            DueDate.setMinutes(value);
            break;
        default:
            throw std::invalid_argument("invalid option");
    }
}

bool TodoItem::create(const std::string_view &new_description) {
    description = new_description;
    return true;
}

TodoItem::~TodoItem() = default;
