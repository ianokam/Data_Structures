/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           main.cpp
//  Program:            Hash Table - Chaining
//  Title:              Main Program
//
//  Author:             Ibeawuchi Anokam
//  Date of Creation:   03/10/20
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
// The program will create a hash table, of size 26 ,using chaining and
// singly linked lists that takes a name (string) from the keyboard.
// To calculate the key.
//
// *  You should convert the first character in the string
//    to its equivalent ASCII,  then calculate the key by taking the
//    ASCII(1st Character) % size  then insert the string in the
//    corresponding hash table index of the linked list.
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
//------------------------
// System-Defined        :
// Libraries             :
//------------------------
#include <iostream>     // Cin/Cout Stream
#include <string>       // Allows For Strings
#include <stdexcept>    // Allows For "runtime_error" object
#include <vector>       // Allows For Dynamic Arrays
using namespace std;


//------------------------
// ADT: SLL Prototype    :
//------------------------
struct NodeType{
    // Record Field(s):
    string data;
    // Pointer Field(s):
    NodeType* Next;
};

//------------------------
// Function Prototype(s) :
//------------------------
// Initialize The Hash Table:
void InitHashTable ( NodeType* hashtable_container[ ],
                     int       hashtable_size          );

// Insert The Name In The Hash Table:
void InsertHash    ( NodeType* hashtable_container[ ],
                     int       hashtable_size,
                     string    name_value_container    );

// Prints The Hash Table:
void PrintHash     ( NodeType* hashtable_container[ ],
                     int       hashtable_size          );


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
    const int size= 6;
    NodeType* hashtable[size];
    int       val_insertion_counter  = 0;
    string    name_value;
    int       char_index;
    bool      is_name;
    
    //--------------------------------------------
    // Hash Table Initialization                 :
    //--------------------------------------------
    InitHashTable ( hashtable, size );
    
    
    //--------------------------------------------
    // Hash Table Creation -  Title Section      :
    //--------------------------------------------
    cout<<endl;
    cout<< "-----------------------------------------------------------"<<endl;
    cout<< "   BUILDING THE HASH TABLE                                :"<<endl;
    cout<< "-----------------------------------------------------------"<<endl;
    cout<< endl;
    
    //--------------------------------------------
    // Insert The Name Values Into               :
    // The Hash Table                            :
    //--------------------------------------------
    while( val_insertion_counter < size )
    {
        // Ask The User For A Name:
        cout << "Entry # " << val_insertion_counter + 1 << "."
             <<endl;
        
        cout << "Enter The Name You Would Like To Insert Into The Hash Table: "
             <<endl;
        
        //---------------------------------------------------------------------
        // Exception Handler                                                  :
        //---------------------------------------------------------------------
        try{
            
            //-----------------------------------------------------------------
            // INSERTS A VALUE  &&                                            :
            // IFF The Value Is The Wrong Data Type                           :
            //-----------------------------------------------------------------
            if(  !(cin >> name_value)  )
            {
                // Clear input stream
                cin.clear();

                // Discard previous input
                cin.ignore(123, '\n');
                
                // PERSONALIZED STATEMENT OF ERROR:
                throw runtime_error("ERROR: Invalid Data Type. A String Must Be Entered.");
            }
            
            //-----------------------------------------------------------------
            // Check For Readable Upper Case And Lower Case Alphabets, Only   :
            // Else OutPut An Error                                           :
            //-----------------------------------------------------------------
            char_index = 0;
            is_name    = true;
            
            while( char_index <  name_value.size() &&
                   is_name    == true                   )
            {
                
                // Looking Upper Case And Lower Case Alphabets:
                if(  !( static_cast<int>( name_value[ char_index ] ) >= 65  &&
                        static_cast<int>( name_value[ char_index ] ) <= 90     )
                                                &&
                     !( static_cast<int>( name_value[ char_index ] ) >= 97  &&
                       static_cast<int>( name_value[ char_index ] ) <= 122     )    )
                {
                    // If A Non-Alphabetical Value Is Found Then:
                    is_name = false;
                }
                else{
                    
                    char_index++;
                }
                
            }// End Of While-Loop
            
            if(  is_name == false  )
             {
                 // Clear input stream
                 cin.clear();
                 // Discard previous input
                 cin.ignore(123, '\n');
                 
                 cout<<endl;
                 
                 // PERSONALIZED STATEMENT OF ERROR:
                 throw runtime_error("ERROR: Invalid Data Type. A String Must Be Entered.");
             }
            else{
                val_insertion_counter++;
            }
            
    
        }
        catch( runtime_error& excpt ){
            // Prints the error message passed by throw statement:
            cout << excpt.what() << endl;
            cout << "Enter a Valid Value." // GENERALIZED STATEMENT OF ERROR
                 << endl << endl;
        }
        
        //-----------------------------------------------------------------
        // Continue With The Normal Flow Of Code.                         :
        // Insert The Name Into The Hash Table                            :
        //-----------------------------------------------------------------
        InsertHash ( hashtable, size, name_value );
        cout<<endl;

    }//END While-Loop

    
    //--------------------------------------------
    // Print The Hash Table                      :
    //--------------------------------------------
    PrintHash( hashtable, size );

    
    //--------------------------------------------
    // System Specific Macro.                    :
    // Pause The System                          :
    //--------------------------------------------
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #endif
    
    //--------------------------------------------
    // End Application                           :
    //--------------------------------------------
    return 0;
}



/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                   F U N C T I O N    D E F I N I T I O N S                */
/*---------------------------------------------------------------------------*/
void InitHashTable ( NodeType* hashtable_container[ ],
                     int       hashtable_size          )
{
//-----------------------------------------------------------------------------
// Function Description
//-----------------------------------------------------------------------------
// This Function Initializes The Hash Table.
//-----------------------------------------------------------------------------

    
    //--------------------------------------------
    // Variable Declarations                     :
    //--------------------------------------------
    int hashTable_init_counter;
    
    //--------------------------------------------
    // Initialize The Hash Table                 :
    //--------------------------------------------
    for( hashTable_init_counter = 0; hashTable_init_counter < hashtable_size; hashTable_init_counter++ ){
        // Initialize Each Array Indices 'Next' Value To A null pointer;
        hashtable_container [ hashTable_init_counter ]         = new NodeType;
        hashtable_container [ hashTable_init_counter ] -> Next = nullptr;
    }
}

void InsertHash ( NodeType* hashtable_container[ ],
                  int       hashtable_size,
                  string    name_value_container    )
{
//-----------------------------------------------------------------------------
// Function Description
//-----------------------------------------------------------------------------
// This Function Creates A Hash Tables Nodes.
// It Reads In A String Value Into Each Generated Singly Linked List Node
// And Stores It Into The Appropriate Array Index.
//-----------------------------------------------------------------------------
    
    
    //-------------------------------------------------------------------------
    // Variable Declarations                                                  :
    //-------------------------------------------------------------------------
    // Create a temporary container to traverse list:
    NodeType* newNode;          // Container For The Newly Generated Data
    NodeType* currentNode;      // Container For The Newly Generated Data
    
    int insert_index;           // This is the Hash Function (Key)
    
    
    //-------------------------------------------------------------------------
    // Hash Table Data Insertion                                              :
    //-------------------------------------------------------------------------
    // Initialize The Hash Function to Find The Index To Use:
    insert_index = name_value_container[0] % hashtable_size;
    
    
    // Check The Hash Table Index And Chain If Need Be:
    if( hashtable_container [ insert_index ] -> Next  == nullptr ){
        // Create A New Node:
        newNode         = new NodeType;
        newNode -> data = name_value_container;
        newNode -> Next = nullptr;

        // Insert The First Node At The Beginning Of The List At That Index:
        hashtable_container [ insert_index ] -> Next = newNode;
    }
    else{
        // Create A New Node:
        newNode         = new NodeType;
        newNode -> data = name_value_container;
        newNode -> Next = nullptr;
        
        // Make The First Node At That Index The Current Node For
        // Traversing Its List:
        currentNode = ( hashtable_container [ insert_index ] -> Next );
        
        // Traverse List To The End:
        while( currentNode -> Next != nullptr ){
            currentNode = ( currentNode -> Next );
        }
        
        // Insert The New Node At The End Of The List:
        currentNode -> Next = newNode;
    }
}

void PrintHash( NodeType* hashtable_container[ ],
                int       hashtable_size          )
{
//-----------------------------------------------------------------------------
// Function Description
//-----------------------------------------------------------------------------
// This Function Prints The Hash Table.
//-----------------------------------------------------------------------------
    
    
    //-------------------------------------------------------------------------
    // Variable Declarations                                                  :
    //-------------------------------------------------------------------------
    NodeType* currentNode;          // Container For The Newly Generated Node
    
    int currentNode_counter = 0;    // This counts the index value of a list
    int insert_index = 0;           // This is the current Index Being Read
    
    //-------------------------------------------------------------------------
    // Printing The Title Block                                               :
    //-------------------------------------------------------------------------
    cout<<endl;
    cout<< "-----------------------------------------------------------"<<endl;
    cout<< "   PRINTING THE HASH TABLE                                :"<<endl;
    cout<< "-----------------------------------------------------------"<<endl;
    cout<< endl;
    
    
    //-------------------------------------------------------------------------
    // Hash Table Traversal & Printing                                        :
    //-------------------------------------------------------------------------
    while( insert_index < hashtable_size ){
        
        // Set/Reset The Node Counter For Each Indices List:
        currentNode_counter = 0;
        
        
        // Output The Current Index:
        cout<< "--------------" << endl
            << "Index "         << insert_index << endl
            << "--------------" <<endl <<endl;
        
        if( hashtable_container [ insert_index ] -> Next  != nullptr ){
            
            // Make The First Node At That Index The Current Node For
            // Traversing Its List:
            currentNode = ( hashtable_container [ insert_index ] -> Next );
            
            // Traverse List To The End And Print:
            while( currentNode != nullptr ){
                // If The List Has Nodes Available, Then Print It's Current Node:
                cout<< "Node "<< currentNode_counter <<":   "
                    << currentNode -> data;
                    
                if( currentNode -> Next != nullptr ){
                    cout<< "     |      ";  // Add Space Between Values
                }
                
                // Move To The Next Possible Node To Print:
                currentNode_counter++;
                currentNode         = currentNode -> Next;
            }
            
            // Move to the Next Index To Search:
            insert_index ++;
        }
        else{
            // Prints If The Current Index Has No Nodes:
            cout<< " * EMPTY "<< endl;
            // Move to the Next Index To Search:
            insert_index ++;
        }
        // Add An Extra Line Of Space After Outputting List Values:
        cout<< endl << endl <<endl;
        
    }// End While-Loop
}

