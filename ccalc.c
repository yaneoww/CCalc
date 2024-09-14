#include <stdio.h>
#include <ncurses.h>
#include <locale.h>

short int A, B;
int cursePos = 0;
bool hasA = false, hasB = false, hasDoing = false;
int res;

void printMenu(){
    char menu[9][27] = {
        "1. Введите A",
        "2. Введите B",
        "3. Сложение (+)",
        "4. Вычитание (-)",
        "5. Умножение (*)",
        "6. Деление (/)",
        "7. Выход",
        "----------------------",
        ""
        };

    for(int i = 0; i <= 8; ++i){
        printw("%s", menu[i]);
        if(i == 0 && hasA){
            printw("%s%d",": ", A);
        }
        if(i == 1 && hasB){
            printw("%s%d",": ", B);
        }
        if(i == 8){
            if(!hasA){
                printw("%s", "Не введён A :(");
            }
            else if (!hasB)
            {
                printw("%s", "Не введён B :(");
            }else if(!hasDoing){
                printw("%s", "Не выбрано действие :(");
            }
            else{
                printw("%s%d", "Результат: ", res);
            }
        }
        if (i == cursePos){
            printw("  %s", "<--");
        }
        printw("\n");
    }
}

void doSomething(int doing){
    switch (doing)
    {
    case 0:
        clear();
        printw("%s", "Введите A: ");
        scanw("%d\n", &A);

        // TODO: Проверка на дебила

        hasA = true;

        clear();
        printMenu();

        break;
    
    case 1:
        clear();
        printw("%s", "Введите B: ");
        scanw("%d\n", &B);

        // TODO: Проверка на дебила

        hasB = true;

        clear();
        printMenu();

        break;
    
    case 2:
        if(hasA && hasB){
            hasDoing = true;
            res = A + B;
        }
        clear();
        printMenu();

        break;
    
    case 3:
        if(hasA && hasB){
            hasDoing = true;
            res = A - B;
        }
        clear();
        printMenu();

        break;

    case 4:
        if(hasA && hasB){
            hasDoing = true;
            res = A * B;
        }
        clear();
        printMenu();

        break;
    
    case 5:
        if(hasA && hasB){
            hasDoing = true;
            res = A / B;
        }
        clear();
        printMenu();

        break;
    
    default:
        break;
    }
}

int main(){
    setlocale(LC_ALL, "");
    int key, key1 = -1, key2 = -1;
    initscr();

    while(true){
        printMenu();

        key = getch();
        if(key == 27){
            key = getch();
            if(key == 91){
                key = getch();
                if(key == 65){
                    cursePos--;
                    if(cursePos < 0){
                        cursePos = 6;
                    }
                }
                if(key == 66){
                    cursePos++;
                    if(cursePos > 6){
                        cursePos = 0;
                    }
                }
            }
            if (key == 27){
                break;
            }
        }
        if(key == 49){
            doSomething(0);
        }
        if(key == 50){
            doSomething(1);
        }if(key == 51){
            doSomething(2);
        }if(key == 52){
            doSomething(3);
        }if(key == 53){
            doSomething(4);
        }if(key == 54){
            doSomething(5);
        }if(key == 55){
            break;
        }

        clear();
    }
    
    return 0;
}