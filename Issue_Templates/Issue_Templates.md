# Issue Templates

GitHub issues can be raised using templates, which ensures users are prompted to provide sufficient information when creating issues, as well as allowing the correct labels to be added to issues on creation.

Issue templates use markdown formatting.

If issue templates are created in a repository in the organisation called ".github", they will be available by default across all repositories, unless a locally defined one overrides it.

# Proposed Templates

The templates in this folder are proposed as defaults for all repositories, and are written as generically as possible.

If a specific template is required for a specific repository, it should be created locally in the repository in a folder called ".github/ISSUE_TEMPLATE".

An example of a use case for local templates would be Beta testing reports, which are going to be very specific for the software being tested.

## Proposed Global Templates

- `bug_report.md` is designed to capture all relevant information relating to a reported bug, with the "Bug" label added.
- `feature_request.md` is designed to capture information relating to a requested new feature or enhancement, with the "Enhancement" label added.
- `support_request.md` is to capture all information to help users raise a support request, with the "Support Request" label added.
- `to_do.md` is to raise a general "To Do" issue that needs to be done, with the "To Do" label added.
