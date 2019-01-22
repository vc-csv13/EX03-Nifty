## Exercise: WindChillIndex (25 Points)

TThe objective of this project is to create your first C++ function and familiarize your self with creating applications from scratch.
 
 The first thing you will need to do is fork and clone this assignment
 from GitHub.  
 
 Be sure that you fork the project first and use the URL from
 the forked project when you clone it in CLion.
 
 In cold weather, meteorologists report an index called the wind chill factor , which
 takes into account the wind speed and the temperature. The index provides a
 measure of the chilling effect of wind at a given air temperature. Wind chill may
 be approximated by the following formula,
 
 ![Wind Chill Index](https://github.com/sbcc-cs140/Course-Information/wiki/images/windchillindex.png)
 
 where
 
 _v_ = wind speed in m/sec \
 _t_ = temperature in degrees Celsius: _t_ <= 10 \
 _w_ = wind chill index (in degrees Celsius)
 
 Write a function that returns the wind chill index. Your code should ensure that
 the restriction on the temperature is not violated. Look up some weather reports
 in back issues of a newspaper in your library and compare the wind chill index you
 calculate with the result reported in the newspaper.
 
### Writing the code for this Project

Writing the code for this project is very simple. You will create three files: a header and implementation of a function, and an implementation of main to test your personally test your code.

#### computeWindChillIndex

This function will compute the wind chill index (and return it as a `double`) based on two input parameters (of type `double`), the current temperature, in C, and the wind speed in m/s. This index is valid only for temperatures below 10 degrees C, inclusive. If the temperature is greater than that, then the function should return -1 to indicate invalid input.

To create this function you'll need a header file with a declaration so it can be used in other code, and an implementation file with the C++ code of this function.

##### windchillindex.h

First you'll need to create windchillindex.h. This is the only file that must be named exactly this. If you misspell, or use differenct capitalization, the test program will not compile.

In CLion in the project explorer, right-click the `include` directory
and chose `New => C++ Header File`. 

Under **Name** fill in
windchillindex. CLion will add the `.h` extension. Press **OK**. You should now see the file `windchillindex.h` in
the project explorer in the `include` directory.

Write your declaration of the `computerWindChillIndex` in here in the `edu::sbcc::cs140` namepspace.

##### Implementation

Next you'll need to create the implementation, separately from the declaration, of the computeWindChillIndex. This can be done in any file in the `src` directory as long as it has the extension `.cc` and is not named `main.cc`. 

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`. 

Under **Name** fill in
windchillindex (or any other name besides `main`). CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `windchillindex.cc` (or whatever you named the file) in
the project explorer in the `src` directory.

Write your implementation of the `computerWindChillIndex` in here in the `edu::vcccd::vc::csv13` namepspace.

#### main()

If you want to test this code yourself, without using the unit tests, which I recommend for at least the first few projects, then you will need to create a `main()` function in a file named `main.cc` in the `src` directory. It is very important that you name it exactly this way, or things might not compile properly.

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`. 

Under **Name** fill in
main. CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `main.cc` in
the project explorer in the `src` directory.

Your main function should look something like this:

```cpp
#include "windchillindex.h"

int main() {
  // Put your code here that calls computeWindChillIndex with some valid input and write the result to the terminal.
  
  return 0;
}
```

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `WindChillIndex | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

```bash
/Users/username/githubusername/ex02-windchillindex/cmake-build-debug/bin/WindChillIndex
The wind chill index is: 11.5

Process finished with exit code 0
```
Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `WindChillIndex_Gtest` and press the 
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
/home/aknight/xormasters/ex02-windchillindex/cmake-build-debug/bin/WindChillIndex_GTest
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from WindChillIndexTest
[ RUN      ] WindChillIndexTest.Basic
[       OK ] WindChillIndexTest.Basic (0 ms)
[ RUN      ] WindChillIndexTest.TemperatureOutOfRange
[       OK ] WindChillIndexTest.TemperatureOutOfRange (0 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 2 tests from WindChillIndexTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.

Process finished with exit code 0

```

Remember, You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

Before submitting your code the first time, you will need to add a webhook to this project to trigger the build in the cloud. This process is simple, and only required once per assignment. First, go to the **Settings** tab at the top of this page. It's right next to **Insights**. Then along the left side select **Webhooks**. On the Webhooks page click **Add Webhook** and copy http://209.129.49.16:8080/github-webhook/ into the **Payload URL** input box and then click **Add Webhook**. That's it. Every time you push code now, a new build will test your latest changes. The results are pasted to the #build channel in slack.

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `main.cc`. Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked, but committing will take longer. Leave `Run git hooks` unchecked as well. Put a message in `Commit Message` and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.
 
Finally, right click on the project name, then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will then submit them to the cloud to have the tests run for grading. You can find your results
in the [#build](https://vc-csv13-spring2019.slack.com/messages/CFBKTRAAU) channel on slack.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/vc-csv13-spring2019/Course-Information/wiki/How-to-Turn-In-Every-Project).
