/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           stack_ADT.cpp
//  Program:            Stacks_and_Queues
//  Title:              Stack Function Definitions
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
// The File Holds The Stack Class Function Definitions.
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
#include "stack_ADT.hpp"


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                   F U N C T I O N    D E F I N I T I O N S                */
/*---------------------------------------------------------------------------*/

stack_ADT::stack_ADT( ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is The Default Constructor Function That Initializes The Default
// Value(s) For The Data Members.
//-----------------------------------------------------------------------------


    // Defualt Stack Top Pointer Value:
    stack_top = nullptr;
}


void  stack_ADT::stack_init( ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Reinitializes A Stack To An Empty State.
//-----------------------------------------------------------------------------
    
    
    //---------------------------------------------------------------------
    // Variable Declaration                                               :
    //---------------------------------------------------------------------
    nodeType* deleter;

    //---------------------------------------------------------------------
    // Deleter Pointer Initialization                                     :
    //---------------------------------------------------------------------
    deleter = stack_top;
    
    //---------------------------------------------------------------------
    // Stack Memory Deallocation                                          :
    //---------------------------------------------------------------------
    // Delete Stack Nodes:
    while ( deleter != nullptr ){
        
        deleter = deleter->next;
        delete stack_top;
        stack_top = deleter;
    }
    
    // Reinitialize Stack Top Pointer To Null:
    stack_top = nullptr;
}


void  stack_ADT::push( char letter ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Pushes In A New Character Element Onto The Stack.
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
    // Inserts a New Stack Top:
    currentNode->next     = stack_top;
    stack_top             = currentNode;
}


void  stack_ADT::pop( ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Removes The Top Character Element From The Stack.
//-----------------------------------------------------------------------------
    
    
    if ( stack_top  != nullptr ){
        
        //---------------------------------------------------------------------
        // Variable Declarations                                              :
        //---------------------------------------------------------------------
        nodeType* currentNode;  // Pointer Used For Deletion
        nodeType* nextNode;     // Pointer Used For The Top of the Stack
        
        
        //---------------------------------------------------------------------
        // Delete Top Node                                                    :
        //---------------------------------------------------------------------
        currentNode           = stack_top;
        nextNode              = currentNode->next;
        
        delete currentNode;
        
        
        //---------------------------------------------------------------------
        // Reset The Top Node                                                 :
        //---------------------------------------------------------------------
        stack_top = nextNode;
        
    }
    else{
        cout << "ERROR: Cannot Remove From The Stack. It Is Empty."
             << endl
             << endl;
    }
}


bool  stack_ADT::is_empty( ) const {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Returns If The Stack Is Empty.
//
// If The Top Pointer is Equivalent To nullptr then return  'true'.
// Else, If The Top Pointer is Not Equivalent To nullptr then return  'false'.
//-----------------------------------------------------------------------------

    
    // Check If  'stack_top'  Is Pointing To Null:
    return ( stack_top == nullptr );
}


bool  stack_ADT::is_full( ) const {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Returns If The Stack Is Full.
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


char  stack_ADT::top( ) const {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Returns The Top Character Element Of The Stack.
// But, If The Assertion Is Not Possible Then It Will Provide Program
// With An Error.
//-----------------------------------------------------------------------------
    

    // Check If Assertion Is True / Possible:
    assert ( stack_top  != nullptr );
        
    // Else, If Possible, Return The Top Character:
    return(  stack_top->char_val  );
}

