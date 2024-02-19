 // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <time.h>

using namespace std;

typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*   
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0; 
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
        for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1=0, r2=0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble &pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double> &A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return ;
}


/*
*  WriteArrayTextFile 
*
*/

void WriteArrayTextFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;   
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
    
}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size=0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
  }

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n"; 
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}


/*
* Задано одновимірний масив А розміру 2N. 
* Побудувати два масиви В і С розміру N, 
* включивши  у масив В елементи масиву А з парними індексами,
* а у С - з непарними.
*****************
*  A - in 
*  B, C - out 
*/
void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}
/*
*  Task  Var
* 
* 
*/
void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
            switch (ch) {
             case '1': cout << " 1 "; break;
             case '2': cout << " 2 "; break;
            //
            case '5': return;
            }
        cout << " Press any key and enter\n";
        ch = getchar();
        } while (ch != 27);
    
}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}


int main()
{ 
    // Завдання 1
    std::cout << "Nomer 1: \n";
    //введення N
    int N;
    std::cout << "Input N: ";
    std::cin >> N;
    
    //Оголошення та введення масиву А
    std::vector<int> A(N);
    std::cout << "Input array A:\n";
    for (int i = 0; i < N; ++i)
    {
        std::cout << "A[" << i << "]: ";
        std::cin >> A[i];
    }

    //Оголошення та створення масиву В
    std::vector<int> B;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] >= 0)
        {
            B.push_back(A[i]);
        }
    }
    //Виведення масиву В
    std::cout << "Array B with +elements  A:\n";
    for (int i = 0; i < B.size(); ++i)
    {
        std::cout << "B[" << i << "]: " << B[i] << "\n";
    }

    // Завдання 2
    std::cout << "Nomer 2: \n";
    //Оголошення змінних, введення Т
    int T, MAX = -1, k = 0;
    std::cout << "Input T: \n";
    std::cin >> T;
    //Початок перевірки елементів списку А
    for (int i = 0; i < N; ++i)
    {   //Перевірка чи елемент додатній
        if (A[i] >= 0)
        {   //Перевірка чи більший новий елемент MAX більший за минулий
            if (A[i] >= MAX)
            {   //Якщо умови виконані, новий ел. стає MAX, записується індекс елементу
                MAX = A[i];
                k = i;
            }
        }
    }
    //Перевірка отриманого MAX (чи додатній)
    if (MAX >= 0)
    {   //Перевірка, чи більший за змінну Т
        if (MAX > T)
        {   //Якщо умови виконані - виведення MAX елементу і його індексу
            std::cout << "Max +element: " << MAX << "\n";
            std::cout << "Index: " << k-1 << "\n";
        }
        //Якщо MAX менше 0 (залишилося -1) - виводить помилку
        else
        {
            std::cout << "! No element highter T ! \n";
        }
    }
    //Якщо MAX менше за Т - виводить помилку
    else
    {
        std::cout << "! No +element ! \n";
    }

    // Завдання 3
    std::cout << "Nomer 3: \n";
    //Оголошення та введення змінних
    float a, b;
    std::cout << "Input a, b (a < b): \n";
    std::cin >> a;
    std::cin >> b;
    //Порівняння змінних а і b, якщо a > b - виводить помилку
    if (a > b)
    {
        std::cout << "! a must be > b ! \n";
    }
    else
    {   //введення потрібних змінних
        int n;
        int sum = 0, dob = 1;
        std::cout << "Input n <= 200: ";
        std::cin >> n;
        //Перевірка, чи n < 200, якщо ні - виводить помилку
        if (n > 200)
        {
            std::cout << "! n must be <= 200 ! \n";
        }
        else   
        {   //Оголошення та введення масиву Х
            std::vector<int> X(n);
            std::cout << "Input array X:\n";
            for (int i = 1; i <= n; i++)
            {
                std::cout << "X[" << i << "]: ";
                std::cin >> X[i];
            }
            //Введення змінних
            int MAX = X[1], MIN = X[1];
            //В одному циклі обчислюємо 4 потрібні значення 4 змінних
            for (int i = 1; i <= n; ++i)
            {   //Значення змінної sum
                if (X[i] < a)
                {
                    sum = sum + X[i];
                }
                //Значення змінної dob
                if (X[i] > b)
                {
                    dob = dob * X[i];
                }
                //Значення змінної MAX
                if (X[i] > MAX)
                {
                    MAX = X[i];
                }
                //Значення змінної MIN
                if (X[i] < MIN)
                {
                    MIN = X[i];
                }
            }
            //Виведення змінних
            std::cout << "Sum elements < a: " << sum << "\n";
            std::cout << "Dobutok elements > b: " << dob << "\n";
            std::cout << "Max element: " << MAX << "\n";
            std::cout << "Min element: " << MIN << "\n";
            
            /*
            double A[MAX_SIZE], B[MAX_SIZE],C[MAX_SIZE];
            int n,m;
            n = RndInputArray(MAX_SIZE, A);
            WriteArrayTextFile(n, A, "1.txt");
            m = ReadArrayTextFile(MAX_SIZE, B, "1.txt");
            cout << " \n m= " << m << endl;
            for (int i = 0; i < m; i++)
                cout << B[i] << "   ";
            WriteArrayBinFile(n, A, "1.bin");
            m = ReadArrayBinFile(MAX_SIZE, C, "1.bin");
            cout << " \n m= " << m << endl;
            for (int i = 0; i < m; i++)
                cout << C[i] << "   ";
            cout << "\n  Vector \n";
            vector<double> vA;
            ConsoleInputVector(MAX_SIZE, vA);
            for (auto v : vA) {
                cout << v << "   ";
            }
           */
            TaskV();
            return 1;
        }
    }
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
