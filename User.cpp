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
        connections_->clear();
        delete connections_;
    }


    void User::add_connection(User * user){

        //makes sure it is not adding a connection to itself
        if(this!=user){
            //makes sure connection has not already been added
            for(int i = 0; i < int(connections_->size());i++){
                if((*connections_)[i]==user){
                    return;
                }
            }
            connections_->push_back(user);
        }
        return;

    }

    const std::string User::get_id(){
        return std::to_string(id_);
    }

<<<<<<< HEAD
    

    //prints out user information in a nice way
    void User::print(){
        std::cout<< "Username: " << User::getusername() << std::endl;
        std::cout<< "ID: " << User::getid() << std::endl;
        return;
    }

    std::string User::getusername(){
        return username_;
    }
    int User::getid(){
        return id_;
=======

    const std::string User::get_username(){
        return username_;
    }


    std::vector<User*> User::get_connections(){
        return *connections_;
    }


    std::string User::user_string(){
        std::string str = "Username: " + get_username() + "\n";
        str += "ID: " + get_id() + "\n" + "Connections: " + "\n";
        for(int i = 0; i < int(connections_->size());i++){
            str+= "   "+(*connections_)[i]->get_id() + "\n";
        }
        return str;
>>>>>>> 241a51edce1676d622403c04e85bec9b9db77b12
    }
