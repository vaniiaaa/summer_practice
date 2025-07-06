#include "tst_test_num.h"



// -- tests data --
void TestNums::testNod_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<int>("result");

    QTest::newRow("5 10 5") << 5 << 10 << 5;
    QTest::newRow("10 10 10") << 10 << 10 << 10;
    QTest::newRow("10 110 10") << 10 << 110 << 10;
    QTest::newRow("10 23 1") << 10 << 23 << 1;

}
void TestNums::testNok_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<int>("result");

    QTest::newRow("5 10 10") << 5 << 10 << 10;
    QTest::newRow("10 10 10") << 10 << 10 << 10;
    QTest::newRow("10 123 10") << 10 << 123 << 1230;
    QTest::newRow("7 5 35") << 7 << 5 << 35;

}
void TestNums::testSimple_data()
{
    QTest::addColumn<int>("x");


    QTest::newRow("5") << 5;

    QTest::newRow("7") << 7;


}
void TestNums::testArm_data()
{
    QTest::addColumn<int>("x");

    QTest::newRow("5") << 5;

    QTest::newRow("1") << 1;
    QTest::newRow("153") << 153;

}

// -- tests --


void TestNums::testNod()
{
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(int, result);
    a = x; b = y;
    QCOMPARE(a.nod(b), result);
}
void TestNums::testNok()
{
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(int, result);
    a = x; b = y;
    QCOMPARE(a.nok(b), result);
}
void TestNums::testSimple()
{
    // retrieve data
    QFETCH(int, x);

    // set values
    a = x;
    if (!a.is_Armstrong()) {
        QFAIL("Number is not simple");
    }
    // test
    QVERIFY(a.IsSimple());
}
void TestNums::testArm()
{
    // retrieve data
    QFETCH(int, x);


    // set values
    a = x;
    if (!a.is_Armstrong()) {
        QFAIL("Number is not arm");
    }
    // test
    QVERIFY(a.is_Armstrong());


}


// generate basic main: no GUI, no events
QTEST_APPLESS_MAIN(TestNums)

// uncomment next line if class declaration is in .cpp (no .h)
//#include "TestNums.moc"

