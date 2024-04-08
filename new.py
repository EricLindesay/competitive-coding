#!/usr/bin/env python3

import argparse
import os
from parsers.kattis import KattisParser
from parsers.leetcode import LeetcodeParser
from parsers._parser import fill_content
import requests


def setup_argparse() -> argparse.ArgumentParser:
    '''
    Setup argparse arguments.
    '''
    parser = argparse.ArgumentParser(
        description='Create readme template in correct directory\n \
                     Leetcode and Kattis uses the problem slug\n \
                     Codeforces uses name, link, difficulty\
                     ')
    # parser.add_argument('website', choices=["cf", "lc", "cw", "ka"])
    parser.add_argument('-ka', '--kattis', nargs=1, action="store")
    parser.add_argument('-cf', '--codeforces', nargs=3, action="store")
    parser.add_argument('-lc', '--leetcode', nargs=1, action="store")
    parser.add_argument('-cw', '--codewars', nargs=3, action="store")
    # parser.add_argument('website', choices=["cf", "lc", "cw", "ka"])
    # parser.add_argument('problem_name')
    # parser.add_argument('problem_link')
    # parser.add_argument('difficulty')
    return parser.parse_args()


def parse_args(parser) -> dict[str: str]:
    parsed = {"website": "",
              "problem_name": "",
              "problem_link": "",
              "difficulty": "",
              }
    if parser.kattis:
        parsed["website"] = "kattis"
        parsed["problem_name"] = parser.kattis[0]
        parsed["problem_link"] = "https://open.kattis.com/problems/" + \
            parsed["problem_name"]
        parsed["difficulty"] = KattisParser(
            parsed["problem_name"]).get_problem_difficulty()
        return parsed
    elif parser.leetcode:
        parsed["website"] = "leetcode"
        parsed["problem_name"] = parser.leetcode[0]
        parsed["problem_link"] = "https://leetcode.com/problems/" + \
            parsed["problem_name"]
        parsed["difficulty"] = LeetcodeParser(
            parsed["problem_name"]).get_problem_difficulty()
        return parsed

    data = None
    if parser.codeforces:
        parsed["website"] = "codeforces"
        data = parser.codeforces
        if int(data[2]) <= 1000:
            data[2] = "easy"
    if parser.codewars:
        parsed["website"] = "codewars"
        data = parser.codewars

    parsed["problem_name"] = data[0]
    parsed["problem_link"] = data[1]
    parsed["difficulty"] = data[2]

    return parsed


def generateContent(file, parsed):
    file = file.replace("problem_link", parsed['problem_link'])
    file = file.replace("problem_name", parsed['problem_name'])
    file = file.replace("solution", parsed['problem_name']+".cpp")
    return file


def makeReadme(parser):
    print("Making README")

    # read the format
    with open("format/README.md") as f:
        file = f.read()

    # fill in the content
    if parsed['website'] == "kattis":  # custom parser for kattis
        try:
            file = fill_content(
                file, KattisParser(parsed['problem_name']))
        except Exception as e:       # if there is any exception, just parse it normally
            print("ERROR - ", e)
            generateContent(file, parsed)
    elif parsed['website'] == "leetcode":  # custom parser for kattis
        # try:
        file = fill_content(
            file, LeetcodeParser(parsed['problem_name']))
        # except Exception as e:       # if there is any exception, just parse it normally
        # print("ERROR - ", e)
        # generateContent(file, parsed)
    else:
        generateContent(file, parsed)

    # write the file
    with open(dir+"/README.md", "w") as f:
        f.write(file)


if __name__ == "__main__":
    parser = setup_argparse()
    print(parser)
    website = {"cf": "codeforces",
               "lc": "leetcode",
               "cw": "codewars",
               "ka": "kattis", }

    parsed = parse_args(parser)

    dir = "./" + "/".join([parsed["website"],
                          parsed["difficulty"], parsed["problem_name"]])

    # Make the directory
    print("Making Folder")
    print(dir)
    if not os.path.exists(f"./{parsed['website']}/{parsed['difficulty']}"):
        os.mkdir(f"./{parsed['website']}/{parsed['difficulty']}")
    else:
        if not os.path.exists(f"./{parsed['website']}/{parsed['difficulty']}/{parsed['problem_name']}"):
            os.mkdir(
                f"./{parsed['website']}/{parsed['difficulty']}/{parsed['problem_name']}")
        else:
            raise NameError("File already exists")

    # Make the README
    makeReadme(parsed)

    # Copy the template cpp file
    print("Making cpp file")
    if parsed["website"] == "leetcode":
        with open("format/leetcodeTemplate.cpp") as f:
            cpp_template = f.read()

        cpp_template = LeetcodeParser(
            parsed["problem_name"]).format_template(cpp_template)
    else:
        with open("format/template.cpp") as f:
            cpp_template = f.read()

    with open(dir+"/"+parsed['problem_name']+".cpp", "w") as f:
        f.write(cpp_template)
