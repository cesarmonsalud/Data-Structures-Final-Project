#include "User.h"
#include <iostream>
#include <vector>


    //Default constructor
    User::User(){
        //nothing
        id_ = -1;
        username_ = "";
        central_node_ = NULL;
        connections_ = new std::vector<User*>();
    }
    //other constructor
    User::User(int id){
        id_ = id;
        //assign null value for username and empty value for username
        username_ = "";
        central_node_ = NULL;
        connections_ = new std::vector<User*>();
    }
    //even another constructor
    User::User(int id, std::string username, User * central_node){

        id_ = id;
        username_ = username;
        central_node_ = central_node;
        connections_ = new std::vector<User*>();
    }

    User::~User(){
        delete [] connections_;
    }

    //adds connection to instance of User
    void User::add_connection(User * user){

        //Before: connections_->push(user);
        connections_->push_back(user);

    }

    const std::string User::get_id(){
        return std::to_string(id_);
    }

    const std::string User::username(){
        return username_;
    }

    //prints out user information in a nice way
    void User::print(){
        std::cout<< "Username: ";
        std::cout<< username() ;
        std::cout<< "ID: " ;
        std::cout << get_id() ;
        return;
}
