#include <iostream>
#include <string>
#include <unordered_map>
#include "User.h"
#include "network.h"

const std::string USERS_FILE = "musae_git_target.csv";
const std::string EDGE_FILE = "musae_git_edges.csv";


/*
std::ostream& operator<< (std::ostream &out, User * user) {
    out << user->get_id() << ':';
    out << user->username() << ':';
    return out;
}
*/




int main(){
    std::cout<<"deez nuts";
    User * central_node = new User();
    User * new_user = new User(12,"bob",central_node);
    std::cout << new_user;
    //std::cout << new_user.id();
    //std::cout << new_user;
    


    /*
    network = Network();
    network.create_user(1,"user one");
    network.create_user(2, "user two");
    network.print_users();
    */

    return 1;
}
