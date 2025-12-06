#include "Folder.h"
#include "Message.h"
#include <string>

void Message::save(Folder &fldr)
{
    folders.insert(&fldr);
    fldr.add_msg(*this);
}

void Message::add_folder(Folder &fldr)
{
    folders.insert(&fldr);
}
bool Message::rem_folder(Folder &fldr)
{
    return folders.erase(&fldr);
}

bool Message::remove(Folder &fldr)
{
    fldr.rem_msg(*this);
    return folders.erase(&fldr);
}
void Message::add_to_folders()
{
    for (const auto &elem : folders)
    {
        elem->add_msg(*this);
    }
}
void Message::rem_frm_folders()
{
    for (const auto &elem : folders)
    {
        elem->rem_msg(*this);
    }
    // folders.clear() should not be here.
    /*
     * Otherwise, Message &Message::operator=(const Message &msg) fails to correctly handle self-assignment.
     * There would be no way to add the message to its folders once it has been removed, because all pointers to folders
     * will be lost.
     *
     * Even without the concern for self-assignment, there is really no need to call std::set::clear() at all.
     * The "clearing" of a set is implicitly handled during destruction.
     */
}
Message::Message(const Message &msg) : content(msg.content), folders(msg.folders)
{
    add_to_folders();
}
Message &Message::operator=(const Message &msg)
{
    // Correctly handles self-assginment now.
    rem_frm_folders();
    content = msg.content;
    folders = msg.folders;
    add_to_folders();
    return *this;
}
// Move operators introduced in the upcoming section(s).
Message::Message(Message &&msg) : content(std::move(msg.content)), folders(std::move(msg.folders))
{
    for (const auto &elem : folders)
    {
        elem->rem_msg(msg);
        elem->add_msg(*this);
    }
    msg.folders.clear();
}

Message &Message::operator=(Message &&msg)
{
    // Handles self-assignment.
    if (this != &msg)
    {
        rem_frm_folders();
        msg = std::move(msg.content);
        folders = std::move(msg.folders);
        for (const auto &elem : folders)
        {
            elem->rem_msg(msg);
            elem->add_msg(*this);
        }
        // Clear() is necessary to make sure that we really have taken ownership over resources.
        msg.folders.clear();
    }
    return *this;
}

Message::~Message()
{
    rem_frm_folders();
}
// Assuming addresses are important here. Otherwise, it suffices to simply just swap(lhsm.content, rhsm.content);
// But this is a bit vague since the book never defined what it means to swap two messages.
void swap(Message &lhsm, Message &rhsm)
{
    lhsm.rem_frm_folders();
    rhsm.rem_frm_folders();
    swap(lhsm.folders, rhsm.folders);
    swap(lhsm.content, rhsm.content);
    lhsm.add_to_folders();
    rhsm.add_to_folders();
}
