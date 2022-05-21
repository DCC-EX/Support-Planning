# DCC++ EX GitHub Project Workflow Process and Automation

A [DCC++ EX](https://github.com/orgs/DCC-EX/projects/7) project has been created to faciliate a single view of all activities relating to the DCC++ EX project.

This uses the new Beta Projects feature, meaning it is tied to the organisation rather than specific repositories, enabling better views across the entire organisation.

In addition to this, we use consistent automated build processes across the various repositories to ensure that uploaded software compiles successfully using PlatformIO.

# Workflows

GitHub workflows are available to automate associating issues and pull requests with the project based on various criteria, and these workflows need to be added to each repository in the organisation.

These workflows require a GitHub App to be created and installed within the organisation, with suitable secrets stored as organisation secrets. **Note** that the free tier of GitHub does not allow private repositories to access organisation secrets, and therefore private repositories will require equivalent repository secrets to be created.

All required workflows must reside in the ".github/workflows" directory, and use YAML syntax.

The build test workflow also must reside in this directory for repositories that require it. This should apply to any repository that is to be compiled via PlatformIO or the Arduino IDE to ensure we release software that at least compiles. Proper regression testing combined with these automated builds should ensure we only release quality software.

## Labels in Workflows

When copying the below workflows to a new repository, a repository secret called "PROJECT_STREAM_LABEL" needs to be added to ensure the repository is associated with the correct stream for the project.

The label added as part of that particular step of the job should reflect the stream of work the repository relates to:

* CommandStation-EX
* Installer-EX
* WebThrottle-EX
* Documentation
* Hardware
* Turntable-EX

Refer to [GitHub Labels](https://github.com/DCC-EX/Support-Planning/blob/master/Processes/GitHub_Labels.md) for the defined list of labels.

Note that while environment variables are the logical place for labels, private repositories on the free tier do not have this option, hence the use of a secret instead.

### Setting the PROJECT_STREAM_LABEL Repository Secret

1. Navigate to the "Settings" tab of the repository in GitHub.
2. Under "Security", expand "Secrets", and select "Actions".
3. If there is an existing repository secret called "PROJECT_STREAM_LABEL", then it is already set. Note that you cannot view secrets, so you will need to use "Update" to set the value.
4. If the secret does not exist, select "New repository secret".
5. Enter "PROJECT_STREAM_LABEL" as the Name, and add the label in the Value field.
6. Click "Add secret" to add the label as a secret.

## New Items Workflow

`new-items.yml` is the workflow file that takes any issue or pull request created in the local repository, and associates it with the Project, with the appropriate labels to populate the appropriate views on the project board.

**Be sure to set the repository secret** relevant to the repository that the workflow is associated with when copying the workflows as per the above process, according to [GitHub Labels](https://github.com/DCC-EX/Support-Planning/blob/master/Processes/GitHub_Labels.md).

## Build Test Workflow

`build-test-workflow.yml` is the workflow file that uses PlatformIO to perform a test build for all platforms supported in the local repository, which is to be executed on commits and pull requests to ensure compilation succeeds.

# GitHub Project

The GitHub Project has been configured to enable the built-in workflows in a way that suits how we need that workflow to operate, as well as letting the workflow items above override with the appropriate status for various items.

In addition, various views have been configured to help the team view only what's relevant to them, as well as be able to provide a holistic overall project view at a glance.

## Project Views

Various project views have been created to allow team members to have an overview of items relevant to themselves, the team they are a member of, or a particular stream of work.

### Project Overview

All items in the project in a Kanban view with no filters.

### Turntable-EX

A Kanban view of all items relating to the Turntable-EX project stream, which is populated based on the "Turntable-EX" label.

### Documenters

A Kanban view of all items of interest for documentation team members, which is populated based on the labels "Documentation", "Needs Documentation", and "Documented".

### My Items

A Kanban view of a team member's items for a personal view, which is populated by the "@me" filter, and is therefore always in the context of the logged in GitHub user.

## Project Workflow Configuration

All default workflows in the GitHub project have been, with adjustments to suit our needs.

- Item added to project: Enabled, status set to Backlog.
- Item reopened: Enabled, default settings.
- Item closed: Enabled, default settings.
- Code changes requested: Enabled, status set to Needs Review.
- Code review approved: Enabled, default settings.
- Pull request merged: Enabled, default settings.

# GitHub App and Permissions

To support the workflows above to integrate with the GitHub project, a GitHub App has been deployed with the required permissions as outlined below.

Organisation secrets have been configured to provide the authentication required, and these have also been configured in private repositories, as organisation secrets are not available to private repositories on the free GitHub tier.

## GitHub App - DCC-EX Project Workflow App

The GitHub App "DCC-EX Project Workflow App" has been created with the bare minimum privileges required to enable the project workflows to succeed.

The app requires very little configuration, with the configured settings outlined below, and all other settings undefined:

Setting | Value
--------|-------
GitHub App Name | DCC-EX Project Workflow App
Homepage URL | https://dcc-ex.com/
Repository access | All repositories

The below permissions have been granted:

### Repository Permissions

Item | Access
-----|-------
Issue | Read-only
Metadata | Read-only
Pull requests | Read-only

### Organisation Permissions

Item | Access
-----|-------
Projects | Read and write

## Organisation and Repository Secrets

In order for the project workflows to succeed, two organisation secrets are required to be configured, and these secrets also need to be configured in each private repository as per the free tier limitations of GitHub.

Secret Name | Value
-----------|--------
PROJECT_APP_ID | App ID as displayed in the app settings
PROJECT_APP_KEY | Complete contents of the private key (.PEM file) associated with the app
