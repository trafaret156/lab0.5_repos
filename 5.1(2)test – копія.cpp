#include "../5.1(2)/5.1(2).cpp"  // шлях змінити під свій проєкт
#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include <cassert>
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

double f(double a, double b, double c)
{
    return pow(sin(a + b + c), 2) * a * b * c /
        (a * a + b * b + c * c);
}

double calcResult(double s, double t)
{
    return (f(1, pow(t, 2), s) + f(t, pow(s, 2), 1)) /
        (1 + f(1, t * s, 1) * f(1, t * s, 1));
}

namespace UnitTest
{
    TEST_CLASS(FunctionTests)
    {
    public:

        TEST_METHOD(Test_f_values)
        {
            Assert::IsTrue(fabs(f(1, 1, 1) - (pow(sin(3), 2) / 3)) < 1e-12);
            Assert::IsTrue(fabs(f(2, 3, 4) -
                (pow(sin(9), 2) * 24 / 29)) < 1e-12);
            Assert::IsTrue(fabs(f(0, 3, 4)) < 1e-12);
            Assert::IsTrue(fabs(f(2, 0, 4)) < 1e-12);
            Assert::IsTrue(fabs(f(2, 3, 0)) < 1e-12);
        }

        TEST_METHOD(Test_calcResult)
        {
            double s = 1, t = 2;

            double expected =
                (f(1, pow(t, 2), s) + f(t, pow(s, 2), 1)) /
                (1 + f(1, t * s, 1) * f(1, t * s, 1));

            Assert::IsTrue(fabs(calcResult(s, t) - expected) < 1e-12);
        }
    };
}