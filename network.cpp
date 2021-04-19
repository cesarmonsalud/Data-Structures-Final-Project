#include <iostream>
#include "User.h"
#include "network.h"
#include <string>
#include <unordered_map>

Network::Network(){
    id_map_ = std::unordered_map<int,User*>();
    user_map_ = std::unordered_map<User*,std::vector<bool>>();
    central_node_ = new User();
}

Network::~Network(){
    delete central_node_;
}

void Network::populate_tree(std::string filename_target, std::string filename_edges){
    //open csv file with user info

    //while lines in csv, pass line into create node and repeat for all lines of csv
    create_user("insert line string");//creates new node given line and adds <int id,User *user>pair to id_map_

    //when finished iterating close csv file

    //open csv file with user edges

    //while there are still edges get a new line
    //add_edge(13939,383839);


    return;
}

User * Network::search_by_id(int id){
    std::unordered_map<int,User*>::const_iterator found = id_map_.find(id);
    if(found==id_map_.end()){ //checks if the user id is not found
        return NULL;
    }else{
        return found->second; //pointer to user
    }
}

void Network::create_user(std::string line){
    //remember to add user to _id_map_
    return;
}

int Network::add_edge(int id_1, int id_2){
    return 1;
}

bool Network::was_visited(User * user, int level){
    return false;
}

void Network::new_visit(User * user, int level){
    return;
}

std::vector<std::string> Network::BFS_username(std::string query, User start){
    //
    return std::vector<std::string>();
}

int Network::shortest_path(User user1, User user2){
    return 1;
}


