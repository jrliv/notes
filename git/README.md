# Git Commands and Notes

## Set up git

    git config

## Get help with git

    git help

Displays the most common git commands and also shows other options for getting help.

## Create a git repository or reinitialize an existing one

    git init

## Create and push a new repository

    git init
    git add *
    git commit -m "Initial commit"
    git remote add origin https://github.com/username/repo.git
    git push -u origin master

## Push an existing repository

    git remote add origin https://github.com/username/repo.git
    git push -u origin master

## Copy a remote repository into a new local directory

    git clone https://github.com/username/repo

## Copy a gist into a new local directory

Create or find the existing gist to copy.

Click the drop down button that says "Embed" then click "Clone via SSH" from the list.

Click the Copy to clipboard button or select the string and copy it.

In terminal enter **git clone** then paste the gists address that was copied previously.

    git clone git@gist.github.com:shaaddresshere.git

## Check the status of a repository

    git status

## Check if local repo is up to date with remote

    git fetch --dry-run
    git status

## Pull changes from a remote repository to a local one

    git pull -u origin master

## Create a project page using GH Pages

Create repository for project then commit and push everything.

Create a directory called **project** or **dist** and add an **index.html** file. Add and commit the changes.

    git add project
    git commit -am "Add project page"
    git subtree push -prefix project origin gh-pages

## Ignore files and folders in a repository

Create a .gitignore file and add files and folders that you want to be ignored.

    touch .gitignore

## Find my own gists

*This note is for GitHub and gists. I figured this would be the best place to put it for now.

To search and find my own gists I have to navigate to gist site and type in search term but don't hit Enter. Leave the term in the search box and a list of related gists will drop down showing starred gists vs. my own.