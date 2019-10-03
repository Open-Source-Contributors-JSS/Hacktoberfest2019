#!/bin/sh

# Usage : move all mp4 files with removing extension

# Command to run : 
# ./move_all_files_with_diff_name.sh <source_folder> <destination_folder> 

# Command structure
# find . -name "*.mp4" 
# normal find command 
# find <loc to search> -name <files to search>

# -exec : execute the next command
# sh -c : execute as a shell script

# 'mv "$0" "${0%.*}"' '{}' ';' 
# 'command "input" "inputModification"' '{input}' ';'

find . -name "*.mp4" -exec sh -c 'mv "$0" "${0%.*}"' '{}' ';'
