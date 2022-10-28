# =========================================================================================
# manage-github-labels.py
# =========================================================================================
# Script to check manage GitHub labels.
# =========================================================================================
import argparse
import json
from github import Github
from pprint import pprint

# =========================================================================================
# Get parameters
# =========================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-o", type=str, dest="OWNER", help="This is the GitHub owner of the repository", required=True)
parser.add_argument("-r", type=str, dest="REPOSITORY", help="This is the name of the repository", required=True)
parser.add_argument("-t", type=str, dest="TOKEN", help="Personal access token", required=True)
parser.add_argument("-f", type=str, dest="FILE", help="File name containing label JSON data", required=True)
args = parser.parse_args()

# =========================================================================================
# Get our label data from the JSON file, bail if not valid
# =========================================================================================
try:
  labelFile = open(args.FILE)
except Exception as errorMessage:
  print("Could not open " + args.FILE + ": " + str(errorMessage))
  exit()

try:
  labelData = json.load(labelFile)
except Exception as errorMessage:
  print(args.FILE + " does not contain valid JSON data: " + str(errorMessage))

# =========================================================================================
# Create GitHub object
# =========================================================================================
ourGithub = Github(args.TOKEN)

# =========================================================================================
# Get repo or bail
# =========================================================================================
try:
  repo = ourGithub.get_repo(args.OWNER + "/" + args.REPOSITORY)
except Exception as errorMessage:
  print("Could not get specified repository for owner: " + str(errorMessage))
  exit()

# =========================================================================================
# Cycle through our label list and see if it exists
# If it exists, validates it matches what's in our JSON file.
# If it does not match, update it.
# if it doesn't exist, create it.
# =========================================================================================
for label in labelData:
  gh_label = repo.get_label(label)
  if (gh_label):
    if (label == gh_label.name and labelData[label]['colour'] == gh_label.color and labelData[label]['description'] == gh_label.description):
      print(label + " is OK")
    else:
      print("Updating '" + label + "' from: Name: " + gh_label.name + ", Colour: " + gh_label.color + ", Description: '" + str(gh_label.description) + "'")
      try:
        gh_label.edit(label, labelData[label]['colour'], labelData[label]['description'])
      except Exception as errorMessage:
        print("Could not update " + label + ": " + str(errorMessage))
  else:
    print(label + " does not exist, creating")
    try:
      repo.create_label(label, labelData[label]['colour'], labelData[label]['description'])
    except Exception as errorMessage:
      print("Could not create " + label + ": " + str(errorMessage))

# =========================================================================================
# Now get all existing labels and cycle through.
# If the label is not in our JSON file, flag it.
# =========================================================================================
gh_labels = repo.get_labels()
for gh_label in gh_labels:
  if (gh_label.name not in labelData):
    print("Extra label exists: " + gh_label.name)