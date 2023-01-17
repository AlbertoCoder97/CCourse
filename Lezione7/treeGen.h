typedef struct node {
    char *key;
    struct node *left;
    struct node *right;
} NODE;

int insert(NODE **binary_tree, char *value);
int delete_tree(NODE *binary_tree);
void display_preorder(NODE *binary_tree);
void display_inorder(NODE *binary_tree);
void display_postorder(NODE *binary_tree);