// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX02-WindChillIndex in CSV13 at Ventura College.
//
// Author: aknight@vcccd.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <cmath>
#include <regex>
#include <ext/stdio_filebuf.h>

#include "gtest/gtest.h"
namespace {

// Tests edu::sbcc:cs140::String.

using std::istringstream;
using std::ostringstream;
using std::string;

using namespace ::testing_internal;

#define SQRT_REGEX "[\\d]+(\\.[\\d]+)?\\s*$"

class BabylonianSquareRootFixture : public ::testing::Test {
protected:
    static const uint MAX_TESTED_SCORE = 20;
    static const uint MAX_OVERALL_SCORE = 25;
    static uint _testScore;
    int _parent_read;
    int _parent_write;

protected:
    void SetUp() override {
        int writepipe[2] = {-1, -1};
        int readpipe[2] = {-1, -1};

        if (pipe(readpipe) < 0 || pipe(writepipe) < 0) {
            return;
        }

        _parent_read  = readpipe[0];
        int child_write  = readpipe[1];
        int child_read   = writepipe[0];
        _parent_write = writepipe[1];

        pid_t childpid = fork();
        if (childpid < 0) {
            return;
        }

        if (childpid == 0) {
            // Child process, set up redirects and execute student code
            close(_parent_write);
            close(_parent_read);

            dup2(child_read, STDIN_FILENO);
            dup2(child_write, STDOUT_FILENO);

            close(child_read);
            close(child_write);

            execl("./BabylonianSquareRoot", "./BabylonianSquareRoot", NULL);
        } else {
            close(child_read);
            close(child_write);
        }
    }

    static void TearDownTestCase() {
        if (_testScore == MAX_TESTED_SCORE) {
            std::cout << std::endl << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << std::endl;
        } else {
            std::cout << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                      << ")" << std::endl;
        }

        std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                  << " where the remaining points" << std::endl;
        std::cout << "comes from grading related to documentation, algorithms, and other"
                  << std::endl;
        std::cout << "criteria." << std::endl << std::endl;
    }
};

uint BabylonianSquareRootFixture::_testScore = 0;

TEST_F(BabylonianSquareRootFixture, SquareRoot2) {
    // This test is named "Positive", and belongs to the "HelloWorld"
    // test case.

    __gnu_cxx::stdio_filebuf<char> in(_parent_read, std::ios::in); // 1
    std::istream child_in(&in);

    __gnu_cxx::stdio_filebuf<char> out(_parent_write, std::ios::out); // 1
    std::ostream child_out(&out);

    child_out << "2" << std::endl;

    std::string prompt;
    std::getline(child_in, prompt);
    std::regex square_regex(SQRT_REGEX);
    std::smatch match;
    if (std::regex_search(prompt, match, square_regex)) {
        EXPECT_STREQ("1.41421", match.str().c_str());
        _testScore += 4;
    } else {
        std::cerr << "No match for square root of 2" << std::endl;
    }
}

TEST_F(BabylonianSquareRootFixture, SquareRoot16) {
        // This test is named "Positive", and belongs to the "HelloWorld"
        // test case.

        __gnu_cxx::stdio_filebuf<char> in(_parent_read, std::ios::in); // 1
        std::istream child_in(&in);

        __gnu_cxx::stdio_filebuf<char> out(_parent_write, std::ios::out); // 1
        std::ostream child_out(&out);

        child_out << "16" << std::endl;

        std::string prompt;
        std::getline(child_in, prompt);
        std::regex square_regex(SQRT_REGEX);
        std::smatch match;
        if (std::regex_search(prompt, match, square_regex)) {
            EXPECT_STREQ("4", match.str().c_str());
            _testScore += 5;
        } else {
            std::cerr << "No match for square root of 16" << std::endl;
        }
    }

    TEST_F(BabylonianSquareRootFixture, SquareRoot625) {
        // This test is named "Positive", and belongs to the "HelloWorld"
        // test case.

        __gnu_cxx::stdio_filebuf<char> in(_parent_read, std::ios::in); // 1
        std::istream child_in(&in);

        __gnu_cxx::stdio_filebuf<char> out(_parent_write, std::ios::out); // 1
        std::ostream child_out(&out);

        child_out << "625" << std::endl;

        std::string prompt;
        std::getline(child_in, prompt);
        std::regex square_regex(SQRT_REGEX);
        std::smatch match;
        if (std::regex_search(prompt, match, square_regex)) {
            EXPECT_STREQ("25.2973", match.str().c_str());
            _testScore += 6;
        } else {
            std::cerr << "No match for square of 625" << std::endl;
        }
}

TEST_F(BabylonianSquareRootFixture, SquareRootNegative) {
    // This test is named "Positive", and belongs to the "HelloWorld"
    // test case.

    __gnu_cxx::stdio_filebuf<char> in(_parent_read, std::ios::in); // 1
    std::istream child_in(&in);

    __gnu_cxx::stdio_filebuf<char> out(_parent_write, std::ios::out); // 1
    std::ostream child_out(&out);

    child_out << "-2" << std::endl;

    std::string prompt;
    std::getline(child_in, prompt);
    std::regex square_regex("-?[\\d]+\\s*$");
    std::smatch match;
    if (std::regex_search(prompt, match, square_regex)) {
        EXPECT_STREQ("-1", match.str().c_str());
        _testScore += 5;
    } else {
        std::cerr << "No match for square of 625" << std::endl;
    }
}
}