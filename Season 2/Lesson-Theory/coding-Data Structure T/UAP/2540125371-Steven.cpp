#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char dino[30];
    char dinoType[30];
    int dinoAge;
    int dinoWeight;
    char dinoSkill[30];
    int height;
    Node* left, *right;
};
Node* root = NULL;

int height(Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int max(int a, int b){
    if(b>a){
        return b;
    }
    return a;
}

Node* rotateKanan(Node* root){
    Node* x = root->left;
    Node* y = x->right;

    x->right = root;
    x->left = y;

    root->height=max(height(root->left), height(root->right)) +1;
    x->height=max(height(x->left), height(x->right)) +1;

    return x;
}

Node* rotateKiri(Node* root){
    Node* x = root->right;
    Node* y = x->left;

    x->left = root;
    x->right = y;

    root->height=max(height(root->left), height(root->right)) +1;
    x->height=max(height(x->left), height(x->right)) +1;

    return x;
}



Node* createNode( char dino[], char dinoType[], int dinoAge, int dinoWeight, char dinoSkill[]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->dino,dino);
    strcpy(newNode->dinoType,dinoType);
    newNode->dinoAge = dinoAge;
    newNode->dinoWeight = dinoWeight;
    strcpy(newNode->dinoSkill,dinoSkill);
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertion(Node* root,char dino[], char dinoType[], int dinoAge, int dinoWeight, char dinoSkill[]){
    if(root == NULL){
        return createNode(dino,dinoType,dinoAge,dinoWeight,dinoSkill);
    }

    if(strcmp(dino,root->dino)<0){
        root->left = insertion(root->left,dino,dinoType,dinoAge,dinoWeight,dinoSkill);
    }else{
        root->right = insertion(root->right,dino,dinoType,dinoAge,dinoWeight,dinoSkill);
    }

    root->height = max(height(root->left), height(root->right)) +1;

    int balance = height(root->left)-height(root->right);

    if(balance>1 && strcmp(dino,root->dino)<0){
        return rotateKanan(root);
    }
    else if (balance>1 && strcmp(dino,root->dino)>0){
        root->left = rotateKiri(root->left);
        return rotateKanan(root);
    }
    else if (balance<-1 && strcmp(dino,root->dino)>0){
        return rotateKiri(root);
    }
    else if (balance<-1 && strcmp(dino,root->dino)<0){
        root->right = rotateKanan(root->right);
        return rotateKiri(root);  
    }
    return root;
}

Node* pop(Node* root,char dino[]){
    if(root == NULL){
        return NULL;
    }

    if(strcmp(dino,root->dino)<0){
        root->left = pop(root->left,dino);
    }else if(strcmp(dino,root->dino)>0){
        root->right = pop(root->right,dino);
    }else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }else if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            *root = *temp;
            free(temp);
            temp=NULL;
        }else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            *root = *temp;
            free(temp);
            temp=NULL;
        }else if(root->left != NULL && root->right != NULL){
            Node* temp = root->left;

            while (root->right!=NULL)
            {
                temp = temp->right;
            }
            
            strcpy(root->dino,temp->dino);
            strcpy(root->dinoType,temp->dinoType);
            root->dinoAge=temp->dinoAge;
            root->dinoWeight=temp->dinoWeight;
            strcpy(root->dinoSkill,temp->dinoSkill);

            root->left = pop(root->left,root->dino);
        }
    }

    root->height = max(height(root->left), height(root->right)) +1;

    int balance = height(root->left)-height(root->right);

    if(balance>1 && strcmp(dino,root->dino)<0){
        return rotateKanan(root);
    }
    else if (balance>1 && strcmp(dino,root->dino)>0){
        root->left = rotateKiri(root->left);
        return rotateKanan(root);
    }
    else if (balance<-1 && strcmp(dino,root->dino)>0){
        return rotateKiri(root);
    }
    else if (balance<-1 && strcmp(dino,root->dino)<0){
        root->right = rotateKanan(root->right);
        return rotateKiri(root);  
    }
    return root;
}

void viewIn(Node* root){
    if(root!=NULL){
        viewIn(root->left);
        printf("|%s|%s|%d|%d|%s|\n",root->dino,root->dinoType,root->dinoAge,root->dinoWeight,root->dinoSkill);
        viewIn(root->right);
    }
}

void viewPre(Node* root){
    if(root!=NULL){
        printf("|%s|%s|%d|%d|%s|\n",root->dino,root->dinoType,root->dinoAge,root->dinoWeight,root->dinoSkill);
        viewPre(root->left);
        viewPre(root->right);
    }
}

void viewPost(Node* root){
    if(root!=NULL){
        viewPost(root->left);
        viewPost(root->right);
        printf("|%s|%s|%d|%d|%s|\n",root->dino,root->dinoType,root->dinoAge,root->dinoWeight,root->dinoSkill);
    }
}

Node* deleteAll(Node* root){
    if(root!=NULL){
        deleteAll(root->left);
        deleteAll(root->right);
        root->left = root->right = NULL;
        free(root);
        root=NULL;
    }
    return root;
}

Node* findDino(Node* root,char dino[]){
    if(root == NULL){
        return NULL;
    }
    if(strcmp(dino,root->dino)==0){
        return root;
    }
    if(strcmp(dino,root->dino)<0){
        findDino(root->left,dino);
    }else{
        findDino(root->right,dino);
    }
}

bool validateDinoName(char dino[]){
    int len = strlen(dino);
    int wordCount = 0;
    if(len<10 || len>30){
        printf("must be between 10 and 30 characters\n");
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if(dino[i] == ' '){
            wordCount++;
        }
    }
    if(wordCount<2){
        printf("must consists of 3 words minimum\n");
        return false;
    }
    if((dino[0]!='S' && dino[0]!='u' && dino[0]!='p' && dino[0]!='e' && dino[0]!='r')||(dino[0]!='H' && dino[0]!='y' && dino[0]!='p' && dino[0]!='e' && dino[0]!='r')){
        return false;
    }
    return (true);
}

int main(){

    root = insertion(root,"dino","darat",10,20,"nyeker");

    int menu = -1;
    char scandino[30];
    char scandinoType[30];
    int scandinoAge;
    int scandinoWeight;
    char scandinoSkill[30];
    char viewType[30];

    do
    {
        do
        {
            puts("");
            puts("Jurassic Jungle");
            puts("1. See Dinosaur");
            puts("2. Add Dinosaur");
            puts("3. Remove Dinosaur");
            puts("4. Exit");
            puts(">>");
            scanf("%d",&menu);getchar();
        } while (menu < 1 || menu > 4);
        switch (menu)
        {
        case 1:
            if(root == NULL){
                printf("There's no dinosaur here!\n");
                printf("Press enter to back...\n");
                getchar();
            }else{
                printf("Choose see order [Pre | In | Post].\n");
                scanf("%s",viewType); getchar();
                if(strcmp(viewType,"Pre")==0){
                    printf("|Dinosaur Name|Dinosaur Type|Dinosaur Age|Dinosaur Weight|Dinosaur Skill|\n");
                    viewPre(root);
                }else if(strcmp(viewType,"In")==0){
                    printf("|Dinosaur Name|Dinosaur Type|Dinosaur Age|Dinosaur Weight|Dinosaur Skill|\n");
                    viewIn(root);
                }else if(strcmp(viewType,"Post")==0){
                    printf("|Dinosaur Name|Dinosaur Type|Dinosaur Age|Dinosaur Weight|Dinosaur Skill|\n");
                    viewPost(root);
                }
            }
            break;
        case 2:
            do
            {
                printf("Input Dinosaur name [10..30 characters]");
                scanf("%[\n]",scandino);getchar();
            } while (validateDinoName==false||findDino(root,scandino)!=NULL);
            do
            {
                printf("Input Dinosaur type [Carnivore | Herbivore | Omnivore]\n");
                scanf("%[\n]",scandinoType);getchar();
            } while (strcmpi(scandinoType,"Carnivore")!=0 && strcmpi(scandinoType,"Herbivore")!=0 && strcmpi(scandinoType,"Omnivore")!=0);
            do
            {
                printf("Input Dinosaur age [must be greater than 1000]\n");
                scanf("%d",scandinoAge);getchar();
            } while (scandinoAge<1000);
            do
            {
                printf("Input Dinosaur weight [must be greater than 10000]\n");
                scanf("%d",scandinoWeight);getchar();
            } while (scandinoWeight<10000);
            do
            {
                printf("Input Dinosaur Skill [Onw Word, Capital]\n");
                scanf("%s",scandinoSkill);getchar();
            } while (scandinoSkill[0] <= 'A' || scandinoSkill[0] >= 'Z');
            break;
        case 3:
            if(root == NULL){
                printf("There's no dinosaur here!\n");
                printf("Press enter to back...\n");
                getchar();
            }else{
                viewIn(root);
                puts("");
                printf("Input Dinosaur name [10..30 characters]");
                scanf("%[\n]",scandino);getchar();
                Node* toRemove = findDino(root,scandino);
                if(findDino(root,scandino)==NULL){
                    printf("Input dino to be find : %s\n",scandino);
                    printf("We can't find dino with %s name\n",scandino);
                }else{
                    printf("Input dino to be find : %s\n",toRemove->dino);
                    root = pop(root,scandino);
                    printf("Remove Successfull");
                }
            }
            break;
        case 4:
            root=deleteAll(root);
            break;
        }
    } while (menu != 4);
    





    return 0;
}