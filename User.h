#pragma once
#include <iostream> 
#include <string>




class User{
    public:
    User();
    User(int id);
    User(int id, std::string username, User * central_node);
    ~User();

    //adds connection to instance of User
    void add_connection(User * user);

    //prints out user information in a nice way
    void print();

    std::string getusername();
    int getid();

    private:
    int id_; 
    std::string username_;
    std::vector<User*> * connections_; 
    User * central_node_; 
};