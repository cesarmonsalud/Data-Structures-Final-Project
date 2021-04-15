#include <iostream> 
#include <string>
#include "User.h"



class Network{
    public:

    Network();

    //PART #1
    //THIS SECTION IS FOR READING IN FILES

    /***
     * takes a user ID and returns the location of the node.
     * Use unordered map to implement
     * @return the address of the node
     * Null if address not found
     */
    User * search_by_id(int id);
    
    /***
     * populates the network using the data from the csv files
     * 1. read through all of the users and create a node for each of them (User constructor with attributes)
     * 2. store each node in a std::unordered_map<int,*User> (int is the user ID user is a pointer to the user)
     * 3. go through the csv file with all of the edges and add each edge to each node
     * using the unordered_map
     * Note: figure out how to handle seperate clusers
     */
    void populate_tree(std::string filename);

    /***
     * helper function for step #2 in populate_tree()
     * 1.create a node with User constructor
     * 2. add the User to id_map_
     */
    void create_node(std::string info); //figure out what info to pass in

    /***
     * helper function for step #3 in populate_tree()
     * use id_map_ to update both users connections with the edge
     * return 1 if successfull and node existed
     * return -1 if either node could not be found
    */
    int add_edge(int id_1, int id_2);


    //USER SEARCH SECTION

    /***
     * given a starting node and a string the function will BFS
     * through the tree and finds all users that have those letters in order in
     * the tree and return a list of the usernames in a list
     * use the user_map_ to implement the visited feature
     */
    std::vector<std::string> BFS_username(std::string query, User start);


    /***
     * takes the address of two connections
     * return int with the shortest path between the two connections return -1 if not connected at all
     * Note: figure out if it would be possible to return the shortest path
     */ 

    int shortest_path(User user1, User user2);


    //Part #2
    
    


    private:
    std::unordered_map<int,*User> id_map_;
    std::unordered_map<*User,std::vector<bool>> user_map_;
    User central_node_;

    




}