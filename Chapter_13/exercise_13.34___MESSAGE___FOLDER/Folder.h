#include <set>
class Message;

class Folder
{
private:
    std::set<const Message *> msgs;

public:
    void add_msg(const Message &msg);
    bool rem_msg(const Message &msg);
};
