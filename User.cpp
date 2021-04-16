#include "User.h"
#include <iostream>


    //Default constructor
    User::User(){
        //nothing
    }
    //other constructor
    User::User(int id){
        id_ = id;
    }
    //even another constructor
    User::User(int id, std::string username, User central_node){

        id_ = id;
        username_ = username;
        central_node_ = central_node;
    }

    //adds connection to instance of User
    void add_connection(User user){

        connections_.push(user);

    }

    //prints out user information in a nice way
    void print(){
        std::cout<< "Username: " << username_;
        std::cout << std::endl;
        std::cout<< "ID: " << id_;

    }
