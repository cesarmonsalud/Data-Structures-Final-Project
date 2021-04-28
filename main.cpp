#include <iostream>
#include <string>
#include <unordered_map>
#include "User.h"
#include "network.h"

const std::string USERS_FILE = "musae_git_target.csv";
const std::string EDGE_FILE = "musae_git_edges.csv";


void print(Network & network){
    std::cout<< network.network_string();
};

void print(User & user){
    std::cout << user.user_string();
};


int main(){
    Network network;
    User * central_node = new User();
    User user1 = User(1,"nick",central_node);
    
    network.populate_tree("names.csv", "musae_git_edges.csv", "targetdata.csv" );

    
    /*
    network.create_user_(1,"nick");
    network.create_user_(2,"keith");
    network.create_user_(3,"liam");
    

    network.add_edge(1,2);
    network.add_edge(1,3);
    network.add_edge(1,3);
    network.add_edge(1,1);
    */

    //print(user1);
    print(network);

    //User * user1 = new User(12,"nick",central_node);
    //std::cout << network.user_to_string(user1);
    //delete central_node;
    //delete user1;

    /**
    Network network = Network();
    std::vector<std::string> name = network.read_csv_string("names.csv");
    std::vector<int> id_1 = network.read_csv_int("musae_git_edges.csv", 0, 2);
    std::vector<int> id_2 = network.read_csv_int("musae_git_edges.csv", 1, 2);
    std::vector<int> id = network.read_csv_int("targetdata.csv", 0, 2);
    std::vector<int> ml_target = network.read_csv_int("targetdata.csv", 1, 2);
    std::cout<< "problem here?" <<std::endl;
    */

    
    User * central_node = new User();
<<<<<<< HEAD
    User new_user = User(12,"bob",central_node);
    new_user.print();
=======
    User * new_user = new User(12,"bob",central_node);
    std::cout << new_user;

    */
    //std::cout << new_user.id();
    //std::cout << new_user;


>>>>>>> 241a51edce1676d622403c04e85bec9b9db77b12
    


    /*
    network = Network();
    network.create_user(1,"user one");
    network.create_user(2, "user two");
    network.print_users();
    */

    return 1;
};
