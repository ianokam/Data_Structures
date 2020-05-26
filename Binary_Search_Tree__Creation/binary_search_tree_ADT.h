/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           binary_search_tree_ADT.h
//  Program:            Binary Trees: A Binary Search Tree
//  Title:              Binary Search Tree Class Definition And Functions
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
// FILE DESCRIPTION                               :
//-------------------------------------------------
//
// The File Holds The Binary Search Tree Class Definition
// And Its Function Definitions.
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
#ifndef binary_search_tree_ADT_h
#define binary_search_tree_ADT_h

//--------------------------------------------
// System-Defined                            :
// Libraries                                 :
//--------------------------------------------
#include <stdio.h>      // Standard Buffered Input/Output
#include <iostream>     // Character Input/Output
using namespace std;


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        C L A S S    S E C T I O N                         */
//---------------------------------------------------------------------------*/
//--------------------------------------------
// ADT: Binary Search Tree (BST) Prototype   :
//--------------------------------------------
template<class dataType>
class binaryTreeType{
    
    //----------------------------------------
    // Public Member Functions               :
    //----------------------------------------
    public:
        //------------------------------------
        // DEFUALT  CONSTRUCTOR              :
        //------------------------------------
            binaryTreeType( );
        
        //------------------------------------
        // MUTATOR -  FUNCTION MEMBERS       :
        //------------------------------------
            // Inserts A New Node In
            // The Proper Location In The BST
            // Obeying the BST ordering property:
            void insert(  int key_val   );
        
        //------------------------------------
        // ACCESSOR - FUNCTION MEMBERS       :
        //------------------------------------
            // Printing With The
            // Preorder Algorithm:
            void preorder (  );
            
    
            // Printing With The
            // Inorder Algorithm:
            void inorder  (  );
    
    
            // Printing With The
            // Postorder Algorithm:
            void postorder(  );
    
    //----------------------------------------
    // Private Data Members (Variables)      :
    //----------------------------------------
    private:
        //------------------------------------
        // DATA MEMBERS                      :
        //------------------------------------
            // BST ( Doubly Linked List )
            // Node Prototype:
            struct binaryTreeNode
            {
                // DATA FIELD:
                dataType key;               // Parent Data Value

                
                // POINTER FIELDS:
                binaryTreeNode* left_child; // Data Is Less-than-or-equal-to
                                            // The Parent Value
                
                binaryTreeNode* right_child;// Data Is Greater-than-or-equal-to
                                            // The Parent Value
            };

        
            // BST ( Doubly Linked List )
            // Root Pointer:
            binaryTreeNode* root;


		//------------------------------------
		// HELPER - FUNCTION MEMBERS         :
		//------------------------------------
			//Preorder Helper Function:
			void preorder_helper(  binaryTreeNode* root_val  );

			//Inorder Helper Function:
			void inorder_helper(   binaryTreeNode* root_val  );

			//Postorder Helper Function:
			void postorder_helper( binaryTreeNode* root_val  );
};


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*           C L A S S    F U N C T I O N    D E F I N I T I O N S           */
/*																             */
/*                              S E C T I O N                                */		
/*---------------------------------------------------------------------------*/
template<class dataType >
binaryTreeType< dataType >::binaryTreeType( ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is The Default Constructor Function That Initializes The 
// Binary Search Trees Root Node.
//-----------------------------------------------------------------------------


    // Defualt BST Initialization:
    root = nullptr;
}


template<class dataType >
void binaryTreeType< dataType >::insert(   int key_val   )
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Inserts the new node in a proper location in the BST while obeying
// the BST ordering property.
//-----------------------------------------------------------------------------


    //---------------------------------------------------------------------
    // Variable Declaration                                               :
    //---------------------------------------------------------------------
    binaryTreeNode* newNode;
    binaryTreeNode* currentNode;
    bool          break_loop;

    //---------------------------------------------------------------------
    // Variable Initialization                                            :
    //---------------------------------------------------------------------
    // Create A New Node:
    newNode = new binaryTreeNode;
    newNode->key = key_val;
    newNode->left_child = nullptr;
    newNode->right_child = nullptr;


    //----------------------------------------------------------------------------------
    // BEGIN IF-ELSE STATEMENT --
    // Check If The Binary Search Tree (BST) Has Been Initialized.
    // IF NOT, Create The Root Node:
    if ( root == nullptr ){
                                    
        // Insert The New Node At The Top Of The BST (The Root):
        root    =    newNode;
    }
    else{ // ... IF The Root Node Has Been Created, Make The Descendant Nodes:


        // Set The Traversal Pointer To The Root Node:
        currentNode = root;
        // Set The While-Loop Flag:
        break_loop = false;

        //---------------------------------------------------------------
        // BEGIN  WHILE-LOOP --- "Begin Traveral, If A Root Node Exists":
        while ( break_loop == false ){


            // Checking if New Node Key Is Lesser Than The Current Node's Key:
            if (  (newNode -> key) < (currentNode -> key)  ){


                // Check If You Can Traverse To The Left Child:
                if ((currentNode->left_child) != nullptr) {
                    currentNode = (currentNode->left_child);
                }
                else { // ... Insert The New Node
                    currentNode->left_child = newNode;
                    break_loop = true;
                }

            }
            // Checking if New Node Key Is Greater Than The Current Node's Key:
            else if (  (newNode->key) > (currentNode->key)  ){


                // Check If You Can Traverse To The Right Child:
                if ((currentNode->right_child) != nullptr) {
                    currentNode = (currentNode->right_child);
                }
                else { // ... Insert The New Node
                    currentNode->right_child = newNode;
                    break_loop = true;
                }

            }
            else{ // ... If The New Nodes Key Is Equal To The
                  // Current Node's Key then:

                break_loop = true;
            }
        }
        // END  WHILE-LOOP --- "Begin Traveral, If A Root Node Exists"
        //---------------------------------------------------------------


        // Insert The New Node:
        currentNode = newNode;

    }
    // END IF-ELSE STATEMENT -- "Check If The Binary Search Tree (BST) Has Been . . . "
    //----------------------------------------------------------------------------------
}



template<class dataType >
void binaryTreeType< dataType >::preorder (  ) {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The BST Is Traversed and Printed Using
// The Recursive PreOrder Algorithm.
//-----------------------------------------------------------------------------


    //---------------------------------------------------------------------
    // Recursive Case                                                     :
    //---------------------------------------------------------------------
	preorder_helper(root);

}
template<class dataType >
void binaryTreeType< dataType >::preorder_helper(binaryTreeNode* root_val){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The is the Private Helper Function That Helps The Public Function, 
// " void binaryTreeType< dataType >::preorder (  ) ", 
// To Carry Out Its Task Of Outputting BST Node Data Values.
//-----------------------------------------------------------------------------

	// Traverse The Binary Tree And Print Values:
	if (root_val != nullptr) {
		cout << (root_val-> key ) << "  ";           // Parent Node
		preorder_helper(root_val-> left_child );    // Left   Node
		preorder_helper(root_val-> right_child );   // Right  Node
	}
}



template<class dataType >
void binaryTreeType< dataType >::inorder (  ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The BST Is Traversed and Printed Using
// The Recursive InOrder Algorithm.
//-----------------------------------------------------------------------------


    //---------------------------------------------------------------------
    // Recursive Case                                                     :
    //---------------------------------------------------------------------
	inorder_helper(root);

}
template<class dataType >
void binaryTreeType< dataType >::inorder_helper(binaryTreeNode* root_val){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The is the Private Helper Function That Helps The Public Function, 
// " void binaryTreeType< dataType >::inorder (  ) ", 
// To Carry Out Its Task Of Outputting BST Node Data Values.
//-----------------------------------------------------------------------------

	// Traverse The Binary Tree And Print Values:
    if (root_val != nullptr) {
		inorder_helper(root_val-> left_child  );    // Left   Node
        cout <<  (root_val-> key ) << "  ";         // Parent Node
		inorder_helper(root_val-> right_child );    // Right  Node
    }
}



template<class dataType >
void binaryTreeType< dataType >::postorder (  ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The BST Is Traversed and Printed Using
// The Recursive PostOrder Algorithm.
//-----------------------------------------------------------------------------


    //---------------------------------------------------------------------
    // Recursive Case                                                     :
    //---------------------------------------------------------------------
	postorder_helper(root);

}
template<class dataType >
void binaryTreeType< dataType >::postorder_helper(binaryTreeNode* root_val){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The is the Private Helper Function That Helps The Public Function, 
// " void binaryTreeType< dataType >::postorder (  ) ", 
// To Carry Out Its Task Of Outputting BST Node Data Values.
//-----------------------------------------------------------------------------

	// Traverse The Binary Tree And Print Values:
    if (root_val != nullptr) {
		postorder_helper(root_val-> left_child  );    // Left   Node
		postorder_helper(root_val-> right_child );    // Right  Node
        cout <<  (root_val-> key ) << "  ";			  // Parent Node
    }
}

#endif
