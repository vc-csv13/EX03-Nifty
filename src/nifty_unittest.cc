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

#include "gtest/gtest.h"

namespace {

using std::istringstream;
using std::ostringstream;
using std::string;

using namespace ::testing_internal;

class NiftyFixture : public ::testing::Test {
protected:
    static const uint MAX_TESTED_SCORE = 20;
    static const uint MAX_OVERALL_SCORE = 25;
    static uint _testScore;
    int _parent_read;
    int _parent_write;



protected:
    std::string GetLine(int fd) {
        char buffer[BUFSIZ];
        //memset(buffer, 0, BUFSIZ);

        for (int total = 0, read = 1; read > 0; total += read) {
            read = ::read(_parent_read, buffer + total, 1);
            if (buffer[total] == '\n') break;
        }

        return std::string(buffer);
    }

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

            execl("./Nifty", "./Nifty", "../population_data.csv", NULL);
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

uint NiftyFixture::_testScore = 0;

TEST_F(NiftyFixture, Population) {
    // This test is named "Positive", and belongs to the "HelloWorld"
    // test case.
    int EXPECTED_RESULTS[][3] = {{0,   0,  10},
                                 {1, 800, 100},
                                 {2, 425, 100},
                                 {3, 375,  75},
                                 {4, 275,  75},
                                 {5, 250,  75},
                                 {6, 180,  50},
                                 {7, 160,  50},
                                 {8, 155,  25},
                                 {9, 140,  25}};

    for (int i = 0; i < 10; i++) {
        std::string result = GetLine(_parent_read);
        std::regex regex("(\\d)[\\D]+([\\d]+)[\\D]+([\\d]+(\\.[\\d]+%)?)");
        std::smatch match;
        if (std::regex_search(result, match, regex)) {
            int digit = std::stoi(match[0].str());
            int variance = abs(EXPECTED_RESULTS[i][1] - std::stoi(match[2].str()));
            EXPECT_EQ(EXPECTED_RESULTS[i][0], digit);
            EXPECT_GE(EXPECTED_RESULTS[i][2], variance);
            bool succeeded = (digit == EXPECTED_RESULTS[i][0]) && (EXPECTED_RESULTS[i][2] >= variance);
            _testScore += succeeded ? 2 : 0;
        } else {
            std::cerr << "No match for row " << (i + 1) << std::endl;
        }
    }
}

}