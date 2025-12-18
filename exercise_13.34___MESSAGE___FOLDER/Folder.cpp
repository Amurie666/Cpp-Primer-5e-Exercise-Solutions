#include "Folder.h"

void Folder::add_msg(const Message& msg) {
    msgs.insert(&msg);
}

bool Folder::rem_msg(const Message& msg) {
    return msgs.erase(&msg);
}