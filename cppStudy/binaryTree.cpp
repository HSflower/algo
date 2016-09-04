/*
 * binaryTree.cpp
 *
 *  Created on: 2016. 8. 30.
 *      Author: hanseul
 */

#include <iostream>
using namespace std;

//First, it is necessary to have a struct, or class, defined as a node.
/*
 * The struct has the ability to store the key_value and contains the two child nodes
 * which define the node as part of a tree.
 * In fact, the node itself is very similar to the node in a linked list.
 * A basic knowledge of the code  for a linked list will  be very  helpful in understanding
 * Essentially, pointers are necessary to allow the arbitrary creation of new nodes in the tree.
 * It is most logical to create a binary tree class to encapsulate the workings of the tree into a single area,
 *  and also making it reusable.
 *  The class will contain functions to insert data into the tree and to search for data.
 *  Due to the use of pointers, it will be necessary to include a function to delete the tree
 *  in order to conserve memory after the program has finished.
 */
struct treeNode {
	int key_value;
	treeNode *left;
	treeNode *right;
};
class btree
{
	treeNode *root;
	btree();
	~btree();
	void destroy_tree(treeNode *leaf);
	void insert(int key, treeNode *leaf);
	treeNode *search(int key, treeNode *leaf);
public:
	void insert(int key);
	treeNode *search(int key);
	void destroy_tree();
};

//It is necessary to initialize root to NULL for the later functions to be able to recognize that it does not exist.
btree::btree()
{
	root=NULL;
}

//The destroy_tree function will set off the recursive function destroy_tree shown below which will actually delete all nodes of the tree.
btree::~btree()
{
	destroy_tree();
}
/*
 * The function destroy_tree goes to the bottom of each part of the tree,
 * that is, searching while there is a  non-null node, deletes that leaf,
 * and then it works its way back up. The function deletes the leftmost node,
 * then the right child node from the leftmost node's parent node, then it deletes the parent node,
 * then works its  way back to  deleting the other child node  of the  parent of the node  it just deleted,
 * and it continues this deletion working its way up to the node of the tree upon which delete_tree was originally called.
 * In the example tree above, the order of deletion of nodes would be 5 8 6 11 18 14 10.
 * Note that it is necessary to delete all the child nodes to avoid wasting memory.
 */
void destroy_tree(treeNode *leaf)
{
	if(leaf!=NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}
void btree::insert(int key, treeNode *leaf)
{
	if(key< leaf->key_value)
	{
		if(leaf->left!=NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left=new treeNode;
			leaf->left->key_value=key;
			leaf->left->left=NULL;    //Sets the left child of the child node to null
			leaf->left->right=NULL;   //Sets the right child of the child node to null
		}
	}
	else if(key>=leaf->key_value)
	{
		if(leaf->right!=NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right=new treeNode;
			leaf->right->key_value=key;
			leaf->right->left=NULL;  //Sets the left child of the child node to null
			leaf->right->right=NULL; //Sets the right child of the child node to null
		}
	}
}
/*
 * The search function shown above recursively moves down the tree until it
 * either reaches a node with a key value equal to the value for which the function is searching or
 * until the function reaches an uninitialized node,
 * meaning that the value being searched for is not stored in the binary tree.
 * It returns a pointer to the node to the previous instance of the function
 * which called it, handing the pointer back up to the search function accessible outside the class.
 */
treeNode *btree::search(int key, treeNode *leaf)
{
	if(leaf!=NULL)
	{
		if(key==leaf->key_value)
			return leaf;
		if(key<leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}
/*
 * The public version of the insert function takes care of the case
 *  where the root has not been initialized by allocating the memory for it
 *  and setting both child nodes to NULL and setting the key_value to the value to be inserted.
 * If the root node already exists,
 *  insert is called with the root node as the initial node of the function,
 *  and the recursive insert function takes over.
 */
void btree::insert(int key)
{
  if(root!=NULL)
insert(key, root);
  else
  {
	  root=new treeNode;
	  root->key_value=key;
	  root->left=NULL;
	  root->right=NULL;
  }
}
//The public version of the search function is used to set off the search recursion at the root node,
// keeping it from being necessary for the user to have access to the root node.
treeNode *btree::search(int key)
{
  return search(key, root);
}
//The  public version  of  the  destroy  tree function
//is  merely  used to  initialize  the  recursive  destroy_tree function
//which then deletes all the nodes of the tree.
void btree::destroy_tree()
{
  destroy_tree(root);
}

