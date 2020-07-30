/** @file
 * @brief Implementation of binary search trees
 */
#ifndef LIBBST_BST_H
#define LIBBST_BST_H

#define

/** @cond */

typedef struct BstTree BstTree;
typedef struct BstNode BstNode;

typedef void (*bst_display_fn)(void *value);
typedef void (*bst_release_fn)(void *value);
typedef int (*bst_cmp_fn)(void *node_value, void *search_value);

/** @endcond */

/**
 * @brief Represents a binary search tree
 */
struct BstTree {
    BstNode *root; /**< Root node */
    bst_display_fn display_fn; /**< Function used to display nodes */
    bst_release_fn release_fn; /**< Function used to deallocate node values */
    bst_cmp_fn cmp_fn; /**< Function used to compare node values */
};

/**
 * @brief Represents a node in a binary search tree
 */
struct BstNode {
    void *value; /**< Value stored by node */
    BstNode *left_node; /**< Left child node */
    BstNode *right_node; /**< Right child node */
};

/**
 * @brief Create an empty binary search tree
 * @param display_fn Function for displaying a node's data.
 * @param release_fn Function for deallocating a node.
 * @param cmp_fn Function for comparing values of nodes. Used for indexing.
 * @return BstTree * structure with empty root.
 */
BstTree *bst_tree_create(bst_display_fn display_fn, bst_release_fn release_fn, bst_cmp_fn cmp_fn);

/**
 * @brief Insert value into a tree
 * @param tree Tree to insert value into.
 * @param value Value to insert.
 */
void bst_tree_insert_value(BstTree *tree, void *value);

/**
 * @brief Search for value in a tree
 * @param tree Tree to search value for.
 * @param value Value to be searched.
 * @return BstNode * if value was found. NULL otherwise.
 */
BstNode *bst_tree_search(BstTree *tree, void *value);

/**
 * @brief Deallocate tree from memory.
 * @param tree Tree to deallocate.
 */
void bst_tree_release(BstTree *tree);

/**
 * @brief Display tree nodes using pre-order algorithm.
 *
 * Values are displayed by calling the tree's display function.
 * @param tree Tree to display.
 */
void bst_tree_display_pre_order(BstTree *tree);

/**
 * @brief Display tree nodes using in-order algorithm
 * @param tree Tree to display.
 */
void bst_tree_display_in_order(BstTree *tree);

/**
 * @brief Display tree nodes using post-order algorithm
 * @param tree Tree to display.
 */
void bst_tree_display_post_order(BstTree *tree);

/** @cond */

BstNode *bst_subtree_insert(BstNode *root, void *value, bst_cmp_fn cmp_fn);

BstNode *bst_subtree_search(BstNode *root, void *value, bst_cmp_fn cmp_fn);

void bst_subtree_release(BstNode *root, bst_release_fn release_fn);

void bst_subtree_display_pre_order(BstNode *root, bst_display_fn display_fn);

void bst_subtree_display_in_order(BstNode *root, bst_display_fn display_fn);

void bst_subtree_display_post_order(BstNode *root, bst_display_fn display_fn);


BstNode *bst_node_create(void *value, BstNode *left_node, BstNode *right_node);

void bst_node_release(BstNode *node, bst_release_fn release_fn);

int bst_node_compare(BstNode *node, void *value, bst_cmp_fn cmp_fn);

void bst_node_release_value(BstNode *node, bst_release_fn release_fn);

void bst_node_display_value(BstNode *node, bst_display_fn display_fn);

/** @endcond */

#endif //LIBBST_BST_H
