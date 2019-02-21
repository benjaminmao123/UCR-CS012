#ifndef BBOARD_H
#define BBOARD_H

#include "Message.h"
#include "User.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BBoard 
{
private:
	string title;
    vector<User> userList;
    const User *currentUser;
    vector<Message*> messageList;

public:
    // Constructs a board with a default title, 
    // empty user & message lists, 
    // and the "default" User
    BBoard();
    
    ~BBoard();

    // Same as the default constructor except 
    // it sets the title of the board
    BBoard(const string &);

    // Imports all the authorized users from an input file, 
    // storing them as User objects in the vector userList
    // The name of the input file is passed in as a parameter to this function.
    // Returns true if the file opened, false if it did not. 
    // See specifications for file format.
    bool loadUsers(const string &);

    void login();

    // Contains main loop of Bulletin Board.
    // First verifies a User has been logged in.
    // Exits **function** immediately if no User logged in (Default User).
    // Continues to display menu options to user and performs requested action
    // until user chooses to quit.
    // See output samples for exact format of menu.
    void run();
    
    //This function gets a filename (datafile) of a file that stores the messages from previous sessions in the given format (See File Format Specs).
 
    //It opens and reads the file, creating Topic and Reply objects as appropriate, and fills the messageList vector 
    //(note: remember that messageList is a vector of Message pointers, not Messages).
 
    //If an error occurs when opening the file, it returns false. Returns true otherwise.
    bool loadMessages(const string &datafile);
    
    //This is the final action of the bulletin board before closing:
 
    //It gets a filename (datafile) of a file that will store all of the the messages, and after opening the file writes the messages into it with the same format 
    //(See File Format Specs).
 
    //If an error occurs when opening the file, it returns false. Returns true otherwise.
 
    //(Note: Since you will be opening the file for writing - i.e. an ofstream - "file not found" is NOT an error; a new file will simply be created for you).
    bool saveMessages(const string &datafile);

	bool fileCheck(const string &datafile);

private:
    // These are only suggestions, not required helper functions.
    // Feel free to make your own private helper functions as you see fit.
	void display() const;
    
    //This function includes the functionality of the old "user_exists" helper:
 
    //It traverses the userList, testing for the existence of a User with the given name and password; 
    //if this User is NOT found, the function returns 0 (or nullptr); otherwise it returns a pointer to the identified User
 
    //(the statement return &userList.at(i) will work - make sure you understand why!!)
 
    //This function may be used by login() to set the currentUser (which is now, obviously, a pointer, not an object).
 
    //There must be no other way to set currentUser to anything other than 0 (or nullptr).
    const User * getUser(const string &name, const string &pw) const;
    
    //This function asks the user to create a new Topic (i.e. the first message of a new discussion "thread"). Every Topic includes a subject (single line), and a body that may consist of  
	//multiple lines. e.g.,
    //Subject: "Thanks"
    //body: "I would like to thank you for this awesome board.
      //I'll visit here regularly."
    //The body ends when the user enters an empty line (i.e. a "double enter").  Each Topic also stores the username of currentUser; and a message id, which is 
    //(index of its Message* + 1)
    //For example, the first message on the board will be a Topic whose pointer will be stored at index 0 of the messageList vectoa	r, so its message id will be (0 + 1) = 1
    //(there are better ways of establishing unique ids for a set of objects, but for now this will work fine)
    //Once the Topic has been constructed, a pointer to it is added to messageList.  
    void addTopic();

	void addReply();

	bool is_empty(ifstream &pFile);

};
#endif