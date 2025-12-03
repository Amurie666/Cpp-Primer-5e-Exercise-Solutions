#include <memory>
#include <string>
#include <vector>
#include <algorithm>
class destination;
class connection
{
    friend void disconnect(connection *);
    friend connection connect(destination *);
    connection(destination *dest) : active(0), target(dest) {}

private:
    bool active;
    destination *target;
};

class destination
{
    friend void disconnect(connection *);
    friend connection connect(destination *dest);
    friend class connection;

private:
    std::vector<connection *> cons;
    std::string on_port;
};

connection connect(destination *dest)
{
    connection c(dest);
    c.active = 1;
    dest->cons.push_back(&c);
    return c;
}

void disconnect(connection *con)
{
    if (con->active)
    {
        auto &cons = con->target->cons;
        auto it = std::find(cons.begin(), cons.end(), con);
        cons.erase(it);
        con->active = 0;
    }
    // Else, if it is not active it has not yet been connected with the target. Hence, no need to "disconnect" from the target.
}
void run_on(destination &dest)
{
    auto c = connect(&dest);
    // For Exercise 12.15, simply replace the next line with std::shared_ptr<connection> con_p(&c, [](connection* con) { /*Same code as in disconnect()*/}); or std::shared_ptr<connection> con_p(&c, [](connection* con) { disconnect(con);});
    std::shared_ptr<connection> con_p(&c, disconnect);
    // use code.
}