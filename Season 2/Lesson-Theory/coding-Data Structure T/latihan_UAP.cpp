#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool emailValidation(char email[]){
    int len = strlen(email);
    if(email[0] == '@' || email[0] == '.'){
        puts("email starts with @ atau .");
        return false;
    }

    // if email ends with @ atau .
    if(email[len-1] == '@'|| email[len-1] == '.'){
        puts("email ends with @ atau .");
        return false;
    }

    //ends with .com
    if(email[len-4] != '.' && email[len-3] != 'c' && email[len-2] != 'o' && email[len-1] != 'm'){
        puts("not ends with .com");
        return false;
    }

    //must exactly contain only 1 @ and
    int atCount = 0;
    int atIdx = 0;
    for (int i = 0; i < len; i++)
    {
        if(email[i] == '@'){
            atIdx = i;
            atCount++;
            //.must not be next to @
            if(email[i-1] == '.' || email[i+1] == '.'){
                puts(". next to @");
                return false;
            }
        }
    }
    if (atCount!=1){
        puts("@ is != 1");
        return false; 
    }

    for (int i = 0; i < len; i++)
    {
        bool lowerLetter = email[i] >= 'a' && email[i] <= 'z';
        bool upperLetter = email[i] >= 'A' && email[i] <= 'Z';
        bool numeric = email[i] >= '0' && email[i] <= '9';
        bool isAt = email[i] == '@';
        bool isDot = email[i] == '.';
        bool notUniqueChar = lowerLetter || upperLetter || numeric || isDot || isAt;
        if(notUniqueChar == false){
            puts("Unique Char");
            return false;
        }
    }
    return (true);
}




struct Node
{
    char title[30];
    char genre[30];
    char email[30];
    int stock;
    int height;
    Node* left,* right;
};
Node* root = NULL;

int height(Node* node){
    if(node== NULL) return 0;
    return node->height;
}

int max(int a,int b){
    if (b>a) return b;
    return a;
}


Node* createNode(char title[], char genre[], char email[],int stock){
    Node* newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->title,title);
    strcpy(newNode->genre,genre);
    strcpy(newNode->email,email);
    newNode->stock = stock;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* root){
    //1, tampung semua node yang kita perlukan
    Node* x = root->left;
    Node* y = x->right;

    //2. rotasi
    x->right = root;
    root->left = y;

    //3. itung height
    root->height = max(height(root->left),height(root->right))+1;
    x->height = max(height(x->left),height(x->right))+1;

    //4. return penggantinya
    return x;
}

Node* leftRotate(Node* root){
    //1, tampung semua node yang kita perlukan
    Node* x = root->right;
    Node* y = x->left;

    //2. rotasi
    x->left = root;
    root->right = y;

    //3. itung height
    root->height = max(height(root->left),height(root->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    
    //4. return penggantinya
    return x;
}


Node* insertion(Node* root,char title[], char genre[], char email[],int stock){
    //1. cek apakah root =  NULL atau gak
    if(root == NULL)return createNode(title,genre,email,stock);


    //2. kalau ada  isinya atau gak NULL
    if(strcmp(title,root->title)<0)
        root->left=insertion(root->left,title,genre,email,stock);
    else
        root->right=insertion(root->right,title,genre,email,stock);


    //3. itung height -> rumus = max(height anak kiri + height anak kanan) + 1
    root->height = max(height(root->left),height(root->right))+1;


    //4. itung balance = rumus = height anak kiri - height anak kanan
    int balance = height(root->left)-height(root->right);


    //balance hanya boleh -1,0,1, selain dari itu harus dirtotasi karena tree tidak balance
    //5. berdasarkan balance akan melakukan rotasi berdasarkan kondisi berikut:
    //Left left case
    if(balance > 1 && strcmp(title,root->left->title) < 0){
        //right rotate
        return rightRotate(root);
    }
    //Left right case
    if(balance > 1 && strcmp(title,root->left->title) > 0){
        //left rotate
        root->left= leftRotate(root->left);
        //right rotate
        return rightRotate(root);
    }
    //Right right case
    if(balance < -1 && strcmp(title,root->right->title) > 0){
        // left rotate
        return leftRotate(root);
    }
    //Right left case
    if(balance < -1 && strcmp(title,root->right->title) < 0){
        //right rotate
        root->right = rightRotate(root->right);
        //left rotate
        return leftRotate(root);
    }

    //6. return root
    return root;
}

Node* deletion(Node* root,char title[]){ 
    //kalau misal dia udah sampe ujung & gak ketemuyang dicari
    if(root == NULL)return NULL;
    //kalau misal root ada isinya , cek kondisi ini:
    //kalau misal key lebih kecil, jalan ke kiri
    if(strcmp(title,root->title) < 0) root->left = deletion(root->left,title);
    //kalau misal key lebih besar, jalan ke kanan
    else if(strcmp(title,root->title) > 0) root->right = deletion(root->right,title);
    //kalau misal key sama/ ketemu
    else{
        //kalau misal ga punya anak
        if(root->left == NULL && root->right == NULL){
            free(root);
            root=NULL; 
        }

        //kalau misal punya anak kiri doang, tapi kanan kosong  
        else if(root->left != NULL && root->right == NULL){
            //1. tampung anak kiri dia
            Node* temp = root->left;
            //2. semua atribut yang dimilikiki *root diganti *temp punya
            // termasuk pointer left & right dan semua value yang dimiliki * temp
            *root = *temp;
            //3. hapus si * temp (krn punya semua atribut yang sama)
            free(temp);
            temp = NULL;
        }

        //kalau misal punya anak kanan doang, tapi kiri kosong  
        else if(root->left == NULL && root->right != NULL){
            //1. tampung anak kanan dia
            Node* temp = root->right;
            //2. semua atribut yang dimilikiki *root diganti *temp punya
            // termasuk pointer left & right dan semua value yang dimiliki * temp
            *root = *temp;
            //3. hapus si * temp (krn punya semua atribut yang sama)
            free(temp);
            temp = NULL;
        }

        //kalau keduanya kosong
        else if(root->left != NULL && root->right != NULL){
            //goal = dapetin pengganti yang keynya paling deket dari node yang mau dihapus
            //tapi lebih kecil
            //1. arahin ke sebelah kiri
            Node* temp = root->left;
            //2. dari sanan jalan terus mentokkin ke kenan bawah
            while (temp->right!=NULL)
            {
                temp = temp->right;
            }
            //3.copy value si pengganti ke tempat node yang mau dihapus
            strcpy(root->title,temp->title);
            strcpy(root->genre,temp->genre);
            strcpy(root->email,temp->email);
            root->stock = temp->stock;
            //4. tinggal kita delete yg di bawah
            root->left = deletion(root->left,root->title);
        }
    }
    //Validasi apakah root == NULL
    if(root == NULL)return NULL;

    //3. itung height -> rumus = max(height anak kiri + height anak kanan) + 1
    root->height = max(height(root->left),height(root->right))+1;


    //4. itung balance = rumus = height anak kiri - height anak kanan
    int balance = height(root->left)-height(root->right);


    //balance hanya boleh -1,0,1, selain dari itu harus dirtotasi karena tree tidak balance
    //5. berdasarkan balance akan melakukan rotasi berdasarkan kondisi berikut:
    //Left left case
    if(balance>1 && strcmp(title,root->left->title) < 0){
        //right rotate
        return rightRotate(root);
    }
    //Left right case
    if(balance>1 && strcmp(title,root->left->title) > 0){
        //left rotate
        root->left= leftRotate(root->left);
        //right rotate
        return rightRotate(root);
    }
    //Right right case
    if(balance<-1 && strcmp(title,root->right->title) > 0){
        // left rotate
        return leftRotate(root);
    }
    //Right left case
    if(balance<-1 && strcmp(title,root->right->title) < 0){
        //right rotate
        root->right = rightRotate(root->right);
        //left rotate
        return leftRotate(root);
    }

    //6. return root
    return root;
}

Node* deleteAll(Node* root){
    if(root != NULL){
        deleteAll(root->left);
        deleteAll(root->right);
        root->right = root->left = NULL;
        free(root);
        root = NULL;
    }
    return root;
}

void viewInOrder(Node* root){
    if(root != NULL){
        viewInOrder(root->left);
        printf("|%-25s|%-15s|%-15s|%-10d| \n",root->title,root->genre,root->email,root->stock);
        viewInOrder(root->right);
    }
}

void viewPreOrder(Node* root){
    if(root != NULL){
        printf("|%-25s|%-15s|%-15s|%-10d| \n",root->title,root->genre,root->email,root->stock);
        viewPreOrder(root->left);
        viewPreOrder(root->right);
    }
}

void viewPostOrder(Node* root){
    if(root != NULL){
        viewPostOrder(root->left);
        viewPostOrder(root->right);
        printf("|%-25s|%-15s|%-15s|%-10d| \n",root->title,root->genre,root->email,root->stock);
    }
}

Node* findNode (Node* root, char title[]){
    if(root == NULL) return NULL;
    if(strcmp(title,root->title )== 0) return root;
    if(strcmp(title,root->title) < 0) findNode(root->left,title);
    else findNode(root->right, title);
}



int main (){
    // root = insertion(root, "tes satu", "genre satu", "email", 50);
    // root = insertion(root, "tes 2", "genre 2", "email", 50);
    // root = insertion(root, "tes 3", "genre 3", "email", 500);

    // viewInOrder(root);

    int menu = -1;
    char temptitle[30];
    char tempgenre[30];
    char tempemail[30];
    int  tempstock;
    do
    {
        do
        {
            puts("");
            puts("GAME SHOP");
            puts("1. Insert Game");
            puts("2. View Game");
            puts("3. Update Stock");
            puts("4. Exit");
            printf(">> ");
            scanf("%d", &menu); getchar();
        } while (menu < 1 || menu > 4); 
        puts("");
        switch (menu)
        {
        case 1:
            do
            {
               printf("Input game title[5-25 chars] [unique]: ");
               scanf("%[\n]", temptitle); getchar();
            } while (findNode(root, temptitle)!=NULL || strlen(temptitle)<5 || strlen(temptitle)>25);
            do
            {
                printf("input game genre[Action | RPG | Adventure | Card Game]: ");
                scanf("%[\n]", tempgenre); getchar();
            } while (strcmp(tempgenre,"Action")!=0 && strcmp(tempgenre,"RPG")!=0 && strcmp(tempgenre,"Adventure")!=0 && strcmp(tempgenre,"Card Game")!=0);
            do
            {
                printf("Input email: ");
                scanf("%[\n]", tempemail); getchar();
            } while (emailValidation(tempemail)==false);
            do
            {
                printf("Input game stock [at least 1]: ");
                scanf("%d", tempstock); getchar();
            } while (tempstock <1);
            root=insertion(root,temptitle,tempgenre,tempemail,tempstock);
            puts("Insert success");
            puts("");
            break;
        case 2:
            viewInOrder(root);
            break;
        case 3:
            printf("input Game title: ");
            scanf("%[\n]", temptitle); getchar();
            Node* toUpdate = findNode(root,temptitle);
            if(toUpdate == NULL){
                puts("Game not found.");
            }else{
                char temptype[30];
                printf("Game title: %s \n",toUpdate->title);
                printf("Game title: %s \n",toUpdate->genre);
                printf("Game title: %s \n",toUpdate->email);
                printf("Game title: %d \n",toUpdate->stock);
                do
                {
                    printf("input update type: ");
                    scanf("%s", temptype); getchar();
                } while (strcmpi(temptype, "add")!=0 && strcmpi(temptype, "remove") != 0);
                do
                {
                    if(strcmpi(temptype, "add")==0){
                        printf("Input qty to add: ");
                    }else{
                        printf("Input qty to remove: ");
                    }
                    scanf("%d", &tempstock); getchar();
                    if(strcmpi(temptype, "add")==0){
                        toUpdate->stock+=tempstock;
                        break;
                    }
                    if(strcmpi(temptype, "remove")==0){
                        toUpdate->stock-=tempstock;
                        break;
                    }
                } while (true);
                puts("AFTER UPDATE");
                printf("Game title: %s \n",toUpdate->title);
                printf("Game title: %s \n",toUpdate->genre);
                printf("Game title: %s \n",toUpdate->email);
                printf("Game title: %d \n",toUpdate->stock);
                if(toUpdate->stock == 0){
                    printf("%s is removed from warehouse. \n",toUpdate->title);
                    root = deletion(root,toUpdate->title);
                }
            }
            break;
        case 4:
            puts("Program exit");
            root = deleteAll(root);
            break;
        }
    } while (menu != 4);
    


    return 0;
}