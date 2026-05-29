
#include "disk_manager.h"
#include <iostream> // to remove

int main() {
    DiskManager dm("test.db");
    std::cout << "DiskManager constructed without crashing\n";
    return 0;
}