/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           main.cpp
//  Program:            Stacks_and_Queues
//  Title:              Main Program
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
// PROGRAM DESCRIPTION                            :
//-------------------------------------------------
//
// The program will reads a  line of text  from the keyboard,
// changes each uppercase letter to lowercase, and places each letter
// both in a queue and onto a stack.  
//
// The program should then verify whether the line of text is a palindrome
// (a set of letters or numbers that is the same whether read forward or
//  backward).
//
//
//-------------------------------------------------
// FILE DESCRIPTION                               :
//-------------------------------------------------
//
// The File Holds:
//      - The Main Function
//      - All The Necessary Libraries
//      - upper_lower_case_swap( string text_container ) Function
//
// And Starts The Program Application.
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
//--------------------------------------------
// System-Defined                            :
// Libraries                                 :
//--------------------------------------------
#include <iostream>     // Character Input/Output
#include <string>       // Allows For The Use Of Strings
using namespace std;

//--------------------------------------------
// User-Defined                              :
// Libraries                                 :
//--------------------------------------------
#include "stack_ADT.hpp"
#include "queue_ADT.hpp"

//--------------------------------------------
// Global                                    :
// Function Prototype(s)                     :
//--------------------------------------------
string upper_lower_case_swap( string text_container );



/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                           M A I N    M O D U L E                          */
/*---------------------------------------------------------------------------*/
//------------------------
// Start Application     :
//------------------------
int main( ){
    //---------------------------------------------------------------------
    // Stack And Queue Declarations                                       :
    //---------------------------------------------------------------------
    stack_ADT stack;
    queue_ADT queue;
    //---------------------------------------------------------------------
    // Variable Declarations                                              :
    //---------------------------------------------------------------------
    string    line_of_text;
    int       char_index;
    string    line_of_text_from_stack;

    //---------------------------------------------------------------------
    // Input Text                                                         :
    //---------------------------------------------------------------------
    cout<< "------------------------------------------------------------"<<endl;
    cout<< "    Program 5 - Queues & Stacks                            :"<<endl;
    cout<< "------------------------------------------------------------"<<endl;
    
    // Ask For A Line Of Text:
    cout << "   INSERT A LINE OF TEXT:   ";
    
    // Input Text Until The End Of The Line ( Up Until A Newline) :
    getline( cin, line_of_text );
        

    
    //---------------------------------------------------------------------
    // Swap Out Uppercase Letters                                         :
    //---------------------------------------------------------------------
    line_of_text = upper_lower_case_swap( line_of_text );
    
    
    
    //---------------------------------------------------------------------
    // Stack And Queue Line Of Text Insertion                             :
    //---------------------------------------------------------------------
    cout<< endl<< endl;
    cout<< "----------------------------------------------------"<<endl;
    cout<< "   INPUT THE LINE OF TEXT ONTO A STACK             :"<<endl;
    cout<< "----------------------------------------------------"<<endl;
    cout<< endl<< endl;
    
    
    // Set Index Counter To The First Index:
    char_index    = 0;
    
    
    // Inserts ONLY Lowercase Letters Into The Stack And Queue
    // IF There Is Free Memory To Create The Stack:
    if(   !stack.is_full()   &&   !queue.is_full()   ){
        
        while(  char_index < line_of_text.length()
                                        &&
              ( static_cast<int>(  line_of_text[ char_index ]  ) >= 97  &&
                static_cast<int>(  line_of_text[ char_index ]  ) <= 122     ) )
        {
        
            // Push In A Character Into The Stack:
            stack.push(  line_of_text[ char_index ]  );
            
            // Inserts A Character Into The Queue:
            queue.add_queue(  line_of_text[ char_index ]  );
            
            
            // Goto The Next Character In The String To Input In:
            char_index++;
        }
    }
    
    cout<< "   Done !";
    cout<< endl << endl;
    
    
    
    //---------------------------------------------------------------------
    // Output The Stack Into A String Variable                            :
    //---------------------------------------------------------------------
    cout<< endl<< endl;
    cout<< "----------------------------------------------------"<<endl;
    cout<< "   INSERT THE LINE OF TEXT FROM THE STACK INTO A   :"<<endl;
    cout<< "   STRING VARIABLE                                 :"<<endl;
    cout<< "----------------------------------------------------"<<endl;
    cout<< endl<< endl;
    
    while (  !stack.is_empty()  ){
        
        // Append Characters To The String:
        line_of_text_from_stack +=  stack.top();
        
        // Delete Characters From The Stack:
        stack.pop();
    }
    cout<< "   Done !";
    cout<< endl << endl;
    
    
    
    //---------------------------------------------------------------------
    // Check For A Palindrome                                             :
    //---------------------------------------------------------------------
    // Print Text In Preparation Of Outputting the Palindrome Checker Results:
    cout<< endl<< endl;
    cout<< "----------------------------------------------------"<<endl;
    cout<< "   CHECK IF THE LINE OF TEXT IS A PALINDROME       :"<<endl;
    cout<< "----------------------------------------------------"<<endl;
    
    // Output If The Line Of Text Is A Palindrome:
    if ( line_of_text == line_of_text_from_stack ) {
        
        cout << endl << endl;
        cout << "   GIVEN:   "    << "'" << line_of_text    <<"'"  <<endl <<endl;
        cout << "   This Line Of Text Is A Palindrome."     <<endl <<endl <<endl;
    }
    else{
        
        cout << endl << endl;
        cout << "   Given:   "    << "'" << line_of_text    <<"'"  <<endl <<endl;
        cout << "   This Line Of Text Is Not A Palindrome." <<endl <<endl <<endl;
    }
    
    
    
    //---------------------------------------------------------------------
    // System Specific Macro.                                             :
    // Pause The System                                                   :
    //---------------------------------------------------------------------
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #endif
    
    //---------------------------------------------------------------------
    // End Application                                                    :
    //---------------------------------------------------------------------
    return 0;
}



/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                   F U N C T I O N    D E F I N I T I O N S                */
/*---------------------------------------------------------------------------*/
string upper_lower_case_swap( string text_container ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Goes Through A String And Turns All The Uppercase Letters
// Into Lowercase Letters.
//
//---
//
// * NOTE 1:  ASCII uppercase letters range from  65 - 90
//            ASCII lowercase letters rangr from  97 - 122
//
// * NOTE 2:  The Distance Betewwn An Uppercase Letter And It's Lowercase
//            Counterpart Is Always 32 Characters Away
//-----------------------------------------------------------------------------
    
    
    //-------------------------------------------------------------------------
    // Variable Declarations                                                  :
    //-------------------------------------------------------------------------
    int  char_index;            // Current Strings Index/Character
    
    char ascii_lowercase_char;  // Holds the Lowercase Character To Be
                                // Swapped In
    
    
    //-------------------------------------------------------------------------
    // Variable Initializations                                               :
    //-------------------------------------------------------------------------
    for( char_index = 0; char_index < text_container.size(); char_index++ ){
        
        if(  static_cast<int>(  text_container[ char_index ]  ) >= 65  &&
             static_cast<int>(  text_container[ char_index ]  ) <= 90      )
        {
            ascii_lowercase_char    =  static_cast<char>( static_cast<int>( text_container[ char_index ] ) + 32 );
            
            text_container[ char_index ] =  ascii_lowercase_char;
        }
    }
    
    
    //-------------------------------------------------------------------------
    // Return The Name With All Lowercase Letters                             :
    //-------------------------------------------------------------------------
    return text_container;
}
