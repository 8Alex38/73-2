#include "pch.h"
#include "CppUnitTest.h"
#include "../73-2/73-2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73_2
{
    TEST_CLASS(UnitTest73_2)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 0; a[0][1] = 1; a[0][2] = 1;
            a[1][0] = 1; a[1][1] = 0; a[1][2] = 1;
            a[2][0] = 1; a[2][1] = 1; a[2][2] = 0;

            int count = 0;
            bool hasZero = CountPositiveAfterZero(a, rowCount, colCount, count);

            if (hasZero) {
                cout << "There are zero elements." << endl;
                cout << "Count of positive elements after zeroes = " << count << endl;
            }
            else {
                cout << "There are no zero elements." << endl;
            }

            if (count == 4) {
                cout << "Test passed: expected count = " << count << endl;
            }
            else {
                cout << "Test failed: expected count = 4, actual count = " << count << endl;
            }

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
