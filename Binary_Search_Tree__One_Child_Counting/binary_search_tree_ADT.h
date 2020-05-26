/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           binary_search_tree_ADT.h
//  Program:            Binary Trees: A Binary Search Tree -One Child Counting
//  Title:              Binary Search Tree Class Definition And Functions
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
            void preorderTraversal (  );
            
    
            // Printing With The
            // Inorder Algorithm:
            void inorderTraversal  (  );
    
    
            // Printing With The
            // Postorder Algorithm:
            void postorderTraversal(  );

			int singleParent(  );
    
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

                
                // POINTER FIELDS:preorderTraversal
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
			void preorderTraversal_helper(  binaryTreeNode* root_val  );

			//Inorder Helper Function:
			void inorderTraversal_helper(   binaryTreeNode* root_val  );

			//Postorder Helper Function:
			void postorderTraversal_helper( binaryTreeNode* root_val  );

			//SingleParent Helper Function:
			int singleParent_helper(binaryTreeNode* root_val);
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
void binaryTreeType< dataType >::preorderTraversal (  ) {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The BST Is Traversed and Printed Using
// The Recursive PreOrder Algorithm.
//-----------------------------------------------------------------------------


    //---------------------------------------------------------------------
    // Recursive Case                                                     :
    //---------------------------------------------------------------------
	preorderTraversal_helper(root);

}
template<class dataType >
void binaryTreeType< dataType >::preorderTraversal_helper(binaryTreeNode* root_val){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The is the Private Helper Function That Helps The Public Function, 
// " void binaryTreeType< dataType >::preorderTraversal (  ) ", 
// To Carry Out Its Task Of Outputting BST Node Data Values.
//-----------------------------------------------------------------------------

	// Traverse The Binary Tree And Print Values:
	if (root_val != nullptr) {
		cout << (root_val-> key ) << "  ";           // Parent Node
		preorderTraversal_helper(root_val-> left_child );    // Left   Node
		preorderTraversal_helper(root_val-> right_child );   // Right  Node
	}
}



template<class dataType >
void binaryTreeType< dataType >::inorderTraversal (  ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The BST Is Traversed and Printed Using
// The Recursive InOrder Algorithm.
//-----------------------------------------------------------------------------


    //---------------------------------------------------------------------
    // Recursive Case                                                     :
    //---------------------------------------------------------------------
	inorderTraversal_helper(root);

}
template<class dataType >
void binaryTreeType< dataType >::inorderTraversal_helper(binaryTreeNode* root_val){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The is the Private Helper Function That Helps The Public Function, 
// " void binaryTreeType< dataType >::inorderTraversal (  ) ", 
// To Carry Out Its Task Of Outputting BST Node Data Values.
//-----------------------------------------------------------------------------

	// Traverse The Binary Tree And Print Values:
    if (root_val != nullptr) {
		inorderTraversal_helper(root_val-> left_child  );    // Left   Node
        cout <<  (root_val-> key ) << "  ";         // Parent Node
		inorderTraversal_helper(root_val-> right_child );    // Right  Node
    }
}



template<class dataType >
void binaryTreeType< dataType >::postorderTraversal(  ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The BST Is Traversed and Printed Using
// The Recursive PostOrder Algorithm.
//-----------------------------------------------------------------------------


    //---------------------------------------------------------------------
    // Recursive Case                                                     :
    //---------------------------------------------------------------------
	postorderTraversal_helper(root);

}
template<class dataType >
void binaryTreeType< dataType >::postorderTraversal_helper(binaryTreeNode* root_val){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// The is the Private Helper Function That Helps The Public Function, 
// " void binaryTreeType< dataType >::postorderTraversal (  ) ", 
// To Carry Out Its Task Of Outputting BST Node Data Values.
//-----------------------------------------------------------------------------

	// Traverse The Binary Tree And Print Values:
    if (root_val != nullptr) {
		postorderTraversal_helper(root_val-> left_child  );    // Left   Node
		postorderTraversal_helper(root_val-> right_child );    // Right  Node
        cout <<  (root_val-> key ) << "  ";			  // Parent Node
    }
}



template<class dataType >
int binaryTreeType< dataType >::singleParent(   ) {
	//-----------------------------------------------------------------------------
	// Function Description                                                       :
	//-----------------------------------------------------------------------------
	// The Function Returns The Number Of Nodes In A Binary Tree That Have Only 
	// One Child
	//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Recursive Case And Return Value                                    :
	//---------------------------------------------------------------------
	// Once The Recursive Step Is Done It Returns The Count Of Nodes With
	// One Child:
	return singleParent_helper(root);
}
template<class dataType >
int binaryTreeType< dataType >::singleParent_helper(binaryTreeNode* root_val) {
	//-----------------------------------------------------------------------------
	// Function Description                                                       :
	//-----------------------------------------------------------------------------
	// The is the Private Helper Function That Helps The Public Function, 
	// " int binaryTreeType< dataType >::singleParent(  ) ", 
	// To Carry Out Its Task Of Outputting The Number Of BST Nodes With One Child.
	//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Check For An Available Binary Search Tree                          :
	//---------------------------------------------------------------------
	if (root_val == NULL) {
		// No Nodes Are Available:
		return 0;
	}
	// Traverse The Binary Tree:
	else if ((root_val->left_child) != nullptr &&
		(root_val->right_child) == nullptr) {

		// Account For The Parent Node With One Child -
		// If only a left child exists:
		return (singleParent_helper(root_val->left_child) + 1);
	}
	else if ((root_val->left_child) == nullptr &&
		(root_val->right_child) != nullptr) {

		// Account For The Parent Node With One Child -
		// If only a right child exists:
		return (singleParent_helper(root_val->right_child) + 1);
	}
	else {
		// No Chnages are applied  -
		// The Parent has a left and right child:
		return singleParent_helper(root_val->left_child) + singleParent_helper(root_val->right_child);
	}

}

#endif
