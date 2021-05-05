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

void print(User * user){
    std::cout << user->user_string();
};

void print(std::string string){
    std::cout << string;
}




int main(){
    Network network;
    //User * central_node = new User();
    //User user1 = User(1,"nick",central_node);
    
    //network.populate_tree("names.csv", "musae_git_edges.csv", "targetdata.csv" );
    //network.populate_tree("namesTestData.csv", "edgesTestData.csv", "targetTestData.csv");


    //print(network);
    //print(network.search_by_id(3));
    //print(network.search_by_id(5));
    //print(network);
    /*
    network.new_visit(network.search_by_id(5),1);
    network.new_visit(network.search_by_id(5),0);
    network.new_visit(network.search_by_id(5),2);
    if(network.was_visited(network.search_by_id(5),0)){
        std::cout<<"true";
    }else{
        std::cout <<"false";
    }
    */
    //print(network);
    //std::cout << "END OF NETWORK \n";
    //print(network.get_connection_level_string(network.search_by_id(1),5));
    //std::cout<< network.shortest_path_string(network.search_by_id(0),network.search_by_id(3));
    //std::cout << network.BFS_username_string("lm");
    

    
    /***BACKTRACE TEST CASE***/
    network.create_user_(1,"nick");
    network.create_user_(2,"keith");
    network.create_user_(3,"liam");
    network.create_user_(4,"cesar");
    network.create_user_(5,"asdf");
    network.create_user_(6,"qwer");
    network.create_user_(7,"zxcv");
    network.create_user_(8,"ghjk");
    network.create_user_(9,"pop");
    network.create_user_(10,"bye");
    network.create_user_(11,"letsgo");
    network.create_user_(12,"onefriend");

 
    

    network.add_edge(1,2);
    network.add_edge(1,3);
    network.add_edge(2,3);
    network.add_edge(2,4);
    network.add_edge(3,4);
    //second
    network.add_edge(1,7);
    network.add_edge(7,8);
    network.add_edge(8,9);
    network.add_edge(9,11);
    network.add_edge(4,6);
    network.add_edge(6,11);
    network.add_edge(2,5);
    network.add_edge(5,10);
    network.add_edge(10,11);
    network.add_edge(9,12);

    //print(user1);
    
    std::unordered_map<User*,std::vector<User*>> previos;
    //previos[network.search_by_id(4)] = std::vector<User*>(); 
    previos[network.search_by_id(4)].push_back(network.search_by_id(2));
    previos[network.search_by_id(4)].push_back(network.search_by_id(3));
    previos[network.search_by_id(2)].push_back(network.search_by_id(1));
    previos[network.search_by_id(3)].push_back(network.search_by_id(1));
    previos[network.search_by_id(1)].push_back(NULL);
    //second
    previos[network.search_by_id(11)].push_back(network.search_by_id(10));
    previos[network.search_by_id(11)].push_back(network.search_by_id(6));
    previos[network.search_by_id(11)].push_back(network.search_by_id(9));
    previos[network.search_by_id(10)].push_back(network.search_by_id(5));
    previos[network.search_by_id(5)].push_back(network.search_by_id(2));
    previos[network.search_by_id(6)].push_back(network.search_by_id(4));
    previos[network.search_by_id(9)].push_back(network.search_by_id(8));
    previos[network.search_by_id(8)].push_back(network.search_by_id(7));
    previos[network.search_by_id(7)].push_back(network.search_by_id(1));
    previos[network.search_by_id(6)].push_back(network.search_by_id(8));

    //std::vector<int> result = network.backtrace_(previos,network.search_by_id(11), network.search_by_id(4));
    //std::cout << result[0] << "\n";
    //std::cout <<result[1];
    
    //std::cout << network.betweeness_centrality(network.search_by_id(1),5);
    network.network_betweeness_centrality(5);
    print(network);
    //std::pair<int,int> result = network.paths_through_node(network.search_by_id(1),network.search_by_id(11),network.search_by_id(4));
    //std::cout << result.first;
    //std::cout <<result.second;

    //std::cout <<network.vector_to_string(previos[network.search_by_id(1)]);
    //print(network);
    

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

    
    //std::cout << new_user.id();
    //std::cout << new_user;


    


    /*
    network = Network();
    network.create_user(1,"user one");
    network.create_user(2, "user two");
    network.print_users();
    */

    return 1;
};
