#!/usr/bin/env python3

import re
import argparse

def setup_argparse():
    parser = argparse.ArgumentParser(description='Fix codeforces README files automatically')
    parser.add_argument('-d, --dir', dest="path", help="The directory of the file to change. Changes dir/README.md")
    parser.add_argument('-f, --file', dest="file", help="The file that you want to fix")
    return parser.parse_args()


if __name__ == "__main__":
    # get the path
    # no args = ./README.md
    # -d <directory> = specified dir/README.md
    # -f <file> = specified file
    parser = setup_argparse();
    print(parser.path)
    print(parser.file)
    
    path = parser.path or "./"
    file = parser.file or "README.md"
    filepath = path+file
    
    lines = []

    with open(filepath, "r") as f:
        lines = f.readlines()

    with open(filepath, "w") as f:
        for line in lines:
            r = re.sub("inputCopy", "Input", line)
            r = re.sub("outputCopy", "Output", r)
            f.write(r)



