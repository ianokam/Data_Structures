/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           main.cpp
//  Program:            Binary Trees: A Binary Search Tree -One Child Counting
//  Title:              Main Program
//
//  Author:             Ibeawuchi Anokam
//  Date of Creation:   04/21/20
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
// The program creates a binary search tree (BST), 
// then writes a function called singleParent, 
// that returns the number of nodes in a binary tree 
// that have only one child.  
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
//--------------------------------------------
// System-Defined                            :
// Libraries                                 :
//--------------------------------------------
#include <iostream>
#include <stdexcept>
using namespace std;

//--------------------------------------------
// User-Defined                            :
// Libraries                                 :
//--------------------------------------------
#include "binary_search_tree_ADT.h"


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                           M A I N    M O D U L E                          */
/*---------------------------------------------------------------------------*/
//------------------------
// Start Application     :
//------------------------
int main( ) {
    //---------------------------------------------------------------------
    // Binary Search Tree (BST) Declarations                              :
    //---------------------------------------------------------------------
    binaryTreeType< int > binary_search_tree;
    //---------------------------------------------------------------------
    // Variable Declarations                                              :
    //---------------------------------------------------------------------
    const int	  MAX_NUM_OF_VALS = 10;	// number of BST Values To Read In

	int			  integer_val = -1;		// Buffer For Each Value To Insert Into
										// The BST

	int			  counter;				// While-Loop Flag
    

	//---------------------------------------------------------------------
    // PROGRAM DESCRIPTION												  :
	//---------------------------------------------------------------------
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "  BINARY SEARCH TREE  -  PROGRAM DESCRIPTION                                 :" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
	cout << "  The program asks the user to input 10 values into a binary search tree."		 << endl; 
	cout << "  It outputs the count of parent nodes with one child."        			 	 << endl;
    

	//---------------------------------------------------------------------
	// READ INTEGER VALUES INTO THE BST				            		  :
	//---------------------------------------------------------------------
	// While-Loop Flag Initialization:
	counter = 0;
	

	// Program Output Divider:
	cout << endl << endl;
	cout << "  ---------------------------------------------------"  << endl;
	cout << "  :      ENTER 10 NUMBERS YOU WANT TO READ IN       : " << endl;
	cout << "  ---------------------------------------------------"  << endl;
	cout << endl;



	// Exception Handler - Check That The User Inputs The Correct Values:
    while( counter < MAX_NUM_OF_VALS )
    {
		cout << "  #"; 
		if (counter + 1 < 10) {
			cout << "0";
		}
		cout << counter + 1 << " --- ENTER THE NUMBER YOU WANT TO READ IN:   ";
       
    
        try{
  
            // Check If The Value Entered Is 
            // The Correct Data Type:
            if(  !(cin >> integer_val)  )
            {
                // Clear Input Buffer Stream:
                cin.clear();
                
				// If An Error Is Found, Don't Incrementing:
				counter = counter;

                // PERSONALIZED STATEMENT OF ERROR:
                throw runtime_error("Invalid Data Type.");
            }
            

			// BST INSERTION CODE:
			binary_search_tree.insert( integer_val );


            // If All Checks Have Been Passed, Allow The Code To Continue Past The While-Loop:
			counter++;
        }
        catch( runtime_error& excpt )
        {
            
            // Prints The Error Message Passed By The Throw Statement:
            cout << endl;
            cout << "----------" << endl << endl;
            cout << "  ERROR:  " << excpt.what() << endl << endl;
            cout << "----------" << endl << endl << endl;
        }
    
    }// END OF TRY-CATCH WHILE-LOOP ( 'Exception Handler - Check That The User Inputs THe Correct Values" )

	

	//---------------------------------------------------------------------
	// OUTPUT THE COUNT OF NODES WITH ONE CHILD					          :
	//---------------------------------------------------------------------
	// Print Section Title:
	cout << endl << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "  BINARY SEARCH TREE  -  COUNT OF NODES WITH ONE CHILD PRINTING              :" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << endl << endl;

	// Output:
	cout << "The Number Of Nodes With One Child Is:   " 
		 << binary_search_tree.singleParent( );

    
	// Give Space At The End Of The Program:
	cout << endl << endl << endl;



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
// END Main Function
