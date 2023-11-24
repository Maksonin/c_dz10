void hello(void){
    printf("DZ 10\n");
}

/* Функция для вывода приглашения и запроса ввода числа с последующим его возвратом */
int setIntVar(char str[]){
    int var;
    printf("%s", str);
    scanf("%d",&var);
    return var;
}

/* Функция для заполнения массива arr типа int размером size вручную */
void setIntArray(int arr[], int size) {
    for(int i = 0; i < size; i++){
        printf("%d element - ", i);
        scanf("%d", &arr[i]);
    }
}

/* Функция для заполнения массива arr типа int размером size рандомными значениями */
void setRandomIntArray(int arr[], int size, int seed) {
    srand(seed);
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
}

/* Функция для заполнения массива arr arr типа int c 
    количеством столбцов - ncol и строк - nrow */
void setQuardIntArray(int arr[], int ncol, int nrow, int seed) {
    srand(seed);
    for(int i = 0; i < nrow; i++){
        for(int j = 0; j < ncol; j++)
            arr[i * ncol + j] = rand() % 100;
    }
}

/* Функция для сдвига массива arr типа int размером size вправо на shiftLen элементов */
void shiftArrayRight(int arr[], int size, int shiftLen){
    int tmp = 0;
    
    for(int l = 0; l < shiftLen; l++){
        tmp = arr[size-1];
        for(int i = size-1; i > 0; i--){
            arr[i] = arr[i-1]; 
        }
        arr[0] = tmp;
    }
}

/* Функция для печти в консоль каждого элемента массива arr типа int размером size */
void printIntArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

/* Функция для печти в консоль каждого элемента строки размером size */
// void printString(char str[], int size) {
//     for(int i = 0; i < size; i++)
//         printf("%c", str[i]);

//     printf("\n");
// }

/* Функция для печти в консоль каждого элемента квадратного массива arr типа int размером size */
void printQuardIntArray(int arr[], int ncol, int nrow) {
    for(int i = 0; i < nrow; i++){
        for(int j = 0; j < ncol; j++)
            printf("%d\t", arr[i * ncol + j]);
        
        printf("\n");
    }

    printf("\n");
}

/* Функция для обмена значений между двумя переменными */
void swap(int *pa, int *pb) {
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

/* Функция для обмена значений между двумя переменными */
void swapChar(char *pa, char *pb) {
    char tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

/* Функция для сортировки int массива 
    в направлении direction = 1 - по возрастанию, 0 - по убыванию
*/
void sortArray(int a[], int size, _Bool direction){
    int i = 0;
    _Bool flag;
    do {
        flag = 0; // сбросить флаг
        for (int j = size - 2; j >= i ; j-- ) {
            if((a[j] > a[j+1]) && (direction)) {
                swap(&a[j], &a[j+1]);
                flag = 1; // поднять флаг если есть обмен
            }
            else if((a[j] < a[j+1]) && (!direction)) {
                swap(&a[j], &a[j+1]);
                flag = 1; // поднять флаг если есть обмен
            }
        }
        i++;
    } while ( flag ); // выход при flag = 0
}