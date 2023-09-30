import re


class Formatter:

    def format_html_tags(text: str) -> str:
        text = text.replace("<p>", "")
        text = text.replace("</p>", "")
        text = text.replace("<code>", "`")
        text = text.replace("</code>", "`")
        text = text.replace("<em>", "*")
        text = text.replace("</em>", "*")
        text = text.replace("<strong>", "**")
        text = text.replace("</strong>", "**")
        text = text.replace("<pre>", "```")
        text = text.replace("</pre>", "```")
        text = text.replace("<ul>", "")
        text = text.replace("</ul>", "")
        text = text.replace("<li>", "- ")
        text = text.replace("</li>", "")
        text = text.replace("<sup>", "^")
        text = text.replace("</sup>", "")
        text = text.replace("<u>", "**")
        text = text.replace("</u>", "**")
        return text

    def fix_ampersands(text: str) -> str:
        text = text.replace("&nbsp;", " ")
        text = text.replace("&quot;", "\"")
        text = text.replace("&lt;", "<")
        text = text.replace("&le;", "<=")
        text = text.replace("&gt;", ">")
        text = text.replace("&ge;", ">=")
        text = text.replace("&#39;", "\'")
        return text

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
        p = re.compile(r'\n[\s\s|\t]+')
        text = p.sub(r' ', text)
        return text

    def fixSpaces(text: str) -> str:
        '''
        If there are multiple spaces in a row, replace them with one space
        '''
        p = re.compile(r'\ +')
        text = p.sub(r' ', text)
        return text
