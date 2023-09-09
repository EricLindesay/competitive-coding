import requests
from bs4 import BeautifulSoup
import re
from ._parser import Parser
from ._formatter import Formatter


class KattisParser(Parser):
    session: requests.Session = requests.Session()
    problem_slug: str = None
    url: str = None
    base_url: str = "https://open.kattis.com/problems/"
    description: str = None
    input: str = None
    output: str = None
    examples: str = []

    def __init__(self, problem_slug: str) -> None:
        self.problem_slug = problem_slug
        self.url = self.base_url+problem_slug
        self.parse_url()

    def get_problem_name(self) -> str:
        '''
        Get the problem name from the url.
        '''
        response = self.session.get(self.url)

        body = response.content.decode("utf-8")
        soup = BeautifulSoup(body, "html.parser")
        headline = soup.select_one("h1.book-page-heading")

        return headline.text

    def get_problem_difficulty(self) -> str:
        '''
        Get the difficulty from the url.
        '''
        response = self.session.get(self.url)

        body = response.content.decode("utf-8")
        soup = BeautifulSoup(body, "html.parser")

        if soup.select_one("span.difficulty_easy"):
            return "easy"
        if soup.select_one("span.difficulty_medium"):
            return "medium"
        if soup.select_one("span.difficulty_hard"):
            return "hard"
        return "error"

    def parse_url(self):
        '''
        Get the problem description from the url, parsed using html.
        The description is within the problembody class
        '''
        response = self.session.get(self.url)
        body = response.content.decode("utf-8")
        soup = BeautifulSoup(body, "html.parser")
        problem = soup.select_one(".problembody").text

        statementInfo = problem.split("\nInput\n")
        self.description = self.formatSection(statementInfo[0])

        # Get [description, input, output+sample]
        x = statementInfo[1].split("\nOutput\n")
        statementInfo[1] = x[0]
        statementInfo.append(x[1])
        self.input = self.formatSection(statementInfo[1])

        # Get [description, input, output, [sample]]
        x = statementInfo[2].split("\nSample Input")
        statementInfo[2] = x[0]
        self.output = self.formatSection(statementInfo[2])
        for i in x[1:]:
            self.examples.append("\nSample Input"+i)

        self.examples = self.format_examples()

    def replace_problem_description(self, fileinfo: str) -> str:
        '''
        Sets the problem description, setting the problem statement, 
        the input, the output and the examples
        '''
        # Replace the appropriate things
        fileinfo = fileinfo.replace(
            "# Description", "# Description\n"+self.description)
        fileinfo = fileinfo.replace(
            "# Input", "# Input\n"+self.input)
        fileinfo = fileinfo.replace(
            "# Output", "# Output\n"+self.output)
        fileinfo = fileinfo.replace(
            "# Examples", "# Examples\n"+"\n".join(self.examples))
        return fileinfo

    def format_examples(self) -> list[str]:
        '''
        Formats the examples
        '''
        formattedExamples = []
        for example in self.examples:
            if len(example) > 0:
                formattedExamples.append(self.format_example(example))
        return formattedExamples

    def format_example(self, example: str) -> str:
        '''
        Formats a specific example
        '''
        example = example.split("\n\n\n")
        output = f"```\nInput{example[1]}\nOutput{example[2]}\n```"
        return output

    def formatSection(self, text: str) -> str:
        '''
        Does general formatting which works for each section
        '''
        text = Formatter.fixDollars(text)
        text = Formatter.stripNewlines(text)
        text = Formatter.fixLatex(text)
        text = Formatter.fixSpaces(text)
        return text


def generateContent(fileinfo: str, problem_name: str) -> str:
    '''
    Generates the content for the readme file
    '''
    parser = KattisParser(problem_name)
    fileinfo = parser.delete_original_example(fileinfo)
    fileinfo = parser.replace_problem_description(fileinfo)
    fileinfo = parser.replace_solution_text(fileinfo)
    fileinfo = parser.replace_problem_link(fileinfo)
    fileinfo = parser.replace_problem_name(fileinfo)
    return fileinfo


if __name__ == "__main__":
    fileinfo = ""
    with open("../format/README.md") as f:
        fileinfo = f.read()

    url = "https://open.kattis.com/problems/honey"
    parser = KattisParser("honey")
    fileinfo = parser.delete_original_example(fileinfo)
    fileinfo = parser.replace_problem_description(fileinfo)
    fileinfo = parser.replace_solution_text(fileinfo)
    fileinfo = parser.replace_problem_link(fileinfo)
    fileinfo = parser.replace_problem_name(fileinfo)
    print(fileinfo)
