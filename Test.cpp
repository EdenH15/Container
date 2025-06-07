//
// Created by eden on 6/5/25.
// Edenhassin@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.h"
using namespace Container;

// Test the default template type of MyContainer (should be int)
TEST_CASE("Default type of MyContainer is int") {
    MyContainer<> defaultContainer;  // no template parameter
    defaultContainer.addElement(1);
    defaultContainer.addElement(2);
    CHECK((defaultContainer.size() == 2));
}

// Test adding, removing, and throwing on missing element
TEST_CASE("Basic container operations") {
    MyContainer<int> container;

    // Check initial size is zero
    CHECK((container.size() == 0));

    // Add elements
    container.addElement(5);
    container.addElement(10);
    container.addElement(3);

    // Check size after additions
    CHECK((container.size() == 3));

    // Remove existing element
    container.removeElement(10);
    CHECK((container.size() == 2));

    // Remove non-existent element should throw
    CHECK_THROWS_AS(container.removeElement(99), std::runtime_error);
}

// Check AscendingIterator produces sorted order
TEST_CASE("AscendingIterator order") {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(2);
    container.addElement(5);

    std::vector<int> expected = {2, 5, 7};
    std::vector<int> actual;

    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));
}

// Check DescendingIterator produces reversed sorted order
TEST_CASE("DescendingIterator order") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(4);
    container.addElement(3);

    std::vector<int> expected = {4, 3, 1};
    std::vector<int> actual;

    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));
}

// Check SideCrossIterator alternates smallest/largest
TEST_CASE("SideCrossIterator order") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(5);
    container.addElement(7);
    container.addElement(9);

    std::vector<int> expected = {1, 9, 3, 7, 5};
    std::vector<int> actual;

    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));
}

// Check ReverseIterator goes backwards by insertion order
TEST_CASE("ReverseIterator order") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    std::vector<int> expected = {30, 20, 10};
    std::vector<int> actual;

    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));
}

// Check OrderIterator returns elements in insertion order
TEST_CASE("OrderIterator order (insertion)") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    std::vector<int> expected = {5, 2, 8};
    std::vector<int> actual;

    for (auto it = container.begin_order(); it != container.end_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));
}

// Check MiddleOutIterator starts at middle and alternates outwards
TEST_CASE("MiddleOutIterator order") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);

    std::vector<int> expected = {30, 40, 20, 50, 10};
    std::vector<int> actual;

    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));
}

// Check all iterators are empty when container is empty
TEST_CASE("Edge cases: empty container iterators") {
    MyContainer<int> empty;

    CHECK((empty.size() == 0));

    CHECK((empty.begin_order() == empty.end_order()));
    CHECK((empty.begin_ascending_order() == empty.end_ascending_order()));
    CHECK((empty.begin_side_cross_order() == empty.end_side_cross_order()));
    CHECK((empty.begin_descending_order() == empty.end_descending_order()));
    CHECK((empty.begin_reverse_order() == empty.end_reverse_order()));
    CHECK((empty.begin_middle_out_order() == empty.end_middle_out_order()));

    // Dereferencing any begin should throw
    CHECK_THROWS_AS(*empty.begin_ascending_order(), std::out_of_range);
    CHECK_THROWS_AS(*empty.begin_reverse_order(), std::out_of_range);
    CHECK_THROWS_AS(*empty.begin_middle_out_order(), std::out_of_range);
}

// Test the container with std::string type instead of int
TEST_CASE("Container with std::string") {
    MyContainer<std::string> names;
    names.addElement("Alice");
    names.addElement("Bob");
    names.addElement("Eden");

    // Check size
    CHECK((names.size() == 3));

    // Check ascending order
    std::vector<std::string> expected = {"Alice", "Bob", "Eden"};
    std::vector<std::string> actual;
    for (auto it = names.begin_ascending_order(); it != names.end_ascending_order(); ++it)
        actual.push_back(*it);
    CHECK((actual == expected));

    // Check reverse order (insertion)
    actual.clear();
    for (auto it = names.begin_reverse_order(); it != names.end_reverse_order(); ++it)
        actual.push_back(*it);
    CHECK((actual == std::vector<std::string>{"Eden", "Bob", "Alice"}));

    // Remove a name and check again
    names.removeElement("Bob");
    CHECK((names.size() == 2));
    CHECK_THROWS_AS(names.removeElement("yovel"), std::runtime_error);
}
