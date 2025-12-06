#include <string>
#include <set>
class Folder;
// I did not write it as precisely described in this section. This is my version of Message.
class Message
{
    friend void swap(Message &, Message &);

private:
    std::string content;
    std::set<Folder *> folders;
    void add_to_folders();
    void rem_frm_folders();

public:
    void save(Folder &fldr);
    bool remove(Folder &fldr);
    void add_folder(Folder &fldr);
    bool rem_folder(Folder &fldr);
    Message(const std::string &str = " ") : content(str) {}
    Message(const Message &msg);
    Message(Message &&msg) noexcept;
    Message &operator=(Message &&msg) noexcept;
    Message &operator=(const Message &msg);
    ~Message();
};
