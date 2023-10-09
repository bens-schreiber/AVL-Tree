#include "AVL/AVLTree.h"
#include <iostream>
#include <sstream>

#define FAIL_TEST(got, want)                                                                        \
    std::stringstream ss;                                                                           \
    ss << "\nTEST FAILED: " << __FILE__ << ":" << __LINE__ << ": got=" << got << ", want=" << want; \
    throw std::runtime_error(ss.str());

void testNullHeight()
{
    AVLTree<int> tree;

    auto got = tree.height();
    const auto want = -1;

    if (got != want)
    {
        FAIL_TEST(got, want);
    }
}

void testNullLength()
{
    AVLTree<int> tree;

    auto got = tree.length();
    const auto want = 0;

    if (got != want)
    {
        FAIL_TEST(got, want);
    }
}

void testRootHeight()
{
    AVLTree<int> tree;

    tree.insert(1);

    auto got = tree.height();
    const auto want = 0;

    if (got != want)
    {
        FAIL_TEST(got, want);
    }
}

void testRootLength()
{
    AVLTree<int> tree;

    tree.insert(1);

    auto got = tree.length();
    const auto want = 1;

    if (got != want)
    {
        FAIL_TEST(got, want);
    }
}

// Height after 3 insertions should be 1 in a balanced binary search tree.
void testBasicBSTRules()
{
    AVLTree<int> tree;

    tree.insert(2);
    tree.insert(3);
    // // tree.insert(1);
    
    auto got = tree.height();
    const auto want = 1;

    if (got != want)
    {
        FAIL_TEST(got, want);
    }
}

#define pass(got) (got == 5 || got == 6 || got == 7)

// In order to pass, we should be in the range
// [ceil(log2(n+1)), floor(1.44*log2(n+2)-.328)] which is [5, 7]
// Duplicates will screw up the height, so we should be careful to avoid them.
void testRequired1() {
    AVLTree<int> tree1;
    AVLTree<int> tree2;
    AVLTree<int> tree3;

    for (int i = 0; i < 50; i++) {
        tree1.insert(i);
        tree2.insert(i + 2 * i % 10);   // unscientifically chosen different values
        tree3.insert(i - 5 + i);
    }

    auto got = tree1.height();

    // Want is just used for the output message
    const auto want = "5 or 6 or 7";

    if (!pass(got))
    {
        FAIL_TEST(got, want);
    }

    got = tree2.height();
    if (!pass(got))
    {
        FAIL_TEST(got, want);
    }

    got = tree3.height();
    if (!pass(got))
    {
        FAIL_TEST(got, want);
    }

}

void runTests()
{
    testNullHeight();
    testNullLength();
    testRootHeight();
    testRootLength();
    testBasicBSTRules();
    testRequired1();
    std::cout << "All tests passed!" << std::endl;
}