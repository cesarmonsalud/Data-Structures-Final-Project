#include <iostream> 
#include <string>



class User{
    public:
    User();
    User(int id)
    User(int id, std::string username, User central_node);

    //adds connection to instance of User
    void add_connection(User user);

    //prints out user information in a nice way
    void print();

    private:
    int id_; 
    std::string username_;
    vector<*Users> connections_; 
    std::User central_node_; 
}