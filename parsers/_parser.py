
class Parser():
    base_url: str = None
    problem_slug: str = None

    def __init__(self, problem_slug: str) -> None:
        raise NotImplementedError(
            "This is the parent class, should not be created")

    def delete_original_example(self, text: str) -> str:
        return text.replace("```\nInput\na b c\nOutput\nc b a\n```", "")

    def replace_solution_text(self, fileinfo: str) -> str:
        return fileinfo.replace("solution", self.get_problem_slug()+".cpp")

    def replace_problem_name(self, fileinfo: str) -> str:
        return fileinfo.replace("problem_name", self.get_problem_name())

    def replace_problem_link(self, fileinfo: str) -> str:
        return fileinfo.replace("problem_linK", self.base_url+self.get_problem_slug())

    def get_problem_slug(self) -> str:
        return self.problem_slug

    def get_problem_name(self) -> str:
        raise NotImplementedError(
            __class__+" get_problem_name not implemented")

    def get_problem_difficulty(self) -> str:
        raise NotImplementedError(
            __class__+" get_problem_difficulty not implemented")

    def get_problem_description(self) -> str:
        raise NotImplementedError(
            __class__+" get_problem_description not implemented")

    def get_problem_examples(self) -> str:
        raise NotImplementedError(
            __class__+" get_problem_description not implemented")

    def get_problem_notes(self) -> str:
        raise NotImplementedError(
            __class__+" get_problem_description not implemented")

    def replace_problem_description(self, fileinfo: str) -> str:
        raise NotImplementedError(
            __class__+" get_problem_description not implemented")


def fill_content(fileinfo: str, parser: Parser) -> str:
    '''
    Generates the content for the readme file
    '''
    # parser = LeetcodeParser(problem_name)
    fileinfo = parser.delete_original_example(fileinfo)
    fileinfo = parser.replace_problem_description(fileinfo)
    fileinfo = parser.replace_solution_text(fileinfo)
    fileinfo = parser.replace_problem_link(fileinfo)
    fileinfo = parser.replace_problem_name(fileinfo)
    return fileinfo
