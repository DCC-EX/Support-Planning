# Testing Processes

To support releasing quality code with less bugs up front, we need to ensure sufficient unit and regression testing is performed prior to releases. In addition, testing provides an opportunity to detect documentation deficiencies, with the output of testing providing information to documenters to address these gaps.

While we can't test for all the use cases possible with the flexibility DCC++ EX provides, we can test the core functions and should test as much of the automation functions as possible.

The ideal way to approach this is to provide some pre-written automation files that contain a step by step testing sequence to follow with each release for regression testing, with bug fixes and new features providing extra unit testing to validate the outcome is as desired.

If any regression or unit tests can be fully automated, with sufficient output being made available to validate the testing outputs, then this should be an acceptable form of testing.

However, given that our end users are humans, we must ensure sufficient manual testing is performed to ensure we don't compromise the end user experience, particularly for Conductor level users who will desire as much "plug and play" as possible.

Each stream of the DCC++ EX project will have a folder, containing unit and regression testing processes, with myAutomation.h and myHal.cpp files where appropriate.

## Regression Testing

Regression testing is to be performed prior to any new release, and must test all core functionality of the CommandStation (including EX-RAIL), plus functionality of the various commonly used and supported accessories such as I/O extenders, along with WiThrottle apps, Engine Driver, and core JMRI support.

The regression testing process needs to have:

- A specific list of items to be tested outlining the commands or methods used to perform each test.
- Details of the expected outputs for each test.
- A list of hardware required to perform testing.
- A myAutomation.h file with automation sequences, ROUTE, and TURNOUT directives associated with specific test steps where applicable.
- A myHal.cpp file configured to load device drivers for the devices to be tested (this should be based on the most recent version of myHal.cpp_example.txt).
- A way to capture the testing output, defining who tested what, and the detailed output of each test.

In addition, regression testing should include a review of documentation related to each test.

At the successful completion of regression testing, the issue must have the "Regression Tested" label added, and if any documentation deficiencies are noted, an issue should be raised to address these including suitable details and the label "Needs Documentation".

Given not every team member will have all required hardware to perform the complete regression test, regression testing will need to be distributed across the team, however anyone assisting with testing should complete as many tests as possible to ensure consistency across different hardware variations.

## Unit Testing

Each bug fix or new feature must be accompanied by a unit test to validate that the bug is indeed fixed, or that the new feature functions as expected.

Unit testing should be completed prior to regression testing leading to a new release, and detailed information relating to unit tests will assist documenters in capturing sufficient information to update website documentation.

Each unit test should have:

- For bug fixes, detailed symptoms experienced when encountering the bug, and steps to reproduce (this should idealy come from the initial bug report).
- For new features, details of what the feature does, including commands or methods to utilise the feature, and what the output or result should be.
- Where appropriate, a myAutomation.h file configured to perform the test.
- Where appropriate, a myHal.cpp file configured to load any required device drivers.
- A way to capture the testing output, defining who tested, and the detailed output of the test.

At the successful completion of unit testing, the issue must have the "Unit Tested" label added along with "Needs Documentation" to ensure any documentation on the website is updated or added.
