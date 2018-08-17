## Exercise: WindChillIndex (25 Points)

The objective of this project is to create your first C++ function and familiarize your self with creating applications from scratch.

The first thing you will need to do is fork and clone this assignment
from GitHub. Follow the instructions 
[here](https://github.com/sbcc-cs140-fall2018/HowToStartEveryProject)
to get started. 

Be sure that you fork the project first and use the URL from
the forked project when you clone it in CLion.

This assignment is based on the Programming Project 7 from Chapter 3 of the text book, _Absolute C++_, on page 139 (5th Edition). This project acted as a basis for this assignment, and as such the description here is the source of truth. Remember: when in doubt consult this assignment description.   

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

Write your implementation of the `computerWindChillIndex` in here in the `edu::sbcc::cs140` namepspace.

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
/Users/username/githubusername/cs140-ex02-windchillindex/cmake-build-debug/bin/WindChillIndex
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
/home/aknight/xormasters/cs140-ex02-windchillindex/cmake-build-debug/bin/WindChillIndex_GTest
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

At the bottom of CLion there should be a view tab labeled **Version Control**.
Select this tab at the bottom of the screen. You should see a tab called **Local Changes**.
Under **Unversion Files** you should have one file: `main.cc`.
Select these files and right-click on them. In the drop-down menu
select **Add to VCS**. Next, right-click on these files again, which should
now be under **Default** and select **Commit**. Add the appropriate
commit message and click **OK**. Finally, right click on the committed files,
select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/sbcc-cs140-fall2018/HowToSubmitEveryProject).
