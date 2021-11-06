#include <iostream>
#include <list>
#include <numeric>
#include <iterator>

using namespace std;

void print_list(const list<double>& list_numbers) {
	copy(list_numbers.begin(), list_numbers.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
}

void add_average(list<double>& list_numbers) {
	double average = accumulate(list_numbers.begin(), list_numbers.end(), 0.0) / list_numbers.size();
	list_numbers.push_back(average);
}

class MATRIX
{
private:
    int** M; 
    int row; 
    int column; 

public:
    MATRIX(int _row, int _column)
    {
        row = _row;
        column = _column;

        M = (int**) new int * [row]; 

        for (int i = 0; i < row; ++i) {
            M[i] = (int*)new int[column];
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                M[i][j] = 0;
            }
        }
    }
    
    void Set_Matrix_ij(int i, int j, int value)
    {
        if ((i < 0) || (i >= row))
            return;
        if ((j < 0) || (j >= column))
            return;
        M[i][j] = value;
    }

    void Print_Matrix(const char* Matrix_Name)
    {
        cout << "Matrix: " << Matrix_Name << endl;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << endl;
    }

    int Determinant() {
        int determ = 0;

        if (row < 1 || row != column || row > 3) {
            cout << "The determinant cannot be calculated!";
            return -1;
        }
        if (row == 1) {
            determ = M[0][0];
            return(determ);
        }
        if (row == 2) {
            determ = M[0][0] * M[1][1] - M[1][0] * M[0][1];
            return(determ);
        }
        if (row == 3) {
            determ = M[0][0] * M[1][1] * M[2][2] + M[2][0] * M[0][1] * M[1][2] + M[1][0] * M[2][1] * M[0][2] 
            - M[2][0] * M[1][1] * M[0][2] - M[0][0] * M[2][1] * M[1][2] - M[1][0] * M[0][1] * M[2][2];
            return(determ);
        }
    }
    
    ~MATRIX()
    {
        if (column > 0)
        {
            for (int i = 0; i < row; ++i)
                delete[] M[i];
        }

        if (row > 0)
            delete[] M;
    }
};

class TestIterator {
private:
    int* m_ptr;
    int  m_current;
    int m_capacity;

public:
    TestIterator(int capacity) {
        m_current = 0;
        m_capacity = capacity;
        m_ptr = new int[m_capacity];
    }

    void AddNumber(int num) {
        m_ptr[m_current] = num;
        ++m_current;
    }

    int* begin() {
        return &m_ptr[0];
    }

    int* end() {
        return &m_ptr[m_current];
    }

    ~TestIterator() {
        delete m_ptr;
    }
};


int main() {
    //Lesson1
    cout << "Lesson 1:" << endl;
    list<double> list_numbers{ 45.12, 34.125, 0.564, 11.02, 20.89, 25.32 };
    print_list(list_numbers);
    add_average(list_numbers);
    print_list(list_numbers);
    cout << endl;

    //Lesson2
    cout << "Lesson 2:" << endl;

    MATRIX Matrix1(1,1);
    Matrix1.Set_Matrix_ij(0, 0, 1);
    Matrix1.Print_Matrix("1x1");
    cout << "Determinat = " << Matrix1.Determinant() << endl << endl;

    MATRIX Matrix2(2, 2);
    Matrix2.Set_Matrix_ij(0, 0, 1);
    Matrix2.Set_Matrix_ij(0, 1, 2);
    Matrix2.Set_Matrix_ij(1, 0, 3);
    Matrix2.Set_Matrix_ij(1, 1, 4);
    Matrix2.Print_Matrix("2x2");
    cout << "Determinat = " << Matrix2.Determinant() << endl << endl;

    MATRIX Matrix3(3, 3);
    Matrix3.Set_Matrix_ij(0, 0, 1);
    Matrix3.Set_Matrix_ij(0, 1, 2);
    Matrix3.Set_Matrix_ij(0, 2, 3);
    Matrix3.Set_Matrix_ij(1, 0, 4);
    Matrix3.Set_Matrix_ij(1, 1, 5);
    Matrix3.Set_Matrix_ij(1, 2, 6);
    Matrix3.Set_Matrix_ij(2, 0, 7);
    Matrix3.Set_Matrix_ij(2, 1, 8);
    Matrix3.Set_Matrix_ij(2, 2, 9);
    Matrix3.Print_Matrix("3x3");
    cout << "Determinat = " << Matrix3.Determinant() << endl << endl;
        
    //Lesson3
    cout << "Lesson 3:" << endl;

    TestIterator test(10);
    test.AddNumber(4);
    test.AddNumber(6);
    test.AddNumber(11);
    test.AddNumber(3);
    test.AddNumber(9);
    test.AddNumber(46);

    for (auto i : test) {
        cout << i << " ";
    }
    cout << endl;

	return 0;
}