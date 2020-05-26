/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           stack_ADT.hpp
//  Program:            Stacks_and_Queues
//  Title:              Stack Class Definition
//
//  Author:             Ibeawuchi Anokam
//  Date of Creation:   03/24/20
//  Version:            1.0.0
//  Revised by:         n/a
//  Revision Date:      n/a
//
//  Copyright:          Copyright © 2020 Ibeawuchi Anokam. 
//						All rights reserved.
//
//-------------------------------------------------
// FILE DESCRIPTION                               :
//-------------------------------------------------
//
// The File Holds The Stack Class Definition.
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
#ifndef stack_ADT_hpp
#define stack_ADT_hpp

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
// ADT: Stack Prototype                      :
//--------------------------------------------
class stack_ADT{
    
    public:
        //------------------------------------
        // DEFUALT  CONSTRUCTOR              :
        //------------------------------------
            stack_ADT( );
        
        //------------------------------------
        // MUTATOR -  FUNCTION MEMBERS       :
        //------------------------------------
            // Initialize Stack To An Empty
            // State:
            void   stack_init( );

    
            // Pushes In A New Character
            // Element Onto The Stack:
            void   push( char letter );
            
    
            // Removes The Top Character
            // Element From The Stack:
            void   pop( );
        
        //------------------------------------
        // ACCESSOR - FUNCTION MEMBERS       :
        //------------------------------------
            // Returns If The Stack Is Empty:
            bool   is_empty( ) const;

    
            // Returns If The Stack Is Full:
            bool   is_full( ) const;
    
    
            // Returns The Top Character
            // Element Of The Stack:
            char   top( ) const;
    
    
    private:
        //------------------------------------
        // DATA MEMBERS                      :
        //------------------------------------
            // Stack ( Singly Linked List )
            // Node Prototype:
            struct nodeType
            {
                //RECORD FIELD(S):
                char      char_val;
                // POINTER FIELD(S):
                nodeType* next;
            };
    
    
            // Stack ( Singly Linked List )
            // Top Pointer:
            nodeType* stack_top;
};

#endif 
