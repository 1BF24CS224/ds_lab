#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void printTree(struct Node *root, int level, int indentSpace)
{
    if (root == NULL)
        return;

    for (int i = 0; i < level * indentSpace; i++)
        printf(" ");

    printf("%d\n", root->data);

    if (root->left != NULL)
    {
        for (int i = 0; i < level * indentSpace; i++)
            printf(" ");
        printf("/\n");
        printTree(root->left, level + 1, indentSpace);
    }

    if (root->right != NULL)
    {
        for (int i = 0; i < level * indentSpace; i++)
            printf(" ");
        printf("\\\n");
        printTree(root->right, level + 1, indentSpace);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    printf("\n-- Binary Search Tree Menu ---\n");
    printf("1. Insert into BST\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Display Tree\n");
    printf("6. Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("\nTree Structure:\n");
            printTree(root, 0, 5);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
