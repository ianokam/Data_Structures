/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           queue_ADT.hpp
//  Program:            Stacks_and_Queues
//  Title:              Queue Class Definition
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
// The File Holds The Queue Class Definition.
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
#ifndef queue_ADT_hpp
#define queue_ADT_hpp

//--------------------------------------------
// System-Defined                            :
// Libraries                                 :
//--------------------------------------------
#include <stdio.h>      // Standard Buffered Input/Output
#include <iostream>     // Character Input/Output
#include <string>       // Allows For The Use Of Strings
#include <assert.h>     // Test Assumptions Made By Programmer
using namespace std;


//--------------------------------------------
// Queue ADT Prototype                       :
//--------------------------------------------
class queue_ADT{
    
    
    //----------------------------------------
    // Public Member Functions               :
    //----------------------------------------
    public:
        //------------------------------------
        // DEFUALT  CONSTRUCTOR              :
        //------------------------------------
            queue_ADT( );
    
        //------------------------------------
        // MUTATOR -  FUNCTION MEMBERS       :
        //------------------------------------
            // Initialize Queue To An Empty
            // State:
            void   queue_init( );
    
    
            // Pushes In A New Character
            // Element Onto The Queue:
            void   add_queue( char letter );
        
    
            // Removes The Front Character
            // Element From The Queue:
            void   delete_queue( );


        //------------------------------------
        // ACCESSOR - FUNCTION MEMBERS       :
        //------------------------------------
            // Returns If The Queue Is Empty:
            bool   is_empty( ) const;
        
    
            // Returns If The Queue Is Full:
            bool   is_full( ) const;
    
    
            // Returns The Front Character
            // Element Of The Queue:
            char   front( ) const;

    
            // Returns The Back Character
            // Element Of The Queue:
            char   rear( ) const;
    
    
    
    //----------------------------------------
    // Private Data Members (Variables)      :
    //----------------------------------------
    private:
        //------------------------------------
        // DATA MEMBERS                      :
        //------------------------------------
            // Queue ( Singly Linked List )
            // Node Prototype:
            struct nodeType
            {
                //RECORD FIELD(S):
                char      char_val;
                // POINTER FIELD(S):
                nodeType* next;
            };
    
    
            // Queue ( Singly Linked List )
            // Front Pointer:
            nodeType* queue_front;
    
    
            // Queue ( Singly Linked List )
            // Back Pointer:
            nodeType* queue_rear;
};

#endif
