#include "lr.h"

void lab1()
{
    float v1, v2, t, t1, s;  // описание переменных

// ввод исходных данных
    printf("v1=");  // вывод на экран подсказки: v1=
    if (scanf("%f", &v1) != 1 || v1<=0) // ввод с клавиатуры значения переменной v1
    {
        printf("Error\n");
        return;
    }

    printf("v2=");  // вывод на экран подсказки: v2=
    if (scanf("%f", &v2) != 1 || v2>=v1 || v2<=0) /* ввод с клавиатуры значения переменной v2*/
    {
        printf("Error");
        return;
    }

    printf("t=");  // вывод на экран подсказки: t=
    if (scanf("%f", &t)!= 1 || t <= 0) // ввод с клавиатуры значения переменной t
    {
        printf("Error");
        return;
    }

// решение задачи
    t1 = t / 3600;
    s = v1*t1+((v2-v1)*t1)/2;

    printf("distance=%.2f km\n", s);

}

void lab2()
{
    float s, a, i;
    int N, sign;  // описание переменных

// ввод исходных данных
    printf("N=");  // вывод на экран подсказки: N=
    scanf("%d", &N); // ввод с клавиатуры значения переменной N
    
    s=0;
    sign=1;
    i=1;
   
// решение задачи    
    while (i<=N)
    {
        a=(i+2)/(i*(i+1));
        s=s+sign*a;
        sign=-sign;
        i=i+1;
    }

    printf("s=%f\n", s);

}

void lab2dop()
{
    float s, a, i;
    int N, sign;
    printf("N=");
    scanf("%d", &N);
    s=0;
    sign=1;
    for (i=1; i<=N; i=i+1)
    {
        a=(i+2)/(i*(i+1));
        s=s+sign*a;
        sign=-sign;
    }
    printf("s=%f\n", s);
}

int isvowel(char c) {
    // Проверка, является ли символ гласной буквой
    char vowels[] = {'a', 'e', 'i', 'o', 'u', '\0'};

    for (int i = 0; vowels[i] != '\0'; i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }

    return 0;
}

void lab3()
{
    char c;
    int cnt = 0;
    int flag = 0;
    getchar();
    printf("Enter the text: ");

    while ((c = getchar()) != '\n') {
        if (c == ' ' || c == ',' || c == '.') {
            // Если текущий символ - разделитель, сбрасываем флаг в слове
            flag = 0;
        } else {
            // Если текущий символ - буква и мы не находимся внутри слова, инкрементируем счетчик слов
            if (flag==0) {
                // Проверяем, является ли текущая буква началом нового слова
                if (isvowel(c)) {
                    cnt++;
                }
                flag = 1;
            }
        }
    }

    printf("%d\n", cnt);

}

int isconsonant(char c) {
        return !isvowel(c);
    
    return 0;
}

void lab3dop()
{
    char c;
    int cnt = 0;
    int flag = 0;
    int firstvowel = 0;
    getchar();
    printf("Enter the text: ");
    
    while((c = getchar()) != '\n') {
        if (c == ' ' || c == ',' || c == '.') {
            flag = 0;
            firstvowel = 0;
            
        } else {
            if (flag==0) {
                flag = 1;
                if (isvowel(c)) {
                    firstvowel = 1;
                } else {
                    firstvowel = 0;
                }
            } else {
                if (firstvowel && isconsonant(c)) {
                    cnt++;
                    flag = 1;
                    firstvowel = 0;
                } else if (!firstvowel && isvowel(c)) {
                    firstvowel = 0;
                } else {
                    firstvowel = 0;
                }
            }
        }
    }
    
    printf("%d\n", cnt);
    
}

void lab4()
{
    #define MAX_LENGTH 100 // Инициализация константы длины строки
    int i,k=1;
    char s[MAX_LENGTH]; // Определение массива символов строки
    
    getchar();
    printf("Enter the string:\n");
    
    // Ввод строки и создание из нее массива символов
    fgets(s,MAX_LENGTH,stdin);
    printf("\nString after deleting even words:\n");
    
    for (i=0; i<MAX_LENGTH; i++)
    {
        if(s[i]=='\0') break;
        if (s[i]!=' ' && s[i]!=',' && s[i]!='.' && s[i]!='\t') // Если текущий символ не разделитель
        {
            if (k%2==1) // Если слово нечетное, печатаем текущий символ
            printf("%c", s[i]);
            
            if (s[i+1]==' ' || s[i+1]==',' || s[i+1]=='.' || s[i+1]=='\t') // Если следующий символ - разделитель
            {
                if (k%2==1)
                printf(" ");
                k++;
            }
        }
    }
}

void lab4dop()
{
    #define MAX_LENGTH 100 // Инициализация константы длины строки
    int i,k=1;
    char s[MAX_LENGTH]; // Определение массива символов строки
    
    getchar();
    printf("Enter the string:\n");
    
    // Ввод строки и создание из нее массива символов
    fgets(s,MAX_LENGTH,stdin);
    printf("\nString after deleting even words:\n");
    
    for (i=0; i<MAX_LENGTH; i++)
    {
        if(s[i]=='\0') break;
        if (s[i]!=' ' && s[i]!=',' && s[i]!='.' && s[i]!='\t') // Если текущий символ не разделитель
        {
            if (k%2==1) // Если слово нечетное, печатаем текщий символ
            printf("%c", s[i]);
            
            if (s[i+1]==' ' || s[i+1]==',' || s[i+1]=='.' || s[i+1]=='\t') // Если следующий символ - разделитель
            {
                if (k%2==1)
                printf("\n");
                k++;
            }
        }
    }
}

#define LENGTH 10 // Инициализация константы длины массива

void lab5()
{
    int numbers[LENGTH],max,i; // Объявление массива чисел, переменных
    
    printf("Enter 10 integers:\n");
    for(i=0;i<LENGTH;i++)
    {
        scanf("%d", &numbers[i]);
        if(i==0) max=numbers[0]; // Присваиваем переменной max значение первого элемента массива
        if(max<numbers[i]) max=numbers[i]; // Если max меньше очередного элемента массива, то max присваивается это значение
    }
    if(max==0)
    {
        printf("Error: division by 0");
    }
    printf("The quotient of dividing negative numbers by the maximum element (%d):\n",max);
    for(i=0;i<LENGTH;i++)
    {
        if(numbers[i]<0) printf("%f\n",(float)numbers[i]/max); // Если текущий элемент отрицательный, то делим его на максимальный элемент и выводим в консоль
    }
}

void lab5dop()
{
    int numbers[LENGTH],i,j=0; // Объявление массива чисел, переменных
    struct numb // Объявление структуры, содержащей массив трех первых отрицательных значений и максимальный элемент
    {
        int negative[3];
        int max;
    } st;
    printf("Enter 10 integers:\n");
    for(i=0;i<LENGTH;i++)
    {
        scanf("%d", &numbers[i]);
        if(numbers[i]<0 && j<3)
        {
            st.negative[j]=numbers[i];
            j++;
        }
        if(i==0) st.max=numbers[0]; // Присваиваем переменной max значение первого элемента массива
        if(st.max<numbers[i]) st.max=numbers[i]; // Если max меньше очередного элемента массива, то max присваивается это значение
    }
    if(st.max==0) 
    {
        printf("Error: division by 0");
    }
    
    printf("The quotient of dividing the first 3 negative numbers by the maximum element (%d):\n",st.max);
    for(i=0;i<3;i++)
    {
        if(st.negative[i]<0) printf("%f\n",(float)st.negative[i]/st.max); // Если текущий элемент отрицательный, то делим на максимальный элемент и выводим в консоль
    }
}

#define N 3 // Инициализация константы количества строк
#define K 3 // Инициализация константы количества элементов в строке

void lab6()
{
    int arr[N][K],arr_temp[K],sum,min,max,i,j,j_min=0,j_max=0; // Объявление массивов и переменных
    /* N - количество строк, K - количество элементов в строке; sum - сумма элементов в текущей строке;
    min - минимальная сумма элементов; max - максимальная сумма элементов;
    j_min - номер строки с минимальной суммой элементов; j_max - номер строки с минимальной суммой элементов*/
    
    printf("Please enter %d rows of %d numbers:\n",N,K);
    for(j=0;j<N;j++) // Цикл перебора массива строк
    {
        printf("%d row:\n",j+1);
        sum=0; // Обнуление суммы значений в строке
        for(i=0;i<K;i++) // Цикл ввода значений строки
        {    
            scanf("%d", &arr[j][i]); // Ввод значений
            sum=sum+arr[j][i]; // Нахождение суммы в строке
        }
        if(j==0) min=max=sum; // Инициализируем переменные min и max
        if(min>sum)
        {
            min=sum; // Если min больше текущей суммы, то min присваиваем значение текущей суммы
            j_min=j; // Строка с минимальной суммой
        }
        if(max<sum)
        {
            max=sum; // Если max меньше текущей суммы, то max присваиваем значение текущей суммы
            j_max=j; // Строка с максимальной суммой
        }
    }
    
    printf("Original array:\n"); // Вывод исходного массива
    for(j=0;j<N;j++)
    {
        printf("\n%d.\t",j+1);
        for(i=0;i<K;i++)
        {
            printf("%d\t",arr[j][i]);
        }
        printf("\n");
    }
    
    if(j_min==j_max)
    {
        printf("The sums in all rows are equal. No replacement is required.");
    }
    
    printf("Array after replacement of %d and %d rows:\n",j_min+1,j_max+1);
    for(i=0;i<K;i++)
    {
        arr_temp[i]=arr[j_min][i]; // Помещаем каждый элемент из строки с минимальной суммой во временный массив
        arr[j_min][i]=arr[j_max][i]; // Заменяем каждый элемент строки с минимальной суммой элементом из строки с максимальной суммой
        arr[j_max][i]=arr_temp[i]; // Заменяем каждый элемент строки с максимальной суммой элементом из временного массива
    }
    
    for(j=0;j<N;j++) // Вывод итогового массива
    {
        printf("\n%d.\t",j+1);
        for(i=0;i<K;i++)
        {
            printf("%d\t",arr[j][i]);
        }
        printf("\n");
    }
}

void lab6dop()
{
    int arr[N][K],i,j,p_i,p_j,min_i,min_j,temp,start,sort_req=0;
    // N - количество строк, K - количество элементов в строке
    // i,j  - позиции обхода массива
    // p_j,p_i текущая позиция перебора происка минимального элемента
    // min_j,min_i текущая позиция минимального элемента
    // start - позиция в строке, с которой начинается перебор поиска минимального элемента
    // sort_req - необходимость сортировки
    // temp - временная переменная для сортировки

    printf("Please enter %d rows of %d numbers:\n",N,K);
    
    for(j=0;j<N;j++)
    {
        printf("%d row:\n",j+1);
        for(i=0;i<K;i++) scanf("%d", &arr[j][i]); // ввод значений
    }
    
    printf("Original array:\n"); // вывод исходного массива
    for(j=0;j<N;j++)
    {
        printf("\n%d.\t",j+1);
        for(i=0;i<K;i++)
        {
            printf("%d\t",arr[j][i]);
        }
        printf("\n");
    }

    for(j=0;j<N;j++)
    {
        for(i=0;i<K;i++)
        {
            min_j=j; // начальная позиция минимального элемента
            min_i=i; // начальная позиция минимального элемента
            start=i+1; // стартовая позиция для начала перебора поиска минимального элемента
            for(p_j=j;p_j<N;p_j++)
            {
                for(p_i=start;p_i<K;p_i++) // p_i и p_j - текущие позиции перебора поиска
                {
                    if(arr[min_j][min_i]>arr[p_j][p_i]) // если минимальное значение больше найденного, то присваиваем новое значение позиции минимального элемента
                    {
                        min_i=p_i;
                        min_j=p_j;
                        sort_req=1; // поскольку позиция min элемента изменилась, то потребуется сортировка
                    }
                }
            start=0;
            }    
            
            if(sort_req==1)
            {
                temp=arr[j][i];
                arr[j][i]=arr[min_j][min_i];
                arr[min_j][min_i]=temp;
                sort_req=0;
            }
        }
    }
    
    printf("Array after replacement:\n");
    for(j=0;j<N;j++)
    {
        printf("\n%d.\t",j+1);
        for(i=0;i<K;i++)
        {
            printf("%d\t",arr[j][i]);
        }
        printf("\n");
    }
}

void lab7()
{
    long number;
    int i,position,length=sizeof(long)*8; // вычисление количества битов в длинном числе
    printf("Enter a long number: ");
    scanf("%ld", &number);
    if (number!=0) // если число не равно нулю
    { 
        position = 0;
        for(i=0;i<length;i++)
        {
            if((number&1)==1) position = i;
            number>>=1; 
        }
        printf("Position of senior 1 digit: %d", position);        
    }
    else printf("0 is entered. No result.");

}