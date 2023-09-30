#!/usr/bin/env python3

import argparse
import re
import os


def printable_readme(dir: str) -> bool:
    # A readme is printable if it isn't in the root directory and it isn't in the first directory (e.g in ./codeforces)
    return len(dir.split("/")) > 2


def from_website(website: str, dir: str) -> bool:
    return dir.find(website) > 0


def problem_solved(dir: str) -> bool:
    '''
    Determines whether a problem is solved or not.

    A problem is solved if it contains the string "Solved!".
    '''
    with open(dir+"/README.md", "r") as f:
        read_file = f.read()
    return re.search("Solved!", read_file)


def setup_argparse() -> argparse.ArgumentParser:
    '''
    Setup argparse arguments.
    '''
    parser = argparse.ArgumentParser(description='List challenges')
    parser.add_argument('--completed',
                        dest="complete",
                        action="store_true",
                        help="List completed challenges")
    parser.add_argument('-a, --all',
                        dest="all",
                        action="store_true",
                        help="List completed and incomplete challenges")
    parser.add_argument('-i, --incomplete',
                        dest="incomplete",
                        action="store_true",
                        help="List incomplete challenges")
    parser.add_argument('-lc',
                        dest="leetcode",
                        action="store_true",
                        help="List leetcode challenges")
    parser.add_argument('-cf',
                        dest="codeforces",
                        action="store_true",
                        help="List codeforces challenges")
    parser.add_argument('-cw',
                        dest="codewars",
                        action="store_true",
                        help="List codewars challenges")
    parser.add_argument('-ka',
                        dest="kattis",
                        action="store_true",
                        help="List kattis challenges")
    return parser.parse_args()


if __name__ == "__main__":
    parser = setup_argparse()

    sites = ["codeforces", "codewars", "kattis", "leetcode"]

    # show_incomplete is on by default
    show_incomplete = parser.incomplete or parser.all or not parser.complete
    show_complete = parser.complete or parser.all
    show_site = [parser.codeforces, parser.codewars,
                 parser.kattis, parser.leetcode]
    # If they don't specify a site, show all of them
    if not any(show_site):
        show_site = [True, True, True, True]

    dirs = [root
            for root, dirs, files in os.walk("./")  # look in subfolders
            for name in files
            if name == "README.md" and printable_readme(root)]  # if the folder contains a README.md, we want it.

    complete_problems = {"codeforces": [],
                         "leetcode": [],
                         "kattis": [],
                         "codewars": [], }
    incomplete_problems = {"codeforces": [],
                           "leetcode": [],
                           "kattis": [],
                           "codewars": [], }

    for dir in dirs:
        for site in sites:
            if from_website(site, dir):
                if problem_solved(dir):
                    complete_problems[site].append(dir)
                    break
                else:
                    incomplete_problems[site].append(dir)
                    break

    if show_complete:
        num_complete = 0;
        for i in range(0, len(sites)):
            if show_site[i]:
                num_complete += len(complete_problems[sites[i]])

        print(f"{num_complete} Completed Problems: ")
        for i in range(0, len(sites)):
            if show_site[i]:
                print("\n".join(complete_problems[sites[i]]))

    if show_incomplete:
        if show_complete:
            print("")  # print a newline for formatting

        num_incomplete = 0;
        for i in range(0, len(sites)):
            if show_site[i]:
                num_incomplete += len(incomplete_problems[sites[i]])

        print(f"{num_incomplete} Incomplete Problems:")
        for i in range(0, len(sites)):
            if show_site[i]:
                print("\n".join(incomplete_problems[sites[i]]))

