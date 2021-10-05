#include <stdgl.h>

// STRUTTURA DI UNA ALBERO
typedef struct Node{
    struct Node* left;
    struct Node* right;
    int* data;  // si scrive anche: void* data;
    int key;  // numero univoco
}node;


node* find_by_key(node *tree, int key);
void in_order_view(node* tree);
void insert(node **tree, node* new);

int main(){

    bool condizione = true;
    int menu;

    int key = 0;

    node *root = (node*)malloc(sizeof(node));
    node *nodo = NULL;

    while(condizione){
        menu = scanfInt("MENÙ:\n\n- digita '1' per inserire elementi\n- digita '2' per stamapre albero\n- digita '3' per uscire dal programma\n\n Inserire numero: ");
        switch (menu)
        {
        case 1:
            key = scanfInt("Inserire la key: ");
            nodo = (node*)malloc(sizeof(node));
            nodo->key = key;
            insert(&root, nodo);
            break;
        case 2:
            in_order_view(root);
            break;
        case 3:
            condizione=false;
            printf("\nuscita\n");
            break;
        default:
            printf("\nerrore\n");
            break;
        }
    }




    return 0;
}





// RICERCA
node* find_by_key(node *tree, int key){
    if (tree == NULL)
        return NULL;
    else{
        if (key < tree->key)
            return find_by_key(tree->left, key);
        else if (key > tree->key) 
            return find_by_key(tree->right, key);
        else
            return tree;

    }
}


// VISTA
void in_order_view(node* tree) {
    if (tree !=NULL) {
        in_order_view(tree->left);
        printf("Key %d, value %d\n", tree->key, tree->data);
        in_order_view(tree->right);
    }

}


// INSERIMENTO
void insert(node **tree, node* new){
    if (*tree == NULL) {
        *tree = new;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }else{
        if (new->key < (*tree)->key) 
            insert(&(*tree)->left, new);
        else if (new->key > (*tree)->key)
            insert (&(*tree)->right, new);
        else
            printf("Chiave duplicata\n");
    }

}


