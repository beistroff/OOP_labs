#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <time.h>
#include <random>

using namespace std;

/*----------------------------FUNCTIONS--------------------------------*/

int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0;
    do {
        cout << "    Specify size of an array (1 <= SIZE =<" << sizeMax << "): ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}

int ConsoleInputSizeArray_Task3(const int sizeMax)
{
    int size = 0;
    do {
        cout << "    Specify size of an array (1 <= SIZE =<" << sizeMax << "): ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}

int ConsoleInputArray(int sizeMax, double A[])   //Array A
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "] = "; cin >> A[i];
    }
    return size;
}
int ConsoleInputArrayNew(int sizeMax, double* newA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    if (newA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "] = "; cin >> newA[i];
    }
    cout << "\n";
    for (int i = 0; i < size; i++) {
        cout << newA[i] << "   ";
    }
    return size;
}
int ConsoleProccesStaticArray(int size, double A[], int sizeB, double B[]) {
    cout << "\n1.1) CONSOLE\nArray A:" << endl;           //CONSOLE
    for (int i = 0; i < size; i++) {
        cout << A[i] << "   ";
        if (A[i] > 10) {
            sizeB++;
            B[sizeB] = A[i];
        }
    }
    cout << "\nArray B:" << endl;
    for (int i = 1; i <= sizeB; i++) {
        cout << B[i] << "   ";
    }
    return size;
}

int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }
    fin.close();
    return size;
}

int ReadArrayTextFileNew(int n, double* newA, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;
    for (int i = 0; i < n; i++) {
        fin >> newA[i];
    }
    fin.close();
    return size;
}

int FileProccesArrayStatic(int MAX_SIZE, double fileA[], int fB, double fileB[], int m) {
    cout << "\n\n1.2) FILE\nArray A:" << endl;            //FILE
    m = ReadArrayTextFile(MAX_SIZE, fileA, "array.txt");
    for (int i = 0; i < m; i++) {
        cout << fileA[i] << "   ";
        if (fileA[i] > 10) {
            fB++;
            fileB[fB] = fileA[i];
        }
    }
    cout << "\nArray B:" << endl;
    for (int i = 1; i <= fB; i++) {
        cout << fileB[i] << "   ";
    }
    return m;
}

int FileProccesArrayDynamic(int MAX_SIZE, int m, int fB, double *newA, double *newB) {
    cout << "\n\n1.2) FILE\nArray A:" << endl;            //FILE
    m = ReadArrayTextFileNew(MAX_SIZE, newA, "array.txt");
    for (int i = 0; i < m; i++) {
        cout << newA[i] << "   ";
        if (newA[i] > 10) {
            ++fB;
            newB[fB] = newA[i];
        }
    }
    cout << "\nArray B:" << endl;
    for (int i = 1; i <= fB; i++) {
        cout << newB[i] << "   ";
    }
    delete[] newA;
    delete[] newB;
    return m;
}

int RndArrayStatic_Task2(int sizeMax, double A[], double B[], double C[]) {
    cout << "\n"; int size = ConsoleInputSizeArray(sizeMax);
    int min, max, T1, T2, nC = 0, nB = 0;
    int random_number;
    srand(size);

    std::cout << "\n    Input range for random numbers:" << endl;
    std::cout << "    Min = "; std::cin >> min;
    std::cout << "    Max = "; std::cin >> max;
    for (int i = 0; i < size; i++){
        std::random_device truly_random_seed;
        std::default_random_engine dank_engine(truly_random_seed());
        std::uniform_int_distribution<> distribution(min, max);
        random_number = distribution(dank_engine);
        A[i] = random_number;
    }
    std::cout << "    Array A:\n" << "    ";
    for (int i = 0; i < size; i++)
        cout << A[i] << "   ";

    cout << "\n    Range in array between T1 and T2" << endl;
    cout << "    Input T1: "; cin >> T1;
    cout << "    Input T2: "; cin >> T2;
    for (int i = 0; i < size; i++) {
        if (A[i] > T1 && A[i] < T2) {
            ++nC;
            C[nC] = A[i];
        }
        else if (A[i] > T2) {
            cout << "\n    Last elem to the 1st elem, which > T2" << endl;
            cout << "    Last[" << nC - 1 << "] = " << C[nC] << endl;
            break;
        }
    }
    cout << "\n    Array B:" << endl;
    cout << "    ";
    for (int i = 0; i < size; i++) {
        if (A[i] > T1 && A[i] < T2) {
            ++nB;
            B[nB] = A[i];
        }
    }
    for (int i = 1; i <= nB; i++)
        cout << B[i] << "   ";
    cout << "\n\n";

    return size;
}

int RndArrayDynamic_Task2(int sizeMax, double *call_A, double *call_B, double C[]) {
    cout << "\n"; int size = ConsoleInputSizeArray(sizeMax);
    int min, max, T1, T2, nC = 0, nB = 0;
    int random_number;
    srand(size);

    std::cout << "\n    Input range for random numbers:" << endl;
    std::cout << "    Min = "; std::cin >> min;
    std::cout << "    Max = "; std::cin >> max;
    for (int i = 0; i < size; i++) {
        std::random_device truly_random_seed;
        std::default_random_engine dank_engine(truly_random_seed());
        std::uniform_int_distribution<> distribution(min, max);
        random_number = distribution(dank_engine);
        call_A[i] = random_number;
    }
    std::cout << "    Array A:\n" << "    ";
    for (int i = 0; i < size; i++)
        cout << call_A[i] << "   ";

    cout << "\n    Range in array between T1 and T2" << endl;
    cout << "    Input T1: "; cin >> T1;
    cout << "    Input T2: "; cin >> T2;
    for (int i = 0; i < size; i++) {
        if (call_A[i] > T1 && call_A[i] < T2) {
            ++nC;
            C[nC] = call_A[i];
        }
        else if (call_A[i] > T2) {
            cout << "\n    Last elem to the 1st elem, which > T2" << endl;
            cout << "    Last[" << nC - 1 << "] = " << C[nC] << endl;
            break;
        }
    }
    cout << "\n    Array B:" << endl;
    cout << "    ";
    for (int i = 0; i < size; i++) {
        if (call_A[i] > T1 && call_A[i] < T2) {
            ++nB;
            call_B[nB] = call_A[i];
        }
    }
    for (int i = 1; i <= nB; i++)
        cout << call_B[i] << "   ";
    cout << "\n\n";

    return size;
}

int RndInputArray(int sizeMax, double A[], double B[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0, k = 0;
    srand(size);
    cout << "Array A:" << endl;
    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        if (A[i] > 10) {
            k++;
            B[k] = A[i];
        }
        cout << A[i] << "   ";
    }
    cout << "\nArray B:" << endl;
    for (int i = 1; i <= k; i++) {
        cout << B[i] << "   ";
    }
    return size;
}

int RndInputArrayNew(int sizeMax, double *newA, double *newB) {
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0, k = 0;
    srand(size);
    cout << "    Array A:" << endl << "    ";
    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        newA[i] = 100.0 * r1;
        newA[i] = newA[i] / (1.0 + r2);
        if (newA[i] > 10) {
            ++k;
            newB[k] = newA[i];
        }
        cout << newA[i] << "   ";
    }
    cout << "\n    Array B:" << endl;
    for (int i = 1; i <= k; i++) {
        cout << newB[i] << "   ";
    }
    delete[] newA;
    delete[] newB;

    return size;
}

/*-----------------------------------Task2-Functions-------------------------------*/

int ConsoleDynamicArrayTask2(int size, int MAX_SIZE, double *newA, double *newB, double C[]) {
    cout << "\n\n    2)Task2_Dynamic_Array\n";
    size = ConsoleInputSizeArray(MAX_SIZE);
    int T1, T2, nB = 0, nC = 0;

    if (newA == NULL) exit(1);
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "] = "; cin >> newA[i];
    }
   
    cout << "\n    Range in array between T1 and T2" << endl;
    cout << "    Input T1: "; cin >> T1;
    cout << "    Input T2: "; cin >> T2;

    for (int i = 0; i < size; i++) {
        if (newA[i] > T1 && newA[i] < T2) {
            ++nC;
            C[nC] = newA[i];
        }
        else if (newA[i] > T2) {
            cout << "\n    Last elem to the 1st elem, which > T2" << endl;
            cout << "    Last[" << nC - 1 << "] = " << C[nC] << endl;
            break;
        }
    }
    cout << "\n    Array B:" << endl;
    cout << "    ";
    for (int i = 0; i < size; i++) {
        if (newA[i] > T1 && newA[i] < T2) {
            ++nB;
            newB[nB] = newA[i];
        }
    }
    for (int i = 1; i <= nB; i++)
        cout << newB[i] << "   ";
    cout << "\n\n";

    return size;
}

int ConsoleStaticArrayTask2(int size, int MAX_SIZE, double A[], double B[], double C[]){
    cout << "\n\n    2)Task2_Dynamic_Array\n";
    size = ConsoleInputSizeArray(MAX_SIZE);
    int T1, T2, nB = 0, nC = 0;

    if (A == NULL) exit(1);
    for (int i = 0; i < size; i++) {
        cout << "    A[" << i << "] = "; cin >> A[i];
    }

    cout << "\n    Range in array between T1 and T2" << endl;
    cout << "    Input T1: "; cin >> T1;
    cout << "    Input T2: "; cin >> T2;

    for (int i = 0; i < size; i++) {
        if (A[i] > T1 && A[i] < T2) {
            ++nC;
            C[nC] = A[i];
        }
        else if (A[i] > T2) {
            cout << "\n    Last elem to the 1st elem, which > T2" << endl;
            cout << "    Last[" << nC-1  << "] = " << C[nC] << endl;
            break;
        }
    }
    cout << "\n    Array B:" << endl;
    cout << "    ";
    for (int i = 0; i < size; i++) {
        if (A[i] > T1 && A[i] < T2) {
            ++nB;
            B[nB] = A[i];
        }
    }
    for (int i = 1; i <= nB; i++)
        cout << B[i] << "   ";
    cout << "\n\n";

    return size;
}

int FileProccesArrayStatic_Task2(int MAX_SIZE, int m, int fB, double A[], double B[], double C[]) {
    m = ReadArrayTextFile(MAX_SIZE, A, "array_task2.txt");
    int T1, T2, nB = 0, nC = 0;

    cout << "\n    Range in array between T1 and T2" << endl;
    cout << "    Input T1: "; cin >> T1;
    cout << "    Input T2: "; cin >> T2;

    cout << "\n    Array A:" << endl; cout << "    ";
    for (int i = 0; i <= m; i++)
        cout << A[i] << "   ";
    for (int i = 0; i < m; i++) {  
        if (A[i] > T1 && A[i] < T2) {
            ++nC;
            C[nC] = A[i];
        }
        else if (A[i] > T2) {
            cout << "\n    Last elem to the 1st elem, which > T2" << endl;
            cout << "    Last[" << nC - 1 << "] = " << C[nC] << endl;
            break;
        }
    }
    cout << "\n    Array B:" << endl;
    cout << "    ";
    for (int i = 0; i <= m; i++) {
        if (A[i] > T1 && A[i] < T2) {
            ++nB;
            B[nB] = A[i];
        }
    }
    for (int i = 1; i <= nB; i++)
        cout << B[i] << "   ";
    cout << "\n\n";

    return m;
}
/*-----------------------------------Task3-Functions-------------------------------*/
int ConsoleInputArrays_Task3(int MAX_SIZE_N, int size, double A[], double B[], double C[]) {
    size = ConsoleInputSizeArray_Task3(MAX_SIZE_N);

    int allSize = 0;

    cout << "    Input elements of array X:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "    A[" << i << "] = "; cin >> A[i];
    }
    cout << "    Input elements of array Y:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "    B[" << i << "] = "; cin >> B[i];
    }

    cout << "\n    Array X:" << endl << "    ";
    for (int i = 0; i < size; i++) cout << A[i] << "   ";
    cout << "\n    Array Y:" << endl << "    ";
    for (int i = 0; i < size; i++) cout << B[i] << "   ";;

    for (int i = 0; i < size; i++) C[i] = A[i];
    allSize = size * 2;
    for (int i = size; i < allSize; i++) {
        C[i] = B[i - size];
    }
    cout << "\n    Connected array X and Y:" << endl << "    ";
    for (int i = 0; i < allSize; i++) cout << C[i] << "   ";
    return size;
}

int RndInputArrays_Task3(int MAX_SIZE_N, int size, double A[], double B[], double C[]) {
    size = ConsoleInputSizeArray_Task3(MAX_SIZE_N);
    int min, max;
    int random_number;
    srand(size);

    std::cout << "\n    Input range for random numbers:" << endl;
    std::cout << "    Min = "; std::cin >> min;
    std::cout << "    Max = "; std::cin >> max;
    for (int i = 0; i < size; i++) {
        std::random_device truly_random_seed;
        std::default_random_engine dank_engine(truly_random_seed());
        std::uniform_int_distribution<> distribution(min, max);
        random_number = distribution(dank_engine);
        A[i] = random_number;
    }
    std::cout << "    Array X:\n" << "    ";
    for (int i = 0; i < size; i++)
        cout << A[i] << "   ";

    std::cout << "\n    Input range for random numbers:" << endl;
    std::cout << "    Min = "; std::cin >> min;
    std::cout << "    Max = "; std::cin >> max;
    for (int i = 0; i < size; i++) {
        std::random_device truly_random_seed;
        std::default_random_engine dank_engine(truly_random_seed());
        std::uniform_int_distribution<> distribution(min, max);
        random_number = distribution(dank_engine);
        B[i] = random_number;
    }
    std::cout << "    Array Y:\n" << "    ";
    for (int i = 0; i < size; i++)
        cout << B[i] << "   ";

    return size;
}

/*-------------------------------MENU--------------------------------------------------*/
int MenuTask1(int answerTask, int size, int sizeB, double A[], double B[], int MAX_SIZE, double fileA[],
    int m, int fB, double fileB[], int n, int arrayType, double *newA, double *newB)
{
    cout << "    Menu Task 1  \n";
    cout << "    1.  Console  \n";
    cout << "    2.  File  \n";
    cout << "    3.  Random \n";
    do {
        cout << "\n    Enter: "; cin >> answerTask;
        switch (answerTask) {
            case 1:
            cout << "    What array do you want to use? (Static/Dynamic)" << endl;
            cout << "    If static, enter 1, else enter 2" << endl;
            cout << "    1. Static" << endl;
            cout << "    2. Dynamic" << endl;
            cout << "    Enter: "; cin >> arrayType;
            switch (arrayType) {
                case 1:
                    size = ConsoleInputArray(MAX_SIZE, A);

                    ConsoleProccesStaticArray(size, A, sizeB, B);
                break;
                case 2:
                    size = ConsoleInputArrayNew(MAX_SIZE, newA);
                    cout << "\n1.1) CONSOLE\nArray A:" << endl;           //CONSOLE
                    for (int i = 0; i < size; i++) {
                        cout << newA[i] << "   ";
                        if (newA[i] > 10) {
                            ++sizeB;
                            B[sizeB] = newA[i];
                        }
                    }
                    cout << "\nArray B:" << endl;
                    for (int i = 1; i <= sizeB; i++) {
                        cout << B[i] << "   ";
                    }
                break;

            }
            break;
            case 2:
                cout << "    What array do you want to use? (Static/Dynamic)" << endl;
                cout << "    If static, enter 1, else enter 2" << endl;
                cout << "    1. Static" << endl;
                cout << "    2. Dynamic" << endl;
                cout << "    Enter: "; cin >> arrayType;
                switch (arrayType) {
                case 1:
                    FileProccesArrayStatic(MAX_SIZE, fileA, fB, fileB, m);
                    break;
                case 2: 
                    FileProccesArrayDynamic(MAX_SIZE, m, fB, newA, newB);
                    break;
                default:
                    cout << "Try again!";
                    break;
                }
            break;
        case 3:
            cout << "    What array do you want to use? (Static/Dynamic)" << endl;
            cout << "    If static, enter 1, else enter 2" << endl;
            cout << "    1. Static" << endl;
            cout << "    2. Dynamic" << endl;
            cout << "    Enter: "; cin >> arrayType;
            switch (arrayType) {
            case 1:
                n = RndInputArray(MAX_SIZE, A, B);
                break;//RANDOM
            case 2:
                n = RndInputArrayNew(MAX_SIZE, newA, newB);
                break;
            default: 
                cout << "Try again!";
                break;
            }
            break;
        default:
            cout << "Try again!";
            break;
        }

    } while (answerTask <= 0 || answerTask > 3);

    return answerTask;
}
int MenuTask2(int answerTask, int size, int arrayType, int MAX_SIZE, double *newA, double *newB, double A[], 
    double B[], double C[], int m, int fB, double *call_A, double *call_B)
{
    cout << "    Menu Task 2  \n";
    cout << "    1.  Console  \n";
    cout << "    2.  File  \n";
    cout << "    3.  Random \n";
    do {
        cout << "\n    Enter: "; cin >> answerTask;
        switch (answerTask) {
        case 1:
            cout << "    What array do you want to use? (Static/Dynamic)" << endl;
            cout << "    If static, enter 1, else enter 2" << endl;
            cout << "    1. Static" << endl;
            cout << "    2. Dynamic" << endl;
            cout << "    Enter: "; cin >> arrayType;
            switch (arrayType) {
            case 1:
                ConsoleStaticArrayTask2(size, MAX_SIZE, A, B, C);
                break;
            case 2:
                ConsoleDynamicArrayTask2(size, MAX_SIZE, newA, newB, C);
                break;
            }
            break;

        case 2:
            cout << "    What array do you want to use? (Static)" << endl;
            cout << "    If static, press 1" << endl;
            cout << "    1. Static" << endl;
            cout << "    Enter: "; cin >> arrayType;
            switch (arrayType) {
            case 1:
                FileProccesArrayStatic_Task2(MAX_SIZE, m, fB, A, B, C);
                break;
            default:
                cout << "Try again!";
                break;
            }
            break;
        case 3:
            cout << "    What array do you want to use? (Static/Dynamic)" << endl;
            cout << "    If static, enter 1, else enter 2" << endl;
            cout << "    1. Static" << endl;
            cout << "    2. Dynamic" << endl;
            cout << "    Enter: "; cin >> arrayType;
            switch (arrayType) {
            case 1:
                RndArrayStatic_Task2(MAX_SIZE, A, B, C);
                break;//RANDOM
            case 2:
                RndArrayDynamic_Task2(MAX_SIZE, call_A, call_B, C);
                break;
            default:
                cout << "Try again!";
                break;
            }
            break;
        default:
            cout << "Try again!";
            break;
        }

    } while (answerTask <= 0 || answerTask > 3);

    return answerTask;
}
int MenuTask3(int answerTask, int MAX_SIZE_N, int size, double A[], double B[], double C[]) {
    cout << "    Menu Task 3  \n";
    cout << "    1.  Console  \n";
    cout << "    2.  Random \n";
    do {
        cout << "\n    Enter: "; cin >> answerTask;
        switch (answerTask) {
        case 1:
            ConsoleInputArrays_Task3(MAX_SIZE_N, size, A, B, C);
            break;
        case 2:
            RndInputArrays_Task3(MAX_SIZE_N, size, A, B, C);
            break;
        default:
            RndInputArrays_Task3(MAX_SIZE_N, size, A, B, C);
            cout << "Try again!";
            break;
        }

    } while (answerTask <= 0 || answerTask > 2);

    return answerTask;
}

int ShowMainMenu(int answer, int answerTask, int size, int sizeB, double A[], double B[], int MAX_SIZE,
    double fileA[], int m, int fB, double fileB[], int n, int arrayType, double *newA, double *newB, double C[],
    double *call_A, double *call_B, int MAX_SIZE_N)
{
    switch (answer)
    {
    case 1:
        MenuTask1(answerTask, size, sizeB, A, B, MAX_SIZE, fileA, m, fB, fileB, n, arrayType, newA, newB);
        break;
    case 2:
        MenuTask2(answerTask, size, arrayType, MAX_SIZE, newA, newB, A, B, C, m, fB, call_A, call_B);
        break;
    case 3:
        MenuTask3(answerTask, MAX_SIZE_N, size, A, B, C);
        break;
    default: 
        cout << "Try again!";
        break;
    }

    return answer;
}
/*-------------------------------MENU--------------------------------------------------*/

int main() {
    const int MAX_SIZE = 500, MAX_SIZE_N = 300;
    int size = 0;
    int sizeB = 0, fB = 0;
    int m = 0, n = 0;
    double A[MAX_SIZE], B[MAX_SIZE], C[MAX_SIZE], fileA[MAX_SIZE], fileB[MAX_SIZE];
    int arrayType = 0;
    int answerTasks = 0;
    int task = 0;
    double* newA, * newB, *call_A, *call_B;
    newA = new double[size];
    newB = new double[MAX_SIZE];
    call_A = (double*)calloc(size, sizeof(double));
    call_B = (double*)calloc(size, sizeof(double));

    cout << "Choose a task! Enter 1 or 2, in order to see task." << endl;
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
    do {
        cout << "\n    Enter: "; cin >> answerTasks;
        ShowMainMenu(answerTasks, task, size, sizeB, A, B, MAX_SIZE, fileA, m, fB, fileB, n, arrayType, newA, 
            newB, C, call_A, call_B, MAX_SIZE_N);
    } while (answerTasks <= 0 || answerTasks > 3);
    delete[] newA;
    delete[] newB; 

    return 1;
}