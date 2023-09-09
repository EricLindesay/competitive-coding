# Access Denied
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](problem_link)

### Description
Computer passwords have been around for a long time. In fact, 60 years ago CTSS was one of the first computers with a password. The implementation of this was very simple. In CTSS the password was stored in plain text in a file on disk. When logging in, the user would enter a password. The computer would then compare the password to the password on disk. If the comparison failed, it would deny access, if it succeeded, access would be allowed. Researchers at MIT were quick to discover several security flaws in this password system. We will explore one of them, the timing attack.

In a timing attack, we exploit that we can deduce a computation path from the time it takes to do the computation. In CTSS the password check was done using a simple string matching algorithm, similar to this:

bool CheckPassword(string pwd1, string pwd2) {
    if (pwd1.Length != pwd2.Length) {
        return false;
    }
    for (int i = 0; i < pwd1.Length; i++) {
        if (pwd1[i] != pwd2[i]) {
            return false;
        }
    }
    return true;
}

For the purpose of this problem, we will use a (very) simplified timing model and the above algorithm. The timing model looks as follows:

    A branching statement (if or for) takes 

ms.

An assignment, or update of a memory address takes

ms.

A comparison between two memory addresses takes

ms.

A return statement takes

    ms.

The password consists of between
and English letters, upper or lower case, and digits.

### Input

### Output

### Examples
```
Input
a b c
Output
c b a
```

## Solution

[solution](./solution)