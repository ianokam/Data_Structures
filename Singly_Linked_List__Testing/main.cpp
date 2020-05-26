/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           main.cpp
//  Program:            Singly Linked Lists
//  Title:              Main Program
//
//  Author:             Ibeawuchi Anokam
//  Date of Creation:   02/11/20
//  Version:            1.0.0
//  Revised by:         n/a
//  Revision Date:      n/a
//
//  Copyright:          Copyright © 2020 Ibeawuchi Anokam. 
//                      All rights reserved.
//
//-------------------------------------------------
// PROGRAM DESCRIPTION                            :
//-------------------------------------------------
//
// The program reads a series of positive integers, one per line, from the
// keyboard into a linked list. reads in a series of positive integers --
// one per line. And then it stores them into an array.
//
// The user indicates that they are finished by entering -1.
//
//--
//
// The program should create the Linked lists:
//      1) List1Front ( nodes are inserted at the front of the list )
//      2) List2End:  ( nodes are inserted at the end of the list   )
//
//
// And then the program should do:
//
//      1) Adds to the tail of the list
//
//      2) Adds to the head of the list
//
//      3) Prints the values in the list on one line separated by spaces
//
//---
//      1) Searches the list for a key value and returns true/false
//         if the key is (not) in the list
//
//      2) Add a single not to the end of the list
//
//      3) Delete the entire list
//
//      4) Delete a node from the end of a list
//
//-------------------------------------------------
// Functions                                      :
//-------------------------------------------------
//
//    void buildListFoward(NodeType* first)
//    void buildListBackward(NodeType* first)
//    void print(NodeType* first)
//
//    void search(int key, NodeType* first)
//    void addNode(int key, NodeType* first)
//    void deleteList(NodeType* first)
//    void deleteNode(NodeType* first)
//
//
//  *** Note: for functions addNode() and deleteNode(),
//            you should print the modified list
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
//------------------------
// Libraries             :
//------------------------
#include <iostream>
#include <stdexcept> // for "runtime_error" object
using namespace std;


//------------------------
// ADT: SLL Prototype(s) :
//------------------------
struct list {
    //RECORD FIELD(S):
    int data;
    //POINTER FIELD(S):
    list* next;
};



//------------------------
// Function Prototypes   :
//------------------------
void buildListFoward( list* &starting_ptr );    // adds to the tail of the list
void print( list* starting_ptr );               // adds to the head of the list
void buildListBackward( list* &starting_ptr );  // prints the values in the list on one line separated by spaces

bool search( int key, list* starting_ptr );
void addNode(int key, list*& starting_ptr); // Add a single not to the end of the list
void deleteList(list*& starting_ptr);       //delete the entire list
void deleteNode(list*& starting_ptr);       // delete a node from the end of a list



/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                           M A I N    M O D U L E                          */
/*---------------------------------------------------------------------------*/
//------------------------
// Start Application     :
//------------------------
int main( ){
    //--------------------------------------------
    // Variable Declarations                     :
    //--------------------------------------------
    int key_val;
    
    //--------------------------------------------
    // WHILE-LOOPS - Variable Declarations       :
    //--------------------------------------------
    bool end_loop;
    bool val_is_found;
    
    //--------------------------------------------
    // Singly Linked List Variable Declarations  :
    //--------------------------------------------
    list* List1Front = nullptr;   // nodes are inserted at the front of the list
    list* List2End = nullptr;     // nodes are inserted at the end of the list
    
    
    //------------------------------------------------
    // INITIALIZE SLL - Add Initial Values into SLL  :
    //------------------------------------------------
    cout<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   BUILDING THE SINGLY LINKED LIST - FORWARD                        :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< endl;
    buildListFoward(List1Front);
    
    //------------------------------------------------
    // PRINT SLL                                     :
    //------------------------------------------------
    cout<< endl << endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   PRINTING THE SINGLY LINKED LIST - FORWARD                        :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    print(List1Front);
    
    
    
    cout<< endl << endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   APPENDING TO THE SINGLY LINKED LIST - FORWARD                    :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    //-----------------------------------
    // Input Number Of Values To Input  :
    //-----------------------------------
    end_loop = false;
    key_val = -1;
    while( end_loop == false &&
           cout << "Enter The KEY Value You Want To ADD:  " )
    {
        //---------------------------------------------------------------------
        // Exception Handler                                                  :
        // To keep error-checking code separate and to reduce redundant       :
        // checks                                                             :
        //---------------------------------------------------------------------
        try{
            
            //-----------------------------------------------------------------
            // INSERTS A VALUE  &&                                            :
            // IFF The Value Is The Wrong Data Type Then OutPut An Error      :
            //-----------------------------------------------------------------
            if( (!(cin >> key_val)) ){

                // Clear input stream
                cin.clear();

                // Discard previous input
                cin.ignore(123, '\n');
                
                
                // If an error is detected
                // ( an unexpected problem in execution )              :
                throw runtime_error("ERROR: A Number Must Be Entered.");
            }
            
            
            //-----------------------------------------------------------------
            // Else, If The Correct Data Type Is Given THEN                   :
            // Error Check -- CHECK IF THE VALUE IS A NEGATIVE INTEGER        :
            //-----------------------------------------------------------------
            if ( key_val < 0 )
            {
                throw runtime_error("ERROR: Invalid Value.");// If an error is
                                                             // detected
                                                             // ( an unexpected
                                                             //   problem in
                                                             //   execution )
            }
            else{
                end_loop = true; // Set to 'true' to end the loop as soon as it
                                 // reaches the end of itself
                cout << endl;
            }
        }
        catch( runtime_error& excpt ){
            // Prints the error message passed by throw statement:
            cout << excpt.what() << endl;
            cout << "The Value Is Negative Or Is An Invalid Data Type."
                 << endl << endl;
            end_loop = false;  // Locks the while-loop from incrementing
                               // ( An incorrect input was given )
        }
        
    }//END While-Loop
    addNode(key_val, List1Front);
    
    
    cout<< endl << endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   PRINTING THE SINGLY LINKED LIST (W/ APPENDED VALUE) - FORWARD    :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    print(List1Front);
    
    
    
    deleteNode(List1Front);
    cout<< endl << endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   PRINTING THE SINGLY LINKED LIST (W/ DELETED VALUE) - FORWARD     :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    print(List1Front);
    
    
    
    //-----------------------------------
    // Print Title Block  &&  Output    :
    //-----------------------------------
    cout<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   BUILDING THE SINGLY LINKED LIST - BACKWARD                       :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< endl;
    buildListBackward(List2End);
    
    cout<< endl << endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   PRINTING THE SINGLY LINKED LIST - BACKWARD                        :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    print(List2End);
    
    
    
    
    //-----------------------------------
    // Print Title Block  &&  Output    :
    //-----------------------------------
    cout<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   FIND THE KEY IN THE SINGLY LINKED LIST - FORWARD LIST            :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< endl;
    
    //-----------------------------------
    // Input Number Of Values To Input  :
    //-----------------------------------
    end_loop = false;
    key_val = -1;
    while( end_loop == false &&
           cout << "Enter The KEY Value You Want To Find:  " )
    {
        //---------------------------------------------------------------------
        // Exception Handler                                                  :
        // To keep error-checking code separate and to reduce redundant       :
        // checks                                                             :
        //---------------------------------------------------------------------
        try{
            
            //-----------------------------------------------------------------
            // INSERTS A VALUE  &&                                            :
            // IFF The Value Is The Wrong Data Type Then OutPut An Error      :
            //-----------------------------------------------------------------
            if( (!(cin >> key_val)) ){

                // Clear input stream
                cin.clear();

                // Discard previous input
                cin.ignore(123, '\n');
                
                
                // If an error is detected
                // ( an unexpected problem in execution )              :
                throw runtime_error("ERROR: A Number Must Be Entered.");
            }
            
            
            //-----------------------------------------------------------------
            // Else, If The Correct Data Type Is Given THEN                   :
            // Error Check -- CHECK IF THE VALUE IS A NEGATIVE INTEGER        :
            //-----------------------------------------------------------------
            if ( key_val < 0 )
            {
                throw runtime_error("ERROR: Invalid Value.");// If an error is
                                                             // detected
                                                             // ( an unexpected
                                                             //   problem in
                                                             //   execution )
            }
            else{
                end_loop = true; // Set to 'true' to end the loop as soon as it
                                 // reaches the end of itself
                cout << endl;
            }
        }
        catch( runtime_error& excpt ){
            // Prints the error message passed by throw statement:
            cout << excpt.what() << endl;
            cout << "The Value Is Negative Or Is An Invalid Data Type."
                 << endl << endl;
            end_loop = false;  // Locks the while-loop from incrementing
                               // ( An incorrect input was given )
        }
        
    }//END While-Loop
    
    
    val_is_found = search( key_val, List1Front );
    if( val_is_found == true ){
        cout << "The KEY has been found !"<<endl;
    }
    else{
        cout << "The KEY was NOT found !"<<endl;
    }
    
    
    //-----------------------------------
    // Print Title Block  &&  Output    :
    //-----------------------------------
    cout<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   DELETE SINGLY LINKED LIST - FORWARD LIST                         :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< endl;
    deleteList( List1Front );

    cout<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< "   DELETE SINGLY LINKED LIST - BACKWARD LIST                        :"<<endl;
    cout<< "---------------------------------------------------------------------"<<endl;
    cout<< endl;
    deleteList( List2End );
    
    cout << endl << endl;
    

	// Platform specific Pre-processor Directive:
	#ifdef _WIN32 || _WIN64   // IFF it's a 32-bit / 64-bit WinOS
		system("pause");
	#endif

    //------------------------
    // End Application       :
    //------------------------
    return 0;
}


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                   F U N C T I O N    D E F I N I T I O N S                */
/*---------------------------------------------------------------------------*/
void buildListFoward( list* &starting_ptr ){
    //-------------------------------------------------
    // Function Description                           :
    //-------------------------------------------------
    // Creates a Singly Linked List.
    // Reads the integers into the array
    //
    //-------------------------------------------------
    
    
    //------------------------------------------------
    // Singly Linked List - Variable Declarations    :
    //------------------------------------------------
    // Create a temporary container to traverse list:
    list* currentNode;
    list* last_Node;

    
    //------------------------------------------------
    // Singly Linked List - Variable Initializations :
    //------------------------------------------------
    last_Node = nullptr;
    // Counter to stop inputs when necessary:
    int count = 0;
    // Point 'currentNode' to the same Node as 'starting_ptr':
    currentNode = starting_ptr;

    

//--------------------------------------------------------------------------
    
    
    
    //-----------------------------------------
    // While-Loop :  Variable Declarations    :
    //-----------------------------------------
    int number_of_integers_to_read = -1; // amount of values user wants to
                                         // read in
    bool end_loop   = false;
    
    
    //-----------------------------------
    // Input Number Of Values To Input  :
    //-----------------------------------
    while( end_loop == false &&
           cout << "Enter The Number Of Values You Want To Read In:  " )
    {
        //---------------------------------------------------------------------
        // Exception Handler                                                  :
        // To keep error-checking code separate and to reduce redundant       :
        // checks                                                             :
        //---------------------------------------------------------------------
        try{
            
            //-----------------------------------------------------------------
            // INSERTS A VALUE  &&                                            :
            // IFF The Value Is The Wrong Data Type Then OutPut An Error      :
            //-----------------------------------------------------------------
            if( (!(cin >> number_of_integers_to_read)) ){

                // Clear input stream
                cin.clear();

                // Discard previous input
                cin.ignore(123, '\n');
                
                
                // If an error is detected
                // ( an unexpected problem in execution )              :
                throw runtime_error("ERROR: Invalid Data Type. A Number Must Be Entered.");
            }
            
            
            //-----------------------------------------------------------------
            // Else, If The Correct Data Type Is Given THEN                   :
            // Error Check -- CHECK IF THE VALUE IS A NEGATIVE INTEGER        :
            //-----------------------------------------------------------------
            if ( number_of_integers_to_read < 0 )
            {
                throw runtime_error("ERROR: The Value Is Negative.");// If an error is
                                                             // detected
                                                             // ( an unexpected
                                                             //   problem in
                                                             //   execution )
            }
            else{
                end_loop = true; // Set to 'true' to end the loop as soon as it
                                 // reaches the end of itself
                cout << endl;
            }
        }
        catch( runtime_error& excpt ){
            // Prints the error message passed by throw statement:
            cout << excpt.what() << endl;
            cout << "Enter An Integer Value Greater Than Zero."
                 << endl << endl;
            end_loop = false;  // Locks the while-loop from incrementing
                               // ( An incorrect input was given )
        }
        
    }//END While-Loop
    
    
    
    
 //--------------------------------------------------------------------------
    
    
    
    //---------------------------------------------------
    // Allow Number Values To Be Inputted               :
    //---------------------------------------------------

        //---------------------------
        // Variable Declarations    :
        //---------------------------
        int integers_buffer=99; // amount of values user wants to read in
        bool error_found = false;
        
        count = 0;
        //-----------------------------------
        // Input Values To Array            :
        //-----------------------------------
        while( count < number_of_integers_to_read &&
               cout << "Enter A Positive Integer Value:  " )
        {
            //-----------------------------------------------------------------
            // Exception Handler                                              :
            // To keep error-checking code separate and to reduce redundant   :
            // checks                                                         :
            //-----------------------------------------------------------------
            try{
                //-----------------------------------------------------------------
                // INSERTS A VALUE  &&                                            :
                // IFF The Value Is The Wrong Data Type Then OutPut An Error      :
                //-----------------------------------------------------------------
                if( (!(cin >> integers_buffer)) ){

                    // Clear input stream
                    cin.clear();

                    // Discard previous input
                    cin.ignore(123, '\n');
                    
                    
                    // If an error is detected
                    // ( an unexpected problem in execution )              :
                    throw runtime_error("ERROR: A Number Must Be Entered.");
                }
                
                
                //-----------------------------------------------------------------
                // Else, If The Correct Data Type Is Given THEN                   :
                // Error Check -- CHECK IF THE VALUE IS A NEGATIVE INTEGER        :
                //-----------------------------------------------------------------
                if ( integers_buffer < 0  )
                {
                    throw runtime_error("ERROR: Invalid Value."); // If an error is
                                                                  // detected
                                                                  //( an unexpected
                                                                  //  problem in
                                                                  //  execution )
                }
                if ( integers_buffer == -1  )
                 {
                     throw runtime_error("ERROR: Invalid Value."); // If an error is
                                                                   // detected
                                                                   //( an unexpected
                                                                   //  problem in
                                                                   //  execution )
                 }
                
                //-----------------------------------------------------------------
                // If   "integers_buffer"   Gets Past All the Error Checks Then   :
                // Insert The Value Into The SLL                                  :
                //-----------------------------------------------------------------
                currentNode = new list;
                currentNode->data = integers_buffer;
                currentNode->next = nullptr;
                if (starting_ptr == nullptr)
                {
                    starting_ptr = currentNode;
                    last_Node = currentNode;
                }
                else
                {
                    last_Node->next = currentNode;
                    last_Node = currentNode;
                }
                
            }
            catch( runtime_error& excpt ){
                // Prints the error message passed by throw statement:
                cout << excpt.what() << endl;
                cout << "The Value Is Not Positive Or Is An Invalid Data Type."
                     << endl << endl;
                error_found = true;  // Locks the while-loop from incrementing
                               // ( An incorrect input was given )
            }
            
            
            //---------------------------------------------------------------------
            // Resumes normal code below                                          :
            //---------------------------------------------------------------------
            if( error_found == false ){
                count ++;           // IFF an input is correctly given
            }
            else{ // IFF an error is reached
                error_found = false;  // Reset and try again
            }
            
        }//END While-Loop
        
}


void buildListBackward( list* &starting_ptr ){
    //-------------------------------------------------
    // Function Description                           :
    //-------------------------------------------------
    // Creates a Singly Linked List.
    // Reads the integers into the array
    //
    //-------------------------------------------------
    
    
    //------------------------------------------------
    // Singly Linked List - Variable Declarations    :
    //------------------------------------------------
    // Create a temporary container to traverse list:
    list* currentNode;
    list* prevNode;
    list* first_node;

    
    //------------------------------------------------
    // Singly Linked List - Variable Initializations :
    //------------------------------------------------
    first_node = nullptr;
    // Counter to stop inputs when necessary:
    int count = 0;
    // Point 'currentNode' to the same Node as 'starting_ptr':
    currentNode = starting_ptr;

    

//--------------------------------------------------------------------------
    
    
    
    //-----------------------------------------
    // While-Loop :  Variable Declarations    :
    //-----------------------------------------
    int number_of_integers_to_read = -1; // amount of values user wants to
                                         // read in
    bool end_loop   = false;
    
    
    //-----------------------------------
    // Input Number Of Values To Input  :
    //-----------------------------------
    while( end_loop == false &&
           cout << "Enter The Number Of Values You Want To Read In:  " )
    {
        //---------------------------------------------------------------------
        // Exception Handler                                                  :
        // To keep error-checking code separate and to reduce redundant       :
        // checks                                                             :
        //---------------------------------------------------------------------
        try{
            
            //-----------------------------------------------------------------
            // INSERTS A VALUE  &&                                            :
            // IFF The Value Is The Wrong Data Type Then OutPut An Error      :
            //-----------------------------------------------------------------
            if( (!(cin >> number_of_integers_to_read)) ){

                // Clear input stream
                cin.clear();

                // Discard previous input
                cin.ignore(123, '\n');
                
                
                // If an error is detected
                // ( an unexpected problem in execution )              :
                throw runtime_error("ERROR: Invalid Data Type. A Number Must Be Entered.");
            }
            
            
            //-----------------------------------------------------------------
            // Else, If The Correct Data Type Is Given THEN                   :
            // Error Check -- CHECK IF THE VALUE IS A NEGATIVE INTEGER        :
            //-----------------------------------------------------------------
            if ( number_of_integers_to_read < 0 )
            {
                throw runtime_error("ERROR: The Value Is Negative.");// If an error is
                                                             // detected
                                                             // ( an unexpected
                                                             //   problem in
                                                             //   execution )
            }
            else{
                end_loop = true; // Set to 'true' to end the loop as soon as it
                                 // reaches the end of itself
                cout << endl;
            }
        }
        catch( runtime_error& excpt ){
            // Prints the error message passed by throw statement:
            cout << excpt.what() << endl;
            cout << "Enter An Integer Value Greater Than Zero."
                 << endl << endl;
            end_loop = false;  // Locks the while-loop from incrementing
                               // ( An incorrect input was given )
        }
        
    }//END While-Loop
    
    
    
    
 //--------------------------------------------------------------------------
    
    
    
    //---------------------------------------------------
    // Allow Number Values To Be Inputted               :
    //---------------------------------------------------
    if( number_of_integers_to_read > 0 ){

        //---------------------------
        // Variable Declarations    :
        //---------------------------
        int integers_buffer; // amount of values user wants to read in
        bool error_found = false;
        bool is_first = true;
        
        count = 0;
        //-----------------------------------
        // Input Values To Array            :
        //-----------------------------------
        while( count < number_of_integers_to_read &&
               cout << "Enter A Positive Integer Value:  " )
        {
            //-----------------------------------------------------------------
            // Exception Handler                                              :
            // To keep error-checking code separate and to reduce redundant   :
            // checks                                                         :
            //-----------------------------------------------------------------
            try{
                //-----------------------------------------------------------------
                // INSERTS A VALUE  &&                                            :
                // IFF The Value Is The Wrong Data Type Then OutPut An Error      :
                //-----------------------------------------------------------------
                if( (!(cin >> integers_buffer)) ){

                    // Clear input stream
                    cin.clear();

                    // Discard previous input
                    cin.ignore(123, '\n');
                    
                    
                    // If an error is detected
                    // ( an unexpected problem in execution )              :
                    throw runtime_error("ERROR: A Number Must Be Entered.");
                }
                
                
                //-----------------------------------------------------------------
                // Else, If The Correct Data Type Is Given THEN                   :
                // Error Check -- CHECK IF THE VALUE IS A NEGATIVE INTEGER        :
                //-----------------------------------------------------------------
                if ( integers_buffer < 0  )
                {
                    throw runtime_error("ERROR: Invalid Value."); // If an error is
                                                                  // detected
                                                                  //( an unexpected
                                                                  //  problem in
                                                                  //  execution )
                }
                
                //-----------------------------------------------------------------
                // If   "integers_buffer"   Gets Past All the Error Checks Then   :
                // Insert The Value Into The SLL                                  :
                //-----------------------------------------------------------------

                
                if (is_first == true)
                {
                    currentNode = new list;
                    currentNode->data = integers_buffer;
                    
                    currentNode->next = first_node;
                    starting_ptr = currentNode;
                    is_first = false;
                }
                else
                {
                    prevNode = currentNode;
                    
                    currentNode = new list;
                    currentNode->data = integers_buffer;
                    
                    currentNode->next = prevNode;
                    starting_ptr = currentNode;
                }
                
            }
            catch( runtime_error& excpt ){
                // Prints the error message passed by throw statement:
                cout << excpt.what() << endl;
                cout << "The Value Is Not Positive Or Is An Invalid Data Type."
                     << endl << endl;
                error_found = true;  // Locks the while-loop from incrementing
                               // ( An incorrect input was given )
            }
            
            
            //---------------------------------------------------------------------
            // Resumes normal code below                                          :
            //---------------------------------------------------------------------
            if( error_found == false ){
                count ++;           // IFF an input is correctly given
            }
            else{ // IFF an error is reached
                error_found = false;  // Reset and try again
            }
            
        }//END While-Loop
        
    }
    else{// if( number_of_integers_to_read == 0 )
         //
         // *** NOTE:  Negatives values are Error Handled above so it's
         //            disregarded here in this IF-ELSE statement
         //--------------------------------------------------------------------
        
         cout<< " No Values Were Inputted Into the Program."<<endl << endl;
        
    }
}


void print(list *starting_ptr) {
    // FUNCTIONS PURPOSE:
    //--------------------
    // Prints a Singly Linked List
    //

    // Create a temporary container to traverse list:
    list* currentNode;

    // Point 'currentNode' to the same Node as 'starting_ptr':
    currentNode = starting_ptr;

    while (currentNode != nullptr) {
        cout << "#: " << (currentNode->data) << endl;
        // Go to the next Node:
        currentNode = (currentNode->next);
    }
}


bool  search( int key, list* starting_ptr ){
    // FUNCTIONS PURPOSE:
    //--------------------
    // searches the list for a key value and returns
    // true/false if the key is (not) in the list
    //

    list* currentNode;

    // Variable Initialization:
    bool is_found = false;

    // Pointer Initialization -
    // Point 'currentNode' to the same Node as 'starting_ptr':
    currentNode = starting_ptr;

    while (currentNode != nullptr &&
           is_found == false )
    { // Traverse through the list until you
                                     // get to the last one - which is
                                     //" last_Node==nullptr "

                                     // Check if 'Key' exists in Current Node:
        if ((currentNode->data) == key) {
            // If it exists then count:
            is_found = true;
        }
        else{
            // Then go to the next Node:
            currentNode = (currentNode->next);
        }
    }

    // Return Count value:
    return is_found;
}

void addNode(int key, list*& starting_ptr){
    // FUNCTIONS PURPOSE:
    //--------------------
    // Add a single not to the end of the list
    //

    // Create a temporary container to traverse list:
    list* currentNode;

    // Point 'currentNode' to the same Node as 'starting_ptr':
    currentNode = starting_ptr;

    while (currentNode->next != nullptr) {
        // Traverse - Go to the next Node:
        currentNode = (currentNode->next);
    }
    currentNode->next         = new list;   // Append new node
    (currentNode->next)->data = key;        // Add value
    (currentNode->next)->next = nullptr;
}

void deleteList(list*& starting_ptr){
    // FUNCTIONS PURPOSE:
    //--------------------
    // Delete the entire list
    //

    // Variable Declaration:
    list *deleter;

    // Variable Initializations:
    deleter = starting_ptr;

    //Begin deleting nodes:
    while (deleter != nullptr)
    {
        deleter = deleter->next;
        delete starting_ptr;
        starting_ptr = deleter;
    }
    cout << "SLL DELETED!!!" << endl;
}

void deleteNode(list*& starting_ptr){
    // FUNCTIONS PURPOSE:
    //--------------------
    // Delete a node from the end of a list
    //

    // Create a temporary container to traverse list:
    list* currentNode;
    list *deleter;

    // Point 'currentNode' to the same Node as 'starting_ptr':
    currentNode = starting_ptr;

    while ( (currentNode->next)->next != nullptr) {
        // Traverse - Go to the next Node:
        currentNode = (currentNode->next);
    }
    
    deleter = currentNode->next;
    delete deleter;
    
    currentNode->next         = nullptr;
}
