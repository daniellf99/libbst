#include <stdlib.h>
#include "bst.h"

void bst_node_release_value(BstNode *node, bst_release_fn release_fn);
void bst_node_display_value(BstNode *node, bst_display_fn display_fn);

BstTree *bst_tree_create(bst_display_fn display_fn, bst_release_fn release_fn, bst_cmp_fn cmp_fn) {

    BstTree *new_tree = (BstTree *) malloc(sizeof(BstTree));

    new_tree->display_fn = display_fn;
    new_tree->release_fn = release_fn;
    new_tree->cmp_fn = cmp_fn;

    return new_tree;

}

void bst_tree_insert_value(BstTree *tree, void *value) {

    if (tree->root == NULL) {
        tree->root = bst_node_create(value, NULL, NULL);
    } else {
        bst_subtree_insert(tree->root, value, tree->cmp_fn);
    }

}

BstNode *bst_tree_search(BstTree *tree, void *value) {

    if (tree == NULL) {
        return NULL;
    }

    return bst_subtree_search(tree->root, value, tree->cmp_fn);

}

BstNode *bst_subtree_insert(BstNode *root, void *value, bst_cmp_fn cmp_fn) {

    // assert value != NULL

    if (root == NULL) {
        BstNode *new_node = bst_node_create(value, NULL, NULL);

        return new_node;
    }

    int cmp_value = bst_node_compare(root, value, cmp_fn);

    if (cmp_value > 0) {
        root->right_node = bst_subtree_insert(root->right_node, value, cmp_fn);
    } else if (cmp_value < 0) {
        root->left_node = bst_subtree_insert(root->left_node, value, cmp_fn);
    }
}

BstNode *bst_subtree_search(BstNode *root, void *value, bst_cmp_fn cmp_fn) {

    if (root == NULL) {
        return NULL;
    }

    int cmp_value = bst_node_compare(root, value, cmp_fn);

    if (cmp_value == 0) {
        return root;
    } else if (cmp_value > 0 && root->right_node != NULL) {
        return bst_subtree_search(root->right_node, value, cmp_fn);
    } else if (cmp_value < 0 && root->left_node != NULL) {
        return bst_subtree_search(root->left_node, value, cmp_fn);
    } else {
        return NULL;
    }

}

void bst_tree_release(BstTree *tree) {

    bst_subtree_release(tree->root, tree->release_fn);
    free(tree);

}

void bst_subtree_release(BstNode *root, bst_release_fn release_fn) {

    if (root->left_node != NULL) {
        bst_subtree_release(root->left_node, release_fn);
    }

    if (root->right_node != NULL) {
        bst_subtree_release(root->right_node, release_fn);
    }

    bst_node_release(root, release_fn);

}

BstNode *bst_node_create(void *value, BstNode *left_node, BstNode *right_node) {

    BstNode *new_node = (BstNode *) malloc(sizeof(BstNode));

    new_node->value = value;
    new_node->left_node = left_node;
    new_node->right_node = right_node;

    return new_node;

}

void bst_node_release(BstNode *node, bst_release_fn release_fn) {

    bst_node_release_value(node, release_fn);
    free(node);

}

int bst_node_compare(BstNode *node, void *value, bst_cmp_fn cmp_fn) {

    return cmp_fn(node->value, value);

}

void bst_node_release_value(BstNode *node, bst_release_fn release_fn) {

    if (release_fn != NULL) {
        release_fn(node->value);
    }

}

void bst_node_display_value(BstNode *node, bst_display_fn display_fn) {

    if (display_fn != NULL) {
        display_fn(node->value);
    }

}

void bst_tree_display(BstTree *tree, int display_mode) {
    switch (display_mode) {
        case BST_DISPLAY_PRE_ORDER:
            bst_subtree_display_pre_order(tree->root, tree->display_fn);
            break;
        case BST_DISPLAY_IN_ORDER:
            bst_subtree_display_in_order(tree->root, tree->display_fn);
            break;
        case BST_DISPLAY_POST_ORDER:
            bst_subtree_display_post_order(tree->root, tree->display_fn);
            break;
    }
}

void bst_subtree_display_pre_order(BstNode *root, bst_display_fn display_fn) {
    if (root != NULL) {
        display_fn(root->value);
        if (root->left_node != NULL) {
            bst_subtree_display_pre_order(root, display_fn);
        }
        if (root->right_node != NULL) {
            bst_subtree_display_pre_order(root, display_fn);
        }
    }
}

void bst_subtree_display_in_order(BstNode *root, bst_display_fn display_fn) {
    if (root != NULL) {
        if (root->left_node != NULL) {
            bst_subtree_display_in_order(root, display_fn);
        }
        display_fn(root->value);
        if (root->right_node != NULL) {
            bst_subtree_display_in_order(root, display_fn);
        }
    }
}

void bst_subtree_display_post_order(BstNode *root, bst_display_fn display_fn) {
    if (root != NULL) {
        if (root->left_node != NULL) {
            bst_subtree_display_post_order(root, display_fn);
        }
        if (root->right_node != NULL) {
            bst_subtree_display_post_order(root, display_fn);
        }
        display_fn(root->value);
    }
}
