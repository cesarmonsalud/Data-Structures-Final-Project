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

    const std::string get_id();
    const std::string get_username();
    std::vector<User*> get_connections();


    std::string user_string();



    private:
    int id_; 
    std::string username_;
    std::vector<User*> * connections_; 
    User * central_node_; 
};