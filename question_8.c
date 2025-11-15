// PROGRAM TO IMPLEMENT OPERATIONS ON BINARY SEARCH TREE (BST)
// WRITTEN BY:  MANISH KUMAR

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Function to search a value in BST
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Find the minimum node (used in deletion)
struct node *findMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Traversal functions
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    struct node *temp;
    int choice, value;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. INSERT\n");
        printf("2. SEARCH\n");
        printf("3. DELETE\n");
        printf("4. INORDER TRAVERSAL\n");
        printf("5. PREORDER TRAVERSAL\n");
        printf("6. POSTORDER TRAVERSAL\n");
        printf("7. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("ENTER VALUE TO INSERT: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("ENTER VALUE TO SEARCH: ");
            scanf("%d", &value);
            temp = search(root, value);
            if (temp != NULL)
                printf("VALUE %d FOUND IN TREE\n", value);
            else
                printf("VALUE %d NOT FOUND\n", value);
            break;

        case 3:
            printf("ENTER VALUE TO DELETE: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("NODE DELETED (IF FOUND)\n");
            break;

        case 4:
            printf("INORDER TRAVERSAL: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("PREORDER TRAVERSAL: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("POSTORDER TRAVERSAL: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("EXITING PROGRAM.\n");
            break;

        default:
            printf("INVALID CHOICE! TRY AGAIN.\n");
        }
    }

    while (choice != 7);

    return 0;
}
