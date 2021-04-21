#include <iostream>
#include "User.h"
#include "network.h"
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

Network::Network(){
    id_map_ = std::unordered_map<int,User*>();
    user_map_ = std::unordered_map<User*,std::vector<bool>>();
    central_node_ = new User();
}

Network::~Network(){
    if(id_map_.empty()==false){
        for (auto pair : id_map_)
        {
            User * temp = pair.second;
            pair.second = NULL;
            delete temp;
            
        }
    }


    //delete user_map_;
    //delete id_map_;
    delete central_node_;
    central_node_ = NULL;
    //update destructor with each user
}

void Network::populate_tree(std::string filename_target_name, std::string filename_edges, std::string filename_target_id){
    //open csv file with user info
    //Edit these files to do the right thing
    std::vector<std::string> name = read_csv_string(filename_target_name);
    std::vector<int> id_1 = read_csv_int(filename_edges, 0, 2);
    std::vector<int> id_2 = read_csv_int(filename_edges, 1, 2);
    std::vector<int> id = read_csv_int(filename_target_id, 1, 2);
    //std::cout<<"sheesh"<<std::endl;
    //while lines in csv, pass line into create node and repeat for all lines of csv
    create_user("insert line string");//creates new node given line and adds <int id,User *user>pair to id_map_
    for(unsigned long i = 0; i<id.size(); i++){
        create_user_(int(id.at(i)),name.at(i));
    }
    //when finished iterating close csv file

    //open csv file with user edges
    for(unsigned long i = 0; i<id_1.size(); i++){
        add_edge(int(id_1.at(i)), int(id_2.at(i)));
    }

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

void Network::create_user_(int id, std::string username){
    User * newUser = new User(id,username,this->central_node_);
    std::pair<int,User*> newPair(id,newUser);
    id_map_.insert(newPair);
}

void Network::print_users(){
    for(auto it=id_map_.begin();it!=id_map_.end();++it){
        it->second->print();
    }
    return;
}



int Network::add_edge(int id_1, int id_2){

    User* User1= search_by_id(id_1); 
    User* User2= search_by_id(id_2); 

    if(User1 == NULL || User2 == NULL){
        return -1;
    }else{

        User1->add_connection(User2);
        User2->add_connection(User1);

        return 1;
    }

    //if either node cannot be found, return -1
   
}

bool Network::was_visited(User * user, int level){

    std::vector<bool> Vector = user_map_[user];
    if((int)Vector.size()<level){
        return false;
    }
    if(Vector[level]==true){
        return true;
    }else{
        return false;
    }
}

void Network::new_visit(User * user, int level){

    /*cases:
    1. Vector dont exist
    2. Vector exists for levels smaller than current level
    3. Vector already exists for level
    */
   /*
    std::vector<bool> Vector = user_map_[user];
    if(Vector.size()==0){
        for(int i=0; i<level; i++){
            Vector[i] = false;
        }
        Vector[level]=true;
    }
    else if()

    Vector[level] = true;
    return;
    */
}

std::vector<std::string> Network::BFS_username(std::string query, User start){
    //
    return std::vector<std::string>();
}

int Network::shortest_path(User user1, User user2){
    return 1;
}


std::vector<int> Network::read_csv_int(std::string filename, int columnIndex, int totalColumns){
    std::vector<int> result;
    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line;
    int val;

    // Read data, line by line
    while(std::getline(myFile, line))
    {
        // Create a stringstream of the current line
        std::stringstream ss(line);
        
        int colIdx = 0;
        // Extract each integer
        while(ss >> val){

            
            if(colIdx == columnIndex){
            // Add the current integer to the 'colIdx' column's values vector
            result.push_back(val);
            
            }
            
            // If the next token is a comma, ignore it and move on
            if(ss.peek() == ',') ss.ignore();

            if(colIdx == totalColumns - 1){
                colIdx = 0;
                break;
            }

            // Increment the column index
            colIdx++;
        }
    }

    // Close file
    myFile.close();

    //std::cout<< filename << " is done!" << std::endl;

    return result;


}

std::vector<std::string> Network::read_csv_string(std::string filename){
    std::vector<std::string> result;
    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line;
    std::string getstring;

    // Read data, line by line
    while(std::getline(myFile, line))
    {
        result.push_back(line);
    }

    // Close file
    myFile.close();

    //std::cout<< filename << " is done!" << std::endl;

    return result;
}

std::string Network::user_to_string(User * user){
    std::string str = user->user_string() + "Connections: " + "\n";
    std::vector<User*> connections = user->get_connections();
    for(int i = 0; i < int(connections.size());i++){
        str+= "   "+connections[i]->get_id() + "\n";
    }
    return str;
}

std::string Network::network_string(){
    std::string str = "NETWORK \n";
    for(auto entry: id_map_){
        str+= user_to_string(entry.second);
    }
    return str;

}