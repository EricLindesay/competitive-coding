# https://www.codewars.com/kata/54de279df565808f8b00126a/train/python
import re

PATTERN = re.compile(r'^0*101*010*$')

tests = [(False, " 0" ),
        (False, "abc"),
        (True,  "000"),
        (True,  "110"),
        (False, "111"),
        (True,  "{:b}".format(12345678)),
       ]

a = re.match(r'(0+101*010*)*', "1001")
print(a.group(0))