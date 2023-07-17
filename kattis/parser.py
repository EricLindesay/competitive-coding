import requests
from bs4 import BeautifulSoup
import re


def getProblemDescription(url: str, session) -> str:
    '''
    Get the problem description from the url, parsed using html.
    The description is within the problembody class
    '''
    response = session.get(url)

    body = response.content.decode("utf-8")
    soup = BeautifulSoup(body, "html.parser")
    problem = soup.select_one(".problembody")

    return problem.text


def getProblemName(url: str, session) -> str:
    '''
    Get the problem name from the url.
    '''
    response = session.get(url)

    body = response.content.decode("utf-8")
    soup = BeautifulSoup(body, "html.parser")
    headline = soup.select_one("h1.book-page-heading")

    return headline.text


def getProblemDifficulty(url: str, session) -> str:
    '''
    Get the difficulty from the url.
    '''
    response = session.get(url)

    body = response.content.decode("utf-8")
    soup = BeautifulSoup(body, "html.parser")

    if soup.select_one("span.difficulty_easy"):
        return "easy"
    if soup.select_one("span.difficulty_medium"):
        return "medium"
    if soup.select_one("span.difficulty_hard"):
        return "hard"
    return "error"


def setProblemName(url: str, session, fileinfo: str) -> str:
    '''
    Set the problem name in the readme
    '''
    problem_name = getProblemName(url, session)

    # Find the place in fileinfo to put the name
    return fileinfo.replace("problem_name", problem_name)


def setProblemLink(url: str, fileinfo: str) -> str:
    '''
    Set the problem link in the readme
    '''
    return fileinfo.replace("problem_link", url)


def fixDollars(text: str) -> str:
    '''
    Set the dollars as ` since $ represents latex which I want formatted with `.
    This does have issues if the problem has a $ in it's description however 
    thats a risk I'm willing to take.
    '''
    p = re.compile(r'[\$|\＄]')
    text = p.sub(r'`', text)
    return text


def fixLatex(text: str) -> str:
    '''
    Latex is something like \le and we want that to be <=.
    The latexTranslations file contains the representation of the latex. 
    '''
    # go through each traslation and translate it if it is present
    with open("latexTranslations.txt") as f:
        for line in f.readlines():
            latex, translation = line.strip().split("|")
            p = re.compile(f'\{latex}')  # escape the first backslash
            text = p.sub(f'{translation}', text)
    return text


def stripNewlines(text: str) -> str:
    '''
    If there is a newline followed by atleast three whitespace characters
    or a tab, remove them. Kattis just does formatting like this so remove it
    '''
    p = re.compile(r'\n[\s\s\s|\t]')
    text = p.sub(r'', text)
    return text


def fixSpaces(text: str) -> str:
    '''
    If there are multiple spaces in a row, replace them with one space
    '''
    p = re.compile(r'\ +')
    text = p.sub(r' ', text)
    return text


def formatSection(text: str) -> str:
    '''
    Does general formatting which works for each section
    '''
    text = fixDollars(text)
    text = stripNewlines(text)
    text = fixLatex(text)
    text = fixSpaces(text)
    return text


def deleteOriginalExample(text: str) -> str:
    return text.replace("```\nInput\na b c\nOutput\nc b a\n```", "")


def formatExamples(examples: list[str]) -> list[str]:
    '''
    Formats the examples
    '''
    formattedExamples = []
    for example in examples:
        if len(example) > 0:
            formattedExamples.append(formatExample(example))
    return formattedExamples


def formatExample(example: str) -> str:
    '''
    Formats a specific example
    '''
    example = example.split("\n\n\n")
    output = f"```\nInput{example[1]}\nOutput{example[2]}\n```"
    return output


def setProblemDescription(url: str, session, fileinfo: str) -> str:
    '''
    Sets the problem description, setting the problem statement, 
    the input, the output and the examples
    '''
    statement = getProblemDescription(url, session)

    # the line in the statement which is the description is everything up to \nInput\n
    info = {"description": "", "input": "", "output": "", "sample": [""]}
    # Get [description, input+output+sample]
    statementInfo = statement.split("\nInput\n")
    info["description"] = formatSection(statementInfo[0])

    # Get [description, input, output+sample]
    x = statementInfo[1].split("\nOutput\n")
    statementInfo[1] = x[0]
    statementInfo.append(x[1])
    info["input"] = formatSection(statementInfo[1])

    # Get [description, input, output, [sample]]
    x = statementInfo[2].split("\nSample Input")
    statementInfo[2] = x[0]
    info["output"] = formatSection(statementInfo[2])
    for i in x[1:]:
        info["sample"].append("\nSample Input"+i)

    info["sample"] = formatExamples(info["sample"])

    # Replace the appropriate things
    fileinfo = fileinfo.replace(
        "# Description", "# Description\n"+info["description"])
    fileinfo = fileinfo.replace(
        "# Input", "# Input\n"+info["input"])
    fileinfo = fileinfo.replace(
        "# Output", "# Output\n"+info["output"])
    fileinfo = fileinfo.replace(
        "# Examples", "# Examples\n"+"\n".join(info["sample"]))
    return fileinfo


def setSolution(solutionName: str, fileinfo: str) -> str:
    '''
    Sets the solution name
    '''
    return fileinfo.replace("solution", solutionName+".cpp")


def generateContent(fileinfo: str, url: str, problem_name: str) -> str:
    '''
    Generates the content for the readme file
    '''
    session = requests.Session()
    fileinfo = deleteOriginalExample(fileinfo)
    fileinfo = setSolution(problem_name, fileinfo)
    fileinfo = setProblemName(url, session, fileinfo)
    fileinfo = setProblemLink(url, fileinfo)
    fileinfo = setProblemDescription(url, session, fileinfo)
    return fileinfo


if __name__ == "__main__":
    fileinfo = ""
    with open("../format/README.md") as f:
        fileinfo = f.read()

    url = "https://open.kattis.com/problems/honey"
    session = requests.Session()
    fileinfo = setSolution("name", fileinfo)
    fileinfo = setProblemName(url, session, fileinfo)
    fileinfo = setProblemLink(url, session, fileinfo)
    fileinfo = setProblemDescription(url, session, fileinfo)
    print(fileinfo)
