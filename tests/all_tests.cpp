#include <iostream>
#include <string>

#define TEST(X)                                                     \
    std::cout << "Running test: " << #X << std::endl;               \
    if (X(argc, argv)) {                                            \
        std::cout << "Test: " << #X << " succeeded." << std::endl;  \
    }                                                               \
    else {                                                          \
        success = false;                                            \
        std::cerr << "Test: " << #X << " failed!" << std::endl;     \
    }

//*************************************************************************************************
int main(int argc, char* argv[]) {
    bool success = true;

    // Add tests here.
    //TEST(sc2::TestRendered);

    if (success)
        std::cout << "All tests succeeded!" << std::endl;
    else
        std::cerr << "Some tests failed!" << std::endl;

    //if (sc2::IsInDebugger()) {
        //// When debugging, this prevents the console from disappearing before it can be read.
        //std::cout << "Hit any key to exit..." << std::endl;
        //while (!sc2::PollKeyPress());
    //}

    return success ? 0 : -1;
}
