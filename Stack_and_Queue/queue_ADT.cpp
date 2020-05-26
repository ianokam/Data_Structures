/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           queue_ADT.cpp
//  Program:            Stacks_and_Queues
//  Title:              Queue Function Definitions
//
//  Author:             Ibeawuchi Anokam
//  Date of Creation:   03/24/20
//  Version:            1.0.0
//  Revised by:         n/a
//  Revision Date:      n/a
//
//  Copyright:          Copyright © 2020 Ibeawuchi Anokam.
//                      All rights reserved.
//
//-------------------------------------------------
// FILE DESCRIPTION                               :
//-------------------------------------------------
//
// The File Holds The Queue Class Function Definitions.
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
//--------------------------------------------
// User-Defined                              :
// Library                                   :
//--------------------------------------------
#include "queue_ADT.hpp"


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                   F U N C T I O N    D E F I N I T I O N S                */
/*---------------------------------------------------------------------------*/

queue_ADT::queue_ADT( ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is The Default Constructor Function That Initializes The Default
// Value(s) For The Data Members.
//-----------------------------------------------------------------------------


    // Defualt Queue Top Pointer Value:
    queue_front = nullptr;
    // Defualt Queue Back Pointer Value:
    queue_rear  = nullptr;
}


void  queue_ADT::queue_init( ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Reinitializes A Queue To An Empty State.
//-----------------------------------------------------------------------------
    
    
    //---------------------------------------------------------------------
    // Variable Declaration                                               :
    //---------------------------------------------------------------------
    nodeType* deleter;

    //---------------------------------------------------------------------
    // Deleter Pointer Initialization                                     :
    //---------------------------------------------------------------------
    deleter = queue_front;
    
    //---------------------------------------------------------------------
    // Queue Memory Deallocation                                          :
    //---------------------------------------------------------------------
    // Delete Queue Nodes:
    while ( deleter != nullptr ){
        
        deleter = deleter->next;
        delete queue_front;
        queue_front = deleter;
    }
    
    // Reinitialize Queue Pointers To Null:
    queue_front = nullptr;
    queue_rear  = nullptr;
}


void  queue_ADT::add_queue( char letter ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Inserts In A New Character Element Into The Queue.
//-----------------------------------------------------------------------------

        
    //---------------------------------------------------------------------
    // Variable Declarations                                              :
    //---------------------------------------------------------------------
    nodeType* currentNode;  // New Node Creator Pointer

    
    //---------------------------------------------------------------------
    // New Node Initialization                                            :
    //---------------------------------------------------------------------
    // Creates a New Node And Push In A Character Into It:
    currentNode           = new nodeType;
    currentNode->char_val = letter;
    currentNode->next     = nullptr;
    
    
    //---------------------------------------------------------------------
    // New Node Insertion                                                 :
    //---------------------------------------------------------------------
    // CASE 1 - Uninitialized Queue.
    // Inserts The Initial, New  Queue Front/Rear  Node:
    if( queue_front == nullptr ){
        
        queue_front = currentNode;
        queue_rear  = currentNode;
        
    }
    // CASE 2 - Initialized Queue.
    // Inserts All Other New Queue Nodes At The Rear:
    else{
        
        queue_rear -> next = currentNode;
        queue_rear         = currentNode;
    }
}


void  queue_ADT::delete_queue( ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Removes The Front Character Element From The Queue.
//-----------------------------------------------------------------------------
    
    
    if ( queue_front  != nullptr ){
        
        //---------------------------------------------------------------------
        // Variable Declarations                                              :
        //---------------------------------------------------------------------
        nodeType* currentNode;  // Pointer Used For Deletion
        nodeType* nextNode;     // Pointer Used For The Front of the Queue
        
        
        //---------------------------------------------------------------------
        // Delete Top Node                                                    :
        //---------------------------------------------------------------------
        currentNode           = queue_front;
        nextNode              = currentNode->next;
        
        delete currentNode;
        
        
        //---------------------------------------------------------------------
        // Reset The Top Node                                                 :
        //---------------------------------------------------------------------
        queue_front = nextNode;
        
    }
    else{
        cout << "ERROR: Cannot Remove From The Queue. It Is Empty."
             << endl
             << endl;
    }
}


bool  queue_ADT::is_empty( ) const {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Returns If The Queue Is Empty.
//
// If The Front And Rear Pointer is Equivalent To nullptr then return  'true'.
// Else, If The Front And Rear Pointer is Not Equivalent To nullptr
// then return  'false'.
//-----------------------------------------------------------------------------

    
    // Check If  'queue_front'  and   'queue_rear'  Is Pointing To Null:
    return ( queue_front == nullptr  &&
             queue_rear  == nullptr      );
}


bool  queue_ADT::is_full( ) const {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Returns If The Queue Is Full.
//
// If There Is No More Memory To Allocate It Will return  'true'.
// Else, If There Is More Memory To Allocate It Will return  'false'.
//-----------------------------------------------------------------------------

    
    //---------------------------------------------------------------------
    // Variable Declarations                                              :
    //---------------------------------------------------------------------
    nodeType* currentNode;
    
    //---------------------------------------------------------------------
    // Variable Initialization                                            :
    //---------------------------------------------------------------------
    // Used To Test If There Is Anymore Dynamic Memory Allocation Possible:
    currentNode = new nodeType;
    
    //---------------------------------------------------------------------
    // Check For Memory                                                   :
    //---------------------------------------------------------------------
    if( currentNode == nullptr ){
       return true;
    }
    else {
       delete currentNode;
       return false;
    }
}


char  queue_ADT::front( ) const {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Returns The Front Character Element Of The Queue.
// But, If The Assertion Is Not Possible Then It Will Provide Program
// With An Error.
//-----------------------------------------------------------------------------
    

    // Check If Assertion Is True / Possible:
    assert ( queue_front  != nullptr );
        
    // Else, If Possible, Return The Top Character:
    return(  queue_front->char_val  );
}


char  queue_ADT::rear( ) const {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Returns The Rear Character Element Of The Queue.
// But, If The Assertion Is Not Possible Then It Will Provide Program
// With An Error.
//-----------------------------------------------------------------------------
    

    // Check If Assertion Is True / Possible:
    assert ( queue_rear  != nullptr );
        
    // Else, If Possible, Return The Top Character:
    return(  queue_rear->char_val  );
}
