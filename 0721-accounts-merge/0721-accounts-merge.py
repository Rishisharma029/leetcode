from collections import defaultdict
from typing import List

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        n = len(accounts)
        parent = list(range(n))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            px, py = find(x), find(y)
            if px != py:
                parent[py] = px

        email_to_account = {}

        # Union accounts having common emails
        for i, account in enumerate(accounts):
            for email in account[1:]:
                if email in email_to_account:
                    union(i, email_to_account[email])
                else:
                    email_to_account[email] = i

        # Group emails by root parent
        groups = defaultdict(list)
        for email, acc in email_to_account.items():
            root = find(acc)
            groups[root].append(email)

        # Build answer
        ans = []
        for root, emails in groups.items():
            ans.append([accounts[root][0]] + sorted(emails))

        return ans