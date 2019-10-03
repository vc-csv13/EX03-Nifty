## Exercise: Nifty (25 Points)

The objective of this project is to create your first C++ function and familiarize your self with creating applications from scratch and reading data from files.
 
### Problem Description

This problem is based on a “Nifty Assignment” by Steve Wolfman 
([http://nifty.stanford.edu/2006/wolfman-pretid](http://nifty.stanford.edu/2006/wolfman-pretid)). 
Consider lists of numbers from real-life data sources, for example, a 
list containing the number of students enrolled in different course 
sections, the number of comments posted for different Facebook status 
updates, the number of books in different library holdings, the number 
of votes per precinct, etc. It might seem like the leading digit of each 
number in the list should be 1–9 with an equally likely probability. 
However, Benford’s Law states that the leading digit is 1 about 30% of 
the time and drops with larger digits. The leading digit is 9 only about 
5% of the time. 

Write a program that tests Benford’s Law. Collect a list of at least one 
hundred numbers from some real-life data source and enter them into a 
text file. Your pro-gram should loop through the list of numbers and 
count how many times 1 is the first digit, 2 is the first digit, etc. 
For each digit, output the percentage it appears as the first digit. If 
you read a number into the string variable named strNum then you can 
access the first digit as a char by using strNum[0]. This is described 
in more detail in Chapter 9.  

### Getting Started

The first thing you will need to do is accept the invitation to this 
assignment from GitHub Classroom. You can click 
[here](https://classroom.github.com/a/CQ2ZmmJ2) to accept the 
invitation, and get started.

Be sure that you accept the invitation first and use the URL to your new project when you clone it in CLion. After copying
the URL into the clipboard, in CLion click **VCS -> Checkout from Version Control -> Git**. Paste the URL into the **URL** box of the _Clone Repository_ dialog box and press **Clone**.

### Writing the code for this Project

In CLion in the project explorer, right-click the `src` directory
and chose `New => C/C++ Source File`. 

![Adding source file](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki/images/03_new_source_file.png)

Under **Name** fill in
main. CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `main.cc` in
the project explorer in the `src` directory.

Copy and paste the following code into this file over any
contents that may already be in the `main.cc` file.

```cpp
/**
 * CS V30 Beginning C++
 * Assignment: Nifty
 * 
 * Statement of code ownership: I hereby state that I have written all of this
 * code and I have not copied this code from any other person or source.
 * 
 * @author [CHANGE THIS TO YOUR INFORMATION]
 */

#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]) {
    // Put your code for this project here.
    return 0;
}
```

Now go through **main.cc** and change the [CHANGE THIS TO YOUR INFORMATION] text to your name and email address.

Next, write your code that prints a string to the console with the computed letter size in `int main` between the curly braces.

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `Nifty [population] | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

Using the test input, your output should look like:

```
/tmp/tmp.iJP6dUckGb/cmake-build-debug/../bin/Nifty population_data.csv
 0:   0	 0.0%
 1: 807	28.9%
 2: 425	15.2%
 3: 392	14.0%
 4: 273	 9.8%
 5: 259	 9.3%
 6: 187	 6.7%
 7: 150	 5.4%
 8: 158	 5.7%
 9: 143	 5.1%

Process finished with exit code 0
```

Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the target `All in Nifty Test | Debug` and press the 
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Testing started at 8:33 PM ...
/tmp/tmp.iJP6dUckGb/cmake-build-debug/../bin/Nifty_GTest --gtest_filter=* --gtest_color=no
Running main() from gtest_main.cc

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.


Process finished with exit code 0
```

### Pushing your code to GitHub

Now you need to turn in your code by sending, or pushing, your code to GitHub. You created a 
GitHub repository when you started the assignment. Now you need to take your local code changes
and send them to GitHub so that you can turn it in and have it graded in the next step in the
work flow.

The first step is to commit your code locally. This tell git what files you want to turn in. In 
this case you only need to turn in the contents of `main.cc`. In the Project view, right-
click **EX03-Nifty** and then select **Git -> Commit Directory...**. In the dialog box that
pops up, be sure only `main.cc` is selected and that there is some text in the _Commit 
Message_ box. A good commit message would be something like `Committing code to get a good grade`.

Once the commit is finished, which is a purely local action, you need to send that commit to 
GitHub. This is called the push phase of the process. Again right-click on **EX03-Nifty**.
Then select **Git -> Repository -> Push**. In the dialog box that pops up, push the **Push** button
and that should be it. You should see a message that says the push was successful. In the next
step you'll confirm that your code is working and then submit it for a grade.

### Turning in and Grading your code

Go back to LazyGrader and login again, if needed. Press the _Build_ button next to 
**EX03-Nifty** for this course. This will send a command to Jenkins to download your code
from GitHub and test it. If all goes well and all the tests pass, the ball next to the _Build_
will turn blue. If some of the tests don't pass the ball will be yellow. If the ball is grey,
that means you have not run the tests before and your project is not ready for grading.

Once the Jenkins status is blue or yellow, press the _Grade_ button for **EX03-Nifty**.
This will read the results from Jenkins and send your grade to Canvas. Once the notification in 
LazyGrader says the grade has been posted, you should see your grade on Canvas.

That's it, once you've submitted your grade, you are done. I will add points later, after I
inspect your code. For example, most projects will be out of a total of 25 points, but after 
pressing the _Grade_ button, Canvas will show 20 points. I will add up to 5 points after I have
looked at your code and am conviced it is original.
