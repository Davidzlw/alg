#include <algorithm>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define MAX_NUM 100005
#define ll long long int
#define for1(a, b, c) for (int a = b; a < c; a++)
#define for12(a, b, c) for (int a = b; a < c; a += 2)
#define for2(a, b, c) for (int a = b; a > c; a--)
// #define DEBUG 1
using namespace std;

struct Node {
    int id;
    int value;
    Node(int _id, int _value) : id(_id), value(_value) {}
};

vector<int> topoSort(int n, vector<vector<int>> prerequisites);

void test_toposort();
