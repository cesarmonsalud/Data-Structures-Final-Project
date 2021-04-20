#include <iostream>
#include <string>
#include <unordered_map>
#include "User.h"
#include "network.h"

const std::string USERS_FILE = "musae_git_target.csv";
const std::string EDGE_FILE = "musae_git_edges.csv";



int main(){
    std::cout<<"deez nuts"<<std::endl;

    Network network;
    network.populate_tree("namesTestData.csv", "edgesTestData.csv", "targetTestData.csv");

    /**
    Network network = Network();
    std::vector<std::string> name = network.read_csv_string("names.csv");
    std::vector<int> id_1 = network.read_csv_int("musae_git_edges.csv", 0, 2);
    std::vector<int> id_2 = network.read_csv_int("musae_git_edges.csv", 1, 2);
    std::vector<int> id = network.read_csv_int("targetdata.csv", 0, 2);
    std::vector<int> ml_target = network.read_csv_int("targetdata.csv", 1, 2);
    std::cout<< "problem here?" <<std::endl;
    */

    /*
    User * central_node = new User();
    User new_user = User(12,"bob",central_node);
    new_user.print();
    */


    /*
    network = Network();
    network.create_user(1,"user one");
    network.create_user(2, "user two");
    network.print_users();
    */

    return 1;
};
