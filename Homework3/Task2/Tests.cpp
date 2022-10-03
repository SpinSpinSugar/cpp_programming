#include "gtest/gtest.h"
#include "generic_sort.h"

TEST (ComparatorINT, Less_int1) {
    int* rhs = new int(1);
    int* lhs = new int(2);
    EXPECT_EQ(true, generic_sort_utility::less_int(rhs, lhs));
    delete rhs;
    delete lhs;
}

TEST (ComparatorINT, Less_int2) {
    void* rhs = reinterpret_cast<void*>(new int(1));
    void* lhs = reinterpret_cast<void*>(new int(2));
    EXPECT_EQ(false, generic_sort_utility::less_int(lhs, rhs));
    delete reinterpret_cast<int*>(rhs);
    delete reinterpret_cast<int*>(lhs);
}

TEST (ComparatorINT, Greater_int1) {
    int* lhs = new int(1);
    int* rhs = new int(2);
    EXPECT_EQ(false, generic_sort_utility::greater_int(lhs, rhs));
    delete rhs;
    delete lhs;
}


TEST (ComparatorINT, Greater_int2) {
    void* rhs = reinterpret_cast<void*>(new int(1));
    void* lhs = reinterpret_cast<void*>(new int(2));
    EXPECT_EQ(true, generic_sort_utility::greater_int(lhs, rhs));
    delete reinterpret_cast<int*>(rhs);
    delete reinterpret_cast<int*>(lhs);
}

TEST (ComparatorDOUBLE, Less_double1) {
    void* rhs = reinterpret_cast<void*>(new double(141.276905));
    void* lhs = reinterpret_cast<void*>(new double(131.259235));
    EXPECT_EQ(true, generic_sort_utility::less_double(lhs, rhs));
    delete reinterpret_cast<int*>(rhs);
    delete reinterpret_cast<int*>(lhs);
}

TEST(Sort_C_style_Array, BubbleSortLess) {
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    generic_sort(a, 10, sizeof(int), generic_sort_utility::less_int, generic_sort_utility::bubble_sort);
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(Sort_C_style_Array, BubbleSortGreater) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    generic_sort(a, 10, sizeof(int), generic_sort_utility::greater_int, generic_sort_utility::bubble_sort);
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(Sort_std_vector, BubbleSortLess) {
    std::vector<int> a = {1, 8, 7, 6, 5, 4, 11, 2, 3};
    std::vector<int> b = {1, 2, 3, 4, 5, 6, 7, 8, 11};
    generic_sort(&a[0], a.size(), sizeof(int), generic_sort_utility::less_int, generic_sort_utility::bubble_sort);
    for (int i = 0; i < b.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(Sort_forward_list, BubbleSortLess) {
    std::forward_list<int> a = { 2, 7, 85, 5, 234, -1, -53};
    std::forward_list<int> b = { -53, -1, 2, 5, 7, 85, 234};
    //a.sort();
    generic_sort(a);
    for (auto it1 = a.begin(), it2 = b.begin(), end = a.end(); it1 != end; ++it1, ++it2) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(Sort_forward_list, BubbleSortGreater) {
    std::forward_list<int> a = { 2, 7, 85, 5, 234, -1, -53};
    std::forward_list<int> b = { 234, 85, 7, 5, 2, -1, -53};
    //a.sort();
    generic_sort(a, std::greater<>{});
    for (auto it1 = a.begin(), it2 = b.begin(), end = a.end(); it1 != end; ++it1, ++it2) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(Sort_list, BubbleSortGreater) {
    std::list<int> a = { 2, 7, 85, 5, 234, -1, -53};
    std::list<int> b = { 234, 85, 7, 5, 2, -1, -53};
    //a.sort();
    generic_sort(a, std::greater<>{});
    for (auto it1 = a.begin(), it2 = b.begin(), end = a.end(); it1 != end; ++it1, ++it2) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(VectorDouble, BubbleSortLess) {
    std::vector<double> a = {-86.9461, -24.8448, -8.60054, -29.9357, 29.366, -17.5306, -20.669, 36.5845, 95.5222, -37.7526, -34.5154, 35.22, 62.8502, 68.7074, -4.41375};
    std::vector<double> b = {-86.9461, -37.7526, -34.5154, -29.9357, -24.8448, -20.669, -17.5306, -8.60054, -4.41375, 29.366, 35.22, 36.5845, 62.8502, 68.7074, 95.5222};
    generic_sort(&a[0], a.size(), sizeof(double), generic_sort_utility::less_double, generic_sort_utility::bubble_sort);
    for (int i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(VectorDouble, BubbleSortGreater) {
    std::vector<double> a = {78.7132, -92.3725, -84.3915, -26.6891, 64.5827, -96.5416, 80.9848, -32.6963, 60.7098, 77.5085, 87.1699, 88.694, -30.4095, 69.9029, 26.1305};
    std::vector<double> b = {88.694, 87.1699, 80.9848, 78.7132, 77.5085, 69.9029, 64.5827, 60.7098, 26.1305, -26.6891, -30.4095, -32.6963, -84.3915, -92.3725, -96.5416};
    generic_sort(&a[0], a.size(), sizeof(double), generic_sort_utility::greater_double, generic_sort_utility::bubble_sort);
    for (int i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(VectorDouble, InsertionSortGreater) {
    std::vector<double> a = {-16.3804, 10.5909, -68.7876, 75.0118, -76.2725, 63.3533, -93.8843, -60.7794, 48.562, -30.4251, -16.1979, 74.029, 78.1098, -75.2846, -27.2093};
    std::vector<double> b = {78.1098, 75.0118, 74.029, 63.3533, 48.562, 10.5909, -16.1979, -16.3804, -27.2093, -30.4251, -60.7794, -68.7876, -75.2846, -76.2725, -93.8843};
    generic_sort(&a[0], a.size(), sizeof(double), generic_sort_utility::greater_double, generic_sort_utility::insertion_sort);
    for (int i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(VectorDouble, InsertionSortLess) {
    std::vector<double> a = {-39.8566, -33.3523, -75.5703, -25.5723, 4.88974, -58.6797, -6.26231, -41.7875, -69.4038, -11.2306, 44.66, 2.21693, -92.6633, 30.3065, -52.4292};
    std::vector<double> b = {-92.6633, -75.5703, -69.4038, -58.6797, -52.4292, -41.7875, -39.8566, -33.3523, -25.5723, -11.2306, -6.26231, 2.21693, 4.88974, 30.3065, 44.66};
    generic_sort(&a[0], a.size(), sizeof(double), generic_sort_utility::less_double, generic_sort_utility::insertion_sort);
    for (int i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}