import leetcode
from ._parser import Parser
from ._formatter import Formatter
import json


class LeetcodeParser(Parser):
    data: dict = None
    description: str = None
    examples: str = None
    constraints: str = None
    notes: str = None
    slug: str = None
    base_url: str = "https://leetcode.com/problems/"

    def __init__(self, problem_slug: str) -> None:
        self.problem_slug = problem_slug

        api_instance = leetcode.DefaultApi(
            leetcode.ApiClient(self.get_configuration()))

        graphql_request = leetcode.GraphqlQuery(  # get the query for the data
            query="""
                query getQuestionDetail($titleSlug: String!) {
                question(titleSlug: $titleSlug) {
                    questionFrontendId
                    title
                    content
                    difficulty
                    codeDefinition
                    sampleTestCase
                }
                }
            """,
            variables=leetcode.GraphqlQueryGetQuestionDetailVariables(
                title_slug=problem_slug),
            operation_name="getQuestionDetail",
        )
        # get the data
        self.data = api_instance.graphql_post(
            body=graphql_request).to_dict()["data"]["question"]
        # t = leetcode.GraphqlResponse()

        self.parse_content()

    def get_configuration(self) -> leetcode.Configuration:
        leetcode_session = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiNzMyNjE0NyIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjBlZmUyYTZmMTlkY2NmYTU2N2FlMGYzMWUyMjgxZjA1MGZkYTQwNGUiLCJpZCI6NzMyNjE0NywiZW1haWwiOiJlcmljQGxpbmRlc2F5LmNvbSIsInVzZXJuYW1lIjoiRmx5aW5nQXBwbGUiLCJ1c2VyX3NsdWciOiJGbHlpbmdBcHBsZSIsImF2YXRhciI6Imh0dHBzOi8vczMtdXMtd2VzdC0xLmFtYXpvbmF3cy5jb20vczMtbGMtdXBsb2FkL2Fzc2V0cy9kZWZhdWx0X2F2YXRhci5qcGciLCJyZWZyZXNoZWRfYXQiOjE2OTQyNzIxMzYsImlwIjoiODIuMjguMTI0LjEzOSIsImlkZW50aXR5IjoiNjc0NjlhNzg1ZDFkNTY4NmJiOTFiZTQ3MTJmYzJiMGYiLCJzZXNzaW9uX2lkIjo0NTkyODQzOSwiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwfQ.Ue_DlMRLSCVImYGpyga6hww-gtlZoEXGLuNDTP-detA"
        csrf_token = "s4qUA1uYpgC3lyZiAcXF3GPKkv1lxZLIvJCDeC4wqd3hgeo8FUIYQ5uI1MoTxVr8"
        configuration = leetcode.Configuration()
        configuration.api_key["x-csrftoken"] = csrf_token
        configuration.api_key["csrftoken"] = csrf_token
        configuration.api_key["LEETCODE_SESSION"] = leetcode_session
        configuration.api_key["Referer"] = "https://leetcode.com"
        configuration.debug = False
        return configuration

    def parse_content(self) -> None:
        content = self.data["content"]
        content = content.split("<p>&nbsp;</p>")

        self.description = content[0].strip()
        self.examples = content[1].strip()
        if len(content) >= 3:
            self.constaints = content[2].strip()
        if len(content) >= 4:
            self.notes = content[3].strip()

    def get_problem_name(self) -> str:
        return self.data["title"]

    def get_problem_difficulty(self) -> str:
        return self.data["difficulty"].lower()

    def get_problem_description(self) -> str:
        self.description = Formatter.format_html_tags(self.description)
        self.description = Formatter.fix_ampersands(self.description)
        return self.description

    def get_problem_examples_list(self) -> list[str]:
        # First split it on examples
        # Examples all have <strong class="example"> before it
        t = self.examples.split("<strong class=\"example\">")
        t = [Formatter.format_html_tags(x) for x in t]
        t = [x.replace("*", "") for x in t]
        t = [x[12:] for x in t if len(x) > 0]  # Example 1:\n\n
        return t

    def get_problem_examples(self) -> str:
        examples = self.get_problem_examples_list()
        examples = ''.join(examples)
        examples = Formatter.format_html_tags(examples)
        examples = Formatter.fix_ampersands(examples)
        return examples

    def get_problem_constaints(self) -> str:
        return_text = Formatter.format_html_tags(self.constaints)
        return_text = return_text.replace("\t", "")
        # Remove the top line of the thing, the Constraints line
        return_text = '\n'.join(return_text.split("\n")[1:])
        return_text = Formatter.format_html_tags(return_text)
        return_text = Formatter.fix_ampersands(return_text)
        return return_text

    def get_problem_notes(self) -> str:
        if not self.notes:
            return None

        return_text = Formatter.format_html_tags(self.notes)
        return_text = Formatter.fix_ampersands(return_text)
        return return_text

    def replace_problem_description(self, fileinfo: str) -> str:
        description_text = "# Description\n"+self.get_problem_description()
        notes = self.get_problem_notes()
        if notes:
            description_text += "\n## Notes\n"+notes
        fileinfo = fileinfo.replace(
            "# Description", description_text)
        fileinfo = fileinfo.replace(
            "# Input", "# Input\n"+self.get_problem_constaints())
        fileinfo = fileinfo.replace(
            "### Output", "")
        fileinfo = fileinfo.replace(
            "# Examples", "# Examples\n"+self.get_problem_examples())

        return fileinfo

    def format_template(self, template: str) -> str:
        # print(self.data["code_definition"][0]["defaultCode"])
        code_class = json.loads(self.data["code_definition"])[0]["defaultCode"]
        return template.replace("[CLASS]", code_class)


if __name__ == "__main__":
    print("started")
    parser = LeetcodeParser("two-sum")
    # parser = LeetcodeParser("combination-sum-iv")
    print(parser.get_problem_notes())
