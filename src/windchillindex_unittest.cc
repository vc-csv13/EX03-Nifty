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

#include <random>

#include "windchillindex.h"

#include "gtest/gtest.h"
namespace {

double computeWindChillIndexMaster(double temperature, double windVelocity) {
    if (temperature > 10.0) return -1.0;

    return 33.0 - ((10.0 * sqrt(windVelocity) - windVelocity + 10.5) * (33.0 - temperature)) / 23.1;
}

using edu::vcccd::vc::csv13::computeWindChillIndex;

// Tests edu::sbcc:cs140::String.

using std::istringstream;
using std::ostringstream;
using std::string;

using namespace ::testing_internal;

class WindChillIndexTest : public ::testing::Test {
protected:
    static const uint MAX_TESTED_SCORE = 20;
    static const uint MAX_OVERALL_SCORE = 25;
    static uint _testScore;

protected:
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

uint WindChillIndexTest::_testScore = 0;

TEST_F(WindChillIndexTest, Basic) {
    // This test is named "Identity", it checks that the basic identity
    // complex number, i, has the correct values for real and imaginary
    // parts.

    std::default_random_engine generator;
    std::uniform_int_distribution<int32_t> tempDistribution(-10,10);
    std::uniform_int_distribution<int32_t> velocityDistribution(0,100);

    int32_t temperature = tempDistribution(generator);
    int32_t velocity = velocityDistribution(generator);

    ASSERT_DOUBLE_EQ(computeWindChillIndexMaster(temperature, velocity),
                     computeWindChillIndex(temperature, velocity));

    temperature = tempDistribution(generator);
    velocity = velocityDistribution(generator);
    ASSERT_DOUBLE_EQ(computeWindChillIndexMaster(temperature, velocity),
                     computeWindChillIndex(temperature, velocity));

    temperature = tempDistribution(generator);
    velocity = velocityDistribution(generator);
    ASSERT_DOUBLE_EQ(computeWindChillIndexMaster(temperature, velocity),
                     computeWindChillIndex(temperature, velocity));

    _testScore += 10;
}

TEST_F(WindChillIndexTest, TemperatureOutOfRange) {
    // This test is named "Identity", it checks that the basic identity
    // complex number, i, has the correct values for real and imaginary
    // parts.

    std::default_random_engine generator;
    std::uniform_int_distribution<int32_t> tempDistribution(11,100);
    std::uniform_int_distribution<int32_t> velocityDistribution(0,10);

    int32_t temperature = tempDistribution(generator);
    int32_t velocity = velocityDistribution(generator);

    ASSERT_DOUBLE_EQ(computeWindChillIndexMaster(temperature, velocity),
                     computeWindChillIndex(temperature, velocity));

    temperature = tempDistribution(generator);
    velocity = velocityDistribution(generator);
    ASSERT_DOUBLE_EQ(computeWindChillIndexMaster(temperature, velocity),
                     computeWindChillIndex(temperature, velocity));

    temperature = tempDistribution(generator);
    velocity = velocityDistribution(generator);
    ASSERT_DOUBLE_EQ(computeWindChillIndexMaster(temperature, velocity),
                     computeWindChillIndex(temperature, velocity));

    _testScore += 10;
}

}