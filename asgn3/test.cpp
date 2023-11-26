#include "Chaining.h"
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "CubicProbing.h"
#include "Comp.h"
#include <cassert>

void testDatabase(BaseClass *db) {
    db->createAccount("Alice", 1000);
    db->createAccount("Bob", 1500);
    db->createAccount("Charlie", 2000);

    assert(db->getBalance("Alice") == 1000);
    assert(db->getBalance("Bob") == 1500);
    assert(db->getBalance("Charlie") == 2000);

    db->addTransaction("Alice", -200);
    db->addTransaction("Bob", 300);
    db->addTransaction("Charlie", -400);

    assert(db->getBalance("Alice") == 800);
    assert(db->getBalance("Bob") == 1800);
    assert(db->getBalance("Charlie") == 1600);

    std::vector<int> topBalances = db->getTopK(2);
    assert(topBalances.size() == 2);
    assert(topBalances[0] == 1800);
    assert(topBalances[1] == 1600);

    assert(db->databaseSize() == 3);

    assert(db->doesExist("Alice"));
    assert(!db->doesExist("Eve"));
}


int main() {
    Chaining chainingDB;
    LinearProbing linearProbingDB;
    QuadraticProbing quadraticProbingDB;
    CubicProbing cubicProbingDB;
    Comp compDB;

    std::cout << "Testing Chaining:" << std::endl;
    testDatabase(&chainingDB);

    std::cout << "\nTesting Linear Probing:" << std::endl;
    testDatabase(&linearProbingDB);

    std::cout << "\nTesting Quadratic Probing:" << std::endl;
    testDatabase(&quadraticProbingDB);

    std::cout << "\nTesting Cubic Probing:" << std::endl;
    testDatabase(&cubicProbingDB);

    std::cout << "\nTesting Comp:" << std::endl;
    testDatabase(&compDB);
    return 0;
}
