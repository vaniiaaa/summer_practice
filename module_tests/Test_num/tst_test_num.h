#ifndef TST_TEST_NUM_H
#define TST_TEST_NUM_H
#include "..\nums\chisla.h"

#include <QtTest>

class TestNums: public QObject
{
    Q_OBJECT

private slots:
    // -- setup/cleanup --


    // -- tests data --
    void testNod_data();
    void testNok_data();
    void testSimple_data();
    void testArm_data();
    // -- tests --
    void testNok();
    void testNod();
    void testSimple();
    void testArm();
private:
    const int A0 = 0;
    const int B0 = 0;

private:
    number a,b;
};

#endif // TST_TEST_NUM_H
