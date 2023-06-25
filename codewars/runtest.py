#!/usr/bin/env python3
import argparse
import time
import importlib
from contextlib import contextmanager
import sys, os

@contextmanager
def suppress_stdout():
    with open(os.devnull, "w") as devnull:
        old_stdout = sys.stdout
        sys.stdout = devnull
        try:  
            yield
        finally:
            sys.stdout = old_stdout


def read_testfile(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()

    function = ""
    parameters = []
    for line in lines:
        line = line.strip()
        if not function:
            function = line.split('\n')
        else:
            parameters.append(line.split(','))

    return function[0], parameters


def function_call(function: str, parameters: list) -> str:
    function_to_run = function+"("
    for parameter in parameters:
        function_to_run += parameter+','
    function_to_run = function_to_run[:-1]
    function_to_run += ")"
    return function_to_run


def display_time_comparison(filenames: list, times: list):
    zip_times = list(zip(list(filenames), times))
    sorted_times = sorted(zip_times, key=lambda x: x[1])
    print(f' {"filename":^20} | {"average time":^25} | {"% better":^10}')
    print("-"*65)
    for ind, stime in enumerate(sorted_times):
        if ind+1 < len(sorted_times):
            percentage = (sorted_times[ind+1][1]/stime[1]-1)*100
            print(f" {stime[0]:^20} | {stime[1]:^25} | {percentage:^10}%")
        else:
            print(f" {stime[0]:^20} | {stime[1]:^25} |")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Run test scripts')
    parser.add_argument('testfile', help="the file containing the tests to run")
    parser.add_argument('files', help="the files to run the tests on", nargs="+")
    parser.add_argument('-a, --all', dest="show_all", action='store_true', help="show the result of each individual test")
    args = parser.parse_args()
    print(args)
    
    function, parameters_list = read_testfile(args.testfile)

    all_times = []
    for file in args.files:
        times = []
        if args.show_all:
            print(f"FILE: {file}")
        module = importlib.import_module(file)
        for parameters in parameters_list:
            function_to_run = function_call(function, parameters)

            start_time = time.time()
            with suppress_stdout(): # don't print to console when running these commands
                eval(f"module.{function_to_run}")
            time_taken = time.time()-start_time
            times.append(time_taken)

            if args.show_all:
                print(f"{function_to_run} took {time_taken} seconds")
        
        average = sum(times)/len(times)
        all_times.append(average)
        if args.show_all:
            print("-----------\n")

    print("sorted best to worst\n")

    display_time_comparison(list(args.files), all_times)



