#include <stdio.h>
#include <string.h>

#include "mylib.h"

void task1(void);
void task2(void);
void task3(void);

int main(void){
    hello();
    char str[] = "Put the task number (1-3) - ";

    switch (setIntVar(str)){
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        default:
            printf("whaaa?\n");
            break;           
    }
}

/* Задача 1. В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt. */
#define SIZE1 1000
void task1(void){
    char str[SIZE1];

    FILE *f;

    // предварительное заполнение файла
    char fileStr[] = "H !ell!o !world";

    if( (f = fopen(".\\task1\\task1.txt", "w" )) == NULL ){
        perror("Error - ");
        return;
    }
    else { 
        fprintf(f, "%s", fileStr);
        fclose(f);
    }

    // начало выполнения задания
    if( (f = fopen(".\\task1\\task1.txt", "a+" )) == NULL ){
        perror("Error - ");
        return;
    }
    else{
        fscanf(f, "%1000[^\n]", str);
    }

    printf("%s\n", str);

    // начало перебора строки
    for(int i = 0; i < strlen(str); i++){
        // если текущий элемент пробел или символ
        if((str[i] == ' ') || (str[i] < 48)){
            continue; // переходим на следующую итерацию цикла
        }

        int i1 = i+1; // вспомогательная переменная
        // цикл для поиска следующего элемента строки с которым будет произведена замена
        // цикл работает пока текущий элемент равен пробелу или символу
        while((str[i1] == ' ') || (str[i1] < 48)){
            i1++;
            if(i1 > strlen(str)){ // проверка на выход за размер строки
                printf("END!\n");
                return;
            }
        }
        // после окончания цикла в переменной i1 находится номер элемента строки который не пробел и не символ
        swapChar(&str[i], &str[i1]); // 

        // главный цикл продолжаем с i1
        i = i1;
    }

    printf("%s\n", str);

    fprintf(f,"\n%s",str);

    fclose(f);
}

/* Задача 2. В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt. */
char *delProbel(char* str){
    char *ptr = calloc(strlen(str), sizeof(char));
    int prob = 0;

    for(int i = 0, i1 = 0 ; i < strlen(str); i++){
        if((i == 0) && (str[i] == ' ')){
            if(str[i+1] == ' ')
                i++;

            continue;
        }

        if((str[i] == ' ') && (str[i+1] == ' '))
            continue;

        ptr[i1] = str[i];
        i1++;
    }

    return ptr;
}

#define SIZE2 1000
void task2(void){
    char str[SIZE2];
    FILE *f;

    // предварительное заполнение файла
    char fileStr[] = "  Task2!  Just  do it!";

    if( (f = fopen(".\\task2\\task2.txt", "w" )) == NULL ){
        perror("Error - ");
        return;
    }
    else { 
        fprintf(f, "%s", fileStr);
        fclose(f);
    }

    if( (f = fopen(".\\task2\\task2.txt", "a+" )) == NULL ){
        perror("Error - ");
        return;
    }
    else {
        fscanf(f, "%1000[^\n]", str);
    }

    printf("%s\n", str);
    char *ptr = delProbel(str);
    printf("%s\n", ptr);

    fprintf(f,"\n%s", ptr);

    free(ptr);
    fclose(f);
}

/* Задача 3. В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
.txt. */
#define SIZE3 1000
void task3(void){
    char str[SIZE3];

    FILE *f;
    // предварительное заполнение файла
    char fileStr[] = "/DOC.TXT/qqq/asd.css";

    if( (f = fopen(".\\task3\\task3.txt", "w" )) == NULL ){
        perror("Error - ");
        return;
    }
    else { 
        fprintf(f, "%s", fileStr);
        fclose(f);
    }

    // открытие файла
    if( (f = fopen(".\\task3\\task3.txt", "a+" )) == NULL ){
        perror("Error - ");
        return;
    }
    else{
        fscanf(f, "%1000[^\n]", str); // считывание 1000 символов в соответствующий массив
    }

    printf("%s\n", str);

    // переменная с размером строки из файла
    int strL = strlen(str);

    // строка с требуемым расширением
    char resol[] = ".html";
    // переменная с размером строки с расширением
    int resolL = strlen(resol);

    // перебор массива из файла с конца
    for(int i = strL; i >= 0; i--){
        if(str[i] == '/'){ // если найден первый с конца слэщ
            _Bool point = 0; // переменная для хранения факта наличия точки
            for(int i1 = i, j = 0; i1 < strL; i1++){ // перебор части строки от слэша до конца в поисках точки
                if(str[i1] == '.'){ // если точка найдена
                    point = 1; // отмечаем этот факт
                    strL += i1 + resolL; // увеличиваем длину массива на длину строки с расширением плюс номер текущего элемента строки
                }
                if(point == 1){ // если уже была найдена
                    str[i1] = resol[j]; // продолжаем замену текущего значения строки на новое
                    j++;
                }
            }
            if(!point){ // если точка не найдена
                for(int i1 = strL, j = 0; j < resolL; i1++, j++){
                    str[i1] = resol[j]; // с конца строки записываем расширение
                }
            }
            break;
        }
    }

    printf("%s\n", str);

    fprintf(f,"\n%s", str);

    fclose(f);
}