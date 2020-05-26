/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           main.cpp
//  Program:            Binary Trees: A Binary Search Tree
//  Title:              Main Program
//
//  Author:             Ibeawuchi Anokam
//  Date of Creation:   04/09/20
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
// The program creates a binary search tree (BST) 
// where each parent node has an ordering property of
// ( left  child key ≤ the parent's key ) and the
// ( right child key ≤ the parent's key ).
//
//---
// The Program adheres to these three statements:
//
//	 1) Initially, the binary search tree is empty
//
//
//	 2) The user inserts a set of random numbers 
//		into the BST
//
//
//	 3) The program then prints the values of the 
//		BST using the three BST traversal 
//		methods :
//
//			a) Preorder  (Root, Left, Right) 
//			b) Inorder   (Left, Root, Right)
//			c) Postorder (Left, Right, Root)
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
// User-Defined                              :
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
	const int MAX_NUM_OF_VALS = 10;	// number of BST Values To Read In

	int	integer_val = -1;	// Buffer For Each Value To Insert Into
					// The BST

	int	counter;		// While-Loop Flag


	//---------------------------------------------------------------------
	// PROGRAM DESCRIPTION						      :
	//---------------------------------------------------------------------
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "  BINARY SEARCH TREE  -  PROGRAM DESCRIPTION                                 :" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "  The program asks the user to input 10 values into a binary search tree."	 << endl; 
	cout << "  It outputs the binary search tree values Using The Algorithms:"		 << endl;
	cout << "  Preorder, Inorder, Postorder"												 << endl;


	//---------------------------------------------------------------------
	// READ INTEGER VALUES INTO THE BST				      :
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
		if (counter + 1 < MAX_NUM_OF_VALS) {
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
	// OUTPUT THE BST VALUES					      :
	// USING THE PREORDER ALGORITHM    				      :
	//---------------------------------------------------------------------
	// Print Section Title:
	cout << endl << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "  BINARY SEARCH TREE  -  PREORDER PRINTING                                   :" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << endl << endl;

	// Print BST:
	binary_search_tree.preorder( );


	//---------------------------------------------------------------------
	// OUTPUT THE BST VALUES					      :
	// USING THE INORDER ALGORITHM    				      :
	//---------------------------------------------------------------------
	// Print Section Title:
	cout << endl << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "  BINARY SEARCH TREE  -  INORDER PRINTING                                    :" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << endl << endl;

	// Print BST:
	binary_search_tree.inorder( );


	//---------------------------------------------------------------------
	// OUTPUT THE BST VALUES					      :
	// USING THE POSTORDER ALGORITHM    				      :
	//---------------------------------------------------------------------
	// Print Section Title:
	cout << endl << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "  BINARY SEARCH TREE  -  POSTORDER PRINTING                                  :" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << endl << endl;

	// Print BST:
	binary_search_tree.postorder( );


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
