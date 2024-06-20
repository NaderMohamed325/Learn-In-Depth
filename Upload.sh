#!/bin/bash

# Read commit message from input
read -p "Enter the commit message: " commit_message

# Add all changes to staging
git add .

# Sleep for 3 seconds
sleep 3

# Commit with the provided message
git commit -m "$commit_message"

# Sleep for 3 seconds
sleep 3

# Pull the latest changes
git pull

# Sleep for 3 seconds
sleep 3

# Push the changes
git push

# Sleep for 3 seconds
sleep 3

echo "Git operations completed successfully."
