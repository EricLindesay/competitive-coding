#!/usr/bin/env python3

import argparse
import os


def setup_argparse() -> argparse.ArgumentParser:
    '''
    Setup argparse arguments.
    '''
    parser = argparse.ArgumentParser(
        description='Create readme template in correct directory')
    parser.add_argument('website', choices=["cf", "lc", "cw", "ka"])
    parser.add_argument('problem_name')
    parser.add_argument('problem_link')
    parser.add_argument('difficulty')
    return parser.parse_args()


if __name__ == "__main__":
    parser = setup_argparse()
    print(parser)
    website = {"cf": "codeforces",
               "lc": "leetcode",
               "cw": "codewars",
               "ka": "kattis", }

    dir = "./" + "/".join([website[parser.website],
                          parser.difficulty, parser.problem_name])

    # Make the directory
    print("Making Folder")
    print(dir)
    if not os.path.exists(f"./{website[parser.website]}/{parser.difficulty}"):
        os.mkdir(f"./{website[parser.website]}/{parser.difficulty}")
    else:
        if not os.path.exists(f"./{website[parser.website]}/{parser.difficulty}/{parser.problem_name}"):
            os.mkdir(
                f"./{website[parser.website]}/{parser.difficulty}/{parser.problem_name}")
        else:
            raise NameError("File already exists")

    # Make the README
    print("Making README")
    with open("format/README.md") as f:
        file = f.read()

    file = file.replace("problem_link", parser.problem_link)
    file = file.replace("problem_name", parser.problem_name)
    file = file.replace("solution", parser.problem_name+".cpp")

    with open(dir+"/README.md", "w") as f:
        f.write(file)

    # Copy the template cpp file
    print("Making cpp file")
    with open("format/template.cpp") as f:
        cpp_template = f.read()

    with open(dir+"/"+parser.problem_name+".cpp", "w") as f:
        f.write(cpp_template)
