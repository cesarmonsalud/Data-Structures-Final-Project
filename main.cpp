#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include "User.h"
#include "network.h"

std::string WELCOME_MESSAGE = "Hello, welcome to our CS225 final project!";
std::string EXIT_MESSAGE = "Thank you for checking out our project! Don't forget to give us an A on the project!";

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

//code inspired by https://www.geeksforgeeks.org/converting-strings-numbers-cc/
int stringToInt(std::string input){
    std::stringstream geek(input);
 
    int x = 0;
    geek >> x;

    return x;
}

void userInterface(){

    //Welcome Message Code
    std::cout << std::endl << std::endl<< std::endl<< std::endl;
    std::cout << WELCOME_MESSAGE << std::endl;
    while(true){
        Network network;

        //Database Selection Code
        std::string dataBaseSelection = "-1";
        while(dataBaseSelection != "1" && dataBaseSelection != "2"){

            //Displays options for database selection to users
            std::cout << "Which database would you like to access?" << std::endl << std::endl;
            std::cout << "0: Exit Program" << std::endl;
            std::cout << "1: Test Database" << std::endl;
            std::cout << "2: Large Database" << std::endl << std::endl;


            //Output for database selection
            std::cin >> dataBaseSelection;
            std::cout << std::endl;
            if(dataBaseSelection == "0"){
                std::cout << EXIT_MESSAGE <<std::endl;
                return;
            }else if(dataBaseSelection == "1"){
                std::cout << "You have selected the Test Database!" << std::endl << std::endl;
                network.populate_tree("namesTestData.csv", "edgesTestData.csv", "targetTestData.csv" );
            }else if(dataBaseSelection == "2"){
                std::cout << "You have selected the Large Database!" << std::endl << std::endl;
                network.populate_tree("names.csv", "musae_git_edges.csv", "targetdata.csv" );
            }else{
                std::cout << "Could not understand input, please try again:" << std::endl << std::endl;
        }
        }

        //The meat and potatoes of the User Interface
        std::string commandSelection = "-1";
        while(commandSelection != "7"){
            std::cout << "Which command would you like to execute?" << std::endl << std::endl;


            //List of commands provided to User
            //TODO: implement centrality
            std::cout << "0: Exit Program" << std::endl;
            std::cout << "1: Print out entire database" << std::endl;
            std::cout << "2: Search up a User Id" << std::endl;
            std::cout << "3: Insert new User" << std::endl;
            std::cout << "4: Add edge to User" << std::endl;
            std::cout << "5: Find shortest path between two Users" << std::endl;
            std::cout << "6: Calculate the centrality of a User" << std::endl;
            std::cout << "7: Return to database selection" << std::endl << std::endl;


            //Selects commands
            std::cin >> commandSelection;
            std::cout << std::endl;

            //Exits Program
            if(commandSelection == "0"){
                std::cout << EXIT_MESSAGE <<std::endl;
                return;
            }

            //Prints out entire network
            else if(commandSelection == "1"){
                print(network);
                std::cout << std::endl << "Command Successful!" << std::endl;
            }
            
            //Prints out specific User
            else if(commandSelection == "2"){
                std::string selectedUserIdString = "-1";
                while(true){
                    std::cout << "Input the User Id" << std::endl << std::endl;
                    std::cin >> selectedUserIdString;
                    int selectedUserIdInt = stringToInt(selectedUserIdString);
                    std::cout << std::endl;
                    if(selectedUserIdInt >= 0 && selectedUserIdInt < network.getTotalNodes()){
                        print(network.search_by_id(selectedUserIdInt));
                        std::cout << std::endl << "Command Successful!" << std::endl <<std::endl;
                        break;
                    }else{
                        std::cout << "Invalid User Id, please try again!" <<std::endl <<std::endl;
                    }
                }
            }
            
            //Inserts new User into the Network
            else if(commandSelection == "3"){
                std::string newUserName;
                std::cout << "Input the User Name" << std::endl << std::endl;
                std::cin >> newUserName;
                std::cout << std::endl;
                network.create_user_(network.getTotalNodes(),newUserName);
                std::cout << "Here is your new user!" << std::endl;
                print(network.search_by_id(network.getTotalNodes()-1));
                std::cout << std::endl << "Command Successful!" << std::endl;
            }
            
            //Adds an edge to an existing User
            else if(commandSelection == "4"){
                std::string selectedUserIdString = "-1";
                int firstUserId = -1;
                while(true){
                    std::cout << "Input the User Id to add edge to" << std::endl << std::endl;
                    std::cin >> selectedUserIdString;
                    int selectedUserIdInt = stringToInt(selectedUserIdString);
                    std::cout << std::endl;
                    if(selectedUserIdInt >= 0 && selectedUserIdInt < network.getTotalNodes()){
                        std::cout << "User Id selected:" <<std::endl;
                        print(network.search_by_id(selectedUserIdInt));
                        firstUserId = selectedUserIdInt;
                        break;
                    }else{
                        std::cout << "Invalid User Id, please try again!" <<std::endl <<std::endl;
                    }
                }
                while(true){
                    std::cout << "Input the second User Id to create edge" << std::endl << std::endl;
                    std::cin >> selectedUserIdString;
                    int selectedUserIdInt = stringToInt(selectedUserIdString);
                    std::cout << std::endl;
                    if(selectedUserIdInt == firstUserId){
                        std::cout << "Can not make edge with self, please pick again!" <<std::endl <<std::endl;
                    }else if(selectedUserIdInt >= 0 && selectedUserIdInt < network.getTotalNodes()){
                        network.add_edge(firstUserId,selectedUserIdInt);
                        std::cout << "First User Id selected: "<< std::endl;
                        print(network.search_by_id(firstUserId));
                        std::cout << std::endl <<"Second User Id selected: "<< std::endl;
                        print(network.search_by_id(selectedUserIdInt));
                        std::cout << std::endl << "Command Successful!" << std::endl <<std::endl;
                        break;
                    }else{
                        std::cout << "Invalid User Id, please try again!" <<std::endl <<std::endl;
                    }
                }
            }
            
            //Displays the shortest path between two Users
            else if(commandSelection == "5"){
                std::string selectedUserIdString = "-1";
                int firstUserId = -1;
                while(true){
                    std::cout << "Input the first User Id" << std::endl << std::endl;
                    std::cin >> selectedUserIdString;
                    int selectedUserIdInt = stringToInt(selectedUserIdString);
                    std::cout << std::endl;
                    if(selectedUserIdInt >= 0 && selectedUserIdInt < network.getTotalNodes()){
                        std::cout << "User Id selected:" <<std::endl;
                        print(network.search_by_id(selectedUserIdInt));
                        firstUserId = selectedUserIdInt;
                        break;
                    }else{
                        std::cout << "Invalid User Id, please try again!" <<std::endl <<std::endl;
                    }
                }
                while(true){
                    std::cout << "Input the second User Id" << std::endl << std::endl;
                    std::cin >> selectedUserIdString;
                    int selectedUserIdInt = stringToInt(selectedUserIdString);
                    std::cout << std::endl;
                    if(selectedUserIdInt == firstUserId){
                        std::cout << "Can not pick same node twice, try again!" <<std::endl <<std::endl;
                    }else if(selectedUserIdInt >= 0 && selectedUserIdInt < network.getTotalNodes()){
                        std::cout << "First User Id selected: "<< std::endl;
                        print(network.search_by_id(firstUserId));
                        std::cout << std::endl <<"Second User Id selected: "<< std::endl;
                        print(network.search_by_id(selectedUserIdInt));
                        std::cout << network.shortest_path_string(network.search_by_id(firstUserId),network.search_by_id(selectedUserIdInt));
                        std::cout << std::endl << "Command Successful!" << std::endl <<std::endl;
                        break;
                    }else{
                        std::cout << "Invalid User Id, please try again!" <<std::endl <<std::endl;
                    }
                }
            }

            //Calculates centrality
            else if(commandSelection == "6"){
                std::string selectedUserIdString = "-1";
                std::string selectedDepthString = "-1";
                int firstUserId = -1;
                while(true){
                    std::cout << "Input the first User Id" << std::endl << std::endl;
                    std::cin >> selectedUserIdString;
                    int selectedUserIdInt = stringToInt(selectedUserIdString);
                    std::cout << std::endl;
                    if(selectedUserIdInt >= 0 && selectedUserIdInt < network.getTotalNodes()){
                        std::cout << "User Id selected:" <<std::endl;
                        print(network.search_by_id(selectedUserIdInt));
                        firstUserId = selectedUserIdInt;
                        break;
                    }else{
                        std::cout << "Invalid User Id, please try again!" <<std::endl <<std::endl;
                    }
                }
                while(true){
                    std::cout << "Input a depth" << std::endl << std::endl;
                    std::cin >> selectedDepthString;
                    int selectedUserIdInt = stringToInt(selectedUserIdString);
                    int selectedInt = stringToInt(selectedDepthString);
                    std::cout << std::endl;
                    if(selectedInt >= 1){
                        std::cout << "The centrality of the user is: " << network.betweeness_centrality(network.search_by_id(selectedUserIdInt),selectedInt)<<std::endl;
                        std::cout << std::endl << "Command Successful!" << std::endl <<std::endl;
                        break;
                    }else{
                        std::cout << "Invalid integer, please try again!" <<std::endl <<std::endl;
                    }
                }
            }
            
            //Returns to Database Selection
            else if(commandSelection == "7"){
                break;
            }
            
            //Used when user makes a bad command
            else{
                std::cout << "Could not understand input, please try again:" << std::endl << std::endl;
            }
        }
    }
}




int main(){
    userInterface();
    //Network network;
    //User * central_node = new User();
    //User user1 = User(1,"nick",central_node);
    
    //actual data
    //network.populate_tree("names.csv", "musae_git_edges.csv", "targetdata.csv" );

    //test data
    //network.populate_tree("namesTestData.csv", "edgesTestData.csv", "targetTestData.csv" );


    //print(network);
    //Network network;
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
    /**
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
    */

    //print(user1);
    
    /**
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
    */

    //std::vector<int> result = network.backtrace_(previos,network.search_by_id(11), network.search_by_id(4));
    //std::cout << result[0] << "\n";
    //std::cout <<result[1];
    
    //std::cout << network.betweeness_centrality(network.search_by_id(1),5);
    /**
    network.network_betweeness_centrality(5);
    print(network);
    */
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

    /**
    User * central_node = new User();
    User new_user = User(12,"bob",central_node);
    new_user.print();
    User * new_user = new User(12,"bob",central_node);
    std::cout << new_user;
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
